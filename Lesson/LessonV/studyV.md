稻草模板
=============

---------------------

[TOC]

# 日期问题

## 基础循环遍历模板

```cpp{.line-numbers}
int main()
{
    for (int year = 2000; year <= 2022; year ++)
        for (int month = 1; month <= 12; month ++)
            for(int day = 1; day <= 31; day ++){
                if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                ;//
                else if (month == 2){
                    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)){
                        if (day > 29) break;
                    }
                    else{
                        if (day > 28) break;
                    }
                }
                else{
                    if (day > 30) break;
                }
            }
}

```
