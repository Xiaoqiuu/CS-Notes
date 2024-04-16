//string的使用

//string简介
//string是C++标准库的重要组成部分，主要用于字符串处理
//使用string库需要在头文件中包括该库 #include<string>
//string与char[]不同，string实现了高度的封装，可以很方便的完成各种字符串的操作，比如拼接、截取、匹配等等
//  1）字符串管理：string封装了字符串的存储和管理。它自动处理字符字符串的内存分配和释放，避免了手动管理内存的麻烦、
//  2）动态大小调整：string可以根据需要自动调整字符串的大小。在添加或者删除字符时，string会自动调整的存储容量，确保足够的空间来容纳字符串
//  3）安全性：string提供了一些方法来确保字符串的安全性。例如，它提供了越界访问检查，以避免访问超出字符串范围的字符
//  4）迭代器支持：string支持迭代器，可以使用迭代器遍历字符串中的字符，进行字符级别的操作
//  5）兼容性：string是C++标准库的一部分，因此在C++中广泛使用，并且与其他标准库组件和C++语言特性兼容

//string的声明与初始化
 #include <iostream>
 #include <string>

 int main()
 {
    //声明并初始化一个空字符串
    std::string str1;
    
    //使用字符串字面量初始化字符串
    std::string str2 = "Hello, World!";
    
    //使用另一个 std::string 对象初始化字符串
    std::string str3 = str2;

    //使用部分字符串初始化字符串
    std::string str4 = str2.substr(0, 5);//子串，substr(起始位置, 长度)不输入长度默认到头

    //使用字符数组初始化字符串
    const char* charArray = "Hello";//被const修饰的东西具有“只读”的特点
    std::string str5(charArray);

    //使用重复的字符初始化字符串
    std::string str6(5, 'A');//string(个数, 字符)

    //输出字符串内容
    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "str3: " << str3 << std::endl;
    std::cout << "str4: " << str4 << std::endl;
    std::cout << "str5: " << str5 << std::endl;
    std::cout << "str6: " << str6 << std::endl;

    return 0;
 }