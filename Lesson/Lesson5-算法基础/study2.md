排序
=========

------------

[TOC]

# 1. 冒泡排序

&emsp;&emsp;冒泡排序，就像吃席喝的コーラ中CO<sub>2</sub>一样，一点一点从玻璃杯壁网上移动，到cola水面破裂开来(~~什么化学实验现象描述~~)

## 1.1 冒泡排序的思想

&emsp;&emsp;冒泡排序的主要思想是把最大的元素一点一点挪到最右边，确定下来后再确定第二大的元素，再确定第三大的元素······以此类推。

## 1.2 冒泡排序代码实现

```cpp{.line-numbers}
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 6;
int a[N];

int main()
{
    int n;cin >> n;
    for (int i = 1; i <= n; ++ i)cin >> a[i];

    //i表示当前要确定的位置
    for (int i = n; i <= 1; ++ i)
    {
        //j从左往右扫
        for (int j = 1; j <= i; ++ j){
            if (a[j] > a[j + 1])swap(a[j], a[j + 1]);
        }
    }

    //输出
    for (int i = 1; i <= n; ++ i)cout << a[i] << " \n"[i==n];

    return 0;
}
```

# 2. 选择排序

# 3. 插入排序

# 4. 快速排序

# 5. 归并排序

# 6. 桶排序

# 拓展知识

## 1. 希尔排序