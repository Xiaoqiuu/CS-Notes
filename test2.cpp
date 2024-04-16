#include<bits/stdc++.h>

/*int main()
{
    int n;cin >> n;
    for(int i = 1; i <= n; ++ i) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; ++ i) {
        int num = 1;
        int pos = i;
        int res = 0;
        while(1)
        {
            if(num == n || num > n)break;
            
            a[i]
        }
    }
    return 0;
}*/
/*
int main(){
    
      ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; ++ i){
    while(i){
      if(i%10==2){
      ans += 1;
      }else{
       i /= 10;
      }
    }
  }
  cout << ans << '\n';
  return 0;printf("%d", 1/10);
    return 0;*/
   /* {
  // 请在此输入您的代码
  int n;cin >> n;
  int ans = 0;
  string str;
  for(int i = 1; i <= n; ++ i){
  string str = to_string(i);
  if(str.find("2"))
  {
    cout << "en";
  }
  str = "0";
  }
  cout << ans << endl;
  return 0;
    }
}*/
using LL = long long;
const int N = 1e5 + 6;
int a[N], b[N], c[N];

using namespace std;

int main(){

  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n; cin >> n;
  for(int i = 1;i <= n; ++ i) cin >> a[i];
  for(int i = 1;i <= n; ++ i) cin >> b[i];
  for(int i = 1;i <= n; ++ i) cin >> c[i];
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  sort(c + 1, c + n + 1);
  LL ans = 0;
  LL cnta;
  LL cntc;

  for(int i = 1; i <= n; ++ i){
    cnta = (int)(lower_bound(a, a+n+1, b[i]) - a) - 1;
    cntc = n - (int)(lower_bound(c, c+n+1, b[i]) - c) + 1;
    if(a[cnta] < b[i] && b[i] < c[n + 1 - cntc])ans += cnta * cntc;
  }
  cout << ans << endl;

  return 0;
}