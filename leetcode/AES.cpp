// ============================================================
// aes.cpp
// 手写 AES-128：单块加解密 + ECB + CBC + PKCS#7 填充
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
// AES 常量表
// ============================================================
namespace tables
{

    // S 盒（256 字节）
    constexpr std::array<uint8_t, 256> SBOX = {
        0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
        0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
        0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
        0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
        0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
        0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
        0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
        0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
        0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
        0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
        0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
        0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
        0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
        0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
        0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
        0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16};

    // 逆 S 盒
    constexpr std::array<uint8_t, 256> INV_SBOX = {
        0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
        0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
        0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
        0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
        0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
        0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
        0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
        0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
        0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
        0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
        0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
        0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
        0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
        0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
        0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
        0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d};

    // 轮常数 Rcon（只用到前 10 个）
    constexpr std::array<uint8_t, 11> RCON = {
        0x00, // 不用
        0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36};

} // namespace tables

// ============================================================
// GF(2^8) 乘法
// ============================================================
static inline uint8_t gf_mul(uint8_t a, uint8_t b)
{
    uint8_t p = 0;
    for (int i = 0; i < 8; i++)
    {
        if (b & 1)
            p ^= a;
        uint8_t hi = a & 0x80;
        a <<= 1;
        if (hi)
            a ^= 0x1B; // AES 不可约多项式 x^8 + x^4 + x^3 + x + 1
        b >>= 1;
    }
    return p;
}

// 快速版：乘 2 和乘 3
static inline uint8_t xtime(uint8_t x)
{
    return (uint8_t)((x << 1) ^ ((x & 0x80) ? 0x1B : 0x00));
}
static inline uint8_t mul2(uint8_t x) { return xtime(x); }
static inline uint8_t mul3(uint8_t x) { return xtime(x) ^ x; }

// ============================================================
// AES 核心类（AES-128）
// ============================================================
class AES128
{
public:
    static constexpr size_t BLOCK_SIZE = 16;
    static constexpr size_t KEY_SIZE = 16;
    static constexpr int NR = 10; // 轮数

    explicit AES128(const std::vector<uint8_t> &key)
    {
        if (key.size() != KEY_SIZE)
        {
            throw std::invalid_argument("AES-128 key must be 16 bytes");
        }
        keyExpansion(key.data());
    }

    void encryptBlock(uint8_t block[BLOCK_SIZE]) const
    {
        uint8_t state[4][4];
        loadState(state, block);

        addRoundKey(state, 0);

        for (int round = 1; round < NR; ++round)
        {
            subBytes(state);
            shiftRows(state);
            mixColumns(state);
            addRoundKey(state, round);
        }

        // 最后一轮：无 MixColumns
        subBytes(state);
        shiftRows(state);
        addRoundKey(state, NR);

        storeState(state, block);
    }

    void decryptBlock(uint8_t block[BLOCK_SIZE]) const
    {
        uint8_t state[4][4];
        loadState(state, block);

        addRoundKey(state, NR);

        for (int round = NR - 1; round >= 1; --round)
        {
            invShiftRows(state);
            invSubBytes(state);
            addRoundKey(state, round);
            invMixColumns(state);
        }

        invShiftRows(state);
        invSubBytes(state);
        addRoundKey(state, 0);

        storeState(state, block);
    }

private:
    uint8_t roundKeys_[11][16]; // 11 个轮密钥

    // --------------------------------------------------------
    // 状态矩阵的加载 / 存储（列优先）
    // --------------------------------------------------------
    static void loadState(uint8_t state[4][4], const uint8_t block[16])
    {
        for (int i = 0; i < 16; ++i)
        {
            state[i % 4][i / 4] = block[i];
        }
    }

    static void storeState(uint8_t state[4][4], uint8_t block[16])
    {
        for (int i = 0; i < 16; ++i)
        {
            block[i] = state[i % 4][i / 4];
        }
    }

    // --------------------------------------------------------
    // 密钥扩展：从 16 字节密钥生成 11 个轮密钥
    // --------------------------------------------------------
    void keyExpansion(const uint8_t key[16])
    {
        using namespace tables;

        uint8_t w[44][4]; // 44 个字，每个字 4 字节

        // 前 4 个字 = 原始密钥
        for (int i = 0; i < 4; ++i)
        {
            w[i][0] = key[4 * i + 0];
            w[i][1] = key[4 * i + 1];
            w[i][2] = key[4 * i + 2];
            w[i][3] = key[4 * i + 3];
        }

        // 扩展出后面 40 个字
        for (int i = 4; i < 44; ++i)
        {
            uint8_t temp[4];
            std::memcpy(temp, w[i - 1], 4);

            if (i % 4 == 0)
            {
                // RotWord：循环左移 1 字节
                uint8_t t = temp[0];
                temp[0] = temp[1];
                temp[1] = temp[2];
                temp[2] = temp[3];
                temp[3] = t;

                // SubWord：每字节查 S 盒
                for (int j = 0; j < 4; ++j)
                {
                    temp[j] = SBOX[temp[j]];
                }

                // 异或 Rcon
                temp[0] ^= RCON[i / 4];
            }

            // W[i] = W[i-4] ⊕ temp
            for (int j = 0; j < 4; ++j)
            {
                w[i][j] = w[i - 4][j] ^ temp[j];
            }
        }

        // 把 44 个字拼成 11 个轮密钥
        for (int r = 0; r <= NR; ++r)
        {
            for (int c = 0; c < 4; ++c)
            {
                for (int j = 0; j < 4; ++j)
                {
                    roundKeys_[r][4 * c + j] = w[4 * r + c][j];
                }
            }
        }
    }

    // --------------------------------------------------------
    // 四个核心操作
    // --------------------------------------------------------

    // SubBytes：字节替换
    // 对 state 中每个字节查 S 盒，做非线性替换
    // 这是 AES 里唯一的非线性操作，抵抗线性和差分分析
    static void subBytes(uint8_t state[4][4])
    {
        using namespace tables;
        for (int i = 0; i < 4; ++i)              // 遍历 4 行
            for (int j = 0; j < 4; ++j)          // 遍历 4 列
                state[i][j] = SBOX[state[i][j]]; // 用当前字节做索引查 S 盒
    }

    // InvSubBytes：逆字节替换
    // 解密时用，查逆 S 盒，把字节还原
    static void invSubBytes(uint8_t state[4][4])
    {
        using namespace tables;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                state[i][j] = INV_SBOX[state[i][j]]; // 查逆 S 盒
    }

    // ShiftRows：行移位
    // 第 0 行不动，第 1 行左移 1，第 2 行左移 2，第 3 行左移 3
    // 作用：让不同列之间的字节互相混合，增强扩散
    static void shiftRows(uint8_t state[4][4])
    {
        // 第 1 行左移 1 字节
        // [a b c d] → [b c d a]
        uint8_t t = state[1][0];
        state[1][0] = state[1][1];
        state[1][1] = state[1][2];
        state[1][2] = state[1][3];
        state[1][3] = t;

        // 第 2 行左移 2 字节
        // [a b c d] → [c d a b]
        // 等价于交换前两个和后两个
        t = state[2][0];
        state[2][0] = state[2][2];
        state[2][2] = t;
        t = state[2][1];
        state[2][1] = state[2][3];
        state[2][3] = t;

        // 第 3 行左移 3 字节，等价于右移 1 字节
        // [a b c d] → [d a b c]
        t = state[3][3];
        state[3][3] = state[3][2];
        state[3][2] = state[3][1];
        state[3][1] = state[3][0];
        state[3][0] = t;
    }

    // InvShiftRows：逆行移位
    // 解密时用，和 ShiftRows 方向相反
    // 第 0 行不动，第 1 行右移 1，第 2 行右移 2，第 3 行右移 3
    static void invShiftRows(uint8_t state[4][4])
    {
        // 第 1 行右移 1 字节
        // [a b c d] → [d a b c]
        uint8_t t = state[1][3];
        state[1][3] = state[1][2];
        state[1][2] = state[1][1];
        state[1][1] = state[1][0];
        state[1][0] = t;

        // 第 2 行右移 2 字节
        // [a b c d] → [c d a b]
        // 和加密时的交换一样，因为交换两次就还原了
        t = state[2][0];
        state[2][0] = state[2][2];
        state[2][2] = t;
        t = state[2][1];
        state[2][1] = state[2][3];
        state[2][3] = t;

        // 第 3 行右移 3 字节，等价于左移 1 字节
        // [a b c d] → [b c d a]
        t = state[3][0];
        state[3][0] = state[3][1];
        state[3][1] = state[3][2];
        state[3][2] = state[3][3];
        state[3][3] = t;
    }

    // MixColumns：列混合
    // 对每一列做矩阵乘法，矩阵是固定的：
    //   [02 03 01 01]
    //   [01 02 03 01]
    //   [01 01 02 03]
    //   [03 01 01 02]
    // 乘法在 GF(2^8) 上进行，mul2 = 乘 2，mul3 = 乘 3
    // 作用：让一列内的 4 个字节互相影响，增强扩散
    static void mixColumns(uint8_t state[4][4])
    {
        for (int c = 0; c < 4; ++c) // 遍历每一列
        {
            // 取出这一列的 4 个字节
            uint8_t a0 = state[0][c];
            uint8_t a1 = state[1][c];
            uint8_t a2 = state[2][c];
            uint8_t a3 = state[3][c];

            // 矩阵乘法的第 0 行：02*a0 + 03*a1 + 01*a2 + 01*a3
            // GF(2^8) 里加法就是异或，01*a = a
            state[0][c] = mul2(a0) ^ mul3(a1) ^ a2 ^ a3;

            // 第 1 行：01*a0 + 02*a1 + 03*a2 + 01*a3
            state[1][c] = a0 ^ mul2(a1) ^ mul3(a2) ^ a3;

            // 第 2 行：01*a0 + 01*a1 + 02*a2 + 03*a3
            state[2][c] = a0 ^ a1 ^ mul2(a2) ^ mul3(a3);

            // 第 3 行：03*a0 + 01*a1 + 01*a2 + 02*a3
            state[3][c] = mul3(a0) ^ a1 ^ a2 ^ mul2(a3);
        }
    }

    // InvMixColumns：逆列混合
    // 解密时用，矩阵是加密矩阵的逆：
    //   [0E 0B 0D 09]
    //   [09 0E 0B 0D]
    //   [0D 09 0E 0B]
    //   [0B 0D 09 0E]
    // 每个系数都要在 GF(2^8) 上乘，所以用通用的 gf_mul
    static void invMixColumns(uint8_t state[4][4])
    {
        for (int c = 0; c < 4; ++c)
        {
            uint8_t a0 = state[0][c];
            uint8_t a1 = state[1][c];
            uint8_t a2 = state[2][c];
            uint8_t a3 = state[3][c];

            // 第 0 行：0E*a0 + 0B*a1 + 0D*a2 + 09*a3
            state[0][c] = gf_mul(a0, 0x0E) ^ gf_mul(a1, 0x0B) ^ gf_mul(a2, 0x0D) ^ gf_mul(a3, 0x09);

            // 第 1 行：09*a0 + 0E*a1 + 0B*a2 + 0D*a3
            state[1][c] = gf_mul(a0, 0x09) ^ gf_mul(a1, 0x0E) ^ gf_mul(a2, 0x0B) ^ gf_mul(a3, 0x0D);

            // 第 2 行：0D*a0 + 09*a1 + 0E*a2 + 0B*a3
            state[2][c] = gf_mul(a0, 0x0D) ^ gf_mul(a1, 0x09) ^ gf_mul(a2, 0x0E) ^ gf_mul(a3, 0x0B);

            // 第 3 行：0B*a0 + 0D*a1 + 09*a2 + 0E*a3
            state[3][c] = gf_mul(a0, 0x0B) ^ gf_mul(a1, 0x0D) ^ gf_mul(a2, 0x09) ^ gf_mul(a3, 0x0E);
        }
    }

    // AddRoundKey：轮密钥加
    // 把当前 state 和本轮轮密钥逐字节异或
    // 这是唯一用到密钥的步骤，其他三步都是固定的
    void addRoundKey(uint8_t state[4][4], int round) const
    {
        for (int i = 0; i < 4; ++i) // 行
        {
            for (int j = 0; j < 4; ++j) // 列
            {
                // roundKeys_ 是按列优先存的：
                // roundKeys_[round][4*j + i] 对应 state[i][j]
                state[i][j] ^= roundKeys_[round][4 * j + i];
            }
        }
    }
};

// ============================================================
// PKCS#7 填充（块大小 16）
// ============================================================
namespace pkcs7
{

    std::vector<uint8_t> pad(const std::vector<uint8_t> &data, size_t blockSize)
    {
        size_t padLen = blockSize - (data.size() % blockSize);
        std::vector<uint8_t> out = data;
        out.insert(out.end(), padLen, static_cast<uint8_t>(padLen));
        return out;
    }

    std::vector<uint8_t> unpad(const std::vector<uint8_t> &data)
    {
        if (data.empty())
            throw std::runtime_error("empty data");

        uint8_t padLen = data.back();
        if (padLen == 0 || padLen > 16 || padLen > data.size())
        {
            throw std::runtime_error("invalid PKCS#7 padding");
        }
        for (size_t i = data.size() - padLen; i < data.size(); ++i)
        {
            if (data[i] != padLen)
            {
                throw std::runtime_error("invalid PKCS#7 padding");
            }
        }
        return std::vector<uint8_t>(data.begin(), data.end() - padLen);
    }

} // namespace pkcs7

// ============================================================
// ECB 模式
// ============================================================
class AESECB
{
public:
    explicit AESECB(const std::vector<uint8_t> &key) : aes_(key) {}

    std::vector<uint8_t> encrypt(const std::vector<uint8_t> &plaintext) const
    {
        std::vector<uint8_t> data = pkcs7::pad(plaintext, AES128::BLOCK_SIZE);
        std::vector<uint8_t> out(data.size());

        for (size_t i = 0; i < data.size(); i += AES128::BLOCK_SIZE)
        {
            uint8_t block[16];
            std::memcpy(block, data.data() + i, 16);
            aes_.encryptBlock(block);
            std::memcpy(out.data() + i, block, 16);
        }
        return out;
    }

    std::vector<uint8_t> decrypt(const std::vector<uint8_t> &ciphertext) const
    {
        if (ciphertext.size() % AES128::BLOCK_SIZE != 0)
        {
            throw std::invalid_argument("ciphertext size must be multiple of 16");
        }

        std::vector<uint8_t> out(ciphertext.size());
        for (size_t i = 0; i < ciphertext.size(); i += AES128::BLOCK_SIZE)
        {
            uint8_t block[16];
            std::memcpy(block, ciphertext.data() + i, 16);
            aes_.decryptBlock(block);
            std::memcpy(out.data() + i, block, 16);
        }
        return pkcs7::unpad(out);
    }

private:
    AES128 aes_;
};

// ============================================================
// CBC 模式
// ============================================================
class AESCBC
{
public:
    AESCBC(const std::vector<uint8_t> &key,
           const std::vector<uint8_t> &iv)
        : aes_(key)
    {
        if (iv.size() != AES128::BLOCK_SIZE)
        {
            throw std::invalid_argument("IV must be 16 bytes");
        }
        std::memcpy(iv_, iv.data(), 16);
    }

    std::vector<uint8_t> encrypt(const std::vector<uint8_t> &plaintext) const
    {
        std::vector<uint8_t> data = pkcs7::pad(plaintext, AES128::BLOCK_SIZE);
        std::vector<uint8_t> out(data.size());

        uint8_t prev[16];
        std::memcpy(prev, iv_, 16);

        for (size_t i = 0; i < data.size(); i += AES128::BLOCK_SIZE)
        {
            uint8_t block[16];
            for (size_t j = 0; j < 16; ++j)
            {
                block[j] = data[i + j] ^ prev[j];
            }
            aes_.encryptBlock(block);
            std::memcpy(out.data() + i, block, 16);
            std::memcpy(prev, block, 16);
        }
        return out;
    }

    std::vector<uint8_t> decrypt(const std::vector<uint8_t> &ciphertext) const
    {
        if (ciphertext.size() % AES128::BLOCK_SIZE != 0)
        {
            throw std::invalid_argument("ciphertext size must be multiple of 16");
        }

        std::vector<uint8_t> out(ciphertext.size());

        uint8_t prev[16];
        std::memcpy(prev, iv_, 16);

        for (size_t i = 0; i < ciphertext.size(); i += AES128::BLOCK_SIZE)
        {
            uint8_t block[16];
            std::memcpy(block, ciphertext.data() + i, 16);

            uint8_t cipherBlock[16];
            std::memcpy(cipherBlock, block, 16);

            aes_.decryptBlock(block);
            for (size_t j = 0; j < 16; ++j)
            {
                out[i + j] = block[j] ^ prev[j];
            }
            std::memcpy(prev, cipherBlock, 16);
        }
        return pkcs7::unpad(out);
    }

private:
    AES128 aes_;
    uint8_t iv_[16];
};

// ============================================================
// 工具：字节流 ↔ 十六进制
// ============================================================
namespace hex
{

    std::string encode(const std::vector<uint8_t> &data)
    {
        std::ostringstream oss;
        for (auto b : data)
        {
            oss << std::hex << std::setw(2) << std::setfill('0') << (int)b;
        }
        return oss.str();
    }

    std::vector<uint8_t> decode(const std::string &s)
    {
        if (s.size() % 2 != 0)
        {
            throw std::invalid_argument("hex length must be even");
        }
        std::vector<uint8_t> out;
        for (size_t i = 0; i < s.size(); i += 2)
        {
            out.push_back(static_cast<uint8_t>(
                std::stoi(s.substr(i, 2), nullptr, 16)));
        }
        return out;
    }

} // namespace hex

// ============================================================
// 测试
// ============================================================
int main()
{
    // ---------- 测试 1：FIPS 197 官方向量 ----------
    std::cout << "===== 测试 1: FIPS 197 单块向量 =====\n";
    {
        // FIPS 197 附录 B 的经典向量
        // key   = 2b7e151628aed2a6abf7158809cf4f3c
        // plain = 3243f6a8885a308d313198a2e0370734
        // cipher = 3925841d02dc09fbdc118597196a0b32
        std::vector<uint8_t> key = hex::decode("2b7e151628aed2a6abf7158809cf4f3c");
        std::vector<uint8_t> plain = hex::decode("3243f6a8885a308d313198a2e0370734");
        std::vector<uint8_t> expect = hex::decode("3925841d02dc09fbdc118597196a0b32");

        AES128 aes(key);
        uint8_t block[16];
        std::memcpy(block, plain.data(), 16);
        aes.encryptBlock(block);

        std::vector<uint8_t> got(block, block + 16);
        std::cout << "明文:   " << hex::encode(plain) << "\n";
        std::cout << "计算:   " << hex::encode(got) << "\n";
        std::cout << "期望:   " << hex::encode(expect) << "\n";
        std::cout << (got == expect ? "✅ 通过" : "❌ 失败") << "\n\n";

        aes.decryptBlock(block);
        std::vector<uint8_t> back(block, block + 16);
        std::cout << "解密:   " << hex::encode(back) << "\n";
        std::cout << (back == plain ? "✅ 往返通过" : "❌ 往返失败") << "\n\n";
    }

    // ---------- 测试 2：FIPS 197 附录 C.1 向量 ----------
    std::cout << "===== 测试 2: FIPS 197 附录 C.1 =====\n";
    {
        // key   = 000102030405060708090a0b0c0d0e0f
        // plain = 00112233445566778899aabbccddeeff
        // cipher = 69c4e0d86a7b0430d8cdb78070b4c55a
        std::vector<uint8_t> key = hex::decode("000102030405060708090a0b0c0d0e0f");
        std::vector<uint8_t> plain = hex::decode("00112233445566778899aabbccddeeff");
        std::vector<uint8_t> expect = hex::decode("69c4e0d86a7b0430d8cdb78070b4c55a");

        AES128 aes(key);
        uint8_t block[16];
        std::memcpy(block, plain.data(), 16);
        aes.encryptBlock(block);

        std::vector<uint8_t> got(block, block + 16);
        std::cout << "明文:   " << hex::encode(plain) << "\n";
        std::cout << "计算:   " << hex::encode(got) << "\n";
        std::cout << "期望:   " << hex::encode(expect) << "\n";
        std::cout << (got == expect ? "✅ 通过" : "❌ 失败") << "\n\n";

        aes.decryptBlock(block);
        std::vector<uint8_t> back(block, block + 16);
        std::cout << "解密:   " << hex::encode(back) << "\n";
        std::cout << (back == plain ? "✅ 往返通过" : "❌ 往返失败") << "\n\n";
    }

    // ---------- 测试 3：ECB 模式 ----------
    std::cout << "===== 测试 3: ECB 模式 =====\n";
    {
        std::vector<uint8_t> key = hex::decode("2b7e151628aed2a6abf7158809cf4f3c");

        // 用两个相同的明文块演示 ECB 缺陷
        std::string msg = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"; // 32 字节 = 2 个相同块
        std::vector<uint8_t> plain(msg.begin(), msg.end());

        AESECB ecb(key);
        auto cipher = ecb.encrypt(plain);

        std::cout << "明文:     " << msg << "\n";
        std::cout << "密文(hex): " << hex::encode(cipher) << "\n";

        std::vector<uint8_t> block1(cipher.begin(), cipher.begin() + 16);
        std::vector<uint8_t> block2(cipher.begin() + 16, cipher.begin() + 32);
        std::cout << "块1: " << hex::encode(block1) << "\n";
        std::cout << "块2: " << hex::encode(block2) << "\n";
        std::cout << (block1 == block2
                          ? "⚠️ 两个块相同（ECB 缺陷演示）"
                          : "两个块不同")
                  << "\n\n";

        auto back = ecb.decrypt(cipher);
        std::string backStr(back.begin(), back.end());
        std::cout << "解密:     " << backStr << "\n";
        std::cout << (backStr == msg ? "✅ 往返通过" : "❌ 往返失败") << "\n\n";
    }

    // ---------- 测试 4：CBC 模式 ----------
    std::cout << "===== 测试 4: CBC 模式 =====\n";
    {
        std::vector<uint8_t> key = hex::decode("2b7e151628aed2a6abf7158809cf4f3c");
        std::vector<uint8_t> iv = hex::decode("000102030405060708090a0b0c0d0e0f");

        std::string msg = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
        std::vector<uint8_t> plain(msg.begin(), msg.end());

        AESCBC cbc(key, iv);
        auto cipher = cbc.encrypt(plain);

        std::cout << "明文:     " << msg << "\n";
        std::cout << "密文(hex): " << hex::encode(cipher) << "\n";

        std::vector<uint8_t> block1(cipher.begin(), cipher.begin() + 16);
        std::vector<uint8_t> block2(cipher.begin() + 16, cipher.begin() + 32);
        std::cout << "块1: " << hex::encode(block1) << "\n";
        std::cout << "块2: " << hex::encode(block2) << "\n";
        std::cout << (block1 == block2
                          ? "⚠️ 两个块相同"
                          : "✅ 两个块不同（CBC 成功消除 ECB 缺陷）")
                  << "\n\n";

        auto back = cbc.decrypt(cipher);
        std::string backStr(back.begin(), back.end());
        std::cout << "解密:     " << backStr << "\n";
        std::cout << (backStr == msg ? "✅ 往返通过" : "❌ 往返失败") << "\n\n";
    }

    // ---------- 测试 5：长消息 CBC ----------
    std::cout << "===== 测试 5: 长消息 CBC =====\n";
    {
        std::vector<uint8_t> key = hex::decode("2b7e151628aed2a6abf7158809cf4f3c");
        std::vector<uint8_t> iv = hex::decode("000102030405060708090a0b0c0d0e0f");

        std::string msg = "The quick brown fox jumps over the lazy dog.";
        std::vector<uint8_t> plain(msg.begin(), msg.end());

        AESCBC cbc(key, iv);
        auto cipher = cbc.encrypt(plain);
        auto back = cbc.decrypt(cipher);

        std::string backStr(back.begin(), back.end());
        std::cout << "明文长度: " << plain.size() << " 字节\n";
        std::cout << "密文长度: " << cipher.size() << " 字节（含填充）\n";
        std::cout << "密文:     " << hex::encode(cipher) << "\n";
        std::cout << "解密:     " << backStr << "\n";
        std::cout << (backStr == msg ? "✅ 往返通过" : "❌ 往返失败") << "\n";
    }

    return 0;
}