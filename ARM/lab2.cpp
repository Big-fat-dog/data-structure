
#include <cstdint>

// 返回两个整数中较大的一个
extern "C" __attribute__((noinline, visibility("default")))
int max_value(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// 判断两个整数是否相等
extern "C" __attribute__((noinline, visibility("default")))
int is_equal(int a, int b) {
    if (a == b) {
        return 1;
    }
    return 0;
}

// 判断一个整数是否在指定范围内
extern "C" __attribute__((noinline, visibility("default")))
int in_range(int value, int low, int high) {
    if (value >= low && value <= high) {
        return 1;
    }
    return 0;
}
