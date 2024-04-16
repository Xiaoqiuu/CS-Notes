#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 150;

double a[N];//double 

int main()
{
    int n;scanf("%d", &n);
    for(int i = 1;i <= n;  ++ i)scanf("%lf", &a[i]);
    double sum = 0;
    for(int i = 1;i <= n; ++ i)sum += a[i];//遍历整个数组 把它们加起来
    printf("%.2lf\n", sum);//保留2位小数，自动进行四舍五入
    return 0;
}