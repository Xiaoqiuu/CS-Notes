//天数
//输入一个月份，请输出2021年这个月有多少天
//输入一行包含一个整数，表示月份
//输出一个整数，这个月的天数

//我的做法 switch语句傻瓜式选择
/*
#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int num;
  scanf("%d", &num);
  switch(num)
  {
    case 1:printf("31\n");break;
    case 2:printf("28\n");break;
    case 3:printf("31\n");break;
    case 4:printf("30\n");break;
    case 5:printf("31\n");break;
    case 6:printf("30\n");break;
    case 7:printf("31\n");break;
    case 8:printf("31\n");break;
    case 9:printf("30\n");break;
    case 10:printf("31\n");break;
    case 11:printf("30\n");break;
    case 12:printf("31\n");break;
  }
  return 0;
}*/

//
/*
#include <iostream>
int main()
{
    //请在此输入您的代码
    int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int n;
    std::cin >> n;
    std::cout << month[n - 1];
    return 0;
}
*/
#include <bits/stdc++.h>

int main()
{
  int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
  int n;
  std::cin >> n;
  std::cout << month[n - 1];
  return 0;
}
//计算平行四边形的面积
/*
#include<iostream>
int main()
{
  //请在此输入您的代码
  double l, h, s;
  int a;
  std::cin>> l >> h;
  s = l * h;
  a = (int)s;
  if(a == s)
    printf("%d",a);
  else
    printf("%.1lf", s);
  return 0;
}
*/
//扫雷

/*
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
  int a;
  double b = 4.44;
  cout << a << b << endl;  
  return 0;
}*/