# CPP（十）——类，内存布局，命名空间

这篇知识量有点爆炸，也是关键内容，且看且珍惜🐧。

- [CPP（十）——类，内存布局，命名空间](#cpp十类内存布局命名空间)
  - [一、函数重载](#一函数重载)
    - [ida时能看到的重载](#ida时能看到的重载)
  - [二、命名空间](#二命名空间)
    - [ida里的命名空间](#ida里的命名空间)
  - [三、类的内存布局](#三类的内存布局)
    - [非静态内存布局](#非静态内存布局)
    - [静态成员变量有何不同](#静态成员变量有何不同)
    - [如果有虚函数呢？](#如果有虚函数呢)
  - [四、this指针](#四this指针)
    - [编译器是怎么理解成员函数的](#编译器是怎么理解成员函数的)
  - [五、构造函数与析构函数](#五构造函数与析构函数)
    - [构造函数](#构造函数)
    - [带参数的构造函数](#带参数的构造函数)
    - [析构函数](#析构函数)
  - [六、拷贝构造与赋值运算符](#六拷贝构造与赋值运算符)
    - [1. 拷贝构造函数](#1-拷贝构造函数)
    - [2.赋值运算符](#2赋值运算符)
    - [浅拷贝与深拷贝](#浅拷贝与深拷贝)
  - [七、申请与释放](#七申请与释放)
  - [八、实战](#八实战)


## 一、函数重载

定义：函数名相同，但参数列表不同，可以定义多个同名函数。

返回值不同不构成重载，参数类型、参数数量、参数顺序等可以构成重载区别。

```cpp
#include <iostream>

int add(int a, int b) {
    return a + b;
}

float add(float a, float b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    std::cout << add(1, 2) << std::endl;
    std::cout << add(1.5f, 2.5f) << std::endl;
    std::cout << add(1, 2, 3) << std::endl;
}
```

### ida时能看到的重载

很常见的一个就是：Name Mangling（名字修饰）。

C++ 编译器为了区分同名函数，会把函数名和参数类型等信息编码进符号名。

举个例子

```cpp
int add(int a, int b);
float add(float a, float b);
这两个函数会被编译器变成下面
_Z3addii
_Z3addff
```

## 二、命名空间

为什么需要命名空间呢？

假设你写了一个函数：

```
void print() {
}
```

你引入的第三方库也有一个 `print()`，就可能发生命名冲突。

命名空间就是给变量、函数、类等划分作用域。

```cpp
#include <iostream>

namespace A {
    void print() {
        std::cout << "A::print" << std::endl;
    }
}

namespace B {
    void print() {
        std::cout << "B::print" << std::endl;
    }
}

int main() {
    A::print();
    B::print();
}
```

这里的 `A::` 和 `B::` 就是命名空间限定符。

### ida里的命名空间

```cpp
namespace Security {
    class Scanner {
    public:
        void scan();
    };
}
这里被编译后的符号就是
Security::Scanner::scan()
ida里表示成
_ZN8Security7Scanner4scanEv
```

## 三、类的内存布局

先说个结论：类和结构体没啥区别，都有内存对齐，权限上存在public和private的默认区别。

### 非静态内存布局

这个是相当重要的一个知识点了，我们来看看。

```cpp
class Person {
public:
    int age;
    int id;

    void setAge(int value) {
        age = value;
    }

    int getAge() {
        return age;
    }
};
Person p1;
Person p2;
```

你需要先区分两种东西：

- 成员变量：属于对象，通常存储在对象的内存空间里。
- 普通非静态成员函数：代码存储在程序的代码段中，不会为每个对象复制一份。

p1的内存布局：地址0处是age，偏移4是id。总共8字节。

p2的内存布局也是同理。

这个时候就有人要问了，成员函数呢？`setAge()、getAge() `的机器指令位于代码区域，由对象调用，不会分别占用 p1、p2 的对象空间。

两个对象各自有 `age` 和 `id`，但它们调用的是同一份 `setAge()` 和 `getAge()` 代码。

### 静态成员变量有何不同

```cpp
class Person {
public:
    int age;
    static int count;
};

int Person::count = 0;
```

这里：

- `age`：每个对象各有一份。
- `count`：属于整个类，所有对象共享一份。

因此，`count` 不会作为普通对象成员占据 `Person` 的实例布局。

```cpp
class Person {
public:
    static void printCount() {
        // 可以访问静态成员
    }

    void printAge() {
        // 可以访问当前对象的 age
    }

    int age;
};
```

静态成员函数没有隐含的 `this` 指针，因此不能直接访问某个对象的非静态成员变量。

这点后面讲 `this` 时会用到。

### 如果有虚函数呢？

虚函数在本篇只会带过一点，后面我们展开讲讲。

```cpp
class Base {
public:
    int value;

    virtual void show() {
    }
};
```

有虚函数的类通常会涉及虚函数表机制：

- 对象中通常会有一个隐藏的虚表指针（vptr）。
- 虚表中保存虚函数的入口地址。
- 通过虚函数调用时，可以根据对象的动态类型选择实际执行的函数。

在常见的 Android ARM64 Clang ABI 实现中，简单的多态对象通常可以观察到一个 8 字节的 vptr，但具体布局应以编译器和 ABI 为准。

如果你看过aosp源码，会发现这个东西很像jni。（还是说jni像他。。。）

## 四、this指针

`this` 是 C++ 类中非常重要的概念。

它代表：

当前正在调用成员函数的对象的地址。

```cpp
class Person {
public:
    int age;

    void setAge(int value) {
        this->age = value;
    }
};

Person p;
p.setAge(18);
可以理解为this == &p，this保存了p的地址。
```

### 编译器是怎么理解成员函数的

比如上面的`p.setAge(18)`可以从概念上理解为`Person_setAge(&p, 18);`。

成员函数实际会有一个隐含的对象参数，也就是 `this`。

```asm
MOV     X0, object_address
MOV     W1, #18
BL      Person_setAge
进入函数后
STR     W1, [X0]
```

相当于`this->age = value;`因为 `age` 位于对象偏移 0。

如果成员变量在偏移 4，那么可能看到：`STR     W1, [X0,#4]`

藏在伪代码里的this

```cpp
void __fastcall sub_1234(__int64 a1, int a2)
{
    *(_DWORD *)a1 = a2;
}
```

这里 `a1` 就有可能是 `this`。

逆向重点：当一个函数的第一个参数反复被用来访问不同固定偏移时，要考虑它是不是对象指针。

## 五、构造函数与析构函数

### 构造函数

构造函数在对象创建时调用，主要负责初始化对象。

```cpp
class Person {
public:
    int age;
    int id;

    Person() {
        age = 0;
        id = 0;
    }
};
```

使用：

```
Person p;
```

对象创建时，构造函数会执行。

构造函数的特点：

- 名字与类名相同。
- 没有返回值类型。
- 可以重载。
- 对象创建时由相应的初始化过程调用。

### 带参数的构造函数

```cpp
class Person {
public:
    int age;
    int id;

    Person(int a, int i) {
        age = a;
        id = i;
    }
};

int main() {
    Person p(18, 1001);
}
```

更推荐使用初始化列表：

```cpp
Person(int a, int i) : age(a), id(i) {
}
```

初始化列表是在成员初始化阶段初始化成员，而不是先默认初始化后再赋值。

### 析构函数

析构函数在对象生命周期结束时调用，主要负责清理资源。

```cpp
class Person {
public:
    int age;

    Person() {
        age = 18;
    }

    ~Person() {
        // 清理资源
    }
};
```

例如：

```
int main() {
    Person p;
    return 0;
}
```

当 `p` 离开作用域时，会调用析构函数。

析构函数特点：

- 名字是 `~类名()`。
- 没有返回值。
- 没有参数。
- 一个类只能有一个析构函数，不能重载。

调用顺序之前讲过了，这里不说了。

构造函数：

- 申请堆内存。
- 保存堆内存地址到对象成员 `data`。

析构函数：

\- 释放 `data` 指向的内存。

## 六、拷贝构造与赋值运算符

### 1. 拷贝构造函数

拷贝构造的作用是：

使用一个已经存在的对象，初始化一个新的对象。

```cpp
class Person {
public:
    int age;

    Person(int a) : age(a) {
    }

    Person(const Person& other) {
        age = other.age;
    }
};

int main() {
    Person p1(18);
    Person p2 = p1;
}
```

调用的是拷贝构造函数。

注意：虽然写了 `=`，但这里不是赋值运算符，而是初始化新对象。

### 2.赋值运算符

把一个已经存在的对象的内容赋给另一个已经存在的对象。

```cpp
class Person {
public:
    int age;

    Person(int a) : age(a) {
    }

    Person& operator=(const Person& other) {
        if (this != &other) {
            age = other.age;
        }

        return *this;
    }
};

int main() {
    Person p1(18);
    Person p2(20);

    p2 = p1;
}
```

这里：

```
p2 = p1;
```

调用赋值运算符。

| 对比             | 拷贝构造                | 赋值运算符                 |
| ---------------- | ----------------------- | -------------------------- |
| 作用             | 初始化新对象            | 修改已有对象               |
| 典型写法         | `Person b = a;`         | `b = a;`                   |
| 是否已有目标对象 | 没有                    | 有                         |
| 典型函数         | `Person(const Person&)` | `operator=(const Person&)` |

### 浅拷贝与深拷贝

假设类里面有指针。

```cpp
class Buffer {
public:
    char* data;

    Buffer(int size) {
        data = new char[size];
    }

    ~Buffer() {
        delete[] data;
    }
};

Buffer a(16);
Buffer b = a;
```

如果没有自定义拷贝构造函数，编译器生成的默认拷贝构造会逐成员复制。

结果就是

```cpp
a.data ─────┐
            ├────> 同一块堆内存
b.data ─────┘
```

这个也叫浅拷贝。当 `a` 和 `b` 分别析构时，可能对同一块内存执行两次 `delete[]`，造成 double free。

深拷贝应该如下

```cpp
class Buffer {
public:
    char* data;
    int size;

    Buffer(int n) : size(n) {
        data = new char[size]{};
    }

    // 拷贝构造
    Buffer(const Buffer& other) : size(other.size) {
        data = new char[size];

        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // 析构
    ~Buffer() {
        delete[] data;
    }
};
```

这样的话

```
a.data ─────> 堆内存 A

b.data ─────> 堆内存 B
```

两个对象拥有独立的内存。

不过，这个例子还没有实现拷贝赋值运算符，因此不能直接安全地用它做完整的拷贝赋值。

## 七、申请与释放

说个小坑

```cpp
int* p = new int[10];

delete[] p;
```

这里必须使用 `delete[]`。

而：

```
int* p = new int(10);

delete p;
```

这里是单个 `int`，使用 `delete`。

如果是对象数组：

```cpp
Person* people = new Person[3];

delete[] people;
```

释放时会逐个调用对象的析构函数，然后释放数组内存。

## 八、实战

```cpp
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
```

来看看ida反编译出来的伪代码

```c
00000000 struct __cppobj NativeLab::User // sizeof=0x10
00000000 {                                       // XREF: main/r main/r
00000000     int id;
00000004     // padding byte
00000005     // padding byte
00000006     // padding byte
00000007     // padding byte
00000008     char *name;                         // XREF: main+34/w main+5C/w ...
00000010 };
可以看到User类的内存布局，这里也有内存对齐，因为char* 是指针，8字节。

int __fastcall main(int argc, const char **argv, const char **envp)
{
  char *v3; // x19
  unsigned __int64 v4; // x20
  _DWORD *v5; // x20
  unsigned __int64 v6; // x22
  void *v7; // x21
  NativeLab::User v9; // [xsp+0h] [xbp-30h] BYREF
  NativeLab::User v10; // [xsp+10h] [xbp-20h] BYREF
  NativeLab::User a; // [xsp+20h] [xbp-10h] BYREF

  a.id = 1001;
  v3 = (char *)operator new[](a1: 6u);
  a.name = v3;
  strcpy(v3, "Alice");
  v10.id = 1001;
  v4 = strlen(s: v3) + 1;
  v10.name = (char *)operator new[](a1: v4);
  memcpy(dest: v10.name, src: v3, n: v4);
  这上面是初始化a的过程，不过这个v10对v3做了拷贝也就是a对象，所以这个对应源码里的NativeLab::User b = a;为啥？因为name在堆上的内存不一样，属于深拷贝。
      
  v5 = (_DWORD *)operator new[](a1: 4u);
  *v5 = 6451010; //注意这个10进制数，他是"Bob\0"
  v6 = strlen(s: v3) + 1;
  v7 = (void *)operator new[](a1: v6);比v3多了一个字节，这里在复制a.name
  memcpy(dest: v7, src: v3, n: v6);
  operator delete[](a1: v5);
  v9.name = (char *)v7;//这里在拷贝赋值，v5 指向刚才构造 "Bob" 时申请的内存。但后面 v9.name 指向的是 v7，不是 v5。这意味着 "Bob" 对应的内存被释放了，最终保留的是从 a.name 深拷贝得到的 "Alice"。
  v9.id = a.id;
  NativeLab::User::print(this: &a);
  NativeLab::User::print(this: &v10);
  NativeLab::User::print(this: &v9);
  if ( v9.name != nullptr )
    operator delete[](a1: v9.name);
  if ( v10.name != nullptr )
    operator delete[](a1: v10.name);
  if ( a.name != nullptr )
    operator delete[](a1: a.name);
  return 0;
}
```

