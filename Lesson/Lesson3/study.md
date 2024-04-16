---------
# sort排序
[TOC]

## sort简介
sort函数包含在头文件`<algorithm>`中,在sort函数使用前需要#include`<algorithm>`或使用万能头文件。
sort是C++标准库中的一个函数模板，用于对指定范围内的元素进行排序。
sort算法使用的是快速排序(QuickSort)或者类似快速排序的改进算法。具有较好的平均时间复杂度，一般为$$O(n log n )$$

## sort用法

### 1
```cpp
sort(起始位置， 结束地址的下一位， *比较函数)；
```
*处的比较函数为空的话，默认小于号`<`（升序）
```cpp{.line-numbers}
int a[1000];

int n;
//读取数组大小
cin >> n;

//读取元素
for(int i = 1;i <= n; ++ i)
    cin >> a[i];

//对数组进行排序
sort(a + 1, a + n + 1);// [1,n+1)左闭右开区间

//输出
for(int i = 1; i <= n; ++ i)
    cout << a[i] << ' ';
```

### 2

```cpp
sort(起始地址， 结束地址的下一位， *比较函数)；
```
这里的起始地址指迭代器begin()

```cpp{.line-numbers}
// 初始化v
vector<int> v = {5, 1, 3, 9, 11};

// 对数组进行排序
sort(v.begin(), v.end());

// 输出
for (int i = 0; i < v.size(); ++ i)
    cout << v[i] << ' ';
//也可以这么写:
//for (auto i : v)cout << i << ' ';
```

关于[vector](#xiaoqiuu_1)相关的拓展知识，请看后文。

## 3. 自定义比较函数
sort默认使用小于号进行排序，如果自定义比较规则，可以传入第三个参数，可以是函数或lambda表达式。
```cpp{.line-numbers}
bool cmp(const int &u, const int &v)
{
    return u > v;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    //初始化v
    vector<int> v = {5, 1, 3, 9, 11};
    
    //对数组进行排序，降序排列
    sort(v.begin(), v.end(), cmp);

    //输出
    for (int i = 0; i < (int)v.size(); ++ i)
        cout << v[i] << ' ';
}
```

使用lambda表达式（[匿名函数](#xiaoqiuu_2)）：
```cpp{.line-numbers}
//初始化v
vector<int> v = {5, 1, 3, 9, 11};

//对数组进行排序，降序排列
sort(v.begin(), v.end(), [](const int &u, const int &v)
{
    return u > v;
});

//输出
for (int i = 0;i < v.size(); ++ i)cout << v[i] << ' ';
```

> *匿名函数什么时候用*：就在这块代码里用一下，别的地方不用

结构体可以将小于号重载后进行排序，当然用前面的方法也是可行的。

```cpp{.line-numbers}
struct Node
{
    int u, v;
    bool operator < (const Node &m)const
    {
        //以u为第一关键字，v为第二关键字排序
        return u == m.u ? v < m.v : u < m.u;
    }
};
```

## 拓展知识

### 1. C++ 数组 之 vector
<a id = "xiaoqiuu_1"></a>

vector中的数据类型T可以表示任何数据类型，比如int, string, class, vector（构建多维数组）等等，就像一个可以放下任何东西的容器，所以vector也常被称作为**容器**，c++中的不同种类的容器拥有很多相同的操作，因此string的很多操作方法可以直接用在vector上。
<style>
.center
{
    width : auto;
    display : table;
    margin-left : auto;
    margin-right : auto;
}
</style>

<p align = "center">表1 vector对象的定义和初始化方式</font></p>

</div class = "center">

|类型|解释|
|----|----|
|vector\<T> v1 | v1是一个元素类型为T的空vector|
|vector\<T> v2(v1)|使用v2中所有元素初始化v1|
|vector\<T> V2 = V1|使用v2中所有元素初始化v1|
|vector\<T> v3(n, val)|v3中包含n个值为val的元素|

</div>

<p align = "center"> 表2 C++中vector向量函数</font></p>

|函数|描述|
|----|----|
|empty()|判断vector是否为空，返回一个bool值|
|begin()|返回第一个元素的迭代器|
|end()|返回最末元素的迭代器(实际上指最末元素的下一个位置)|
|size()|查询vector的元素个数|

</div>

### 2. C++的匿名函数(lambda表达式)
<a id ="xiaoqiuu_2"></a>

> *C++11提供了对匿名函数的支持，成为Lambda函数(也叫做Lambda表达式)。它是定义和使用匿名函数对象的一种简便的方式。匿名函数是我们需要用到的一个函数，但是又不想去费尽心思去命名一个函数的办法。我们无需为每个值或每种类型单独编写函数，更不必把值保存在令人厌倦的全局变量中。利用Lambda表达式可以编写内嵌的匿名函数，用以替换独立函数或者函数对象，并且使代码更可读。*

#### 1. 表达式结构
#### 2. 基本的参数分析

C++11中的Lambda表达式捕获外部变量主要有以下形式：
* []：默认不捕获任何变量；
* [=]：默认以值捕获所有变量；
* [&]：默认以引用捕获所有变量；

无捕获、无参数、无返回值的lambda表达式
```cpp
auto lambda = []() { std::cout << "Hello, World!" << std::endl; };  
lambda();
```



### 3. C++结构体

**结构体**，一种构造类型数据。

#### 1. 结构体创建
* struct *变量名*
* struct *变量名*={成员值1, 成员值2, ...}
* 定义结构体时顺便定义变量

> 成员的数据类型可以是c中允许的任何数据类型。

示例代码如下：

```cpp{.line-numbers}
#include <bits/stdc++.h>
using namespace std;

//通过结构体创建变量的方式有三种
    
struct Student
{
    string name;
    int age;
    int score;
};

struct Student2
{
    string name;
    int age;
    int score;
}s3;

int main()
{
    //1. struct 结构体名 变量名
    Student s1;
    s1.name = "xiaoqiuu";
    s1.age = 17;
    s1.score = 100;
    cout << "name: " << s1.name << " age: " << s1.age << " score: " << s1.score << '\n';
    
    //2. struct 结构体名 变量名 = {成员值1, 成员值2...}
    Student s2 = {"gujiqiu", 18, 99};
    cout << "name: " << s2.name << " age: " << s2.age << " score: " << s2.score << '\n';

    //3. 定义结构体时顺便定义变量
    s3.name = "QiuBaiBai";
    s3.age = 19;
    s3.score = 59.5;

    cout << "name: " << s3.name << " age: " << s3.age << " score: " << s3.score << '\n';

    return 0;
}
```

#### 2. 结构体数组

一个结构体变量中可以存放一组数据（如一个学生的学号，姓名，成绩等数据）。如果有10个学生的数据需要参加运算，显然应该用数组，这就是结构体数组。结构体数组与以前介绍过的数据值型数组不同之处在于每个数组元素都一个结构体类型的数据，它们分别包括各个成员（分量）项。

```c{.line-numbers}
// A C language program code
#include <stdio.h>

struct student{
    int num;
    char name[20];
    char sex;
    char add[20];
}

void main()
{
    struct student s;
    scanf("%d", &s.num);
    scanf("%s", s.name);
    getchar();
    scanf("%c", &s.sex);
    scanf("%s", s.add);
    printf("num%d\nname:%s\nsex:%c\nadd:%s\n", s.num, s.name, s.sex, s.add);
}
```
