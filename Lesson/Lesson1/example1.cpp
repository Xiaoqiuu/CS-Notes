#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 150;

int a[N];//大小为N的int数组 全局默认初始化为0

int main()
{
    //取消同步流
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;cin >> n;//输入数组大小
    for(int i = 1;i <= n; ++ i)cin >> a[i];//遍历数组并输入
    for(int i = n;i >= 1; -- i)cout << a[i] << ' ';
    return 0;
}