#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int pre[maxn];
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        cout<<pre[i]<<" ";
    }
    cout << "\n";
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        cout << pre[r] - pre[l-1] << "\n";
    }
    cout << "\n";
}
