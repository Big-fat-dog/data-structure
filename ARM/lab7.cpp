
#include <cstdint>

// 禁止内联，方便在 IDA 中观察函数调用
#define NOINLINE __attribute__((noinline))

// 第四层：最终计算
extern "C" NOINLINE
int leaf_mix(int x, int y, int* out) {
    int temp = x * 3 + y;

    *out = temp - 7;

    return temp + 11;
}

// 第三层：调用 leaf_mix
extern "C" NOINLINE
int stage2(int a, int b, int* out) {
    int local = a + 5;

    int result = leaf_mix(local, b, out);

    return result + local;
}

// 第二层：调用 stage2
extern "C" NOINLINE
int stage1(int seed, int* out) {
    int x = seed * 2;
    int y = seed + 3;

    return stage2(x, y, out) - 1;
}

// 第一层：导出的入口函数
extern "C" NOINLINE
int run_lab(int seed, int* out) {
    int base = seed + 10;

    int result = stage1(base, out);

    return result + *out;
}
