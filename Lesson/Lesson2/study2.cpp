//

//在C++中，std::string类提供了一个成员函数c_str()
//C_str()用于返回一个指向以空字符结尾的C风格字符串(即const char*类型)
//在进行printf输出时，需要将string转换为C风格的字符串进行输出

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    char buf[100];//临时变量，用于输入
    scanf("%s", buf);//输入buf
    string str(buf);//用buf来构造str
    printf("str = %s\n", str.c_str());//输出str

    return 0;
}