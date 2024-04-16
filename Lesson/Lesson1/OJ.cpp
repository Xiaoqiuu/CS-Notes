//lanqiao OJ 254 A+B问题

//printf-scanf

/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a + b);
    return 0;
}

*/

//cin-cout
/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b;
    cin >> a >> b;
    cout << a + b << '\n';
    return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    
    // 请在此输入你的代码
    int m, d;
    int day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    cin >> m >> d;
    if(d == day[m - 1] || d <= day[m - 1]){
        cout << "yes.\n" << endl;
    }else{
        cout << "no.\n" << endl;
    }
    return 0;
}