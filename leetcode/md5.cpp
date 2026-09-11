#include <iostream>
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

// ============================================================
// MD5 核心常量
// ============================================================

// 每轮左移位数（RFC 1321 定义）
static const uint32_t S[64] = {
    7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  // 第1轮
    5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  // 第2轮
    4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  // 第3轮
    6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21   // 第4轮
};

// 正弦表 T[i] = floor(2^32 * |sin(i+1)|)，RFC 1321 给出固定值
static const uint32_t K[64] = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

// ============================================================
// 小端序读写工具
// ============================================================
// 注意：MD5 规定所有 32 位字按小端序从字节流读取/写入。
// 这里不用 memcpy + 强制转换，而是显式按字节拼装，
// 这样在大端机器上也能得到正确结果（跨平台安全）。

// 从 4 字节按小端序读出一个 uint32_t
static inline uint32_t read_le32(const uint8_t* p) {
    return (uint32_t)p[0]
         | ((uint32_t)p[1] << 8)
         | ((uint32_t)p[2] << 16)
         | ((uint32_t)p[3] << 24);
}

// 把一个 uint32_t 按小端序写入 4 字节
static inline void write_le32(uint8_t* p, uint32_t v) {
    p[0] = (uint8_t)(v & 0xff);
    p[1] = (uint8_t)((v >> 8) & 0xff);
    p[2] = (uint8_t)((v >> 16) & 0xff);
    p[3] = (uint8_t)((v >> 24) & 0xff);
}

// 循环左移
static inline uint32_t rotl(uint32_t x, uint32_t n) {
    return (x << n) | (x >> (32 - n));
}

// ============================================================
// MD5 上下文
// ============================================================
struct MD5Context {
    uint32_t state[4];      // A, B, C, D 四个寄存器
    uint64_t bitCount;      // 已处理的比特数（用于最后填充长度）
    uint8_t  buffer[64];    // 当前未处理完的 64 字节块
    size_t   bufferLen;     // buffer 中已有多少字节

    MD5Context() { init(); }

    void init() {
        // 四个魔数（RFC 1321 定义），注意这里是数值，不是内存字节
        state[0] = 0x67452301;   // A
        state[1] = 0xefcdab89;   // B
        state[2] = 0x98badcfe;   // C
        state[3] = 0x10325476;   // D
        bitCount = 0;
        bufferLen = 0;
    }
};

// ============================================================
// 处理一个 512 位（64 字节）块
// ============================================================
static void md5Transform(uint32_t state[4], const uint8_t block[64]) {
    uint32_t M[16];
    // 按小端序把 64 字节拆成 16 个 32 位字
    for (int i = 0; i < 16; i++) {
        M[i] = read_le32(block + i * 4);
    }

    uint32_t A = state[0];
    uint32_t B = state[1];
    uint32_t C = state[2];
    uint32_t D = state[3];

    // 64 步主循环
    for (int i = 0; i < 64; i++) {
        uint32_t F;
        int g;   // M 的下标

        if (i < 16) {
            // 第 1 轮：F = (B & C) | (~B & D)
            F = (B & C) | (~B & D);
            g = i;
        } else if (i < 32) {
            // 第 2 轮：F = (D & B) | (~D & C)
            F = (D & B) | (~D & C);
            g = (5 * i + 1) % 16;
        } else if (i < 48) {
            // 第 3 轮：F = B ^ C ^ D
            F = B ^ C ^ D;
            g = (3 * i + 5) % 16;
        } else {
            // 第 4 轮：F = C ^ (B | ~D)
            F = C ^ (B | ~D);
            g = (7 * i) % 16;
        }

        // 核心运算：F = F + A + K[i] + M[g]; A = D; D = C; C = B;
        // B = B + rotl(F, S[i])
        F = F + A + K[i] + M[g];
        A = D;
        D = C;
        C = B;
        B = B + rotl(F, S[i]);
    }

    // 累加回 state
    state[0] += A;
    state[1] += B;
    state[2] += C;
    state[3] += D;
}

// ============================================================
// 更新数据（可以分多次调用）
// ============================================================
static void md5Update(MD5Context& ctx, const uint8_t* data, size_t len) {
    ctx.bitCount += (uint64_t)len * 8;   // 累加比特数

    // 先填满之前没处理完的 buffer
    while (len > 0) {
        size_t space = 64 - ctx.bufferLen;
        size_t copy = (len < space) ? len : space;

        std::memcpy(ctx.buffer + ctx.bufferLen, data, copy);
        ctx.bufferLen += copy;
        data += copy;
        len  -= copy;

        // buffer 满了，处理一个块
        if (ctx.bufferLen == 64) {
            md5Transform(ctx.state, ctx.buffer);
            ctx.bufferLen = 0;
        }
    }
}

// ============================================================
// 收尾：填充 + 写入原始长度 + 输出 16 字节摘要
// ============================================================
static void md5Final(MD5Context& ctx, uint8_t digest[16]) {
    uint8_t padding[64];
    std::memset(padding, 0, sizeof(padding));
    padding[0] = 0x80;   // 第一个填充字节是 0x80，其余是 0

    // 记录填充前的比特数
    uint64_t bits = ctx.bitCount;

    // 需要填充的字节数：让 (bufferLen + 8) % 64 == 0
    size_t padLen = (ctx.bufferLen < 56)
                  ? (56 - ctx.bufferLen)
                  : (120 - ctx.bufferLen);

    // 先填 0x80 和 0x00
    md5Update(ctx, padding, padLen);

    // 再把 64 位原始长度按小端序追加（8 字节）
    uint8_t lenBytes[8];
    for (int i = 0; i < 8; i++) {
        lenBytes[i] = (uint8_t)((bits >> (8 * i)) & 0xff);
    }
    md5Update(ctx, lenBytes, 8);

    // 把 A、B、C、D 按小端序输出成 16 字节
    for (int i = 0; i < 4; i++) {
        write_le32(digest + i * 4, ctx.state[i]);
    }
}

// ============================================================
// 一次性计算 MD5（封装接口）
// ============================================================
std::string md5(const std::string& input) {
    MD5Context ctx;
    md5Update(ctx, reinterpret_cast<const uint8_t*>(input.data()), input.size());

    uint8_t digest[16];
    md5Final(ctx, digest);

    // 转十六进制字符串
    std::ostringstream oss;
    for (int i = 0; i < 16; i++) {
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
        {"", "d41d8cd98f00b204e9800998ecf8427e"},
        {"abc", "900150983cd24fb0d6963f7d28e17f72"},
        {"message digest", "f96b697d7cb7938d525a2f31aaf161d0"},
        {"abcdefghijklmnopqrstuvwxyz", "c3fcd3d76192e4007dfb496cca67e13b"},
        {"The quick brown fox jumps over the lazy dog", "9e107d9d372bb6826bd81d3542a419d6"}
    };

    for (auto& t : tests) {
        std::string result = md5(t.first);
        std::cout << "输入: \"" << t.first << "\"\n";
        std::cout << "计算: " << result << "\n";
        std::cout << "期望: " << t.second << "\n";
        std::cout << (result == t.second ? "✅ 通过" : "❌ 失败") << "\n\n";
    }

    return 0;
}