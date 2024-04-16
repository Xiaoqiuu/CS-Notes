--------
# C++要了解的竞赛知识
[TOC]

## 拓展知识

### 1. 万能头文件 <bits/stdc++.h>
```cpp
#include <bits/stdc++.h>
int main()
{
    //write code here
    return 0;
}
```

它是C++支持的一个几乎万能的头文件，几乎包含所有的可用到的C++库函数。以后写代码就可以直接引用这一个头文件了，不需要写一大堆vector,string,map,stack......

万能头文件的优点：
* 在竞赛中节省时间
* 减少了编写所有必要头文件的工作量
* 对于使用的每个函数，不用记住GNU C++的所有STL

万能头文件的缺点：
* 不属于GNU C++库的标准头文件，在部分情况下可能会失败
* 使用它将包含许多不必要的东西，并增加编译时间、内存占用高
* 这个头文件不是C++标准的一部分，因此是不可移植的，应该避免
* 编译器每次编译翻译单元时都必须实际读取和分析每个包含的头文件

最后总结：比赛神器，尽量少用

### 2. 取消同步流

#### 2.1 
`ios::sync_with_stdio()`这个函数是一个「是否兼容 stdio」的开关，C++ 为了兼容 C，保证程序在使用了 printf 和 std::cout 的时候不发生混乱，将输出流绑到了一起。同步的输出流是线程安全的。
> 这其实是 C++ 为了兼容而采取的保守措施，也是使 cin/cout 速度较慢的主要原因。我们可以在进行 IO 操作之前将 stdio 解除绑定，但是在这样做之后要注意不能同时使用 std::cin 和 scanf，也不能同时使用 std::cout 和 printf，但是可以同时使用 std::cin 和 printf，也可以同时使用 scanf 和 std::cout。
```cpp
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//注意别忘记打上ios
```

通过取消同步流，你可以独立地操作C++标准输入输出流和C标准输入输出库，它们不再共享同一个缓冲区，各自拥有独立的缓冲区。
由于cin和cout需要自动判断变量类型等内部原因，读写效率比scanf和printf更低，数据量较大时，可能会导致程序运行超时。因此可以通过取消同步流来加速cin和cout，加速后效率相差无几
#### 2.2 tie
`tie` 是将两个 stream 绑定的函数，空参数的话返回当前的输出流指针。

在默认的情况下 `std::cin` 绑定的是 `std::cout`，每次执行 `<<` 操作符的时候都要调用 `flush()` 来清理 stream buffer，这样会增加 IO 负担。可以通过 `std::cin.tie(0)`（0 表示 NULL）来解除 `std::cin` 与 `std::cout` 的绑定，进一步加快执行效率。

但需要注意的是，在解除了 `std::cin` 和 `std::cout` 的绑定后，程序中必须手动 flush 才能确保每次 `std::cout` 展现的内容可以在 `std::cin` 前出现。这是因为 `std::cout` 被 buffer 为默认设置。 

### 3. typedef

使用`typedef`可以为现有的数据类型换一个“花名”。

```cpp{.line-numbers}
typedef int Qiubaibai;
Qiubaibai s = 10;
```

在上面示例代码中，使用`typedef`将`int`改名为`Qiubaibai`。

在定义结构体中，使用`typedef`将`struct`类型名称换掉。在这里，我把`struct`换名为`Qiubaibai`，那么后续使用(比如新建一个结构体)直接引用Qiubaibai就好，不用再传呼struct了。

```cpp{.line-numbers}
typedef struct{
    int id;
    string name;
    int date;
} Qiubaibai;

int main(){
    Qiubaibai qiubaibai;
    
    qiubaibai.id = 10010;
    qiubaibai.name = "xiaoqiuu";
    qiubaibai.date = "225";
}
```

### 4. getline()

> getline()跟C语言中的gets差不多，都是获取一行字符串。

```cpp
cin.getline(cString, 10000); //gets(cString)
```

`cin.getline()`第一个参数应该是`char*`类型。

```cpp{.line-numbers}
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    getline(cin, line);
    cout << line << endl;
}
```
### 5. 字符串与整型之间的转换

#### 5.1 字符串转整数

使用`stoi`函数可以将字符串转换为int类型。但是，只是转换成了int类型，它无法处理`long long`类型变量。



## 值得思考的问题

### 1. C语言和C++的区别是什么？

从语言特性方面来讲，C语言是面向过程的语言，而C++是面向对象的语言。

C操控一切过程和细节。

C++则是每个数据对象都有自己的动作。

### 2. OO(Object-oriented)思想————面向对象的编程是什么意思?

OO思想主要有以下特点：
- **封装**: 把对象的属性和方法结合成一个独立的系统单位，并尽可能地隐藏对象的内部细节。
- **抽象**: 对具体问题进行概括的过程。
- **继承**: 子类对象拥有与基类对象相同的全部属性和方法。
- **多态**: 在基类中定义的属性和行为被子类继承后，可以具有不同的数据类型或者表现行为等特性。