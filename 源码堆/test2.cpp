#include <bits/stdc++.h>

using LL = long long;
using namespace std;

int main()
{
    LL num, ans = 0, temp = 0;
    while(cin >> num){
        if( num % 2 == 0 ) ans ++;
        else temp += num;
    }
    cout << ans << endl << temp << endl;
    return 0;
}