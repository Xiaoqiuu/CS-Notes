-----------------
[TOC]

# STL

  > STL 即标准模板库（Standard Template Library）是一套功能强大的 C++ 模板类，提供了通用的模板类和函数，这些模板类和函数可以实现多种流行和常用的算法和数据结构，如向量、链表、队列、栈。
  > 由于其模板化的特点，它能够兼容自定义的数据类型，避免大量的造轮子工作。NOI 和 ICPC 赛事都支持 STL 库的使用，因此合理利用 STL 可以避免编写无用算法，并且充分利用编译器对模板库优化提高效率。

STL的几个基本概念:

1. **容器**:可容纳各种数据类型的数据结构
2. **迭代器**:可**依次存取**容器中的元素

![](../Pictures/0006.png)
C++的STL提供了多种容器，例如vector存储数组，list存储链表，set、map存储二叉树等等。

## 1. pair
### 1.1 pair的定义与结构
   在C++中，`pair`是一个**模板类**，用于表示一对值的组合。它位于`<utility>`的头文件中。
   pair的定义如下：
   ```cpp{.line-numbers}
   template<class T1, class T2>
   struct pair{
   T1 first;//第一个值
   T2 second;//第二个值

   //构造函数
   pair();
   pair(const T1& x, const T2& y);

   //比较运算符重载
   bool operator==(const pair& rhs) const;
   bool operator!=(const pair& rhs) const;

   //其它成员函数和特性
   };
   ```
   pair类模板有两个模板参数，T1和T2，分别表示第一个值和第二个值的类型。
   pair类有两个成员变量，first和second，分别表示第一个值和第二个值。
   pair类还有一些成员函数和特性，例如默认构造函数、带参数的构造函数、比较运算符重载等。
   使用pair类，你可以方便地将两个值组合在一起，并进行传递、存储和操作。
   例如，可以将两个整数组合一起作为返回值，或者将一对值存储在容器中。

   ```cpp{.line-numbers}
    #include <iostream>
    #include <utility>
    
    int main()
    {
    std::pair<int, double> p(1, 3.14);
    std::pair<char, std::string> p2('a', "hello");

    std::cout << p1.first << ", " << p1.second << "\n";
    std::cout << p2.first << ", " << p2.second << "\n";
    }
   ```
   以上代码创建了两个pair对象，分别包含不同类型的值。
   通过访问first和second成员变量，输出了这些值。

   还可以这么使用：
   ```cpp{.line-numbers}
#include <iostream>
#include <utility>
#include <string>

int main()
{
    pair<int , std::string> stu;
    stu.first = 233;
    stu.second = "cxk";
    
    std::cout << "姓名：" << stu.second << " 学号：" << stu.first << "\n";
    return 0;
}
  ```

在C++11版本后，`make_pair`函数

### 1.2 pair的嵌套

   pair可以进行嵌套，也就是说可以见将一个pair对象作为另一个pair对象的成员。
   通过嵌套pair，你可以方便地组合多个值，并形成更为复杂的数据结构。
   例如，你可以创建一个三维坐标系的点，其中第1个维度由一个整数表示，第2、3维度由一个pair来表示。

 ```cpp{.line-numbers}
    #include <iostream>
    #include <utility>

    int main()
    {
        std::pair<int ,int> p1(1, 2);
        std::pair<int, std::pair<int, int>> p2(3, std::make_pair(4, 5));
        std::pair<std::pair<int, int>, std::pair<int, int>> p3(std::make_pair(6, 7), std::make_pair(2, 6));

        std::cout << p1.first << ", " << p1.second << "\n";
        std::cout << p2.first << ", " << p2.second.first << ", " << p2.second.second << "\n";
    }
 ```

### 1.3 pair自带排序规则
   pair自带的排序规则是按照first成员进行升序排序。
   如果first成员相等，则按照second成员进行升序排序。
   这就意味着，当使用标准库中的排序算法(比如`std::sort`)对包含pair对象的容器进行排序时，会根据pair对象的first成员进行排序。

```cpp{.line-numbers}
#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

int main()
{
    std::vector<std::pair<int, int>> vec;
    vec.push_back(std::make_pair(3, 2));
    vec.push_back(std::make_pair(1, 4));
    vec.push_back(std::make_pair(2, 1));

    std::sort(vec.begin(), vec.end());

    for (const auto&p : vec)
    {
        std::cout << p.first << ", " << p.second << std::endl;
    }

    return 0;
}
```
   如果想按照其他排序规则对pair进行排序，可以自定义比较函数或使用lambda表达式来传递给排序算法。

## 2. vector

### 2.1 vector的定义和特性

在C++中，vector是一个动态数组容器，可以存储一系列相同类型的元素。它是标准库`<vector>`中定义的模板类。

vector的定义和结构非常简单：
- **模板类声明**：vector是一个模板类，使用它必须带头文件<vector>，声明一个vector对象的通用语法如下
```cpp
std::vector<T> vec; //T可以是int、double、char、vector等等
```
- **容器大小**：vector是一个动态数组，可以根据需要自动调整大小。它会根据元素的数量动态分配内存空间。
- **元素访问**：可以通过索引访问vector中的元素，索引从0开始，最后一个元素的索引是`size() - 1`(注意，遍历的话要强制转换为int，或者`i < size()`)，可以使用[]运算符或at()函数来访问元素。
- **元素添加或删除**：可以使用push_back()函数在vector的末尾添加元素，使用pop_back()函数删除元素末尾的元素。还可以使用insert()函数在指定位置插入元素，使用erase()函数删除指定位置的元素。（以上操作都会改变vector元素的数量）
- **容器大小管理**：可以使用size()函数获取vector中元素的数量，使用empty()函数检查vector是否为空。还可以使用resize()函数调整vector的大小。
- **迭代器**：vector提供了迭代器，可以用于遍历容器中的元素。可以使用begin()函数获取指向第一个元素的迭代器，使用end()函数获取指向最后一个元素之后位置的迭代器。

### 2.2 vector常用函数

#### 1. push_back()

将元素添加到vector的末尾。
```cpp
void push_back(const T& value);// '&'表示引用，给变量一个新的名字
```

#### 2. pop_back()

删除vector末尾的元素。
> 注意：一定要保证vector是非空的。

```cpp
void pop_back();
```
#### 3. begin() 和 end()

返回指向第一个元素和最后一个元素之后位置的迭代器。

```cpp
std::vector<int> vec = {10, 20, 30};
for (auto it = vec.begin(); it != vec.end(); ++ it){
    std::cout << *it << " ";
}
//这里的第二个判断不可以使用<=
//第三个表达式不可以使用+=1，迭代器不允许这么做
```

### 2.3 vector排序去重

#### 排序
要对vector进行排序，可以使用标准库中的std::sort函数，该函数位于头文件`<algorithm`中。

```cpp
#include <algorithm>

std::vector<T> vec = {...};//T为元素类型
std::sort(vec.begin(), vec.end());//sort接受两个迭代器参数，表示要排序的范围
```

#### 去重
要去除vector的重复元素，可以使用std::unique函数。该函数位于头文件`<algorithm>`中。

```cpp
#include <algorithm>

std::vector<T> vec = {...};//T为元素类型
std::sort(vec.begin(), vec.end());
auto last = std::unique(vec.begin(), vec.end());//unique函数将重复的元素移动到vector的末尾
//并且返回一个不重复元素的迭代器
vec.erase(last, vec.end());//erase函数将重复元素从vector中删除
```

## 3. list

### 3.1 list定义和结构

**list在竞赛中不常用**。只做了解即可。

list的时间复杂度(是否与STL的list相同？)

> *list存储类型为链式存储。*

list是一种双向链表容器。它是STL提供的一种**序列容器**。list以**节点**(node)的形式存储元素，并使用指针将这些节点链接在一起，形成一个链表结构。
看到指针不用害怕，因为STL用函数封装好了，不用人为操控指针了。

如果想调用list,请使用头文件`<list>`

![](../Pictures/0005.png)

list的容器特点包括:

- **双向性**: 每个结点都包括指向前一个结点和后一个结点的指针，因此可以在常数时间内在链表中的任意位置(**不能随机访问**)进行插入、删除和访问操作。
  - 记住迭代器后才可以中间位置访问，实际上是不能随机访问的
- **动态大小**: 链表的大小可以根据需要动态扩展或收缩，不需要预先指定容器的大小。
- **不连续存储**: 链表中的结点可以在内存中的任意位置分布，不要求连续存储，因此插入和删除操作不会导致元素的移动。

list容器提供了一系列成员函数和迭代器来操作和访问链表中的元素，包括删除、访问、反转等操作。可以使用迭代器来遍历链表中的元素。

```cpp{.line-numbers}
#include <iostream>
#include <list>

int main()
{
    std::list<int> myList;

    //在链表尾部插入元素
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    //在链表头部插入元素
    myList.push_front(0);

    //遍历链表并输出元素
    for(int num : myList)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
```

list与vector区别在于:

- list不支持随机存取
- list没有提供空间容量，空间重新分配等操作函数，每个元素都会有自己的内存

## 3.2 list常用函数

|函数|描述|时间复杂度|
|---|---|---|
|push_front(x)|在链表头插入元素x|$O(?)$|
|push_back(x)|在链表尾插入元素x|$O(?)$|
|pop_front()|删除链表头部元素|$O(?)$|
|pop_back()|删除链表尾部元素|$O(?)$|
|front()|返回链表头部元素|$O(1)$|
|back()|返回链表尾部元素|$O(1)$|


## 4. stack

### 4.1 stack的定义与结构

stack是一种容器适配器，提供一种**后进先出**(Last In First Out)的数据结构，使用时注意引用头文件`<stack>`
stack提供了一组函数来操作和访问元素，但是它的功能相对简单些。

```cpp
template <class T, class Container = deque<T>>
class stack;

//T为元素类型：int，double...
//Container: 表示底层容器的类型，默认就是deque。也可以使用其他容器类型，比如list，vector等

```

stack内部实现使用了底层容器来存放元素，并且只能通过特定的函数来访问和操作元素。打个比方，有一个三层格子的杯子，假设最顶上的格子叫做栈顶，最底下的格子叫做栈底，现在你想倒入可乐，你在倒入的过程中会发现，它是从最底层往最上层填满的，这就意味着你想喝到可乐，只能喝到最上层的可乐(当然我们假设这个杯子只有上面是有口的)。stack就是这样的，你只能访问最上层的栈顶元素。只有栈顶元素弹出后，你才能看到它下面的元素是什么。

### 4.2 stack常用函数

|函数|描述|时间复杂度|
|---|---|---|
|push()|在栈顶**插入元素**x|$O(1)$|
|pop()|弹出栈顶元素|$O(1)$|
|top()|返回栈顶元素，栈顶元素让我康康(伟哥音|$O(1)$|
|empty()|检查栈是否为空|$O(1)$|
|size()|返回栈中元素的个数|$O(1)$|

</style>

<p align = "center">表4.2 stack常用函数</font></p>

</div class = "center">


> *请注意，stack是不可以遍历的，因为需要来回弹出元素*

```cpp{.line-numbers}
#include <iostream>  
#include <stack>  
  
int main() {  
    std::stack<int> myStack;  
      
    // 添加元素到stack  
    myStack.push(1);  
    myStack.push(2);  
    myStack.push(3);  
      
    // 检查stack的大小  
    std::cout << "Size of stack: " << myStack.size() << std::endl;  
      
    // 输出并移除stack顶部的元素  
    while (!myStack.empty()) {  
        std::cout << "Top element: " << myStack.top() << std::endl;  
        myStack.pop();  
    }  
      
    // 检查stack是否为空  
    if (myStack.empty()) {  
        std::cout << "Stack is empty." << std::endl;  
    }  
      
    return 0;  
}
```
## 5. queue

### 5.1 queue队列

`queue`是一个**先进先出**(**First In First Out**)的数据结构。举个栗子，一个两头开眼的管子，从一端先塞进去第一颗栗子，然后第二颗，第三颗······从另一端拿出栗子时，你会发现你取出的栗子顺序和你塞进去时的顺序是一样的。
`queue`提供了一组函数来操作和访问元素，但是它的功能相对来说比较简单。

定义与结构如下:

```cpp
template <class T, class Container = deque<T>>
class queue;
```

queue的常见语法如下

|函数|描述|时间复杂度|
|---|----|----|
|push(x)|在队尾插入元素x|$O(1)$|
|pop()|弹出队首元素|$O(1)$|
|front()|返回队首元素|$O(1)$|
|back()|返回队尾元素|$O(1)$|
|empty()|返回队列是否为空|$O(1)$|
|size()|请问一共有几个元素？|$O(1)$|

### 5.2 priority_queue 优先排列(堆)

`priority_queue`与普通的`queue`不同，默认情况下，它会将元素按照**从小到大**的优先级顺序进行排序。

`priority_queue`中的元素逻辑结构是树形结构。最顶层的top是最大值。树杈的值都会比顶端小，它的排列顺序就不是那么重要了(直接可以忽略)。

priority_queue的常见语法如下：

|函数|描述|时间复杂度|
|------|-------|-----|
|push(x)|将元素x插入到优先队列中|$O(log N)$|
|pop()|弹出优先队列中的顶部元素|$O(log N)$|
|top()|返回优先排列中的顶部元素|$O(1)$|
|empty()|检查队列是否为空|$O(1)$|
|size()|请问一共有几个元素？|$O(1)$|

如果你想要考虑吧修改一下比较函数，你可以使用以下方法：

```cpp{.line-numbers}

// 1 仿函数

struct Compare{
    bool operator()(int a, int b){
    //自定义比较函数，按照逆序排列
    return a > b;
    }
};

int main()
{
    priority_queue<int, std::vector<int>, Compare> pq;
}
```

还有一种定义的方法(lambda表达式)，可以参考一下：

```cpp
auto compare[](int a, int b)
{
    return a > b;//小根堆
}

int main()
{
    std::priority_queue<int, std::vector<int>, decltype(compare)> pq(compare);
}
```

如果优先队列中的元素类型比较简单，可以直接使用`greater<T>`来修改比较方法。

其中，`std::greater`在头文件`functional`中。

```cpp
priority_queue<int, std::vector<int>, greater<int>>;
```
### 5.3 deque 双端序列

`deque`与`queue`的区别在于，queue是单端传递，后端进入前端输出，而deque是双头双向传递的。
其它的就跟queue就没什么区别了。

使用双端队列一般就不考虑调用中间元素了。后续内容中的**“单调序列”**将使用双端序列来实现，单独考察双端序列的其实并不是很常见。

|函数|描述|时间复杂度|
|------|-------|-----|
|push_back(x)|在尾部插入元素x|平摊$O(1)$|
|push_front(x)|在头部插入元素x|平摊$O(1)$|
|pop_back()|弹出尾部元素|平摊$O(1)$|
|pop_front()|弹出头部元素|平摊$O(1)$|
|front()|返回头部元素|$O(1)$|
|back()|返回尾部元素|$O(1)$|
|empty()|检查一下deque四不四空滴|$O(1)$|
|size()|返回deque中元素的个数|$O(1)$|
|clear()|清空deque中的所有元素|$O(n)$|

## 6. set

### 6.1 set集合

#### 6.1.1 set简介

`set`是一种容器，用于存储唯一的元素，并按照一定的排序规则进行排序。默认set中的元素按升序排序，使用元素的比较运算符`<`进行排序。

`set`内部实现使用了**红黑树**，保持了元素的有序性。

删除和查找元素的时间复杂度都是对数时间$O(log n)$
set中的元素必须是唯一的，这就意味着不允许出现重复的元素。当插入一个重复的元素时，set会默认自动忽略掉。(如果你想重复使用的话请看后续的`multiset`)

```cpp
template <class key, class Compare = less<key>,class Allocator = allocator<key>>
class set;
```
上述代码中，Allocator表示用于分配内存的分配器类型，默认为`alloctor`。

#### 6.1.2 常用set函数

常见的set函数：

|函数|描述|平均时间复杂度|最坏时间复杂度|
|---|----|----|----|
|insert|向集合中插入元素|$O(log n)$|$O(log n)$|
|erase|从集合中移除元素|$O(log n)$|$O(log n)$|
|find|查找集合中的元素|$O(log n)$|$O(log n)$|
|lower_bound|返回第一个不小于给定值的迭代器|$O(log n)$|$O(log n)$|
|upper_bound|返回第一个大于给定值的迭代器|$O(log n)$|$O(log n)$|
|size|返回集合中元素的数量|$O(1)$|$O(1)$|
|empty|检查这个集合是否为空|$O(1)$|$O(1)$|
|clear|清空集合|$O(n)$|$O(n)$|
|begin|返回指向集合起始位置的迭代器|$O(1)$|$O(1)$|
|end|返回指向集合末尾位置的迭代器|$O(1)$|$O(1)$|
|rbegin|返回指向集合末尾位置的逆向迭代器|$O(1)$|$O(1)$|
|rend|返回指向集合起始位置的逆向迭代器|$O(1)$|$O(1)$|

#### 6.1.3 修改set比较方法

```cpp
#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int ,greater<int>> mySet;// '<' -> '>'

    mySet.insert(25);
    mySet.insert(11);
    mySet.insert(38);
    mySet.insert(44);

    for (const auto& elem : mySet) {
        cout << elem << " ";
    }
    cout << '\n';

    return 0;
    
}
```

## 7. map

### 7.1 *map*

`map`是一种关联容器，用于存储一组键值对(key-value pairs)，其中每个键(key)都是**唯一的**。

`map`容器会根据键来自动排序，并且可以通过对key的快速查找对应的值。

`map`容器使用**红黑树**的数据结构来实现，具有较快的插入、删除和查找操作，时间复杂度为$O(log~n)$

|函数|功能|时间复杂度|
|------|-----------|-----------|
|insert(*{k, v}*)|插入元素|$O(log~n)$|
|erase|删除元素|$O(log~n)$|
|find|查找元素|$O(log~n)$|
|count(*key*)|统计元素个数(也可以用来判断元素是否存在)|$O(log~n)$|
|size|返回元素个数|$O(1)$|
|begin|返回指向容器起始位置的迭代器|$O(1)$|
|end|返回指向容器末尾位置的迭代器|$O(1)$|
|lower_bound|返回指向第一个不小于指定键的元素位置|$O(log~n)$|
|upper_bound|返回指向第一个大于指定键的元素位置|$O(log~n)$|
|clear|清空容器||
|empty|判断容器是否为空||

多数情况下，使用map函数需要在意的是**键与值的映射关系**，而不是它们在容器中的顺序。

```cpp{.line-numbers}
#include<iostream>
#include<map>

int main()
{
    map<int, int> mp;
    mp.insert({1, 10});
    mp.insert({2, 20});
    if(mp.count(0)){
        cout << "见鬼了" << endl;
    } else {
        cout << "Okay." << endl; 
    }

    if(mp.count(2))
    cout << "Okay." << endl;

    mp.clear();

    if(mp.count(2))
    {
        cout << "见鬼了" << endl;
    }
    else{
    cout << "Okay." << endl;
    }
    return 0;
}
```

### 7.2 multimap

multimap是一种关联容器，类似于map，但允许存储多个具有相同键的键值对。

比赛中基本用不上。



### 7.3 unordered_map

使用**哈希函数**将键映射到存储桶中。
时间复杂度不稳定。

# 拓展知识

## 1. C++中的函数重载
<a id = "Xiaoqiuu_1"></a>

> 函数重载（Function Overloading）是C++中一项非常有用的特性，它允许我们在同一个作用域内定义多个同名函数，但这些函数的参数列表（参数的类型、数量或顺序）必须不同。这样，在调用函数时，编译器会根据提供的参数来确定调用哪个版本的函数。

函数重载提供了更大的灵活性，可以使用相同的函数名来执行不同的任务，这只需要这些任务接受不同类型的参数或不同数量的参数。

以下是一段代码示例：

```cpp{.line-numbers}
#include <iostream>  
#include <string>  
  
// 函数重载示例  
void print(int x) {  
    std::cout << "Integer: " << x << std::endl;  
}  
  
void print(double x) {  
    std::cout << "Double: " << x << std::endl;  
}  
  
void print(const std::string& s) {  
    std::cout << "String: " << s << std::endl;  
}  
  
int main() {  
    print(42);           // 调用 print(int)  
    print(3.14);         // 调用 print(double)  
    print("Hello");      // 调用 print(const std::string&)  
    return 0;  
}
```

在5.2中，`bool operator`就是使用函数重载。

## 2. C++中的模板函数

<a id = "Xiaoqiuu_2"></a>

### 2.1 

## 3. tuple
