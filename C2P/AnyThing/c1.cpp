#include<iostream>
#include<math.h>
using namespace std;
int single_money[7] = {1,2,5,10,20,50,100};
int number_money[7] = {1,5,1,3,4,0,4};

//每种面值使用贪心后的张数

int count[7] = {};

int total_count;

int tanxin(int money)
{
    if(money>=0)
    {
        for(int i = 6;i<=0;i--)
        {
            count[i]=min(number_money[i],money/single_money[i]);

            money = money - count[i] * single_money[i];
        }

        return 0;
    }

    else

    {
        return money;
    }
}

int main()
{
    int money;

    cout << "please input the amount of money" << '\n';

    cin >> money;

    if(!tanxin(money))
    {
        cout << "贪心最优结果为：" << endl;

        for(int j=6;j>=0;j--)
        {
            cout << single_money[j] <<"元：" <<count[j] << "张" <<endl;
        }
    }

    else

    {
        cout << "ops,wrong number";
    }

    return 0;

}