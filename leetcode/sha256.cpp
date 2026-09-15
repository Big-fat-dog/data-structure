// sha256.cpp —— 按 MD5 版风格实现的 SHA-256
#include <iostream>
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

// ============================================================
// SHA-256 常数 K[0..63]
// 来源：前 64 个素数立方根小数部分的前 32 位（FIPS 180-4）
// ============================================================
static const uint32_t K[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

// ============================================================
// 大端序读写工具（SHA-256 规定大端）
// ============================================================
static inline uint32_t read_be32(const uint8_t* p) {
    return ((uint32_t)p[0] << 24)
         | ((uint32_t)p[1] << 16)
         | ((uint32_t)p[2] << 8)
         |  (uint32_t)p[3];
}

static inline void write_be32(uint8_t* p, uint32_t v) {
    p[0] = (uint8_t)((v >> 24) & 0xff);
    p[1] = (uint8_t)((v >> 16) & 0xff);
    p[2] = (uint8_t)((v >> 8)  & 0xff);
    p[3] = (uint8_t)( v        & 0xff);
}

// 循环右移
static inline uint32_t rotr(uint32_t x, uint32_t n) {
    return (x >> n) | (x << (32 - n));
}

// ============================================================
// 6 个辅助函数
// ============================================================
static inline uint32_t Ch (uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (~x & z);
}
static inline uint32_t Maj(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}
static inline uint32_t Sigma0(uint32_t x) {   // 大写 Σ0
    return rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22);
}
static inline uint32_t Sigma1(uint32_t x) {   // 大写 Σ1
    return rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25);
}
static inline uint32_t sigma0(uint32_t x) {   // 小写 σ0
    return rotr(x, 7) ^ rotr(x, 18) ^ (x >> 3);
}
static inline uint32_t sigma1(uint32_t x) {   // 小写 σ1
    return rotr(x, 17) ^ rotr(x, 19) ^ (x >> 10);
}

// ============================================================
// SHA-256 上下文
// ============================================================
struct SHA256Context {
    uint32_t state[8];      // H0..H7
    uint64_t bitCount;      // 已处理比特数
    uint8_t  buffer[64];    // 未处理完的块
    size_t   bufferLen;

    SHA256Context() { init(); }

    void init() {
        // 前 8 个素数平方根小数部分前 32 位（FIPS 180-4）
        state[0] = 0x6a09e667;
        state[1] = 0xbb67ae85;
        state[2] = 0x3c6ef372;
        state[3] = 0xa54ff53a;
        state[4] = 0x510e527f;
        state[5] = 0x9b05688c;
        state[6] = 0x1f83d9ab;
        state[7] = 0x5be0cd19;
        bitCount = 0;
        bufferLen = 0;
    }
};

// ============================================================
// 处理一个 512bit 块
// ============================================================
static void sha256Transform(uint32_t state[8], const uint8_t block[64]) {
    uint32_t W[64];

    // 1. 前 16 字：大端读入
    for (int i = 0; i < 16; i++) {
        W[i] = read_be32(block + i * 4);
    }

    // 2. 扩展到 64 字
    for (int i = 16; i < 64; i++) {
        W[i] = sigma1(W[i - 2]) + W[i - 7]
             + sigma0(W[i - 15]) + W[i - 16];
    }

    // 3. 加载工作变量
    uint32_t a = state[0], b = state[1], c = state[2], d = state[3];
    uint32_t e = state[4], f = state[5], g = state[6], h = state[7];

    // 4. 64 轮
    for (int i = 0; i < 64; i++) {
        uint32_t T1 = h + Sigma1(e) + Ch(e, f, g) + K[i] + W[i];
        uint32_t T2 = Sigma0(a) + Maj(a, b, c);

        h = g;
        g = f;
        f = e;
        e = d + T1;
        d = c;
        c = b;
        b = a;
        a = T1 + T2;
    }

    // 5. 累加回 state
    state[0] += a; state[1] += b; state[2] += c; state[3] += d;
    state[4] += e; state[5] += f; state[6] += g; state[7] += h;
}

// ============================================================
// 更新
// ============================================================
static void sha256Update(SHA256Context& ctx, const uint8_t* data, size_t len) {
    ctx.bitCount += (uint64_t)len * 8;

    while (len > 0) {
        size_t space = 64 - ctx.bufferLen;
        size_t copy  = (len < space) ? len : space;

        std::memcpy(ctx.buffer + ctx.bufferLen, data, copy);
        ctx.bufferLen += copy;
        data += copy;
        len  -= copy;

        if (ctx.bufferLen == 64) {
            sha256Transform(ctx.state, ctx.buffer);
            ctx.bufferLen = 0;
        }
    }
}

// ============================================================
// 收尾：填充 + 长度 + 输出 32 字节
// ============================================================
static void sha256Final(SHA256Context& ctx, uint8_t digest[32]) {
    uint8_t padding[64];
    std::memset(padding, 0, sizeof(padding));
    padding[0] = 0x80;

    uint64_t bits = ctx.bitCount;

    size_t padLen = (ctx.bufferLen < 56)
                  ? (56 - ctx.bufferLen)
                  : (120 - ctx.bufferLen);

    sha256Update(ctx, padding, padLen);

    uint8_t lenBytes[8];
    for (int i = 0; i < 8; i++) {
        lenBytes[i] = (uint8_t)((bits >> (8 * (7 - i))) & 0xff);
    }
    sha256Update(ctx, lenBytes, 8);

    for (int i = 0; i < 8; i++) {
        write_be32(digest + i * 4, ctx.state[i]);
    }
}

// ============================================================
// 一次性接口
// ============================================================
std::string sha256(const std::string& input) {
    SHA256Context ctx;
    sha256Update(ctx, reinterpret_cast<const uint8_t*>(input.data()), input.size());

    uint8_t digest[32];
    sha256Final(ctx, digest);

    std::ostringstream oss;
    for (int i = 0; i < 32; i++) {
        oss << std::hex << std::setw(2) << std::setfill('0')
            << (int)digest[i];
    }
    return oss.str();
}

// ============================================================
// 测试
// ============================================================
int main() {
    std::vector<std::pair<std::string, std::string>> tests = {
        {"", "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855"},
        {"abc", "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad"},
        {"abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq",
         "248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1"},
        {"The quick brown fox jumps over the lazy dog",
         "d7a8fbb307d7809469ca9abcb0082e4f8d5651e46d3cdb762d02d0bf37c9e592"},
    };

    for (auto& t : tests) {
        std::string result = sha256(t.first);
        std::cout << "输入: \"" << t.first << "\"\n";
        std::cout << "计算: " << result << "\n";
        std::cout << "期望: " << t.second << "\n";
        std::cout << (result == t.second ? "✅ 通过" : "❌ 失败") << "\n\n";
    }

    return 0;
}