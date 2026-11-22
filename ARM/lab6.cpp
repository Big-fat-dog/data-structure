#include <stdint.h>

// 1. 无符号提取 bit[11:8]
extern "C" __attribute__((noinline))
uint32_t extract_field(uint32_t x) {
    return (x >> 8) & 0x0F;
}

// 2. 有符号提取 bit[7:4]
extern "C" __attribute__((noinline))
int32_t extract_signed(uint32_t x) {
    int32_t value = (int32_t)((x >> 4) & 0x0F);
    return (value ^ 0x08) - 0x08;
}

// 3. 将 value 的低4位写入 x 的 bit[19:16]
extern "C" __attribute__((noinline))
uint32_t insert_field(uint32_t x, uint32_t value) {
    x &= ~(0x0F << 16);
    x |= (value & 0x0F) << 16;
    return x;
}

// 4. 清除 bit[6:4]
extern "C" __attribute__((noinline))
uint32_t clear_field(uint32_t x) {
    return x & ~(0x07 << 4);
}

// 5. 把 bit[11:8] 复制到 bit[19:16]
extern "C" __attribute__((noinline))
uint32_t copy_field(uint32_t x) {
    uint32_t field = (x >> 8) & 0x0F;
    x &= ~(0x0F << 16);
    x |= field << 16;
    return x;
}