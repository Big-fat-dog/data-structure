// ============================================================
// des.cpp
// 手写 DES：单块加解密 + ECB + CBC + PKCS#7 填充
// ============================================================
#include <iostream>
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>
#include <array>
#include <stdexcept>
#include <iomanip>
#include <sstream>

// ============================================================
// DES 常量表
// ============================================================
namespace tables {

// IP 初始置换
constexpr std::array<uint8_t, 64> IP = {
    58,50,42,34,26,18,10, 2, 60,52,44,36,28,20,12, 4,
    62,54,46,38,30,22,14, 6, 64,56,48,40,32,24,16, 8,
    57,49,41,33,25,17, 9, 1, 59,51,43,35,27,19,11, 3,
    61,53,45,37,29,21,13, 5, 63,55,47,39,31,23,15, 7
};

// FP 逆初始置换
constexpr std::array<uint8_t, 64> FP = {
    40, 8,48,16,56,24,64,32, 39, 7,47,15,55,23,63,31,
    38, 6,46,14,54,22,62,30, 37, 5,45,13,53,21,61,29,
    36, 4,44,12,52,20,60,28, 35, 3,43,11,51,19,59,27,
    34, 2,42,10,50,18,58,26, 33, 1,41, 9,49,17,57,25
};

// E 扩展
constexpr std::array<uint8_t, 48> E = {
    32, 1, 2, 3, 4, 5,  4, 5, 6, 7, 8, 9,
     8, 9,10,11,12,13, 12,13,14,15,16,17,
    16,17,18,19,20,21, 20,21,22,23,24,25,
    24,25,26,27,28,29, 28,29,30,31,32, 1
};

// P 置换
constexpr std::array<uint8_t, 32> P = {
    16, 7,20,21,29,12,28,17, 1,15,23,26, 5,18,31,10,
     2, 8,24,14,32,27, 3, 9,19,13,30, 6,22,11, 4,25
};

// PC-1 密钥置换
constexpr std::array<uint8_t, 56> PC1 = {
    57,49,41,33,25,17, 9,  1,58,50,42,34,26,18,
    10, 2,59,51,43,35,27, 19,11, 3,60,52,44,36,
    63,55,47,39,31,23,15,  7,62,54,46,38,30,22,
    14, 6,61,53,45,37,29, 21,13, 5,28,20,12, 4
};

// PC-2 压缩置换
constexpr std::array<uint8_t, 48> PC2 = {
    14,17,11,24, 1, 5,  3,28,15, 6,21,10,
    23,19,12, 4,26, 8, 16, 7,27,20,13, 2,
    41,52,31,37,47,55, 30,40,51,45,33,48,
    44,49,39,56,34,53, 46,42,50,36,29,32
};

// 循环左移位数表
constexpr std::array<uint8_t, 16> SHIFT = {
    1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};

// S 盒
constexpr uint8_t SBOX[8][4][16] = {
    {{14, 4,13, 1, 2,15,11, 8, 3,10, 6,12, 5, 9, 0, 7},
     { 0,15, 7, 4,14, 2,13, 1,10, 6,12,11, 9, 5, 3, 8},
     { 4, 1,14, 8,13, 6, 2,11,15,12, 9, 7, 3,10, 5, 0},
     {15,12, 8, 2, 4, 9, 1, 7, 5,11, 3,14,10, 0, 6,13}},
    {{15, 1, 8,14, 6,11, 3, 4, 9, 7, 2,13,12, 0, 5,10},
     { 3,13, 4, 7,15, 2, 8,14,12, 0, 1,10, 6, 9,11, 5},
     { 0,14, 7,11,10, 4,13, 1, 5, 8,12, 6, 9, 3, 2,15},
     {13, 8,10, 1, 3,15, 4, 2,11, 6, 7,12, 0, 5,14, 9}},
    {{10, 0, 9,14, 6, 3,15, 5, 1,13,12, 7,11, 4, 2, 8},
     {13, 7, 0, 9, 3, 4, 6,10, 2, 8, 5,14,12,11,15, 1},
     {13, 6, 4, 9, 8,15, 3, 0,11, 1, 2,12, 5,10,14, 7},
     { 1,10,13, 0, 6, 9, 8, 7, 4,15,14, 3,11, 5, 2,12}},
    {{ 7,13,14, 3, 0, 6, 9,10, 1, 2, 8, 5,11,12, 4,15},
     {13, 8,11, 5, 6,15, 0, 3, 4, 7, 2,12, 1,10,14, 9},
     {10, 6, 9, 0,12,11, 7,13,15, 1, 3,14, 5, 2, 8, 4},
     { 3,15, 0, 6,10, 1,13, 8, 9, 4, 5,11,12, 7, 2,14}},
    {{ 2,12, 4, 1, 7,10,11, 6, 8, 5, 3,15,13, 0,14, 9},
     {14,11, 2,12, 4, 7,13, 1, 5, 0,15,10, 3, 9, 8, 6},
     { 4, 2, 1,11,10,13, 7, 8,15, 9,12, 5, 6, 3, 0,14},
     {11, 8,12, 7, 1,14, 2,13, 6,15, 0, 9,10, 4, 5, 3}},
    {{12, 1,10,15, 9, 2, 6, 8, 0,13, 3, 4,14, 7, 5,11},
     {10,15, 4, 2, 7,12, 9, 5, 6, 1,13,14, 0,11, 3, 8},
     { 9,14,15, 5, 2, 8,12, 3, 7, 0, 4,10, 1,13,11, 6},
     { 4, 3, 2,12, 9, 5,15,10,11,14, 1, 7, 6, 0, 8,13}},
    {{ 4,11, 2,14,15, 0, 8,13, 3,12, 9, 7, 5,10, 6, 1},
     {13, 0,11, 7, 4, 9, 1,10,14, 3, 5,12, 2,15, 8, 6},
     { 1, 4,11,13,12, 3, 7,14,10,15, 6, 8, 0, 5, 9, 2},
     { 6,11,13, 8, 1, 4,10, 7, 9, 5, 0,15,14, 2, 3,12}},
    {{13, 2, 8, 4, 6,15,11, 1,10, 9, 3,14, 5, 0,12, 7},
     { 1,15,13, 8,10, 3, 7, 4,12, 5, 6,11, 0,14, 9, 2},
     { 7,11, 4, 1, 9,12,14, 2, 0, 6,10,13,15, 3, 5, 8},
     { 2, 1,14, 7, 4,10, 8,13,15,12, 9, 0, 3, 5, 6,11}}
};

} // namespace tables

// ============================================================
// DES 核心类
// ============================================================
class DES {
public:
    static constexpr size_t BLOCK_SIZE = 8;
    static constexpr size_t KEY_SIZE   = 8;

    explicit DES(const std::vector<uint8_t>& key) {
        if (key.size() != KEY_SIZE) {
            throw std::invalid_argument("DES key must be 8 bytes");
        }
        generateSubkeys(key.data());
    }

    void encryptBlock(uint8_t block[BLOCK_SIZE]) const {
        processBlock(block, true);
    }

    void decryptBlock(uint8_t block[BLOCK_SIZE]) const {
        processBlock(block, false);
    }

private:
    uint64_t subkeys_[16];

    // --------------------------------------------------------
    // 通用位置换（修复：显式指定输入位宽）
    //   table  : 置换表，1-based，第 1 位是 MSB
    //   n      : 输出位数
    //   in     : 输入值（右对齐，低 inBits 位有效）
    //   inBits : 输入的有效位宽
    // --------------------------------------------------------
    static uint64_t permute(const uint8_t* table, int n,
                            uint64_t in, int inBits) {
        uint64_t out = 0;
        for (int i = 0; i < n; ++i) {
            int pos = table[i];
            uint64_t bit = (in >> (inBits - pos)) & 1ULL;
            out = (out << 1) | bit;
        }
        return out;
    }

    // 28bit 循环左移
    static uint32_t rotl28(uint32_t x, int n) {
        return ((x << n) | (x >> (28 - n))) & 0x0FFFFFFFU;
    }

    // 密钥扩展
    void generateSubkeys(const uint8_t key[KEY_SIZE]) {
        using namespace tables;

        // 1. 大端加载 64bit 密钥
        uint64_t key64 = 0;
        for (int i = 0; i < 8; ++i) {
            key64 = (key64 << 8) | key[i];
        }

        // 2. PC-1: 64 → 56（输入 64bit）
        uint64_t pc1 = permute(PC1.data(), 56, key64, 64);

        // 3. 拆 C / D（各 28bit）
        uint32_t C = static_cast<uint32_t>((pc1 >> 28) & 0x0FFFFFFFU);
        uint32_t D = static_cast<uint32_t>(pc1 & 0x0FFFFFFFU);

        // 4. 16 轮：左移 + PC-2 压缩
        for (int i = 0; i < 16; ++i) {
            C = rotl28(C, SHIFT[i]);
            D = rotl28(D, SHIFT[i]);

            uint64_t CD = (static_cast<uint64_t>(C) << 28) | D;  // 56bit
            // 关键修复：PC-2 的输入是 56bit，不是 64bit
            subkeys_[i] = permute(PC2.data(), 48, CD, 56)
                        & 0xFFFFFFFFFFFFULL;
        }
    }

    // 轮函数 F
    static uint32_t feistel(uint32_t R, uint64_t subkey) {
        using namespace tables;

        // E 扩展：输入 32bit
        uint64_t expanded = permute(E.data(), 48, R, 32);

        // 异或子密钥
        expanded ^= subkey;

        // S 盒：48 → 32
        uint32_t sOut = 0;
        for (int i = 0; i < 8; ++i) {
            int shift = (7 - i) * 6;
            uint8_t six = static_cast<uint8_t>((expanded >> shift) & 0x3F);
            int row = ((six & 0x20) >> 4) | (six & 0x01);
            int col = (six >> 1) & 0x0F;
            uint8_t val = SBOX[i][row][col];
            sOut = (sOut << 4) | val;
        }

        // P 置换：输入 32bit
        return static_cast<uint32_t>(permute(P.data(), 32, sOut, 32));
    }

    // 单块处理
    void processBlock(uint8_t block[BLOCK_SIZE], bool encrypt) const {
        using namespace tables;

        // 1. 大端加载
        uint64_t data = 0;
        for (int i = 0; i < 8; ++i) {
            data = (data << 8) | block[i];
        }

        // 2. IP 置换：输入 64bit
        uint64_t ip = permute(IP.data(), 64, data, 64);

        // 3. 拆 L / R
        uint32_t L = static_cast<uint32_t>(ip >> 32);
        uint32_t R = static_cast<uint32_t>(ip & 0xFFFFFFFFULL);

        // 4. 16 轮 Feistel
        for (int i = 0; i < 16; ++i) {
            int ki = encrypt ? i : (15 - i);
            uint32_t F = feistel(R, subkeys_[ki]);
            uint32_t newR = L ^ F;
            L = R;
            R = newR;
        }

        // 5. 左右交换
        uint64_t preoutput = (static_cast<uint64_t>(R) << 32) | L;

        // 6. FP 置换：输入 64bit
        uint64_t out = permute(FP.data(), 64, preoutput, 64);

        // 7. 大端拆回字节
        for (int i = 0; i < 8; ++i) {
            block[i] = static_cast<uint8_t>((out >> (56 - i * 8)) & 0xFF);
        }
    }
};

// ============================================================
// PKCS#7 填充
// ============================================================
namespace pkcs7 {

std::vector<uint8_t> pad(const std::vector<uint8_t>& data, size_t blockSize) {
    size_t padLen = blockSize - (data.size() % blockSize);
    std::vector<uint8_t> out = data;
    out.insert(out.end(), padLen, static_cast<uint8_t>(padLen));
    return out;
}

std::vector<uint8_t> unpad(const std::vector<uint8_t>& data) {
    if (data.empty()) throw std::runtime_error("empty data");

    uint8_t padLen = data.back();
    if (padLen == 0 || padLen > 8 || padLen > data.size()) {
        throw std::runtime_error("invalid PKCS#7 padding");
    }
    for (size_t i = data.size() - padLen; i < data.size(); ++i) {
        if (data[i] != padLen) {
            throw std::runtime_error("invalid PKCS#7 padding");
        }
    }
    return std::vector<uint8_t>(data.begin(), data.end() - padLen);
}

} // namespace pkcs7

// ============================================================
// ECB 模式
// ============================================================
class DESECB {
public:
    explicit DESECB(const std::vector<uint8_t>& key) : des_(key) {}

    std::vector<uint8_t> encrypt(const std::vector<uint8_t>& plaintext) const {
        std::vector<uint8_t> data = pkcs7::pad(plaintext, DES::BLOCK_SIZE);
        std::vector<uint8_t> out(data.size());

        for (size_t i = 0; i < data.size(); i += DES::BLOCK_SIZE) {
            uint8_t block[DES::BLOCK_SIZE];
            std::memcpy(block, data.data() + i, DES::BLOCK_SIZE);
            des_.encryptBlock(block);
            std::memcpy(out.data() + i, block, DES::BLOCK_SIZE);
        }
        return out;
    }

    std::vector<uint8_t> decrypt(const std::vector<uint8_t>& ciphertext) const {
        if (ciphertext.size() % DES::BLOCK_SIZE != 0) {
            throw std::invalid_argument("ciphertext size must be multiple of 8");
        }

        std::vector<uint8_t> out(ciphertext.size());
        for (size_t i = 0; i < ciphertext.size(); i += DES::BLOCK_SIZE) {
            uint8_t block[DES::BLOCK_SIZE];
            std::memcpy(block, ciphertext.data() + i, DES::BLOCK_SIZE);
            des_.decryptBlock(block);
            std::memcpy(out.data() + i, block, DES::BLOCK_SIZE);
        }
        return pkcs7::unpad(out);
    }

private:
    DES des_;
};

// ============================================================
// CBC 模式
// ============================================================
class DESCBC {
public:
    DESCBC(const std::vector<uint8_t>& key,
           const std::vector<uint8_t>& iv)
        : des_(key)
    {
        if (iv.size() != DES::BLOCK_SIZE) {
            throw std::invalid_argument("IV must be 8 bytes");
        }
        std::memcpy(iv_, iv.data(), DES::BLOCK_SIZE);
    }

    std::vector<uint8_t> encrypt(const std::vector<uint8_t>& plaintext) const {
        std::vector<uint8_t> data = pkcs7::pad(plaintext, DES::BLOCK_SIZE);
        std::vector<uint8_t> out(data.size());

        uint8_t prev[DES::BLOCK_SIZE];
        std::memcpy(prev, iv_, DES::BLOCK_SIZE);

        for (size_t i = 0; i < data.size(); i += DES::BLOCK_SIZE) {
            uint8_t block[DES::BLOCK_SIZE];
            for (size_t j = 0; j < DES::BLOCK_SIZE; ++j) {
                block[j] = data[i + j] ^ prev[j];
            }
            des_.encryptBlock(block);
            std::memcpy(out.data() + i, block, DES::BLOCK_SIZE);
            std::memcpy(prev, block, DES::BLOCK_SIZE);
        }
        return out;
    }

    std::vector<uint8_t> decrypt(const std::vector<uint8_t>& ciphertext) const {
        if (ciphertext.size() % DES::BLOCK_SIZE != 0) {
            throw std::invalid_argument("ciphertext size must be multiple of 8");
        }

        std::vector<uint8_t> out(ciphertext.size());

        uint8_t prev[DES::BLOCK_SIZE];
        std::memcpy(prev, iv_, DES::BLOCK_SIZE);

        for (size_t i = 0; i < ciphertext.size(); i += DES::BLOCK_SIZE) {
            uint8_t block[DES::BLOCK_SIZE];
            std::memcpy(block, ciphertext.data() + i, DES::BLOCK_SIZE);

            uint8_t cipherBlock[DES::BLOCK_SIZE];
            std::memcpy(cipherBlock, block, DES::BLOCK_SIZE);

            des_.decryptBlock(block);
            for (size_t j = 0; j < DES::BLOCK_SIZE; ++j) {
                out[i + j] = block[j] ^ prev[j];
            }
            std::memcpy(prev, cipherBlock, DES::BLOCK_SIZE);
        }
        return pkcs7::unpad(out);
    }

private:
    DES des_;
    uint8_t iv_[DES::BLOCK_SIZE];
};

// ============================================================
// 工具：字节流 ↔ 十六进制
// ============================================================
namespace hex {

std::string encode(const std::vector<uint8_t>& data) {
    std::ostringstream oss;
    for (auto b : data) {
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)b;
    }
    return oss.str();
}

std::vector<uint8_t> decode(const std::string& s) {
    if (s.size() % 2 != 0) {
        throw std::invalid_argument("hex length must be even");
    }
    std::vector<uint8_t> out;
    for (size_t i = 0; i < s.size(); i += 2) {
        out.push_back(static_cast<uint8_t>(
            std::stoi(s.substr(i, 2), nullptr, 16)));
    }
    return out;
}

} // namespace hex

// ============================================================
// 测试
// ============================================================
int main() {
    // ---------- 测试 1：经典单块向量 ----------
    std::cout << "===== 测试 1: 经典单块向量 =====\n";
    {
        std::vector<uint8_t> key    = hex::decode("133457799BBCDFF1");
        std::vector<uint8_t> plain  = hex::decode("0123456789ABCDEF");
        std::vector<uint8_t> expect = hex::decode("85E813540F0AB405");

        DES des(key);
        uint8_t block[8];
        std::memcpy(block, plain.data(), 8);
        des.encryptBlock(block);

        std::vector<uint8_t> got(block, block + 8);
        std::cout << "明文:   " << hex::encode(plain)  << "\n";
        std::cout << "计算:   " << hex::encode(got)    << "\n";
        std::cout << "期望:   " << hex::encode(expect) << "\n";
        std::cout << (got == expect ? "✅ 通过" : "❌ 失败") << "\n\n";

        des.decryptBlock(block);
        std::vector<uint8_t> back(block, block + 8);
        std::cout << "解密:   " << hex::encode(back) << "\n";
        std::cout << (back == plain ? "✅ 往返通过" : "❌ 往返失败") << "\n\n";
    }

    // ---------- 测试 2：ECB 模式 ----------
    std::cout << "===== 测试 2: ECB 模式 =====\n";
    {
        std::vector<uint8_t> key = hex::decode("133457799BBCDFF1");
        std::string msg = "AAAAAAAAAAAAAAAA";
        std::vector<uint8_t> plain(msg.begin(), msg.end());

        DESECB ecb(key);
        auto cipher = ecb.encrypt(plain);

        std::cout << "明文:     " << msg << "\n";
        std::cout << "密文(hex): " << hex::encode(cipher) << "\n";

        std::vector<uint8_t> block1(cipher.begin(), cipher.begin() + 8);
        std::vector<uint8_t> block2(cipher.begin() + 8, cipher.begin() + 16);
        std::cout << "块1: " << hex::encode(block1) << "\n";
        std::cout << "块2: " << hex::encode(block2) << "\n";
        std::cout << (block1 == block2
                      ? "⚠️ 两个块相同（ECB 缺陷演示）"
                      : "两个块不同") << "\n\n";

        auto back = ecb.decrypt(cipher);
        std::string backStr(back.begin(), back.end());
        std::cout << "解密:     " << backStr << "\n";
        std::cout << (backStr == msg ? "✅ 往返通过" : "❌ 往返失败") << "\n\n";
    }

    // ---------- 测试 3：CBC 模式 ----------
    std::cout << "===== 测试 3: CBC 模式 =====\n";
    {
        std::vector<uint8_t> key = hex::decode("133457799BBCDFF1");
        std::vector<uint8_t> iv  = hex::decode("0000000000000000");

        std::string msg = "AAAAAAAAAAAAAAAA";
        std::vector<uint8_t> plain(msg.begin(), msg.end());

        DESCBC cbc(key, iv);
        auto cipher = cbc.encrypt(plain);

        std::cout << "明文:     " << msg << "\n";
        std::cout << "密文(hex): " << hex::encode(cipher) << "\n";

        std::vector<uint8_t> block1(cipher.begin(), cipher.begin() + 8);
        std::vector<uint8_t> block2(cipher.begin() + 8, cipher.begin() + 16);
        std::cout << "块1: " << hex::encode(block1) << "\n";
        std::cout << "块2: " << hex::encode(block2) << "\n";
        std::cout << (block1 == block2
                      ? "⚠️ 两个块相同"
                      : "✅ 两个块不同（CBC 成功消除 ECB 缺陷）") << "\n\n";

        auto back = cbc.decrypt(cipher);
        std::string backStr(back.begin(), back.end());
        std::cout << "解密:     " << backStr << "\n";
        std::cout << (backStr == msg ? "✅ 往返通过" : "❌ 往返失败") << "\n\n";
    }

    // ---------- 测试 4：长消息 CBC ----------
    std::cout << "===== 测试 4: 长消息 CBC =====\n";
    {
        std::vector<uint8_t> key = hex::decode("0123456789ABCDEF");
        std::vector<uint8_t> iv  = hex::decode("1234567890ABCDEF");

        std::string msg = "The quick brown fox jumps over the lazy dog.";
        std::vector<uint8_t> plain(msg.begin(), msg.end());

        DESCBC cbc(key, iv);
        auto cipher = cbc.encrypt(plain);
        auto back   = cbc.decrypt(cipher);

        std::string backStr(back.begin(), back.end());
        std::cout << "明文长度: " << plain.size() << " 字节\n";
        std::cout << "密文长度: " << cipher.size() << " 字节（含填充）\n";
        std::cout << "密文:     " << hex::encode(cipher) << "\n";
        std::cout << "解密:     " << backStr << "\n";
        std::cout << (backStr == msg ? "✅ 往返通过" : "❌ 往返失败") << "\n";
    }

    return 0;
}