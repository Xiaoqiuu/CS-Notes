//LanQiaoLesson1
#include<bits/stdc++.h>//万能头文件
using namespace std;//释放std命名空间中的变量名，即可以使用C++标准库
/*int main()//main函数式 C++内置的启动函数 也就是程序入口
{
    //cout << "Hello World" << "\n";//利用cout将字符串输出，字符串用双引号括起来
    //std::cout <<"Hello World" << "\n";//不释放std 可以在cout前面加上std::
    printf("Hello World\n");//利用printf将字符串输出

    double a , b;
    scanf("%lf,%lf", &a ,&b);
    printf("%.2lf, %.3lf\n", a, b);

    return 0;//遇到return就会结束
} */
/*int main()
{
    char s[10];
    scanf("%s", s);
    printf("%s", s);
    return 0;
}*/
/*
int main()
{
    char s[15];
    scanf("%[^\n]", s);
    printf("%s", s);
    return 0;
} 
*//*
int main()
{
    double a, b;
    cin >> a >> b;
    cout << fixed << setprecision(8) << a << ' ' << b << '\n';
    return 0;
}
*/
// 取消同步流
//由于cin和cout需要自动判断变量类型等内部原因，读写效率比scanf和printf更低
//数据量较大时，可能会导致程序运行超时
//我们可以通过取消同步流来加速cin和cout，加速后效率相差无几
int main()
{
    //取消同步流
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //其它操作基本不变
    int x;
    cin >> x;
    cout << x << '\n';

    return 0;
}