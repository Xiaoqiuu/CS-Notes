------
2024.3.1 数据结构作业
========
[TOC]
# 题目：求数组的和，要求使用循环结构

## 方法1 不用指针

思路：构建一个数组`n[5]`，先用for循环读取输入的五个数，然后再使用for循环(~~遍历~~)五个数累加到`sum`中

```c{.line-numbers}
#include <stdio.h>  
  
int main() 
{  
    int n[5];//定义一个数组  
    int sum = 0;//一会拿来存总和
    for (int i = 0; i < 5; ++ i)
    {
        scanf("%d", &n[i]);//输入五个数
    }
    for (int i = 0; i < 5; ++ i) 
    {  
        sum += n[i];  
    }  
  
    printf("5个数总和为: %d\n", sum);  
    return 0;  
}
```
演示如下捏：
<img src = "C:\Archive\LanQiao\Lesson\Pictures\0004.png">

## 方法2 使用数组和指针
```c{.line-numbers}
#include <stdio.h>  
  
int main() 
{  
    int n[5]; 
    int* p = n;//定义一个指针p，将其初始化为指向数组n的第一个元素
    int sum = 0;//一会拿来存总和
    for (int i = 0; i < 5; ++ i)
    {
        scanf("%d", &n[i]);//输入五个数
    }
    for (int i = 0; i < 5; i++) 
    {  
        sum += *(p + i);
        //*(p + i)是通过指针访问数组元素的一种方式，等价于n[i]
    }  
  
    printf("5个数的总和为: %d\n", sum);  
    return 0;  
}
```
执行演示如下：
<img src = "C:\Archive\LanQiao\Lesson\Pictures\0002.png">

## 方法3 使用指针与函数

思路：定义一个名为`sum`的函数，该函数接受一个整数指针`p`和一个整数`size`作为参数，用于计算指针指向的数组中前size个元素的和。~~（size的值在main函数中我设置成了5，那就是计算5个数的和，事实上可以直接把sum中的size换成5，就不用定义size了~~

```c
#include <stdio.h>  
  
int sum(int *p, int size) {  
    int u = 0;  
    for (int i = 0; i < size; ++ i) 
    {  
        u += *(p + i);  
    }  
    return u;  
}  
  
int main() {  
    int n[5];  
    int *p = n;  
    for (int i = 0; i < 5; ++ i)
    {
        scanf("%d", &n[i]);//输入五个数
    }
    int _sum = sum(p, 5); //调用函数sum 
    printf("5个数的总和为: %d\n", _sum);  
    return 0;  
}
```
执行演示如下：
<img src = "C:\Archive\LanQiao\Lesson\Pictures\0003.png">

```cpp
#include<stdio.h>

int main()
{
    int a[3] = {1, 2, 3};
    int s = 0;
    int *pa = NULL;
    for (pa=a;pa<a+3;pa++){
        s += *pa;
    }
    printf("%d\n", s);
    return 0;
}
```
