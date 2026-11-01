#include <iostream>
#include <cstring>

namespace NativeLab {

class User {
public:
    int id;
    char* name;

    // 构造函数
    User(int userId, const char* userName) : id(userId) {
        size_t len = strlen(userName) + 1;
        name = new char[len];
        memcpy(name, userName, len);
    }

    // 拷贝构造
    User(const User& other) : id(other.id) {
        size_t len = strlen(other.name) + 1;
        name = new char[len];
        memcpy(name, other.name, len);
    }

    // 赋值运算符
    User& operator=(const User& other) {
        if (this != &other) {
            char* newName = nullptr;

            if (other.name != nullptr) {
                size_t len = strlen(other.name) + 1;
                newName = new char[len];
                memcpy(newName, other.name, len);
            }

            delete[] name;
            name = newName;
            id = other.id;
        }

        return *this;
    }

    // 析构函数
    ~User() {
        delete[] name;
    }

    void print() const {
        std::cout << id << " " << name << std::endl;
    }
};

}

int main() {
    NativeLab::User a(1001, "Alice");

    // 拷贝构造
    NativeLab::User b = a;

    // 赋值运算符
    NativeLab::User c(1002, "Bob");
    c = a;

    a.print();
    b.print();
    c.print();

    return 0;
}