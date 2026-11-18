#include<iostream>
#include<cstdint>
#include<vector>
// 实验1：两个32位整数相加
extern "C"
__attribute__((noinline, visibility("default")))
int32_t add_32(int a,int b){
    return a+b;
}

// 实验2：两个64位整数相加
extern "C"
__attribute__((noinline, visibility("default")))
int64_t add_i64(int64_t a, int64_t b) {
    return a + b;
}

// 实验3：指针传递
extern "C"
__attribute__((noinline, visibility("default")))
int read_value(const int* ptr) {
    return *ptr;
}

// 实验4：多个参数
extern "C"
__attribute__((noinline, visibility("default")))
int sum_four(int a, int b, int c, int d) {
    return a + b + c + d;
}

int main(){
    std::vector<int> list;
    int64_t jack=6000000006;
    int64_t dog =4888888884;
    int a{1};
    int b{2};
    int c{3};
    int d=4;
    int* pointer=&a;


    int res=add_32(a,b);
    list.push_back(res);

    int res2 = add_i64(jack,dog);
    std::cout<<res2;

    int res3=read_value(pointer);
    list.push_back(res3);
    
    int res4=sum_four(a,b,c,d);
    list.push_back(res4);
}