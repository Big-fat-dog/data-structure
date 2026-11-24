# ARM汇编学习笔记（一）

**ARM64 汇编本质上就是处理器通过寄存器、内存和指令来执行程序——GPT**

- [ARM汇编学习笔记（一）](#arm汇编学习笔记一)
  - [**ARM64 架构**](#arm64-架构)
    - [**1. ARM、ARM64、AArch64**](#1-armarm64aarch64)
    - [**2. ARM64 是 RISC 架构**](#2-arm64-是-risc-架构)
  - [寄存器体系](#寄存器体系)
    - [**X0–X30：64 位通用寄存器**](#x0x3064-位通用寄存器)
    - [**W0–W30：32 位寄存器**](#w0w3032-位寄存器)
    - [**X0–X30 分别有什么用途？**](#x0x30-分别有什么用途)
      - [**1. X0–X7：参数和返回值寄存器**](#1-x0x7参数和返回值寄存器)
      - [**2.X8：间接结果寄存器**](#2x8间接结果寄存器)
      - [**3. X9–X15：临时寄存器**](#3-x9x15临时寄存器)
      - [**4. X16–X17：IP0 / IP1**](#4-x16x17ip0--ip1)
      - [**5. X18：平台相关寄存器**](#5-x18平台相关寄存器)
      - [**6. X19–X28：被调用者保存寄存器**](#6-x19x28被调用者保存寄存器)
      - [**7. X29：FP，帧指针**](#7-x29fp帧指针)
      - [**8. X30：LR，链接寄存器**](#8-x30lr链接寄存器)
    - [**SP、PC、NZCV：特殊寄存器**](#sppcnzcv特殊寄存器)
      - [**1. SP：Stack Pointer**](#1-spstack-pointer)
      - [**2. PC：Program Counter**](#2-pcprogram-counter)
      - [**3. NZCV：条件标志寄存器**](#3-nzcv条件标志寄存器)
    - [**别漏掉另一组寄存器：V0–V31**](#别漏掉另一组寄存器v0v31)
    - [动手写代码](#动手写代码)
  - [**寄存器读写规则与 NZCV**](#寄存器读写规则与-nzcv)
    - [**1. Xn 和 Wn 的读写规则**](#1-xn-和-wn-的读写规则)
    - [**2. SP 和 XZR 不要混淆**](#2-sp-和-xzr-不要混淆)
    - [**3. NZCV 标志位**](#3-nzcv-标志位)
      - [常见比较指令](#常见比较指令)
    - [4.反编译实战](#4反编译实战)
  - [**内存寻址方式**](#内存寻址方式)
    - [**第一种：基址寻址** `[Xn]`](#第一种基址寻址-xn)
    - [**第二种：立即数偏移寻址** `[Xn, #imm]`](#第二种立即数偏移寻址-xn-imm)
    - [**第三种：寄存器偏移寻址** `[Xn, Xm]`](#第三种寄存器偏移寻址-xn-xm)
    - [**变体：带扩展或移位的寄存器偏移**](#变体带扩展或移位的寄存器偏移)
    - [**第四种：后索引寻址** `[Xn], #imm`](#第四种后索引寻址-xn-imm)
    - [**第五种：前索引寻址** `[Xn, #imm]!`](#第五种前索引寻址-xn-imm)
    - [做个小练习](#做个小练习)
  - [**LDR / STR 指令家族与数据类型**。](#ldr--str-指令家族与数据类型)
    - [**一、内存里只有字节，没有 signed 和 unsigned**](#一内存里只有字节没有-signed-和-unsigned)
    - [**二、LDR 家族：读取不同宽度的数据**](#二ldr-家族读取不同宽度的数据)
    - [**三、符号扩展：LDRSB / LDRSH / LDRSW**](#三符号扩展ldrsb--ldrsh--ldrsw)
      - [**1. LDRSB：读取有符号字节**](#1-ldrsb读取有符号字节)
      - [**2. LDRSB X0：直接扩展到 64 位**](#2-ldrsb-x0直接扩展到-64-位)
      - [**3. 其他符号扩展指令**](#3-其他符号扩展指令)
    - [**四、STR 家族：写入不同宽度的数据**](#四str-家族写入不同宽度的数据)
    - [小练习](#小练习)
  - [**基础算术与逻辑指令**](#基础算术与逻辑指令)
    - [**加减法指令**](#加减法指令)
      - [**一、ADD：加法**](#一add加法)
      - [**二、SUB：减法**](#二sub减法)
      - [**ADDS 和 SUBS：运算并更新标志位**](#adds-和-subs运算并更新标志位)
      - [**为什么需要 ADDS / SUBS？**](#为什么需要-adds--subs)
    - [乘除法指令](#乘除法指令)
      - [**一、MUL：乘法**](#一mul乘法)
        - [**2. W 寄存器和 X 寄存器的区别**](#2-w-寄存器和-x-寄存器的区别)
      - [**二、SDIV：有符号除法**](#二sdiv有符号除法)
        - [**1. 基本用法**](#1-基本用法)
        - [**2. SDIV 的特殊情况**](#2-sdiv-的特殊情况)
      - [**三、UDIV：无符号除法**](#三udiv无符号除法)
    - [**位运算指令（AND、ORR、EOR、BIC）**](#位运算指令andorreorbic)
      - [**1. AND：按位与**](#1-and按位与)
      - [**2. ORR：按位或**](#2-orr按位或)
      - [**3. EOR：按位异或**](#3-eor按位异或)
      - [**4. BIC：按位清除**](#4-bic按位清除)
      - [位运算与nzcv](#位运算与nzcv)
    - [**移位指令与位域操作**](#移位指令与位域操作)
      - [**一、什么是移位？**](#一什么是移位)
      - [**二、LSL：逻辑左移**](#二lsl逻辑左移)
      - [**三、LSR：逻辑右移**](#三lsr逻辑右移)
      - [**四、ASR：算术右移**](#四asr算术右移)
      - [五、**循环右移：ROR**](#五循环右移ror)
      - [六、循环左移和算数左移](#六循环左移和算数左移)
      - [七、移位的作用](#七移位的作用)
    - [**位域操作：UBFX、SBFX、BFI**](#位域操作ubfxsbfxbfi)
      - [**UBFX：无符号位域提取**](#ubfx无符号位域提取)
      - [**SBFX：有符号位域提取**](#sbfx有符号位域提取)
      - [**BFI：位域插入**](#bfi位域插入)
      - [**UBFM 为什么能实现 LSR 和 UBFX？**](#ubfm-为什么能实现-lsr-和-ubfx)
      - [**SBFM 为什么能实现 ASR 和 SBFX？**](#sbfm-为什么能实现-asr-和-sbfx)
      - [**BFM 与 BFI**](#bfm-与-bfi)
      - [总结BFM的关系。](#总结bfm的关系)
    - [**深入理解 UBFM：位旋转与位掩码**](#深入理解-ubfm位旋转与位掩码)
      - [总结](#总结)
    - [**SBFM 与 BFM：符号扩展和位域插入**](#sbfm-与-bfm符号扩展和位域插入)
      - [按位提取](#按位提取)
      - [再来看看算数右移](#再来看看算数右移)
      - [BFM](#bfm)
      - [BFXIL](#bfxil)
      - [BFC](#bfc)
      - [小练习](#小练习-1)


## **ARM64 架构**

### **1. ARM、ARM64、AArch64**

你可能经常看到以下几个名称：

|  名称   |               含义                |
| :-----: | :-------------------------------: |
|   ARM   |        一种处理器架构家族         |
| AArch32 |    ARM 架构中的 32 位执行状态     |
| AArch64 |    ARM 架构中的 64 位执行状态     |
|  ARM64  | 通常指面向 64 位 ARM 的平台或架构 |
|   A64   |    AArch64 状态下使用的指令集     |

Android通常用AArch64

比如apk反编译后常常能看到

```
lib/
├── arm64-v8a/
│   └── libnative.so
├── armeabi-v7a/
│   └── libnative.so
└── x86_64/
    └── libnative.so
```

其中：

- `arm64-v8a`：64 位 ARM。
- `armeabi-v7a`：32 位 ARM。
- `x86_64`：64 位 x86

### **2. ARM64 是 RISC 架构**

ARM64 属于 RISC（精简指令集计算机）架构。

可以先简单理解为：

- 指令格式相对规整。
- 大量操作围绕寄存器展开。
- 内存读写通常由专门的 Load/Store 指令完成。
- 运算指令通常处理寄存器中的数据。

看个例子

```asm
ldr w0, [x1]
add w0, w0, #1
str w0, [x1]
```

翻译一下

```cpp
int temp = *(int*)x1;
temp = temp + 1;
*(int*)x1 = temp;
```

这里已经能看出一个很重要的特点：

**ARM64 中，寄存器承担了大量临时数据和运算结果的存储工作。**

## 寄存器体系

AArch64 提供了 31 个通用寄存器：

```
X0
X1
X2
...
X28
X29
X30
```

每个都是 64 位。

同时，每个通用寄存器都有对应的 32 位视图：

```
W0
W1
W2
...
W28
W29
W30
```

此外，还有 SP、PC 和 SIMD/浮点寄存器等。

![fUpL-1G62Zlh_RV1qbbtIVDzmk8KYIJEOVswavClafkhzVHA8w6Gpls7Npm3BH87zo8YEKd0EFM0ikt99nNw1wpuQQ9nlrgx1P3OhKKzeGPiiCRFK_s6hytYK7v6gBPNl7gDa6JDkKv0fJJTowVklgoNzE9IQZaE23UZaNUs5gTzAZOgebsz_J_5gms_d06f](fUpL-1G62Zlh_RV1qbbtIVDzmk8KYIJEOVswavClafkhzVHA8w6Gpls7Npm3BH87zo8YEKd0EFM0ikt99nNw1wpuQQ9nlrgx1P3OhKKzeGPiiCRFK_s6hytYK7v6gBPNl7gDa6JDkKv0fJJTowVklgoNzE9IQZaE23UZaNUs5gTzAZOgebsz_J_5gms_d06f.jpg)

###  **X0–X30：64 位通用寄存器**

每个 X 寄存器可以存放 64 位数据。

例如：

```asm
mov x0, #100
```

表示把整数 100 放入 X0。

64 位寄存器可以表示：

- 64 位整数。
- 指针地址。
- 函数参数。
- 函数返回值。
- 临时计算结果。

对于 Android ARM64 Native 逆向，最重要的是：**指针通常是 64 位的，因此经常通过 X 寄存器传递。**

### **W0–W30：32 位寄存器**

上面说了，W开头的是X的视图，这点很重要。

即：W0 不是一个独立于 X0 的物理寄存器。它是 X0 的低 32 位视图。（为啥低32位在右边，小端序呀，包子。）

![image-20261118123412159](image-20261118123412159.png)

例如：

```
mov x0, #0x12345678
```

此时：

```
X0 = 0x0000000012345678
W0 =         0x12345678
```

再执行：

```
mov w0, #10
```

此时：

```
W0 = 0x0000000A
X0 = 0x000000000000000A
```

**关键规则：向 Wn 写入结果，会将对应 Xn 的高 32 位清零。**

这不是简单地只修改 Xn 的低 32 位，而是整个 Xn 的高半部分也被清零。这是个小坑。

结合之前学的cpp，可以有这么个对应关系。

| C++ 类型    | 常见寄存器视图 |
| ----------- | -------------- |
| `int`       | Wn             |
| `uint32_t`  | Wn             |
| `long long` | Xn             |
| `uint64_t`  | Xn             |
| `void*`     | Xn             |
| `char*`     | Xn             |

### **X0–X30 分别有什么用途？**

虽然它们都是通用寄存器，但在函数调用约定中有不同的用途。

这里先介绍 Android Native 常用的 AAPCS64 规则。

#### **1. X0–X7：参数和返回值寄存器**

这是最需要熟悉的一组。

在 AAPCS64 中，普通整数和指针参数通常优先使用：

```
X0
X1
X2
X3
X4
X5
X6
X7
```

例如：

```
int add(int a, int b) {
    return a + b;
}
```

在函数入口处，通常是：

```
W0 = a
W1 = b
```

因为 `a` 和 `b` 是 32 位整数。如果是int64，那么a和b就会被赋值给X0,X1。

返回整数或指针时，通常通过 X0/W0 返回。

例如：

```
int add(int a, int b) {
    return a + b;
}
```

函数体可以简单表示为：

```asm
add w0, w0, w1
ret
```

含义：

1. W0 存储第一个参数。
2. W1 存储第二个参数。
3. 把两个参数相加，结果放回 W0。
4. 返回。

#### **2.X8：间接结果寄存器**

X8 有一个比较特殊的 ABI 用途：

**间接结果地址寄存器（Indirect Result Location Register）。**

例如某些比较大的结构体返回值，可能由调用者先准备存储空间，再把地址通过 X8 传给被调用函数。

先码住：

- X0–X7：普通参数和结果。
- X8：某些间接返回值场景会用到。

这里暂时放一下，后面学习结构体返回和 ABI 时再详细讲。

#### **3. X9–X15：临时寄存器**

这些寄存器通常用于临时计算。

例如：

```
mov x9, x0
add x9, x9, x1
```

可以理解为：

```
temp = a + b;
```

在 AAPCS64 中，X9–X15 通常属于调用者保存（caller-saved）寄存器。

也就是说，调用其他函数后，不能假定这些寄存器仍然保持原值。

#### **4. X16–X17：IP0 / IP1**

这两个寄存器也经常被称为：

- X16：IP0
- X17：IP1

它们属于过程内调用临时寄存器，链接器也可能利用它们插入中间跳转代码（veneer）。

在 Native 逆向时，如果看到 X16、X17，不要直接认为它们就是普通业务变量，狠狠mark一下！

#### **5. X18：平台相关寄存器**

X18 是一个特殊情况。

它的用途依赖具体平台 ABI。在一些平台上可能保留给平台运行时使用。

因此：

**不要随意把 X18 当成普通临时寄存器使用。**

对于 Android NDK 编译出的代码，具体应以目标平台 ABI 和工具链约定为准。

#### **6. X19–X28：被调用者保存寄存器**

这些寄存器通常用于保存跨函数调用仍然需要使用的数据。

例如：

```cpp
int process(int a) {
    int important = a * 10;
    another_function();
    return important;
}
```

假设编译器决定把 `important` 放在 X19 中。

因为 `process` 调用了 `another_function()`，而 `another_function()` 也可能使用寄存器。

所以按照 AAPCS64，使用 X19–X28 的被调用函数需要保证返回时恢复这些寄存器原本的值。

因此你可能看到：

```
stp x19, x20, [sp, #-16]!
```

这类指令通常和保存寄存器有关。

比如

```asm
mov x19, x0
bl sub_1234 ;把下一条指令的地址（也就是 mov x0, x19 这条指令的地址）写入 x30（也叫 LR，Link Register）。
mov x0, x19
ret ;ret 在 ARM64 上就是 br x30 的别名：跳到 x30 里存的地址，继续执行。
```

假设

```
X0=100
X19=100
那么进入1234函数后，X0不被保护他是可以被随意修改的
而X19还是100，他不能被修改！
```

最后的`ret`：通过 X30 返回调用者地址（告诉 CPU 函数执行完后应该跳回哪里），同时 X0 中的 100 作为返回值交给调用者。

#### **7. X29：FP，帧指针**

X29 通常被用作：

FP = Frame Pointer

它常用于帮助定位当前函数的栈帧。

例如：

```
mov x29, sp
```

可以理解为：

```
frame_pointer = stack_pointer;
```

不过要注意：

- X29 是通用寄存器。
- FP 是它的常用别名。
- 编译器不一定始终使用 X29 建立栈帧。
- 优化编译可能省略传统帧指针。

所以在 IDA 中没有看到 X29，也不意味着函数没有栈帧。

#### **8. X30：LR，链接寄存器**

LR = Link Register

X30 是 ARM64 函数调用中极其重要的寄存器。

当执行：

```
bl function  
```

即跳转指令时

处理器会把返回地址写入 X30，然后跳转到目标函数。

因此：

```
X30 = 返回地址
```

被调用函数执行完成后，通常通过：

```asm
ret ;ret 在 ARM64 上就是 br x30 的别名：跳到 x30 里存的地址，继续执行。
```

返回。

默认情况下，`ret` 使用 X30 作为返回地址。

这意味着 X30 经常承担函数调用的返回地址保存工作，区别于X0，X0存的是返回值。

### **SP、PC、NZCV：特殊寄存器**

除了 X0–X30，还有几个必须认识的寄存器。

#### **1. SP：Stack Pointer**

SP 是栈指针。

它保存当前栈的位置，主要用于管理函数调用过程中的栈内存。

假设：

```cpp
int add(int a, int b) {
    int c = a + b;
    return c;
}
```

编译器可能需要为函数局部数据、保存的寄存器等分配栈空间。

你可能看到：

```
sub sp, sp, #0x20
```

意思是：

SP 向低地址移动 0x20 字节，也就是分配 32 字节栈空间。

注意：AArch64 的栈通常向低地址增长。

而在符合 AAPCS64 的常规函数边界，SP 必须保持 16 字节对齐。

ps：之前在cpp里讲过栈的生长方向哦，**SP 必须保持 16 字节对齐**这一点记一下，嘿嘿。

#### **2. PC：Program Counter**

PC 是程序计数器。

它和在 x86 汇编中的 RIP 有相似的概念。

它用于描述当前指令执行位置。

但是要注意：

**AArch64 中，PC 不是一个可以像 X0 那样直接读写的普通通用寄存器。**

你不能直接写：

```
mov x0, pc
```

这种普通寄存器式访问。

AArch64 可以通过 ADR 等 PC 相对指令获取相关地址。

后面学习 `ADR`、`ADRP` 时会详细讲。

#### **3. NZCV：条件标志寄存器**

NZCV 保存一些运算产生的条件标志。

| 标志 | 含义                     |
| ---- | ------------------------ |
| N    | Negative，负数标志       |
| Z    | Zero，零标志             |
| C    | Carry，进位标志          |
| V    | Overflow，有符号溢出标志 |

例如：

```
cmp w0, #0
b.eq loc_1000
```

你可以先理解成：

```
if (w0 == 0) {
    goto loc_1000;
}
```

`CMP` 会进行比较并更新标志位，`B.EQ` 会根据 Z 标志决定是否跳转。

本节只需要认识 NZCV，具体条件跳转留到后面的控制流章节。

### **别漏掉另一组寄存器：V0–V31**

除了整数通用寄存器，AArch64 还有一组 SIMD 和浮点寄存器：

```
V0
V1
V2
...
V31
```

每个 V 寄存器最大为 128 位。

同一组寄存器可以通过不同宽度的名字访问：

| 名称    | 宽度   |
| ------- | ------ |
| B0      | 8 位   |
| H0      | 16 位  |
| S0      | 32 位  |
| D0      | 64 位  |
| Q0 / V0 | 128 位 |

例如：

```
fadd s0, s1, s2
```

表示浮点加法。

在 Android Native 逆向中，它们常用于：

- `float` 和 `double` 运算。
- SIMD 向量计算。
- NEON 指令。
- 图像处理和音视频算法。
- 加密或高性能数值计算。

AAPCS64 中，浮点和 SIMD 参数也有独立的寄存器传递规则，后面会单独学习。

### 动手写代码

我们写一个简单的cpp，然后放到ida里反编译看看汇编。

```cpp
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
```

我们先来看看四个函数的反汇编结果

首先是add_32

```asm
.text:00000000000083A8 ; int32_t __cdecl add_32(int a, int b)
.text:00000000000083A8                 EXPORT add_32  #EXPORT 表示这个函数是导出的。
.text:00000000000083A8 add_32                                  ; CODE XREF: .add_32+C↓j
.text:00000000000083A8                                         ; DATA XREF: LOAD:00000000000006F8↑o ...
.text:00000000000083A8  #下面四个玩意是栈帧偏移变量。
.text:00000000000083A8 var_8           = -8
.text:00000000000083A8 var_4           = -4
.text:00000000000083A8 b               =  8
.text:00000000000083A8 a               =  0xC
.text:00000000000083A8 
.text:00000000000083A8 ; __unwind {  
.text:00000000000083A8                 SUB             SP, SP, #0x10   ;开辟 16 字节栈帧
.text:00000000000083AC                 STR             W0, [SP,#0x10+var_4] ; 把参数 a（W0）存到 SP+0xC
.text:00000000000083B0                 STR             W1, [SP,#0x10+var_8] ; 把参数 b（W1）存到 SP+0x8
.text:00000000000083B4                 LDR             W8, [SP,#0x10+var_4] ; 从 SP+0xC 读回 a 到 W8
.text:00000000000083B8                 LDR             W9, [SP,#0x10+var_8] ; 从 SP+0x8 读回 b 到 W9
.text:00000000000083BC                 ADD             W0, W8, W9 ;两者相加存到W0
.text:00000000000083C0                 ADD             SP, SP, #0x10 ;恢复栈帧
.text:00000000000083C4                 RET      ; 返回，返回值在 W0
.text:00000000000083C4 ; } // starts at 83A8
.text:00000000000083C4 ; End of function add_32
```

read_value

```asm
.text:00000000000083E8 ; int __cdecl read_value(const int *ptr)
.text:00000000000083E8                 EXPORT read_value
.text:00000000000083E8 read_value                              ; CODE XREF: .read_value+C↓j
.text:00000000000083E8                                         ; DATA XREF: LOAD:0000000000000710↑o ...
.text:00000000000083E8
.text:00000000000083E8 var_8           = -8
.text:00000000000083E8 ptr             =  8
.text:00000000000083E8
.text:00000000000083E8 ; __unwind {
.text:00000000000083E8                 SUB             SP, SP, #0x10
.text:00000000000083EC                 STR             X0, [SP,#0x10+var_8] ;把sp+0x08存到X0,这里用了X0哎！为什么捏？指针8字节哦！
.text:00000000000083F0                 LDR             X8, [SP,#0x10+var_8]
.text:00000000000083F4                 LDR             W0, [X8]  ; 解引用：读 X8 指向的 4 字节到 W0
.text:00000000000083F8                 ADD             SP, SP, #0x10
.text:00000000000083FC                 RET
.text:00000000000083FC ; } // starts at 83E8
.text:00000000000083FC ; End of function read_value
.text:00000000000083FC
```

`X0, [SP,#0x10+var_8] ;把sp+0x08存到X0,这里用了X0哎！为什么捏？回去看看这个函数的第一个参数吧。`

其他两个函数也是大差不差，感兴趣可以自己动手看看。

## **寄存器读写规则与 NZCV**

### **1. Xn 和 Wn 的读写规则**

先记住最重要的规则(其实上面讲过）：

**写入 Wn，会自动清零对应 Xn 的高 32 位。**

```asm
X0 = 0x0000567800001234
mov w0, #10
X0 = 0x000000000000000A
```

注意：不是只修改低 32 位，高 32 位也会清零。而读取 W0 时，只会读取 X0 的低 32 位。

### **2. SP 和 XZR 不要混淆**

| 寄存器 | 含义          | 读取       | 写入       |
| ------ | ------------- | ---------- | ---------- |
| SP     | 栈指针        | 当前栈地址 | 修改栈指针 |
| XZR    | 零寄存器      | 恒为 0     | 写入被忽略 |
| WZR    | 32 位零寄存器 | 恒为 0     | 写入被忽略 |

比如

```asm
mov x0, xzr ;X0 = 0
;而SP确实能被操作 mov sp, x0 修改栈指针。
```

### **3. NZCV 标志位**

NZCV 是 CPU 的四个条件标志（全局的！全局的！全局的！大家公用！）：

- 任何会写标志的指令（`CMP`、`CCMP`、`SUBS`、`ADDS` 等）都会覆盖这一套标志。
- 任何读标志的指令（`B.cond`、`CSET`、`CSEL`、`CCMP` 里的条件）都读这同一套。
- 所以它是“全局唯一、随时被最后一条写标志的指令覆盖”的。

| 标志 | 含义               | 什么时候常见            |
| ---- | ------------------ | ----------------------- |
| N    | Negative，负数标志 | 运算结果最高位为 1      |
| Z    | Zero，零标志       | 运算结果为 0            |
| C    | Carry，进位标志    | 无符号运算进位/借位相关 |
| V    | Overflow，溢出标志 | 有符号运算溢出          |

举个例子

```asm
cmp w0, w1;比较二者
subs wzr, w0, w1;和上面一个意思。

假设W0 = 10，W1 = 10
则上面指令的结果为 0，因此 Z = 1。
```

它计算 `w0 - w1`，但不保存计算结果，只更新 NZCV。

#### 常见比较指令

这里讲到比较了，就给出常见的**条件**指令。

这些**条件指令**读的是NECV！

| 指令   | 条件       | 含义           |
| ------ | ---------- | -------------- |
| `b.eq` | Z=1        | 相等           |
| `b.ne` | Z=0        | 不相等         |
| `b.gt` | Z=0 且 N=V | 有符号大于     |
| `b.ge` | N=V        | 有符号大于等于 |
| `b.lt` | N≠V        | 有符号小于     |
| `b.le` | Z=1 或 N≠V | 有符号小于等于 |
| `b.hi` | C=1 且 Z=0 | 无符号大于     |
| `b.ls` | C=0 或 Z=1 | 无符号小于等于 |

特别注意：`b.gt` 和 `b.hi` 不一样。前者用于有符号比较，后者用于无符号比较。

### 4.反编译实战

写三个简单的函数，来看看是如何进行比较的吧。

```cpp

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

```

首先看比较较大者

```asm
.text:0000000000004678 ; int __cdecl max_value(int a, int b)
.text:0000000000004678                 EXPORT max_value
.text:0000000000004678 max_value                               ; DATA XREF: LOAD:0000000000000330↑o
.text:0000000000004678
.text:0000000000004678 var_C           = -0xC
.text:0000000000004678 var_8           = -8
.text:0000000000004678 var_4           = -4
.text:0000000000004678 b               =  4
.text:0000000000004678 a               =  8
.text:0000000000004678
.text:0000000000004678 ; __unwind {
.text:0000000000004678                 SUB             SP, SP, #0x10
.text:000000000000467C                 STR             W0, [SP,#0x10+var_8]
.text:0000000000004680                 STR             W1, [SP,#0x10+var_C]
.text:0000000000004684                 LDR             W8, [SP,#0x10+var_8]
.text:0000000000004688                 LDR             W9, [SP,#0x10+var_C]
.text:000000000000468C                 SUBS            W8, W8, W9 ;作减法，和cmp其实一个意思,不同于SUB，SUBS会更新NZCV。
.text:0000000000004690                 B.LE            loc_46A4
.text:0000000000004694                 B               loc_4698
.text:0000000000004698 ; ---------------------------------------------------------------------------
.text:0000000000004698
.text:0000000000004698 loc_4698                                ; CODE XREF: max_value+1C↑j
.text:0000000000004698                 LDR             W8, [SP,#0x10+var_8]
.text:000000000000469C                 STR             W8, [SP,#0x10+var_4]
.text:00000000000046A0                 B               loc_46B0
.text:00000000000046A4 ; ---------------------------------------------------------------------------
.text:00000000000046A4
.text:00000000000046A4 loc_46A4                                ; CODE XREF: max_value+18↑j
.text:00000000000046A4                 LDR             W8, [SP,#0x10+var_C]
.text:00000000000046A8                 STR             W8, [SP,#0x10+var_4]
.text:00000000000046AC                 B               loc_46B0
.text:00000000000046B0 ; ---------------------------------------------------------------------------
.text:00000000000046B0
.text:00000000000046B0 loc_46B0                                ; CODE XREF: max_value+28↑j
.text:00000000000046B0                                         ; max_value+34↑j
.text:00000000000046B0                 LDR             W0, [SP,#0x10+var_4] ;两者之差
.text:00000000000046B4                 ADD             SP, SP, #0x10
.text:00000000000046B8                 RET
.text:00000000000046B8 ; } // starts at 4678
.text:00000000000046B8 ; End of function max_value
```

`is_equal`上面关闭了编译器优化，可以看出是作差来比较的，下面开启优化看看指令有什么变化。

```asm
.text:0000000000004674 ; int __fastcall is_equal(int a, int b)
.text:0000000000004674                 EXPORT is_equal
.text:0000000000004674 is_equal                                ; DATA XREF: LOAD:0000000000000348↑o
.text:0000000000004674 a = X0                                  ; int
.text:0000000000004674 b = X1                                  ; int
.text:0000000000004674 ; __unwind {
.text:0000000000004674                 CMP             W0, W1 ;SUBS    WZR, W0, W1，只改变nzcv，不存结果。
.text:0000000000004678                 CSET            W0, EQ ;CSET 的完整意思是 Conditional Set
.text:000000000000467C                 RET
.text:000000000000467C ; } // starts at 4674
.text:000000000000467C ; End of function is_equal

CSET伪代码
if (EQ条件成立) {
    W0 = 1;
} else {
    W0 = 0;
}
```

```asm
.text:0000000000004680 ; int __fastcall in_range(int value, int low, int high)
.text:0000000000004680                 EXPORT in_range
.text:0000000000004680 in_range                                ; DATA XREF: LOAD:0000000000000360↑o
.text:0000000000004680 value = X0                              ; int
.text:0000000000004680 low = X1                                ; int
.text:0000000000004680 high = X2                               ; int
.text:0000000000004680 ; __unwind {
.text:0000000000004680                 CMP             W0, W1 ;比较value和low
.text:0000000000004684                 CCMP            W0, W2, #0, GE
.text:0000000000004688                 CSET            W0, LE
.text:000000000000468C                 RET
.text:000000000000468C ; } // starts at 4680
.text:000000000000468C ; End of function in_range


假设value = 15，low = 10，high = 20
CMP w0,w1  ;这里15>10，更新了nzcv，但啥也没做
CCMP  ;GE先查看nzcv发现确实是大于等于（如果不是，那nzcv会被全部置零），开始比较W0和W2，
cset  ；先看LE，发现成立，更新W0为1
```

将CCMP拆解一下

| 部分     | 含义                           |
| -------- | ------------------------------ |
| `W0, W2` | 第二次比较的两个操作数         |
| `#0`     | 条件不成立时写入 NZCV 的替代值 |
| `GE`     | 决定是否执行第二次比较的条件   |

它的执行规则是：

- 如果当前 NZCV 满足 GE，就执行 `W0 - W2` 比较，并更新 NZCV。
- 如果当前 NZCV 不满足 GE，就不执行比较，而是把 `#0` 对应的标志位写入 NZCV。

这就是 CCMP 的核心：**根据上一次比较结果，决定是否进行下一次比较。**

名言：**比较指令产生 NZCV，条件指令消费 NZCV。**

`CSET` 是 Conditional Set：根据条件码把一个 0/1 写进寄存器。

- `LE` 表示“有符号比较 ≤”，即 `value <= high`。
- 如果 `CCMP` 之后的条件 `LE` 成立，`W0 = 1`；否则 `W0 = 0`。

注意 `CSET W0, LE` 等价于 `CSINC W0, WZR, WZR, INVERT(LE)`，就是“条件成立置 1，否则置 0”。

## **内存寻址方式**

首先得有内存形态这个意识，可以看看我之前的cpp内存布局的博客，里面有结构体，类的内存布局，嘿嘿。

然后下面都是用上了`[]`表示取内存地址，相当于引用或者解引用。

### **第一种：基址寻址** `[Xn]`

```asm
LDR W0, [X1]
```

含义：

- `X1` 保存一个内存地址。
- CPU 到这个地址读取 4 字节。
- 将读取结果放入 `W0`。

```asm
假设：
X1 = 0x1000
[0x1000] = 1001

LDR W0, [X1] ;W0 = 1001    W0 是 32 位，所以读取的是 4 字节
```

这里读取的指令有

| 指令            | 读取宽度 |
| --------------- | -------- |
| `LDRB W0, [X1]` | 1 字节   |
| `LDRH W0, [X1]` | 2 字节   |
| `LDR W0, [X1]`  | 4 字节   |
| `LDR X0, [X1]`  | 8 字节   |

反过来，`STR` 是写入内存：

```
STR W0, [X1]
```

将 `W0` 的 4 字节写到 `X1` 指向的地址。

**记忆：LDR = Load（读），STR = Store（写）。**

### **第二种：立即数偏移寻址** `[Xn, #imm]`

```asm
LDR W0, [X1, #8]
```

**先用 X1 的值加上 8，得到目标地址，再从目标地址读取 4 字节。**

看看如下例子

```cpp
struct User {
    int id;     // +0
    int age;    // +4
    int score;  // +8
};

int get_score(User* user) {
    return user->score;
}
```

如果 `X1` 保存 `user` 的地址，那么：

```
LDR W0, [X1, #8]
RET
```

就可以还原为：

```
return user->score;
```

### **第三种：寄存器偏移寻址** `[Xn, Xm]`

前两种都是基址加一个固定数字。

但如果偏移量不是固定的，而是放在另一个寄存器中呢？

例如：

```
LDR W0, [X1, X2]
```

含义：

```
读取地址 = X1 + X2
```

假设：

```
X1 = 0x1000
X2 = 0x8
[0x1008] = 95
```

那么执行后：

```
W0 = 95
```

对应 C++ 指针思维：

```
int value = *(int*)((char*)base + offset);
```

这里的 `X1` 可以理解为 `base`，`X2` 可以理解为 `offset`。

### **变体：带扩展或移位的寄存器偏移**

你还可能看到：

```
LDR W0, [X1, X2, LSL #2]
```

这里的地址计算是：

`address = x1+(x2<<2)`

左移 2 位，相当于乘以 4。

假设：

```
X1 = 0x1000
X2 = 3
```

那么：

```
Address = 0x1000 + 3 * 4
        = 0x100C
```

这在数组访问中非常常见：

```
int arr[10];
int value = arr[3];  //访问base+12字节的地址内容。
```

如果 `X1` 是数组首地址，`X2` 是数组下标，那么 `LSL #2` 就是在把数组下标转换成字节偏移，因为一个 `int` 占 4 字节。

注意这里只能当个线索，不一定真的是数组哦！

### **第四种：后索引寻址** `[Xn], #imm`

看这条指令：

```
LDR W0, [X1], #4
```

它分成两个动作：

1. 使用原来的 `X1` 地址读取 4 字节到 `W0`。
2. 读取完成后，`X1 = X1 + 4`。

假设：

```
X1 = 0x1000
[0x1000] = 10
[0x1004] = 20
```

第一次执行：

```
LDR W0, [X1], #4
```

结果：

```
W0 = 10
X1 = 0x1004
```

第二次执行同一条指令：

```
W0 = 20
X1 = 0x1008
```

它很适合实现指针逐个向后移动的操作：

```
int* p = arr;
int a = *p++;
```

注意，`*p++` 是先取当前指针指向的值，再让指针后移，这与后索引寻址的顺序一致，注意和++p区别一下。

### **第五种：前索引寻址** `[Xn, #imm]!`

注意这玩意儿和立即数寻址的区别，多了个感叹号。

```
LDR W0, [X1, #4]!
```

这次顺序反过来了：

1. 先让 `X1 = X1 + 4`。
2. 再从新的 `X1` 地址读取 4 字节。

假设：

```
X1 = 0x1000
[0x1004] = 20
```

执行后：

```
X1 = 0x1004
W0 = 20
```

对应指针思维：

```
int* p = arr;
int a = *++p;
```

这里的 `!` 很重要，它表示**把计算后的地址写回基址寄存器**，也叫写回（write-back）。

**三种写法一定要区分**

| 汇编                | 访问地址  | 是否修改 X1   |
| ------------------- | --------- | ------------- |
| `LDR W0, [X1, #4]`  | 原 X1 + 4 | 否            |
| `LDR W0, [X1], #4`  | 原 X1     | 是，读取后 +4 |
| `LDR W0, [X1, #4]!` | 原 X1 + 4 | 是，读取前 +4 |

可以用一句话记忆：

- 没有 `!`、没有逗号后偏移：只计算地址，不写回。
- `], #4`：先访问，后更新。
- `, #4]!`：先更新，再访问。

### 做个小练习

编写一个简单的结构体，然后访问里面的成员看看。

```cpp
struct User {
    int id;
    int age;
    int score;
};

int test(User* user, int* arr, int index) {
    int a = user->score;
    int b = arr[index];
    return a + b;
}
```



```asm
.text:00000000000045E8
.text:00000000000045E8 ; int __fastcall test(User *user, int *arr, int index)
.text:00000000000045E8                 EXPORT _Z4testP4UserPii
.text:00000000000045E8 _Z4testP4UserPii                        ; DATA XREF: LOAD:0000000000000330↑o
.text:00000000000045E8 user = X0                               ; User *
.text:00000000000045E8 arr = X1                                ; int *
.text:00000000000045E8 index = X2                              ; int
.text:00000000000045E8 ; __unwind {
.text:00000000000045E8                 LDR             W8, [user,#8]
.text:00000000000045EC a = X8                                  ; int
.text:00000000000045EC                 LDR             W9, [arr,W2,SXTW#2]
.text:00000000000045F0 b = X9                                  ; int
.text:00000000000045F0                 ADD             W0, W9, W8
.text:00000000000045F4                 RET
.text:00000000000045F4 ; } // starts at 45E8
.text:00000000000045F4 ; End of function test(User *,int *,int)
```

- `SXTW` = **Sign Extend Word to X**：把 `W2` 的 32 位有符号数符号扩展到 64 位。因为 `index` 是 `int`，可能为负，地址计算要用 64 位，所以先符号扩展。

- `#2` = 左移 2 位，即乘以 4。因为 `int` 是 4 字节，`arr[index]` 的地址 = `arr + index * 4`。
- 合起来：地址 = `X1 + (SignExtend(W2) << 2)`，读 4 字节到 `W9`。

## **LDR / STR 指令家族与数据类型**。

### **一、内存里只有字节，没有 signed 和 unsigned**

看下面的 C++：

```cpp
int8_t a = -1;
uint8_t b = 255;
```

它们虽然数值不同，但在内存中，二进制表示完全一样：

```
11111111
```

也就是十六进制：

```
0xFF
```

为什么？

因为计算机内存存储的是比特。至于 `0xFF` 应该解释成 `-1` 还是 `255`，取决于程序如何解释它。

| 类型      | 8 位二进制 | 十进制解释 |
| --------- | ---------- | ---------- |
| `int8_t`  | `11111111` | -1         |
| `uint8_t` | `11111111` | 255        |

### **二、LDR 家族：读取不同宽度的数据**

先认识最常见的几种指令：

| 指令            | 读取字节数 | 目标寄存器 |
| --------------- | ---------- | ---------- |
| `LDRB W0, [X1]` | 1          | W0         |
| `LDRH W0, [X1]` | 2          | W0         |
| `LDR W0, [X1]`  | 4          | W0         |
| `LDR X0, [X1]`  | 8          | X0         |

这里有两个概念：

- `B`：Byte，1 字节。
- `H`：Halfword，2 字节。

例如：

```asm
LDRB W0, [X1]

假设：
X1 = 0x1000
[0x1000] = FF
```

执行后：

```
W0 = 0x000000FF
```

注意：`LDRB` 读取一个字节，但结果放进 32 位的 W0，其余高位补零。

这是**零扩展（Zero Extension）**。

再看：

```
LDRH W0, [X1]
```

假设内存中两个字节为：

```
地址       内容
0x1000     34
0x1001     12
```

在 Android 常见的 ARM64 小端序环境下，这两个字节组成：

```
0x1234
```

因此：

```
W0 = 0x00001234
```

同样是零扩展。

### **三、符号扩展：LDRSB / LDRSH / LDRSW**

刚才的 `LDRB` 会把读取到的 8 位数据高位补零。但如果这个字节本身代表一个负数呢？

例如：

```
int8_t a = -1;
```

内存中：

```
0xFF
```

如果使用：

```
LDRB W0, [X1]
```

结果是：

```
W0 = 0x000000FF
```

这在有符号 32 位整数中代表 255，而不是 -1。

如果我们希望保留它原本的负数含义，就要使用符号扩展指令。

#### **1. LDRSB：读取有符号字节**

```asm
LDRSB W0, [X1]
```

`SB` = Signed Byte。

假设内存中是：

```
[ X1 ] = 0xFF
```

执行后：

```
W0 = 0xFFFFFFFF
```

因为 `0xFF` 作为 8 位有符号整数是 -1，扩展到 32 位后仍然是 -1。

注意：符号扩展并不是简单地“高位补 1”。

规则是：

- 原数据最高位为 0：高位补 0。
- 原数据最高位为 1：高位补 1。

因此：

| 原始 8 位数据 | 有符号解释 | 扩展到 32 位 |
| ------------- | ---------- | ------------ |
| `0x7F`        | 127        | `0x0000007F` |
| `0x01`        | 1          | `0x00000001` |
| `0x80`        | -128       | `0xFFFFFF80` |
| `0xFF`        | -1         | `0xFFFFFFFF` |

#### **2. LDRSB X0：直接扩展到 64 位**

根据上面那个读取会补位的原理，这个指令还有一种作用：

```
LDRSB X0, [X1]
```

它将一个有符号字节直接扩展到 64 位。

如果内存中是 `0xFF`：

```
X0 = 0xFFFFFFFFFFFFFFFF
```

也就是 64 位的 -1。

所以要区分：

```
LDRSB W0, [X1]  // 符号扩展到 32 位
LDRSB X0, [X1]  // 符号扩展到 64 位
```

#### **3. 其他符号扩展指令**

| 指令             | 读取宽度 | 扩展目标 |
| ---------------- | -------- | -------- |
| `LDRSB W0, [X1]` | 1 字节   | 32 位    |
| `LDRSB X0, [X1]` | 1 字节   | 64 位    |
| `LDRSH W0, [X1]` | 2 字节   | 32 位    |
| `LDRSH X0, [X1]` | 2 字节   | 64 位    |
| `LDRSW X0, [X1]` | 4 字节   | 64 位    |

其中：

- `SB`：Signed Byte，有符号字节。
- `SH`：Signed Halfword，有符号半字。
- `SW`：Signed Word，有符号字。

例如：

```
LDRSH W0, [X1]
```

如果读取的两个字节是：

```
0xFF 0xFF
```

小端序下组成 `0xFFFF`，作为 16 位有符号数是 -1，扩展后：

```
W0 = 0xFFFFFFFF
```

再看：

```
LDRSW X0, [X1]
```

如果读取的 4 字节是：

```
FF FF FF FF
```

那么：

```
X0 = 0xFFFFFFFFFFFFFFFF
```

它是 64 位的 -1。

### **四、STR 家族：写入不同宽度的数据**

读懂了读取，现在看写入。

| 指令            | 写入字节数 | 写入内容        |
| --------------- | ---------- | --------------- |
| `STRB W0, [X1]` | 1          | W0 的低 8 位    |
| `STRH W0, [X1]` | 2          | W0 的低 16 位   |
| `STR W0, [X1]`  | 4          | W0 的低 32 位   |
| `STR X0, [X1]`  | 8          | X0 的全部 64 位 |

加上个U就变成了无符号寻址哦！如`STURB`

例如：

```asm
MOV W0, #0x1234
STRB W0, [X1]
```

虽然 W0 中有：

```
0x00001234
```

但是 `STRB` 只写最低 8 位：

```
[ X1 ] = 0x34
```

同理：

```
STRH W0, [X1]
```

只写最低 16 位：

```
[ X1     ] = 0x34
[ X1 + 1 ] = 0x12
```

这里仍然按照 Android ARM64 常见的小端序展示。

**重要：STR 不负责符号扩展或零扩展。它只负责把寄存器的低位写入指定宽度的内存。**

### 小练习

来一段小练习吧，酣畅淋漓。

```cpp
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
```

反编译结果

```asm
.text:00000000000047B8 ; int __fastcall main(int argc, const char **argv, const char **envp)
.text:00000000000047B8                 EXPORT main
.text:00000000000047B8 main                                    ; DATA XREF: LOAD:0000000000000390↑o
.text:00000000000047B8
.text:00000000000047B8 var_10          = -0x10
.text:00000000000047B8 var_C           = -0xC
.text:00000000000047B8 var_8           = -8
.text:00000000000047B8 a               = -4
.text:00000000000047B8 var_s0          =  0
.text:00000000000047B8 var_s10         =  0x10
.text:00000000000047B8
.text:00000000000047B8 ; __unwind {
.text:00000000000047B8                 SUB             SP, SP, #0x30
.text:00000000000047BC                 STP             X29, X30, [SP,#0x10+var_s0] ; 保存帧指针和返回地址到SP+0X10
.text:00000000000047C0                 STP             X20, X19, [SP,#0x10+var_s10] ; 保存被保护寄存器到sp+0x20
.text:00000000000047C4                 ADD             X29, SP, #0x10 ;x29作为帧指针。
.text:00000000000047C8                 MOV             W8, #0xFF
.text:00000000000047CC                 MOV             W9, #0xFFFE
.text:00000000000047D0                 SUB             X0, X29, #-a ; signed __int8 * ;x29-4赋值给x0
.text:00000000000047D4                 STURB           W8, [X29,#a] ; 读取W8的一字节存到x29-4，也就是说现在x0是 0x000000FF
.text:00000000000047D8                 STRB            W8, [SP,#0x10+var_8]; 将W8的一字节存到 x29-0x08
.text:00000000000047DC                 MOV             W8, #0xFFFFFFFD 
.text:00000000000047E0                 STRH            W9, [SP,#0x10+var_C] ;存储两字节到x29-0x0C   0x0000FFFE
.text:00000000000047E4                 STR             W8, [SP,#0x10+var_10] ；把#0xFFFFFFFD 存到 x29-0x10
.text:00000000000047E8                 BL              ._Z11signed_testPKa ; signed_test(signed char const*)
.text:00000000000047EC                 MOV             W19, W0 ;读到了-1
.text:00000000000047F0                 ADD             X0, SP, #0x10+var_8 ; unsigned __int8 *   x29-8赋值给x0
.text:00000000000047F4                 BL              ._Z13unsigned_testPKh ; unsigned_test(uchar const*)     ;此时返回值是0xFF无符号
.text:00000000000047F8                 ADD             W20, W0, W19  ;w20是255-1
.text:00000000000047FC                 ADD             X0, SP, #0x10+var_C ; __int16 *
.text:0000000000004800                 BL              ._Z17signed_short_testPKs ; signed_short_test(short const*)  此时x0是0xFFFFFFFFFFFFFFFE 有符号
.text:0000000000004804                 MOV             W19, W0
.text:0000000000004808                 MOV             X0, SP  ; int *
.text:000000000000480C                 BL              ._Z15signed_int_testPKi ; signed_int_test(int const*)  这个也是一样,-3
.text:0000000000004810                 ADD             W8, W19, W0
.text:0000000000004814                 ADD             W0, W20, W8
.text:0000000000004818                 LDP             X20, X19, [SP,#0x10+var_s10]
.text:000000000000481C                 LDP             X29, X30, [SP,#0x10+var_s0]
.text:0000000000004820                 ADD             SP, SP, #0x30 ; '0'
.text:0000000000004824                 RET
.text:0000000000004824 ; } // starts at 47B8
```

在跟踪BL跳转的时候还有个额外的收获。

```asm
.plt:0000000000004880 ; __int64 __fastcall signed_test(const signed __int8 *)
.plt:0000000000004880 ._Z11signed_testPKa                     ; CODE XREF: main+30↑p
.plt:0000000000004880                 ADRP            X16, #_Z11signed_testPKa_ptr@PAGE
.plt:0000000000004884                 LDR             X17, [X16,#_Z11signed_testPKa_ptr@PAGEOFF] ; signed_test(signed char const*) ...
.plt:0000000000004888                 ADD             X16, X16, #_Z11signed_testPKa_ptr@PAGEOFF
.plt:000000000000488C                 BR              X17     ; signed_test(signed char const*)
.plt:000000000000488C ; End of function signed_test(signed char const*)

ADRP 把 _Z11signed_testPKa_ptr 所在页的基地址（PC 相对，4KB 对齐）加载到 X16。@PAGE 是链接器修饰符，表示取页地址。
结果：X16 = 存放函数指针的 GOT 条目的页基址。

@PAGEOFF 是页内偏移。这条从 X16 + 偏移 处加载 8 字节到 X17。
这个地址就是 GOT（Global Offset Table） 里的 _Z11signed_testPKa_ptr 条目。它里面存的是 signed_test 的地址
```

**PLT（Procedure Linkage Table）桩代码**：**第一次调用时通过动态链接器解析 `signed_test` 的真实地址，之后直接跳过去**。

- **第一次调用前**：存的是**本 PLT 桩后面那条 `ADD` 指令的地址**（由链接器/加载器预置），即“解析器入口”。
- **解析之后**：存的是 `signed_test` 在 `.so` 里的真实运行时地址。

跟进这个函数

```asm
.text:0000000000004798 ; int __fastcall signed_test(const int8_t *p)
.text:0000000000004798                 EXPORT _Z11signed_testPKa
.text:0000000000004798 _Z11signed_testPKa                      ; CODE XREF: signed_test(signed char const*)+C↓j
.text:0000000000004798                                         ; DATA XREF: LOAD:0000000000000330↑o ...
.text:0000000000004798 p = X0                                  ; const int8_t *
.text:0000000000004798 ; __unwind {
.text:0000000000004798                 LDRSB           W0, [p]
.text:000000000000479C                 RET
.text:000000000000479C ; } // starts at 4798
.text:000000000000479C ; End of function signed_test(signed char const*)
```

很短，就是从x0，也就是`x29-4`里加载有符号一字节也就是`0xFFFFFFFF`到W0里返回。

## **基础算术与逻辑指令**

###  **加减法指令**

#### **一、ADD：加法**

最基础的加法指令：

```
ADD W0, W1, W2
```

含义：

```
W0 = W1 + W2;
```

三个操作数分别是：

```
ADD 目标寄存器, 操作数1, 操作数2
```

例如：

```
MOV W1, #10
MOV W2, #20
ADD W0, W1, W2
```

执行后：

```
W1 = 10
W2 = 20
W0 = 30
```

注意：`ADD` 默认不会更新 NZCV 标志位。

另外加减法还能加减立即数

```asm
ADD X0, X1, #8
```



#### **二、SUB：减法**

```
SUB W0, W1, W2
```

对应：

```
W0 = W1 - W2;
```

例如：

```
MOV W1, #30
MOV W2, #10
SUB W0, W1, W2
```

结果：

```
W0 = 20
```

和 ADD 一样，普通 `SUB` 不更新 NZCV。

#### **ADDS 和 SUBS：运算并更新标志位**

先回忆一下之前遇到的比较指令：

- `CMP W0, W1`：比较两个数，更新 NZCV，不保存减法结果。
- `SUBS W0, W1, W2`：执行减法，保存结果，同时更新 NZCV。

实际上：

```
CMP W1, W2
```

可以理解为：

```
SUBS WZR, W1, W2
```

区别是 `CMP` 将结果丢弃，而 `SUBS` 将结果保存到目标寄存器。

看一个例子：

```asm
MOV W1, #10
MOV W2, #10
SUBS W0, W1, W2
```

计算：

```
W0 = 10 - 10 = 0
```

同时更新 NZCV：

```
N = 0
Z = 1
C = 1
V = 0
```

这里最值得注意的是：

**Z=1，因为运算结果为0。**

再看 ADDS：

```
ADDS W0, W1, W2
```

相当于：

```
W0 = W1 + W2;
// 同时更新 NZCV
```

例如：

```asm
MOV W1, #10
MOV W2, #20
ADDS W0, W1, W2
```

结果：

```
W0 = 30
```

同时更新标志位。

#### **为什么需要 ADDS / SUBS？**

因为编译器经常利用它们完成运算之后的条件判断。

例如 C++：

```
int is_zero(int a, int b) {
    return a - b == 0;
}
```

可能编译成：

```asm
SUBS W8, W0, W1
CSET W0, EQ
RET
```

逐条分析：

**第一条：**

```
SUBS W8, W0, W1
```

计算：

```
W8 = a - b
```

并更新 NZCV。

**第二条：**

```
CSET W0, EQ
```

如果 Z=1，则 W0=1，否则 W0=0。

最终效果：

```
return a == b;
```

### 乘除法指令

#### **一、MUL：乘法**

```
MUL W0, W1, W2
```

含义：

```
W0 = W1 * W2;
```

例如：

```
MOV W1, #10
MOV W2, #20
MUL W0, W1, W2
```

执行结果：

```
W0 = 200
```

和 ADD、SUB 一样，MUL 不会更新 NZCV。

##### **2. W 寄存器和 X 寄存器的区别**

```
MUL W0, W1, W2
```

执行32位乘法，结果保留低32位。

```
MUL X0, X1, X2
```

执行64位乘法，结果保留低64位。

这里要特别注意：**MUL 不会自动把完整的双倍宽度乘积保存下来。**

例如两个32位数相乘，数学上的完整结果最多需要64位，但：

```
MUL W0, W1, W2
```

只保留低32位。

如果需要完整的64位乘积，可以使用：

```
SMULL X0, W1, W2
```

这是有符号32×32位乘法，得到64位结果。

```asm
UMULL X0, W1, W2
```

这是无符号32×32位乘法，得到64位结果。

例如：

```
W1 = 0xFFFFFFFF
W2 = 2
```

按无符号数理解：

```
UMULL X0, W1, W2
```

得到：

```
X0 = 0x00000001FFFFFFFE
```

按有符号数理解，`W1` 是 -1：

```
SMULL X0, W1, W2
```

得到：

```
X0 = 0xFFFFFFFFFFFFFFFE
```

如果源码涉及较大整数乘法，或者编译器需要保留完整乘积，就可能出现这些指令。

#### **二、SDIV：有符号除法**

##### **1. 基本用法**

```asm
SDIV W0, W1, W2
```

含义：

```
W0 = (int32_t)W1 / (int32_t)W2;
```

例如：

```asm
MOV W1, #20
MOV W2, #5
SDIV W0, W1, W2
```

结果：

```
W0 = 4
```

再看负数：

```asm
MOV W1, #-20
MOV W2, #5
SDIV W0, W1, W2
```

结果：

```
W0 = -4
```

再看：

```asm
MOV W1, #20
MOV W2, #-5
SDIV W0, W1, W2
```

结果：

```
W0 = -4
```

ARM64 的整数除法向零截断，而不是向下取整。

例如：[ -7 / 2 = -3 ] 不是 -4。对应 C/C++ 的整数除法规则。

##### **2. SDIV 的特殊情况**

有两个特殊情况值得记住：

- 除数为0：ARM64 的 SDIV 不会产生普通的除零异常，而是将结果写为0。
- 最小有符号整数除以 -1：结果无法在相同位宽内表示，ARM64 指令保留位宽结果，即最小有符号整数本身。

#### **三、UDIV：无符号除法**



```asm
UDIV W0, W1, W2
含义：
W0 = (uint32_t)W1 / (uint32_t)W2;
```

例如：

```asm
MOV W1, #20
MOV W2, #5
UDIV W0, W1, W2
```

结果也是：

```
W0 = 4
```

正数情况下，SDIV 和 UDIV 看起来没有区别。

但负数或最高位为1的数据就完全不同了。

假设：

```
W1 = 0xFFFFFFFF
W2 = 2
```

同一组二进制数据，可以有两种解释。

**有符号解释（int32_t）**

```asm
0xFFFFFFFF = -1
SDIV W0, W1, W2  ;得到-1
```

**无符号解释（uint32_t）**

```asm
0xFFFFFFFF = 4294967295
UDIV W0, W1, W2   ;得到2147483647
```

这里要千万小心！

在分析时，尤其需要关注：

- 乘法结果是否只保留低32位。
- 是否使用有符号或无符号运算。
- 是否存在整数溢出或截断。
- 除法是否被编译器转换成乘法和移位。

### **位运算指令（AND、ORR、EOR、BIC）**

#### **1. AND：按位与**

规则：**只有两个位都为1，结果才为1。**

例如：

```
  00001010   (10)
& 00001100   (12)
-----------
  00001000   (8)
```

ARM64：

```
AND W0, W1, W2
```

对应 C++：

```
W0 = W1 & W2;
```

AND 的典型用途：提取某些位**

例如：

```
uint32_t flags = 0b11010110;
uint32_t result = flags & 0b00001111;
```

结果：

```
  11010110
& 00001111
----------
  00000110
```

也就是只保留低4位。

在逆向中看到：

```
AND W8, W0, #0xFF
```

通常可以初步判断为：

```
W8 = W0 & 0xFF;
```

作用是保留最低8位，清除其余位。

#### **2. ORR：按位或**

规则：**只要两个位中有一个为1，结果就是1。**

例如：

```
  00001010   (10)
| 00001100   (12)
-----------
  00001110   (14)
```

ARM64：

```
ORR W0, W1, W2
```

对应：

```
W0 = W1 | W2;
```

 **ORR 的典型用途：设置某些位**

例如：

```
uint32_t flags = 0b10000001;
flags |= 0b00000100;
```

结果：

```
  10000001
| 00000100
----------
  10000101
```

原来的其他位不变，指定位置被设置为1。

在逆向中，看到：

```
ORR W8, W0, #0x04
```

通常表示把第2位设置为1（从最低位开始编号）。

#### **3. EOR：按位异或**

这是非常重要的指令。

规则：**两个位不同，结果为1；相同，结果为0。**

例如：

```
  00001010   (10)
^ 00001100   (12)
-----------
  00000110   (6)
```

ARM64：

```
EOR W0, W1, W2
```

对应 C++：

```
W0 = W1 ^ W2;
```

 **EOR 的三个重要性质**

**性质一：自己异或自己，结果为0。**

```
EOR W0, W1, W1
```

结果：

```
W0 = 0
```

**性质二：任何数异或0，结果不变。**

**性质三：异或同一个数两次，可以恢复原值。**

举个简单例子：

```c
uint8_t data = 0x53;
uint8_t key  = 0x12;

uint8_t encrypted = data ^ key;
uint8_t decrypted = encrypted ^ key;
```

结果：

```
原始数据：0x53
密钥：    0x12
加密结果：0x41
解密结果：0x53
```

所以以后在 IDA 中看到大量 `EOR`，尤其是循环中反复出现时，要考虑是否存在异或加密、密钥混合或哈希计算。

#### **4. BIC：按位清除**

BIC 是 Bit Clear 的缩写。

```
BIC W0, W1, W2
```

含义：

```
W0 = W1 & ~W2;
```

也就是：

先把第二个操作数按位取反，再和第一个操作数进行 AND。作用是清除第二个操作数指定的位。

例如：

```
W1 = 11010110
W2 = 00001100
```

先对 W2 取反：

```
~W2 = 11110011
```

再 AND：

```
  11010110
& 11110011
----------
  11010010
```

因此：

```
W0 = 11010010
```

**BIC 的典型用途：清除某些标志位**

C++：

```
flags &= ~0x04;
```

汇编可能表现为：

```
BIC W8, W0, #4
```

它会清除第2位，而不影响其他位。

举一个小例子

```asm
AND W8, W0, #2
CMP W8, #0
CSET W0, NE
RET
```

逐条理解：

1. `AND`：提取 WRITE 标志位。
2. `CMP`：判断提取结果是否为0。
3. `CSET NE`：非零返回1，否则返回0。

这类代码在 Android Native 权限检查、状态判断、协议解析中都很常见。

#### 位运算与nzcv

AND,ORR这些普通形式不会更新 NZCV。

但你可能遇到：

```
ANDS W0, W1, W2
```

它会执行 AND，并更新 NZCV。

例如：

```
ANDS W8, W0, #0xFF
B.EQ loc_1000
```

这表示：

1. 提取 W0 的最低8位。
2. 更新 NZCV。
3. 如果结果为0，就跳转。

这和之前学过的 `ADDS`、`SUBS` 是同一类思路：带 S 的指令会更新标志位。

### **移位指令与位域操作**

#### **一、什么是移位？**

移位就是让一个**二进制数**的所有位向左或向右移动指定的位置。

假设有一个8位数：

```
00001101
```

它的十进制值是13。

如果左移一位：

```
00011010
```

结果是26。

如果右移一位：

```
00000110
```

结果是6。

对于不考虑溢出的情况：

- 左移一位，通常相当于乘以2。
- 右移一位，通常相当于除以2。

但这里有一个非常重要的问题：

**右移时，左侧空出来的位置应该补0，还是补原来的符号位？**

这就引出了 LSR 和 ASR 的区别。(记得回顾一下之前的LDRSB哦！)

#### **二、LSL：逻辑左移**

```
LSL W0, W1, #2
```

含义：

```
W0 = W1 << 2;
```

也就是把 W1 的二进制数据向左移动2位。

假设：

```
W1 = 00001101
```

为了便于观察，暂时只展示低8位：

```
原始：00001101
左移：00110100
```

结果：

```
0x34 = 52
```

对应：`13x2**2=52`

假设：

```
W1 = 0x80000001
```

执行：

```
LSL W0, W1, #1
```

结果：

```
W0 = 0x00000002
```

为什么？

因为32位左移时：

1. 所有位向左移动1位。
2. 最左边溢出的位被丢弃。
3. 最右边空出来的位置补0。

注意：**LSL 不会保留溢出位。**

因此，左移不能简单地理解成数学上的无限精度乘法。

#### **三、LSR：逻辑右移**

```asm
LSR W0, W1, #2
```

含义：

```
W0 = (uint32_t)W1 >> 2;
```

LSR 的核心特点：

**右移时，左侧空出来的位置始终补0。**

例如：

```
W1 = 11010000
```

右移2位：

```
原始：11010000
右移：00110100
```

结果：

```
00110100
```

注意左侧补的是0，而不是原来的最高位1。

假设：

```
W1 = 0xFFFFFFFF
```

执行：

```
LSR W0, W1, #1
```

结果：

```
W0 = 0x7FFFFFFF
```

为什么？

原始32位：

```
11111111 11111111 11111111 11111111
```

右移一位：

```
01111111 11111111 11111111 11111111
```

最高位补0。

所以结果是：2147483647 

#### **四、ASR：算术右移**

```asm
ASR W0, W1, #2
```

含义：

**将 W1 作为有符号整数进行算术右移，左侧空位使用原来的符号位填充。**

规则：

- 最高位是0：左侧补0。
- 最高位是1：左侧补1。

例如：

```
W1 = 11110000
```

算术右移2位：

```
原始：11110000
右移：11111100
```

左边补1，因为原始最高位是1。

#### 五、**循环右移：ROR**

概念：普通右移会丢弃移出去的位，而循环右移会把移出去的位从另一端补回来。相当于饶了一圈。

```
原始数据：
10000001

逻辑右移一位：
01000000

循环右移一位：
11000000
```

指令如下ROR

```
MOV W0, #0x80000001
ROR W1, W0, #1
```

结果：

```
W1 = 0xC0000000
```

此外，还有寄存器指定移位量的 `RORV`：

```
RORV W0, W1, W2
```

它使用 W2 中的值作为循环右移位数。

#### 六、循环左移和算数左移

需要强调的是！！！ARM里并没有专门用来循环左移的指令！！！

对于 32 位数据：
$$
ROL(x,n)=ROR(x,32-n) 
$$
例如，循环左移 4 位等价于循环右移 28 位：

```asm
ROR W0, W1, #28
```

对于算数左移来说，ARM里没有专门的指令

你已经知道：

- `LSL`：逻辑左移
- `LSR`：逻辑右移
- `ASR`：算术右移

为什么没有 `ASL`？

因为对于固定宽度的二进制数据，**逻辑左移和算术左移的位操作完全相同**。

因为最左边那个符号位会被挤掉，符号没了作用，右边补零就行。

例如：

```
原始数据：10000001

左移一位：00000010
```

不管把原始数据解释成有符号数还是无符号数，硬件执行的左移操作都是一样的。

所以 ARM64 只需要 `LSL`，不需要另外定义 `ASL`。

#### 七、移位的作用

编译器通常会进行乘除法优化

```cpp
uint32_t calculate(uint32_t x) {
    return x * 8;
}
上面这段代码通常被翻译为
LSL W0, W0, #3   ;也就是x*(2**3)
RET
```

另外根据寄存器视图的不同，也有以下两种分类

| 寄存器 | 位宽 | 合法移位量 |
| ------ | ---- | ---------- |
| W0–W30 | 32位 | 0～31      |
| X0–X30 | 64位 | 0～63      |

最后再总结一下

| 操作     | ARM64 指令 | 说明               |
| -------- | ---------- | ------------------ |
| 逻辑左移 | `LSL`      | 右侧补0            |
| 逻辑右移 | `LSR`      | 左侧补0            |
| 算术右移 | `ASR`      | 左侧补符号位1      |
| 循环右移 | `ROR`      | 移出的位回到另一端 |
| 循环左移 | 无独立指令 | 可用 `ROR` 实现    |

### **位域操作：UBFX、SBFX、BFI**

这些东西有什么作用？

例如，一个 32 位整数可能同时存储了：

- bit 0：是否登录
- bit 1：是否管理员
- bit 2：是否启用
- bit 3～7：用户类型
- bit 8～15：权限等级

程序不一定用多个变量存储这些信息，而是把它们压缩到一个整数中。

我们要学会从汇编反推出这些字段。

#### **UBFX：无符号位域提取**

`UBFX` 全称 Unsigned Bit Field Extract。

它的作用是：

**从源寄存器中提取指定范围的 bit，并将结果零扩展到目标寄存器。**

语法：

```
UBFX Wd, Wn, #lsb, #width
```

参数含义：

- `Wd`：结果寄存器
- `Wn`：源寄存器
- `lsb`：从哪一位开始提取
- `width`：提取多少位

例如：

```asm
MOV W1, #0xAD
UBFX W0, W1, #2, #3
```

我们来手算。

原始数据：

```
W1 = 0xAD

二进制：
10101101
```

从 bit 2 开始，提取 3 位：

```
bit编号： 7 6 5 4 3 2 1 0
原始数据：1 0 1 0 1 1 0 1
                 └——──┘
                  取3位
```

提取到的内容是：

```
011
```

所以：

```
W0 = 0x00000003
```

你可以把它理解为下面的 C++：

```
uint32_t result = (value >> 2) & 0x7;
```

这里的 `0x7` 是三位掩码：

```
0x7 = 00000111
```

**逆向识别技巧：**

如果你在 IDA 中看到：

```
UBFX W8, W0, #5, #3
```

就可以先尝试还原成：

```
result = (value >> 5) & 0x7;
```

也就是提取 bit 5、6、7。

#### **SBFX：有符号位域提取**

`SBFX` 全称 Signed Bit Field Extract。

它与 UBFX 的区别在于：

**提取完成后，按照提取结果的最高位进行`符号扩展。`**

语法：

```
SBFX Wd, Wn, #lsb, #width
```

举个例子：

```
MOV W1, #0x70
SBFX W0, W1, #4, #4
```

原始数据：

```
W1 = 0x70

01110000
```

从 bit 4 开始，提取 4 位：

```
0111
```

最高位是 0，因此符号扩展后：

```
W0 = 0x00000007
```

再看一个更有代表性的例子：

```
MOV W1, #0xF0
SBFX W0, W1, #4, #4
```

原始数据：

```
11110000
```

提取 bit 4～7：

```
1111
```

这是一个 4 位有符号数。

4 位补码中：

```
1111 = -1
```

因此符号扩展到 32 位：

```
W0 = 0xFFFFFFFF
```

如果换成 UBFX：

```
UBFX W0, W1, #4, #4
```

结果就是：

```
W0 = 0x0000000F
```

对比一下：

| 指令 | 提取结果 | 扩展方式 | 最终结果     |
| ---- | -------- | -------- | ------------ |
| UBFX | `1111`   | 零扩展   | `0x0000000F` |
| SBFX | `1111`   | 符号扩展 | `0xFFFFFFFF` |

这与前面学过的 `LDRB` 和 `LDRSB` 很相似：

- UBFX 类似无符号提取。
- SBFX 类似有符号提取。

#### **BFI：位域插入**

前面两个指令都是提取 bit。

现在反过来：我们想修改一个整数中的某几位，但保留其他位。

这就是 `BFI`（Bit Field Insert）。

语法：

```
BFI Wd, Wn, #lsb, #width
```

含义：

- 从 Wn 的低位开始取 `width` 位。
- 把它们插入 Wd 中，从 `lsb` 位置开始。
- Wd 中其他位保持不变。

例如：

```
MOV W0, #0xF0
MOV W1, #0x05
BFI W0, W1, #2, #3
```

先看原始值：

```
W0 = 0xF0 = 11110000
W1 = 0x05 = 00000101
```

从 W1 的最低位取 3 位：

```
101
```

把这三位插入 W0 的 bit 2～4（注意bit位从0开始算）：

```
原始 W0：11110000
插入字段：  101
```

结果：

```
W0 = 11110100
   = 0xF4
```

对应 C++ 思路：

```
value = (value & ~(0x7u << 2))
      | ((new_value & 0x7u) << 2);
```

这里：

- `0x7u`：三位掩码。
- `~(0x7u << 2)`：清除原来 bit 2～4。
- `new_value & 0x7u`：只保留新数据的低三位。
- 左移两位后与原数据合并。

除了上面三个，还有另外三个指令。**BFM / UBFM / SBFM**，这三个更底层一点，在这里简单讲一下，后面深入。

你可能会好奇：为什么 ARM64 有 `UBFX`、`SBFX`、`BFI`，又有 `UBFM`、`SBFM`、`BFM`？

原因是：**它们底层属于同一类位域操作指令，只是汇编器根据不同参数，把常见用法显示成了更容易理解的别名。**

| 指令   | 核心功能                       |
| ------ | ------------------------------ |
| `UBFM` | 位域操作，结果零扩展           |
| `SBFM` | 位域操作，结果符号扩展         |
| `BFM`  | 位域操作，保留目标寄存器其他位 |

这三种指令都可以通过不同的位范围参数实现多种操作。

#### **UBFM 为什么能实现 LSR 和 UBFX？**

```
LSR W0, W1, #4
```

它的底层别名对应：

```
UBFM W0, W1, #4, #31
```

这里：

- `immr = 4`
- `imms = 31`

对于 32 位寄存器，`UBFM` 可以理解为：从源寄存器的 bit 4 开始取位，进行右移式提取，超出有效范围的高位补 0。

结果就是逻辑右移 4 位。

再看：

```
UBFX W0, W1, #4, #8
```

对应的底层指令：

```
UBFM W0, W1, #4, #11
```

为什么最后一个参数是 11？

因为：
$$
imms=lsb+width-1 
$$
代入： 4+8-1=11 

#### **SBFM 为什么能实现 ASR 和 SBFX？**

同理：

```
ASR W0, W1, #4
```

底层对应：

```
SBFM W0, W1, #4, #31
```

而：

```
SBFX W0, W1, #4, #8
```

对应：

```
SBFM W0, W1, #4, #11
```

两者的区别在于提取后的高位处理：

- UBFM：高位补 0。
- SBFM：高位补符号位。

#### **BFM 与 BFI**

例如：

```
BFI W0, W1, #4, #8
```

对应：

```
BFM W0, W1, #28, #7
```

这里的 `immr` 不是直接使用 lsb，而是：
$$
immr=(-lsb)\bmod 32
$$
所以： (-4) % 32=28 

`imms = width - 1 = 7`。

这就是为什么你可能在 IDA 中看到 `BFM`，但它实际完成的是类似 `BFI` 的操作。

#### 总结BFM的关系。

下面是对于32位来说的，64位是另一种公式。

| 你熟悉的指令             | 底层别名对应                            |
| ------------------------ | --------------------------------------- |
| `LSR Wd,Wn,#n`           | `UBFM Wd,Wn,#n,#31`                     |
| `ASR Wd,Wn,#n`           | `SBFM Wd,Wn,#n,#31`                     |
| `UBFX Wd,Wn,#lsb,#width` | `UBFM Wd,Wn,#lsb,#(lsb+width-1)`        |
| `SBFX Wd,Wn,#lsb,#width` | `SBFM Wd,Wn,#lsb,#(lsb+width-1)`        |
| `BFI Wd,Wn,#lsb,#width`  | `BFM Wd,Wn,#((-lsb) mod 32),#(width-1)` |

64位如下

| 你熟悉的指令（64 位）       | 底层别名对应                               |
| :-------------------------- | :----------------------------------------- |
| `LSR Xd, Xn, #n`            | `UBFM Xd, Xn, #n, #63`                     |
| `ASR Xd, Xn, #n`            | `SBFM Xd, Xn, #n, #63`                     |
| `UBFX Xd, Xn, #lsb, #width` | `UBFM Xd, Xn, #lsb, #(lsb+width-1)`        |
| `SBFX Xd, Xn, #lsb, #width` | `SBFM Xd, Xn, #lsb, #(lsb+width-1)`        |
| `BFI Xd, Xn, #lsb, #width`  | `BFM Xd, Xn, #((-lsb) mod 64), #(width-1)` |

### **深入理解 UBFM：位旋转与位掩码**

对于 32 位寄存器：

```
UBFM Wd, Wn, #immr, #imms
```

可以先按照下面三个步骤理解：

1. 将源寄存器循环右移 `immr` 位。
2. 保留结果中 bit 0 到 bit `imms`。
3. 其余高位补 0。

这个模型可以帮助你理解常见的 `LSR` 和 `UBFX` 别名。

注意：这是便于理解 UBFM 常见非环绕情况的模型。完整指令还涉及位域环绕和特殊掩码行为，我们后面再展开。

```
UBFM W0, W1, #4, #31
```

假设：

```
W1 = 0x000000D0
```

二进制：

```
00000000 00000000 00000000 11010000
```

`immr = 4`，循环右移 4 位：

```
00000000 00000000 00000000 00001101
```

`imms = 31`，保留 bit 0～31，也就是全部 32 位。

最终：

```
W0 = 0x0000000D
```

因此：

```
UBFM W0, W1, #4, #31
```

等价于：

```
LSR W0, W1, #4
```

你可以发现：这里并没有发生额外的截断，因为保留范围就是整个 32 位寄存器。

现在看：

```
UBFM W0, W1, #4, #7
```

假设：

```
W1 = 0x000000D0
```

二进制：

```
11010000
```

第一步：循环右移 4 位：

```
00001101
```

第二步：只保留 bit 0～7。

因为 `imms = 7`，所以保留低 8 位：

```
00001101
```

最终：

```
W0 = 0x0000000D
```

它对应：

```
UBFX W0, W1, #4, #4
```

因为：
$$
imms=lsb+width-1
$$
4+4-1=7

所以：

```asm
UBFM W0, W1, #4, #7
```

就是从原始 W1 的 bit 4 开始提取 4 位。

为什么会有位域环绕这个东西？这是理解 UBFM 的关键。

假设：

```
UBFM W0, W1, #28, #7
```

这里：

- `immr = 28`
- `imms = 7`

如果按照刚才的模型：

1. 循环右移 28 位。
2. 保留低 8 位。

这个例子对应的提取字段会跨越原始寄存器的边界。

也就是说，不能只把 UBFM 当作普通的右移再掩码；当 `immr` 和 `imms` 的关系变化时，它还可以实现环绕提取。

这也是 ARM64 位域指令非常灵活的原因。

#### 总结

串联一下之前的知识

咱们已经接触过：

- `LSL`
- `LSR`
- `ASR`
- `ROR`
- `UBFX`
- `SBFX`
- `BFI`

这些指令并不是互不相关的独立操作。

ARM64 将很多位域操作统一放在了同一类底层编码中，再由汇编器选择更容易阅读的别名显示出来。

例如：

```
LSR W0, W1, #4
```

可能显示为：

```
UBFM W0, W1, #4, #31
```

而：

```
UBFX W0, W1, #4, #8
```

可能显示为：

```
UBFM W0, W1, #4, #11
```

### **SBFM 与 BFM：符号扩展和位域插入**

#### 按位提取

先回忆 `UBFM`：

```
UBFM W0, W1, #immr, #imms
```

它可以实现逻辑右移、无符号位域提取，结果高位补 0。

而 `SBFM`：

```
SBFM W0, W1, #immr, #imms
```

核心区别是：**提取结果的高位使用符号位扩展，而不是零扩展。**

常见的两个别名：

| 常见指令                 | 底层形式                         |
| ------------------------ | -------------------------------- |
| `ASR W0,W1,#n`           | `SBFM W0,W1,#n,#31`              |
| `SBFX W0,W1,#lsb,#width` | `SBFM W0,W1,#lsb,#(lsb+width-1)` |

例如：

```
SBFM W0, W1, #4, #7
```

对应：

```
SBFX W0, W1, #4, #4
```

假设：

```
W1 = 0x000000F0
```

二进制低 8 位：

```
11110000
```

从 bit 4 开始提取 4 位：

```
1111
```

4 位补码的 `1111` 表示 -1。

符号扩展到 32 位：

```
11111111 11111111 11111111 11111111
```

所以：

```
W0 = 0xFFFFFFFF
```

#### 再来看看算数右移

```
SBFM W0, W1, #4, #31
```

因为 `imms=31`，它对应：

```
ASR W0, W1, #4
```

假设：

```
W1 = 0xFFFFFFF0
```

按 32 位有符号数解释：

```
W1 = -16
```

算术右移 4 位：

```
W0 = 0xFFFFFFFF
```

即 -1。

这里需要区分两种情况：

- `SBFM #4,#7`：提取 4 位并符号扩展。
- `SBFM #4,#31`：算术右移 4 位。

判断它们的关键是 `imms`。

#### BFM

现在看 `BFM`：

```
BFM Wd, Wn, #immr, #imms
```

它和 UBFM、SBFM 最大的不同是：

**BFM 不会简单地把结果高位补 0 或补符号位，而是把操作结果与原目标寄存器的其他位合并。**

常见别名是：

```
BFI W0, W1, #lsb, #width
```

对应底层： 

```
BFM W0, W1, #((-lsb) mod 32), #(width-1)
```

注意这里的 `immr` 与 BFI 的 `lsb` 不是同一个数。

BFI 的底层形式如下

```
MOV W0, #0xF0
MOV W1, #0x05
BFI W0, W1, #2, #3
```

它对应：

```
BFM W0, W1, #30, #2
```

#### BFXIL

除了 `BFI`，你还可能遇到 `BFXIL`（Bitfield Extract and Insert Low）。

它的作用是：

**从源寄存器提取一段位域，放到目标寄存器对应位置，目标寄存器其他位保留。**

例如：

```
BFXIL W0, W1, #4, #4
从 W1 的第 4 位开始，取出 4 位，零扩展后放到 W0 的最低 4 位，W0 其余位保留。
```

含义：

- 从 W1 的 bit 4 开始提取 4 位。
- 放到 W0 的 bit 0～3。
- W0 的其他位保持不变。

假设：

```
W0 = 0x12345678
W1 = 0x000000D0
```

W1 的 bit 4～7 是：

```
1101
```

插入 W0 的 bit 0～3：

```
W0 原始低位：1000
新字段：     1101
```

最终：

```
W0 = 0x1234567D
```

对应的底层形式：

```
BFM W0, W1, #4, #7
```

注意它和 BFI 的区别：

| 指令                | 源寄存器取哪些位 | 目标寄存器写入位置 |
| ------------------- | ---------------- | ------------------ |
| `BFI W0,W1,#4,#4`   | W1 的 bit 0～3   | W0 的 bit 4～7     |
| `BFXIL W0,W1,#4,#4` | W1 的 bit 4～7   | W0 的 bit 0～3     |

#### BFC

| 底层指令 | 常见别名        | 主要用途             |
| -------- | --------------- | -------------------- |
| UBFM     | LSR、UBFX、LSL  | 无符号提取、逻辑移位 |
| SBFM     | ASR、SBFX       | 有符号提取、算术右移 |
| BFM      | BFI、BFXIL、BFC | 位域插入、替换、清除 |

另外还有一个你可能遇到的别名：

```
BFC W0, #4, #3
```

它表示清除 W0 的 bit 4～6，其他位保留。

可以理解为：

```
W0 &= ~(0x7u << 4);
```

底层可以表示为：

```
BFM W0, WZR, #28, #6
```

这里 WZR 是零寄存器，因此插入的字段全为 0。

#### 小练习

最后做个小练习吧。这个练习里我们可以看到凡是要对一个寄存器的一段位插入操作的，都先删除这段也就是&一个1111啥的置零。

```cpp
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
    return (value ^ 0x08) - 0x08;  //扩展到32位。
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
```

对应的每个反编译函数

```asm
.text:0000000000004700 ; uint32_t __fastcall extract_field(uint32_t x)
.text:0000000000004700                 EXPORT extract_field
.text:0000000000004700 extract_field                           ; DATA XREF: LOAD:0000000000000330↑o
.text:0000000000004700 x = X0                                  ; uint32_t
.text:0000000000004700 ; __unwind {
.text:0000000000004700                 UBFX            W0, W0, #8, #4  ;偏移8位提取4个
.text:0000000000004704                 RET
.text:0000000000004704 ; } // starts at 4700
```

```asm
.text:0000000000004708 ; int32_t __fastcall extract_signed(uint32_t x)
.text:0000000000004708                 EXPORT extract_signed
.text:0000000000004708 extract_signed                          ; DATA XREF: LOAD:0000000000000348↑o
.text:0000000000004708 x = X0                                  ; uint32_t
.text:0000000000004708 ; __unwind {
.text:0000000000004708                 SBFX            W0, W0, #4, #4 ；有符号的偏移4提取4，符号扩展到32位
.text:000000000000470C                 RET
.text:000000000000470C ; } // starts at 4708
```

```asm
.text:0000000000004710 ; uint32_t insert_field(uint32_t x, uint32_t value)
.text:0000000000004710                 EXPORT insert_field
.text:0000000000004710 insert_field                            ; DATA XREF: LOAD:0000000000000360↑o
.text:0000000000004710 value = X1                              ; uint32_t
.text:0000000000004710 ; __unwind {
.text:0000000000004710                 BFI             W0, W1, #0x10, #4  ;提取w1的低4位然后插到w0的偏移10处。
.text:0000000000004714 x = X0                                  ; uint32_t
.text:0000000000004714                 RET
.text:0000000000004714 ; } // starts at 4710
```

清除直接用的and我去

```asm
.text:0000000000004718 ; uint32_t __fastcall clear_field(uint32_t x)
.text:0000000000004718                 EXPORT clear_field
.text:0000000000004718 clear_field                             ; DATA XREF: LOAD:0000000000000378↑o
.text:0000000000004718 x = X0                                  ; uint32_t
.text:0000000000004718 ; __unwind {
.text:0000000000004718                 AND             W0, W0, #0xFFFFFF8F
.text:000000000000471C                 RET
.text:000000000000471C ; } // starts at 4718
```

```asm
.text:0000000000004720 ; uint32_t __fastcall copy_field(uint32_t x)
.text:0000000000004720                 EXPORT copy_field
.text:0000000000004720 copy_field                              ; DATA XREF: LOAD:0000000000000390↑o
.text:0000000000004720 x = X0                                  ; uint32_t
.text:0000000000004720 ; __unwind {
.text:0000000000004720                 LSR             W8, W0, #8  ;逻辑右移8位然后插入。
.text:0000000000004724                 BFI             W0, W8, #0x10, #4
.text:0000000000004728 x = X0                                  ; uint32_t
.text:0000000000004728                 RET
.text:0000000000004728 ; } // starts at 4720
```

