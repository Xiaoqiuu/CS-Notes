#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 150;//const 常量限定符 用来限定特定常量 通知编译器这个变量是不可修改的 避免在函数中对某些不应修改的变量造成可能的波动

char s[N];

int main()
{
    //取消同步流
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> (s + 1);//从s[1]开始输入
    for(int i = 1;s[i]; ++ i)cout << s[i];//s[i] != '\0'

    return 0;
}