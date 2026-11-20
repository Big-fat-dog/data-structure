#include <cstdint>

__attribute__((noinline))
int signed_test(const int8_t* p) {
    return *p;
}

__attribute__((noinline))
int unsigned_test(const uint8_t* p) {
    return *p;
}

__attribute__((noinline))
int signed_short_test(const int16_t* p) {
    return *p;
}

__attribute__((noinline))
long long signed_int_test(const int32_t* p) {
    return *p;
}

int main() {
    int8_t a = -1;
    uint8_t b = 255;
    int16_t c = -2;
    int32_t d = -3;

    return signed_test(&a)
         + unsigned_test(&b)
         + signed_short_test(&c)
         + signed_int_test(&d);
}