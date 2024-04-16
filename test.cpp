//#include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <string>
#include <map>
using namespace std;

//通过结构体创建变量的方式有三种
/*    
struct Student
{
    string name;
    int age;
    int score;
};

struct Student2
{
    string name;
    int age;
    int score;
}s3;

int main()
{
    //1. struct 结构体名 变量名
    Student s1;
    s1.name = "xiaoqiuu";
    s1.age = 17;
    s1.score = 100;
    cout << "name: " << s1.name << " age: " << s1.age << " score: " << s1.score << '\n';
    
    //2. struct 结构体名 变量名 = {成员值1, 成员值2...}
    Student s2 = {"gujiqiu", 18, 99};
    cout << "name: " << s2.name << " age: " << s2.age << " score: " << s2.score << '\n';

    //3. 定义结构体时顺便定义变量
    s3.name = "QiuBaiBai";
    s3.age = 19;
    s3.score = 59.5;

    cout << "name: " << s3.name << " age: " << s3.age << " score: " << s3.score << '\n';

    return 0;
}*//*
int main()
{
    int a = 10;
    int* p = NULL; // 说明符
    
    scanf("%d", &a);    //99
    p = &a;
    a = 666;
    *p = 888;//运算符
    printf("%d\n", a);
    printf("%d\n", p);
    printf("%d\n", *p);
    return 0;
}
*/
//通过指针计算五个整型元素之和
/*
int calculateSum(vector<int>& nums)
{
    int sum = 0;
    for (int num : nums)
    {
        sum += num;
    }
    return sum;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int sum = calculateSum(nums);
    cout << "Sum of the elements: " << sum << endl;

    return 0;
}*/

/*
struct account{
    int ano;
    string name;
    string password;
    int balance;
};

int main()
{
    account acc;
    
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> acc.ano >> acc.name >> acc.password >> acc.balance ;

    cout << "Your account is : " << acc.ano << '\n';
    cout << "Your name is : " << acc.name << '\n';
    cout << "Your password is : " << acc.password << '\n';
    cout << "Your balance is : " << acc.balance << '\n';

    return 0;
}
*/

/*
struct account{
    int num;
    string name;
    string sex;
    string add;
};

int main()
{
    account acc[3];
    
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    for (int i = 0 ;i < 3 ; ++ i)
        cin >> acc[i].num >> acc[i].name >> acc[i].sex >> acc[i].add ;
    for (int i = 0 ;i < 3 ; ++ i)
    {
        cout << "Your account is : " << acc[i].num << '\n';
        cout << "Your name is : " << acc[i].name << '\n';
        cout << "Your password is : " << acc[i].sex << '\n';
        cout << "Your balance is : " << acc[i].add << '\n';
    }
}
*/
/*
#include <iostream>  
#include <stack>  
  
int main() {  
    std::stack<int> myStack;  
      
    // 添加元素到stack  
    myStack.push(1);  
    myStack.push(2);  
    myStack.push(3);  
      
    // 检查stack的大小  
    std::cout << "Size of stack: " << myStack.size() << std::endl;  
      
    // 输出并移除stack顶部的元素  
    while (!myStack.empty()) {  
        std::cout << "Top element: " << myStack.top() << std::endl;  
        myStack.pop();  
    }  
      
    // 检查stack是否为空  
    if (myStack.empty()) {  
        std::cout << "Stack is empty." << std::endl;  
    }  
      
    return 0;  
}*/
/*
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    priority_queue<int> jc;
    jc.push(10);
    jc.push(20);
    jc.push(30);

    std::cout << "The top element is : " << jc.top() << ". \n";

    jc.pop();

    std::cout << "Now I cleaned the top of the element." << '\n';

    std::cout << "Now the top element is : " << jc.top() << ". \n";
    return 0;
}
*/

/*

bool cmp(const int &u, const int &v)
{
    return u > v;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    
    //初始化v
    vector<std::string> v;
    
    //对数组进行排序，降序排列
    sort(v.begin(), v.end(), cmp);

    //输出
    for (int i = 0; i < (int)v.size(); ++ i)
        cout << v[i] << ' ';
}

*/


/*
int main()
{
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int a = 10;
    //int p = &a;
    cout << a << '\n';

    //system.pause(0);

    return 0;
}*/

void overload()
{
    int a = 10;
    cout << "a is " << a << endl;
}

int overload(int a)
{
    cout << "a is " << a <<endl;
    return 0;
}

int overload(int a, int b)
{
    cout << "a and b :" << a << ", " << b << endl;
    return 0;
}

int main()
{
    int a[4];
    int b[] = &a[]; 

    overload();
    overload(10);
    overload(10, 20);

    cout << "----------------" << '\n';
    //创建并初始化multimap
    multimap<int, string> mp = {{1, "Jujube"}, {2, "Apple"}};
    //向mp插入元素
    mp.insert({1, "Banana"});
    mp.insert({6, "Mangoo"});
    //
    if(mp.count(0)){
        cout << "见鬼了" << endl;
    } else {
        cout << "Okay." << endl; 
    }

    if(mp.count(2))
    cout << "Okay." << endl;
    //遍历并打印mp中的元素
    for (const auto& pair : mp){
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }
    mp.clear();

    if(mp.count(2))
    {
        cout << "见鬼了" << endl;
    }
    else{
    cout << "Okay." << endl;
    }
    return 0;
}

/*
int main()
{
 pair<int , std::string> stu;
 stu.first = 233;
 stu.second = "cxk";
 
 std::cout << "姓名：" << stu.second << " 学号：" << stu.first << "\n";
 return 0;
}*/

