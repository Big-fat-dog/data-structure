#include <cstdint>

__attribute__((noinline))
int signed_div(int a, int b) {
    return a / b;
}

__attribute__((noinline))
uint32_t unsigned_div(uint32_t a, uint32_t b) {
    return a / b;
}

__attribute__((noinline))
int multiply(int a, int b) {
    return a * b;
}