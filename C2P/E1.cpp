//极简C2P
/*
#include <iostream>
using namespace std;

int main(){
    int num1, num2;

    cout << "请输入2个数字\n" ;

    cin >> num1 >> num2;

    cout << "首先输入了" << num1 << "。\n";
    cout << "接着输入了" << num2 << "。\n";

    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;

map<int, int> mp;

int main ()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;cin >> n >> m;

    for(int i = 1; i <= n * m; ++i)
    {
        int x;cin >> x;
        mp[x] ++;
    }

    for(const auto &[x, y] : mp)
    {
        if(2 * y > n * m)cout << x << '\n';
    }

    return 0;
}