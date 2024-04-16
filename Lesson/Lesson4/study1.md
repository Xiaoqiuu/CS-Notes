--------


[TOC]
# 最值查找
## 1. min 和 max 函数
`min`和`max`是最常用的取值操作。min传出最小值，max传出最大值。注意，正常是只能传入两个数，如果你想传入更多的数，那么你应该考虑使用数组。
下面就是一个使用例子：
```cpp
max(1, 9)//max(一个数, 另一个数)
min({1, 55, 6543, 23, 9})
```
时间复杂度为O(1),传入参数为数组时的时间复杂度为O(n)，n为数组大小


## 2. min_element 和 max_element
`min_element(st, ed)`返回地址[st, ed)最小值的那个地址（迭代器），传入参数为两个地址或迭代器。
`max_element(st, ed)`返回地址[st, ed)最大值的那个地址（迭代器），传入参数为两个地址或迭代器。

时间复杂度为O(n)，n为数组大小（由传入的参数决定）
```cpp
cout << *max_element(v1.begin(), v1.end()) << endl;
```

## 3. nth_element
使用`nth_element`时，常见的场景是当你不需要对整个序列进行排序，而只需要找到某个特定位置上的元素时。例如，你可以使用`nth_element`来找到中位数。
```cpp{.line-numbers}
vector<int> v ={5, 1, 3, 7, 10, 22, 32};

//输出最大的元素 通过*进行解引用，即通过地址(迭代器)获得值
nth_element(v.begin(), v.begin() + 3, v.end());
//这里v[3]的位置将会位于排序后的位置，其他的任意
for(auto &i : v)cout << i << ' ';
```

# 二分查找

## 1. 二分查找的前提

库函数**只能对数组**进行二分查找。
对一个数组进行二分查找的前提是这个数组的元素是**单调的**，一般为单调不减，如果是单调不增的话，就需要改一下比较函数了（跟sort函数用法差不多？）
```c
[1, 3, 3, 5 , 6, 77] //这是单调的
[1, 22, 12, 333, 26] //这不是单调的
[10, 9, 8, 8, 7, 2]  //这是单调的
```

## 2. binary_search函数

`binary_search`函数是c++标准库中的一个算法函数，用于在已排序的序列（例如数组或者容器(一般是vector)）中查找特定元素，它通过二分查找算法来确定序列中**是否存在**目标元素。函数返回一个**bool值**，并表示目标元素是否存在于序列中。                 
如果需要获取找到的元素的位置，可以使用std::lower_bound函数或者std::upper_bound函数。

```cpp{.line-numbers}
vector<int> n = {1, 3, 5, 7, 9};

int target = 5;

//使用 binary_search 查找目标元素

bool found = binary_search(n.begin(), n.end(), target);

if (found)
{
    cout << "Target element " << target << "found." << "\n";
}
else
{
    cout << "Target element " << target << "not found." << "\n";
}
```
## 3. lower_bound 和 upper_bound
> *前提*:数组必须为非降序

如果要在非升序的数组中使用，可以通过修改比较函数实现（方法与sort自定义函数比较类似）。
```cpp
lower_bound(st, ed, x)//返回地址[st ,ed) 中第一个大于等于x的元素的地址。
upper_bound(st, ed, x)//返回地址[st ,ed) 中第一个大于x的元素的地址。
```
如果不存在则返回最后一个元素的下一个位置，在vector中即end()。

```cpp{.line-numbers}
vector<int> v = {5, 1, 7, 3, 10, 18, 9};
sort(v.begin(), v.end());

for (auto &i : v)cout << i << ' ';
cout << '\n';

//找到数组中第一个大于等于8的元素位置
cout << (lower_bound(v.begin(), v.end(), 8) - v.begin()) << '\n';
```
# 大小写转换

## 1. islower 和 isupper 函数

islower和isuppper是C++标准库中的字符分类函数，用于检查一个字符是否为小写字母或者大写字母。
islower和isupper函数需要包含头文件`<cctype>`，也可以使用万能头文件。
注意，函数返回值是**bool类型**。

```cpp{.line-numbers}
char ch1 = 'A';
char ch2 = 'b';

//使用 islower 函数判断字符是否为小写字母
if (islower(ch1))
{
    cout << ch1 << " is a lowercase letter." << '\n';
}
else
{
    cout << ch1 << " is not a lowercase letter." << '\n';
}

//使用 isupper 函数判断字符是否为大写字母
if (isupper(ch2))
{
    cout << ch2 << " is a uppercase letter." << '\n';
}
else
{
    cout << ch2 << " is not a uppercase letter." << '\n';
}
```

## 2. tolower 和 toupper 函数
`tolower(char ch)`可以将ch转换为小写字母，如果ch不是大写字母则不能进行操作。
toupper()同理。

```cpp{.line-numbers}
char ch1 = 'A';
char ch2 = 'b';

//使用 tolower 函数将字符转换为小写字母
char lowercaseCh1 = tolower(ch1);
cout << "Lowercase of " << ch1 << "is " << lowercaseCh1 << '\n';

//使用 toupper 函数将字符转换为大写字母
char lowercaseCh2 = toupper(ch2);
cour << "Uppercase of " << ch2 << "is " << uppercaseCh2 << '\n';
```

## 3. ASCII码

<img src = "C:\Archive\LanQiao\Lesson\Pictures\0001.png">

</style>

<p align = "center">图3.1 ASCII码表</font></p>

</div class = "center">

'c' - 'a' + 'A' = 'C'

在了解ASCII码后，我们可以通过直接对英文字母进行加减运算计算出其大小写的字符。
在ASCII码表中，大写字母的编码范围是65('A')到90('Z')，而小写字母的编码范围是97('a')到122('z')，根据这个规则，可以使用ASCII码表进行大小写转换。

```cpp{.line-numbers}
char ch = 'A';// 大写字母
char convertedCh;

if (ch >= 'A' && ch <= 'Z')
{
    //大写字母转换为小写字母
    convertedCh = ch + 32；
    cout << "Converted character: " << convertedCh << '\n';
}
else if (ch >= 'a' && ch <= 'z')
{
    convertedCh = ch - 32;
    cout << "Converted character: " << convertedCh << '\n';
}
else
{
    cout << "Invaild character!" << '\n';
}
```
> 设计程序并使用char类型时，注意一下是数字0-9还是字符0-9


# 全排列

## 1. next_permutation()函数
`next_permutation`函数用于生成当前序列的下一个排列。它按照字典序对序列进行重新排列，如果存在下一个排列，则将当前序列更改为下一个排列，并且返回true；如果当前序列已经是最后一个序列，则将序列更改为第一个序列，并且返回false。
```cpp{.line-numbers}
vector<int> nums = {1, 2, 3};

cout << "Initial permutation: ";
for (int num : nums)
{
    cout << num << ' ';
}
cout << '\n';

// 生成下一个排列
while (next_permutation(nums.begin(), nums.end()))
{
    cout << "Next permutation: ";
    for (int num : nums)
    {
        cout << num << ' ';
    }
    cout << '\n';
}
```

# 其它库函数

## 1. memset()

`memset()` 是一个用于设置内存块值的函数。
它的原型定义在`<cstring>`头文件中，函数的声明如下：
```cpp{.line-numbers}
void* memset(void* ptr, int val, size_t num);
//ptr: 指向要填充的内存块的指针
//val：要设置的值，该值以int的形式提供，但函数填充该值的无符号字符转换形式
//num：要被设置为该值的字节数

//memset()函数将ptr指向的内存块的前num个字节设置为value的值。它返回一个指向ptr的指针（返回值一般我们用不上） 
```
- 解释：复制字符 c（一个无符号字符）到参数 str 所指向的字符串的前 n 个字符。
- 作用：是在一段内存块中填充某个给定的值，它是对较大的结构体或数组进行清零操作的一种最快方法
- 头文件：C中`#include <string.h>`，C++中`#include <cstring>`

```cpp
int arr[10];
memset(arr, 0, sizeof(arr));
```
上述示例当中，`memset(arr, 0, sizeof(arr))`将数组`arr`的所有元素设置为0。
需要注意的是，memset()函数对于非字符类型的数组可能会产生未定义行为。
在处理非字符类型的数组时，更好使用C++中的其它方法，如循环遍历来初始化数组。

```cpp{.line-numbers}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[5];
    memset(a, 1, sizeof(a));
    for (int i = 0; i < 5; ++ i)cout << bitset<32>(a[i]) << '\n';
    return 0;
}
```

## 2. swap()
swap(T &a,T &b)函数需要**接收两个参数**：
a：要交换值的第一个变量的引用
b：要交换值的第二个变量的引用
swap()函数通过将第一个变量的值存储到临时变量中，然后将第二个变量的值赋给第一个变量，最后将临时变量的值赋给第二个变量，实现两个变量值的交换。
swap()函数可以用于交换任意类型的变量，包括基本类型（如整数、浮点数等）和自定义类型（如结构体、类对象等）。
```cpp
int a = 20;
int b = 10;
std::swap(a, b);
```

## 3. reverse()

reverse()是一个用于反转容器中元素顺序的函数。
它的原型定义在`<algorithm>`头文件中。

## 拓展知识
### 1. 迭代器

迭代器类似于指针，提供了对象的间接访问，但获取迭代器并不是使用取地址符。如果将指针理解为元素的“地址”，那么迭代器可以理解为元素的“位置”。可以使用迭代器访问某个元素，迭代器也能从一个元素移动到另一个元素。

一个迭代器的范围由一对迭代器表示，分别为 begin 和 end。其中 begin 成员返回指向第一个元素的迭代器；end 成员返回容器最后一个元素的下一个位置（one past the end），也就是指向一个根本不存在的尾后位置，这样的迭代器没什么实际含义，仅是个标记而已，表示已经处理完了容器中的所有元素。所以 begin 和 end 表示的是一个左闭右开的区间\[begin, end\)

迭代器可以用来实现容器的遍历、插入等操作。

### 2. 指针(\*)、取地址(&)、解引用(\*)、引用(&)

> 在C语言中，创建变量就是在向内存申请空间。

```cpp{.line-numbers}
#include <iostream>

int main()
{
    int a = 10;
}
```



#### 2.1 指针

### 3. 0x3f ~ 0x3f3f3f3f

在计算机解决问题时，时常要将一些变量初始化为极大值，比如说无穷大$\infty$。
众所周知，计算机的存储空间是有限的，使用0x3f3f3f3f作为极大值来表示$\infty$。
```cpp{.line-numbers}
int m = 0x3f3f3f3f;
cout << m << '\n';
```

### 4. 原码、反码、补码

#### 4.1 原码
正常的二进制表达，需要注意的是，最左的位是符号位，*0为正*，*1为负*。