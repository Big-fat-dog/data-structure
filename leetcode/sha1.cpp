// sha1.cpp —— 按 MD5 版风格重写的 SHA-1
#include <iostream>
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

// ============================================================
// SHA-1 每轮常数 K（只有 4 个，每 20 轮换一个）
// ============================================================
static const uint32_t K[4] = {
    0x5A827999,   // 0..19
    0x6ED9EBA1,   // 20..39
    0x8F1BBCDC,   // 40..59
    0xCA62C1D6    // 60..79
};

// ============================================================
// 大端序读写工具（SHA-1 规定 32 位字按大端序读/写）
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

// 循环左移
static inline uint32_t rotl(uint32_t x, uint32_t n) {
    return (x << n) | (x >> (32 - n));
}

// ============================================================
// SHA-1 上下文
// ============================================================
struct SHA1Context {
    uint32_t state[5];      // A, B, C, D, E 五个寄存器
    uint64_t bitCount;      // 已处理的比特数
    uint8_t  buffer[64];    // 当前未处理完的 64 字节块
    size_t   bufferLen;     // buffer 中已有多少字节

    SHA1Context() { init(); }

    void init() {
        // SHA-1 的 5 个初始魔数（RFC 3174 定义）
        state[0] = 0x67452301;   // A
        state[1] = 0xEFCDAB89;   // B
        state[2] = 0x98BADCFE;   // C
        state[3] = 0x10325476;   // D
        state[4] = 0xC3D2E1F0;   // E
        bitCount = 0;
        bufferLen = 0;
    }
};

// ============================================================
// 处理一个 512 位（64 字节）块
// ============================================================
static void sha1Transform(uint32_t state[5], const uint8_t block[64]) {
    uint32_t W[80];

    // 1. 按大端序把 64 字节拆成 16 个 32 位字
    for (int i = 0; i < 16; i++) {
        W[i] = read_be32(block + i * 4);
    }

    // 2. 扩展到 80 个字：W[t] = rotl(W[t-3]^W[t-8]^W[t-14]^W[t-16], 1)
    for (int i = 16; i < 80; i++) {
        W[i] = rotl(W[i - 3] ^ W[i - 8] ^ W[i - 14] ^ W[i - 16], 1);
    }

    uint32_t A = state[0];
    uint32_t B = state[1];
    uint32_t C = state[2];
    uint32_t D = state[3];
    uint32_t E = state[4];

    // 3. 80 步主循环
    for (int i = 0; i < 80; i++) {
        uint32_t F;
        uint32_t k;

        if (i < 20) {
            // 第 1 段：选择函数
            F = (B & C) | (~B & D);
            k = K[0];
        } else if (i < 40) {
            // 第 2 段：异或
            F = B ^ C ^ D;
            k = K[1];
        } else if (i < 60) {
            // 第 3 段：多数函数
            F = (B & C) | (B & D) | (C & D);
            k = K[2];
        } else {
            // 第 4 段：异或（和 20..39 相同）
            F = B ^ C ^ D;
            k = K[3];
        }

        uint32_t tmp = rotl(A, 5) + F + E + k + W[i];
        E = D;
        D = C;
        C = rotl(B, 30);
        B = A;
        A = tmp;
    }

    // 4. 累加回 state
    state[0] += A;
    state[1] += B;
    state[2] += C;
    state[3] += D;
    state[4] += E;
}

// ============================================================
// 更新数据（可以分多次调用）
// ============================================================
static void sha1Update(SHA1Context& ctx, const uint8_t* data, size_t len) {
    ctx.bitCount += (uint64_t)len * 8;   // 累加比特数

    while (len > 0) {
        size_t space = 64 - ctx.bufferLen;
        size_t copy  = (len < space) ? len : space;

        std::memcpy(ctx.buffer + ctx.bufferLen, data, copy);
        ctx.bufferLen += copy;
        data += copy;
        len  -= copy;

        if (ctx.bufferLen == 64) {
            sha1Transform(ctx.state, ctx.buffer);
            ctx.bufferLen = 0;
        }
    }
}

// ============================================================
// 收尾：填充 + 写入原始长度 + 输出 20 字节摘要
// ============================================================
static void sha1Final(SHA1Context& ctx, uint8_t digest[20]) {
    uint8_t padding[64];
    std::memset(padding, 0, sizeof(padding));
    padding[0] = 0x80;

    uint64_t bits = ctx.bitCount;

    // 让 (bufferLen + 8) % 64 == 0
    size_t padLen = (ctx.bufferLen < 56)
                  ? (56 - ctx.bufferLen)
                  : (120 - ctx.bufferLen);

    sha1Update(ctx, padding, padLen);

    // 64 位原始长度按大端序追加
    uint8_t lenBytes[8];
    for (int i = 0; i < 8; i++) {
        lenBytes[i] = (uint8_t)((bits >> (8 * (7 - i))) & 0xff);
    }
    sha1Update(ctx, lenBytes, 8);

    // 把 A..E 按大端序输出成 20 字节
    for (int i = 0; i < 5; i++) {
        write_be32(digest + i * 4, ctx.state[i]);
    }
}

// ============================================================
// 一次性计算 SHA-1（封装接口）
// ============================================================
std::string sha1(const std::string& input) {
    SHA1Context ctx;
    sha1Update(ctx, reinterpret_cast<const uint8_t*>(input.data()), input.size());

    uint8_t digest[20];
    sha1Final(ctx, digest);

    std::ostringstream oss;
    for (int i = 0; i < 20; i++) {
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
        {"", "da39a3ee5e6b4b0d3255bfef95601890afd80709"},
        {"abc", "a9993e364706816aba3e25717850c26c9cd0d89d"},
        {"abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq",
         "84983e441c3bd26ebaae4aa1f95129e5e54670f1"},
        {"The quick brown fox jumps over the lazy dog",
         "2fd4e1c67a2d28fced849ee1bb76e7391b93eb12"},
    };

    for (auto& t : tests) {
        std::string result = sha1(t.first);
        std::cout << "输入: \"" << t.first << "\"\n";
        std::cout << "计算: " << result << "\n";
        std::cout << "期望: " << t.second << "\n";
        std::cout << (result == t.second ? "✅ 通过" : "❌ 失败") << "\n\n";
    }

    return 0;
}