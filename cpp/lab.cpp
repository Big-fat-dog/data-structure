#include <iostream>
#include <string>
#include <cstring>
#include <cstdint>
#include <cstddef>
#include <iomanip>

// 防止常见编译器轻易内联这些函数，方便初次观察调用关系
#if defined(_MSC_VER)
#define NOINLINE __declspec(noinline)
#elif defined(__GNUC__) || defined(__clang__)
#define NOINLINE __attribute__((noinline))
#else
#define NOINLINE
#endif

union Payload
{
    std::int32_t number;
    float value;
    char name[16];
};

struct Request
{
    std::uint32_t type;
    std::uint32_t length;
    Payload payload;
};

std::uint32_t getRequestType(const Request *req)
{
    return req->type;
}

std::uint32_t getRequestLength(const Request *req)
{
    return req->length;
}

Payload getRequestPayload(const Request *req)
{
    return req->payload;
}

std::int32_t getPayloadLength(const Request *req)
{
    return req->payload.number;
}

std::int32_t processRequest(const Request *req)
{
    Payload p = getRequestPayload(req);
    if (req->type == 1)
    {
        p.number += 100;
        return p.number;
    }
    else if (req->type == 2)
    {
        if (req->payload.value > 10.0f)
        {
            return 200;
        }
        return 201;
    }
    return -1;
}

// c风格长度
std::size_t c_len(const char *s)
{
    return std::strlen(s);
}

// 字符串比较
NOINLINE bool isAdmin(const char *s)
{
    return std::strcmp(s, "admin") == 0;
}

int main()
{
    std::cout << '\n'
              << "string相关";
    std::string a = "nihao";
    std::string b = "i am mj,nice to meet you.mjmjmjmjmjmj!";
    std::cout << "short_size: " << a.size() << '\n';
    std::cout << "long_size: " << b.size() << '\n';
    std::cout << "sizeof(std::string) = "
              << sizeof(std::string) << '\n';
    std::cout << "short_str->object: " << static_cast<const void *>(&a) << '\n';
    std::cout << "short_str data: " << static_cast<const void *>(a.data()) << '\n';
    std::cout << "long_str->object: " << static_cast<const void *>(&b) << '\n';
    std::cout << "long_str data: " << static_cast<const void *>(b.data()) << '\n';

    // 观察c字符串
    std::cout << "===============观察c字符串===============" << '\n';
    std::cout << "isAdmin(admin) = "
              << isAdmin("admin") << '\n';

    std::cout << "strlen(hello) = "
              << c_len("hello") << '\n';

    // 观察结构体字段偏移
    std::cout << "sizeof(Request) = " << sizeof(Request) << '\n';
    std::cout << "offsetof(type) = " << offsetof(Request, type) << '\n';
    std::cout << "offsetof(length) = "
              << offsetof(Request, length) << '\n';
    std::cout << "offsetof(payload) = "
              << offsetof(Request, payload) << '\n';

    // 联合体
    Request req{};
    req.length = sizeof(req.payload.number);
    req.type = 1;
    req.payload.number = 25;

    std::cout << "request type = "
              << getRequestType(&req) << '\n';
    std::cout << "request length = "
              << getRequestLength(&req) << '\n';
    std::cout << "payload code = "
              << getPayloadLength(&req) << '\n';
    std::cout << "process result = "
              << processRequest(&req) << '\n';

    std::cout << '\n'
              << "观察联合体的底层字节" << '\n';
    const auto *bytes = reinterpret_cast<const unsigned char *>(&req.payload);
    std::cout << "payload bytes = ";
    for (int i = 0; i < sizeof(req.payload); i++)
    {
        // 在字节输出循环中
        std::cout << std::hex
                  << std::setw(2) << std::setfill('0')
                  << static_cast<unsigned int>(bytes[i]) << ' ';
    }
    std::cout << std::dec << '\n';

    // D. 改为使用 value 成员，不读取 code 成员
    req.type = 2;
    req.payload.value = 12.5f;
    std::cout << "payload bytes = ";
    for (int i = 0; i < sizeof(req.payload); i++)
    {
        // 在字节输出循环中
        std::cout << std::hex
                  << std::setw(2) << std::setfill('0')
                  << static_cast<unsigned int>(bytes[i]) << ' ';
    }
    
    std::cout << std::dec << '\n';
    std::cout << "process float result = "
              << processRequest(&req) << '\n';

    return 0;
}