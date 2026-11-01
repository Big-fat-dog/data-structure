#include<iostream>
#include<string>
#include <cstring>
#include <cstdint>
//普通指针
int read_pointer(int* tmp){
    if(tmp==nullptr)return 0;
    return *tmp;
}

void write_pointer(int* tmp){
    *tmp=6767;
}

void swap_p(int* a,int* b){
    std::swap(a,b);
}


//数组与指针
int arr_sum(int* arr,int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    return sum;
}

int find_target(int* arr,int index,int length){
    if (arr == nullptr) return 0;
    if (index < 0 || index >= length) return 0;
    int* address=arr+index;
    return *address;
}

//结构体与结构体指针
struct User{
    int id;
    int age;
    int score;
    char name[16];
};

//修改用户信息
void change_user(User* user,int age,int score,std::string name){
    user->age=age;
    user->score=score;
    std::strncpy(user->name,name.c_str(),sizeof(user->name) - 1);
    user->name[sizeof(user->name) - 1] = '\0';
}

//结构体数组遍历与条件查找
const User* find_user(const User* users,int count,int id){
    if(count<=0||id<0)return nullptr;
    for(int i=0;i<count;i++){
        if(users[i].id==id){
            return &users[i];
        }
    }
    return nullptr;
}

//多级指针
int alloc_pointer(int** pp,int value){
    if (pp == nullptr) return false;
    int *p = new int(value);
    if(p==nullptr)return false;

    *pp=p;
    return true;
}


//函数指针
typedef int (*Option)(int a,int b);
int add(int a,int b){
    return a+b;
}
int sub(int a,int b){
    return a-b;
}
static Option option[2] = {
    add,
    sub
}; 
// 根据索引选择函数
int calculateByIndex(
    int a,
    int b,
    int index
) {
    if (index < 0 || index >= 2) return -1;

    Option operation = option[index];

    return operation(a, b);
}



// ============================================================
// 6. 综合结构体：Request + Union + 函数指针
// ============================================================

union Payload {
    int32_t number;
    float value;
    char name[16];
};

struct Request {
    uint32_t type;
    uint32_t length;
    Payload payload;
};

//三种操作函数表
// 处理整数请求
static int handleInteger(Request* req) {
    if (req == nullptr) return -1;

    return req->payload.number + 100;
}

// 处理浮点数请求
static int handleFloat(Request* req) {
    if (req == nullptr) return -1;

    if (req->payload.value > 10.0f) {
        return 200;
    }

    return 201;
}

// 处理字符串请求
static int handleString(Request* req) {
    if (req == nullptr) return -1;

    int length = 0;

    for (int i = 0; i < 16; i++) {
        if (req->payload.name[i] == '\0') break;
        length++;
    }

    return length;
}

typedef int (*RequestHandler)(Request*);

// 请求处理函数表
static RequestHandler handlers[4] = {
    nullptr,
    handleInteger,
    handleFloat,
    handleString
};

// 统一请求处理入口
int processRequest(Request* req) {
    if (req == nullptr) return -1;

    if (req->type >= 4) return -1;

    RequestHandler handler = handlers[req->type];

    if (handler == nullptr) return -1;

    return handler(req);
}

// 获取 Request 字段
uint32_t getRequestType(const Request* req) {
    if (req == nullptr) return 0;
    return req->type;
}

uint32_t getRequestLength(const Request* req) {
    if (req == nullptr) return 0;
    return req->length;
}

int32_t getRequestNumber(const Request* req) {
    if (req == nullptr) return 0;
    return req->payload.number;
}


int main() {
    std::cout << "========== 1. 普通指针 ==========\n";
    {
        int x = 42;
        std::cout << "read_pointer(&x)      = " << read_pointer(&x) << " (期望 42)\n";
        std::cout << "read_pointer(nullptr) = " << read_pointer(nullptr) << " (期望 0，你的实现返回空)\n";

        int y = 0;
        write_pointer(&y);
        std::cout << "write_pointer 后 y    = " << y << " (期望 6767)\n";


    }

    std::cout << "\n========== 2. 数组与指针 ==========\n";
    {
        int arr[] = {1, 2, 3, 4, 5};
        int len = sizeof(arr) / sizeof(arr[0]);
        std::cout << "arr_sum(arr,5)        = " << arr_sum(arr, len) << " (期望 15)\n";
        std::cout << "find_target(arr,2,5)  = " << find_target(arr, 2, len) << " (期望 3)\n";
        std::cout << "find_target(arr,9,5)  = " << find_target(arr, 9, len) << " (期望 0，越界返回空)\n";
        std::cout << "find_target(nullptr,0,5) = " << find_target(nullptr, 0, len) << " (期望 0)\n";
    }

    std::cout << "\n========== 3. 结构体与结构体指针 ==========\n";
    {
        User u{};
        u.id = 1;
        change_user(&u, 20, 90, "Alice");
        std::cout << "change_user 后: id=" << u.id
                  << " age=" << u.age
                  << " score=" << u.score
                  << " name=" << u.name << " (期望 20,90,Alice)\n";

        // 测试超长名字截断
        change_user(&u, 21, 91, "ThisNameIsWayTooLongFor16Bytes");
        std::cout << "超长名字截断后 name   = " << u.name
                  << " (长度 " << std::strlen(u.name) << "，期望 15)\n";

        User users[3] = {
            {1, 18, 80, "Tom"},
            {2, 19, 85, "Jerry"},
            {3, 20, 90, "Spike"},
        };
        const User* found = find_user(users, 3, 2);
        if (found)
            std::cout << "find_user(id=2)       = " << found->name << " (期望 Jerry)\n";
        else
            std::cout << "find_user(id=2)       = 未找到\n";

        const User* notFound = find_user(users, 3, 99);
        std::cout << "find_user(id=99)      = " << (notFound ? "找到" : "nullptr") << " (期望 nullptr)\n";
    }

    std::cout << "\n========== 4. 多级指针 ==========\n";
    {
        int* p = nullptr;
        bool ok = alloc_pointer(&p, 123);
        std::cout << "alloc_pointer 返回    = " << ok << " (期望 1)\n";
        if (p) {
            std::cout << "*p                    = " << *p << " (期望 123)\n";
            delete p;   // ⚠️ 你的函数里 new 了，必须由调用方 delete
        }

        bool bad = alloc_pointer(nullptr, 1);
        std::cout << "alloc_pointer(nullptr)= " << bad << " (期望 0)\n";
    }

    std::cout << "\n========== 5. 函数指针 ==========\n";
    {
        std::cout << "calculateByIndex(6,2,0) = " << calculateByIndex(6, 2, 0) << " (期望 8, add)\n";
        std::cout << "calculateByIndex(6,2,1) = " << calculateByIndex(6, 2, 1) << " (期望 4, sub)\n";
        // 注意：option 数组只有 2 个元素，但 calculateByIndex 检查的是 index >= 3，
        // 传 index=2 会越界读 option[2]，是 bug（见下方问题清单）
        std::cout << "calculateByIndex(6,2,3) = " << calculateByIndex(6, 2, 3) << " (期望 -1, 越界)\n";
    }

    std::cout << "\n========== 6. Request + Union + 函数指针 ==========\n";
    {
        // type=1：整数
        Request r1{};
        r1.type = 1;
        r1.payload.number = 5;
        std::cout << "processRequest(整数5)   = " << processRequest(&r1) << " (期望 105)\n";

        // type=2：浮点，>10
        Request r2{};
        r2.type = 2;
        r2.payload.value = 3.14f;
        std::cout << "processRequest(浮点3.14)= " << processRequest(&r2) << " (期望 201)\n";

        Request r2b{};
        r2b.type = 2;
        r2b.payload.value = 20.0f;
        std::cout << "processRequest(浮点20)  = " << processRequest(&r2b) << " (期望 200)\n";

        // type=3：字符串
        Request r3{};
        r3.type = 3;
        std::strncpy(r3.payload.name, "hello", sizeof(r3.payload.name) - 1);
        std::cout << "processRequest(字符串hello) = " << processRequest(&r3) << " (期望 5)\n";

        // type=0：handlers[0]=nullptr
        Request r0{};
        r0.type = 0;
        std::cout << "processRequest(type=0)  = " << processRequest(&r0) << " (期望 -1, nullptr handler)\n";

        // type=4：越界
        Request r4{};
        r4.type = 4;
        std::cout << "processRequest(type=4)  = " << processRequest(&r4) << " (期望 -1)\n";

        // nullptr
        std::cout << "processRequest(nullptr) = " << processRequest(nullptr) << " (期望 -1)\n";

        // getter
        std::cout << "getRequestType(&r1)     = " << getRequestType(&r1) << " (期望 1)\n";
        std::cout << "getRequestLength(&r1)   = " << getRequestLength(&r1) << " (期望 0，未设置)\n";
        std::cout << "getRequestNumber(&r1)   = " << getRequestNumber(&r1) << " (期望 5)\n";
        std::cout << "getRequestType(nullptr) = " << getRequestType(nullptr) << " (期望 0)\n";
    }

    std::cout << "\n========== 测试结束 ==========\n";
    return 0;
}