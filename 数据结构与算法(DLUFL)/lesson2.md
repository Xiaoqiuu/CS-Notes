第二课
==============

[TOC]

# 小程序

```cpp{.line-numbers}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 10;
    int* p;
    p = &a;
    scanf("%d", &a);    //99
    printf("%d\n", a);
    printf("%x\n", p);
    return 0;
}
```

地址访问