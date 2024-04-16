2403NCRE二级拼老命死磕计划
====================
Excel 第二集 函数
--------------

[TOC]

# 1. 英语单词

|序号|原单词|含义|
|----|----|----|
|1|lookup_value|查找的值|
|2|start_num|开始的位数|
|3|col_index_num|列序号|
|4|row_num|行序号|
|5|ref|序列|
|6|array|数据区域|
|7|table_array|数据区域/表格区域|
|8|range|区域|
|9|num_digits|小数位数|
|10|criteria|条件|
|11|criteria_range|条件区域|

# 2. 基础运算函数

## 2.1 SUM

<img src = "C:\Archive\LanQiao\等级考试\Pictures\0004.png">

> sum函数正常忽略文本单元格。

## 2.2 PRODUCT

求数值型数字乘积。跟sum一样忽略文本单元格等。

<img src = "C:\Archive\LanQiao\等级考试\Pictures\0005.png">

## 2.3 AVERAGE

求区域数据平均数。

<img src = "C:\Archive\LanQiao\等级考试\Pictures\0006.png">

## 2.4 COUNT系列

基础的**COUNT**：查一查框选的数据里有几个是数字类型的数据

其它的count函数可以看注释。

<img src = "C:\Archive\LanQiao\等级考试\Pictures\0007.png">

## 2.5 MAX与MIN

### 2.5.1 MAX

找最大值。

### 2.5.2 MIN

找最小值

## 2.6 RANK

求某数字在所选区域中的排名

<img src = "C:\Archive\LanQiao\等级考试\Pictures\0008.png">

## 2.7 MOD

求两个数相除的余数

<img src = "C:\Archive\LanQiao\等级考试\Pictures\0009.png">

## 2.8 LARGE与SMALL

返回一个第k大(小)的值

<img src = "C:\Archive\LanQiao\等级考试\Pictures\0010.png">

## 2.9 SUMPRODUCT

两两相乘，再相加

统计总价(单价x数量)

## 2.10 ROUNDUP 和 ROUNDDOWN

**ROUNDUP**：取几位小数，四舍五入
**ROUNDDOWN**：不四舍五入

<img src = "C:\Archive\LanQiao\等级考试\Pictures\0011.png">

## 2.11 INT

取整，没有四舍五入

## 2.12 CEILING

将数值增大为最接近的某个数字的倍数

<img src = "C:\Archive\LanQiao\等级考试\Pictures\0012.png">

# 3. 条件运算函数

## 3.1 SUMIFS

对满足条件的数据求总和

<img src = "C:\Archive\LanQiao\等级考试\Pictures\0013.png">

## 3.2 AVERAGEIFS

同上用法，筛选条件，求平均值

## 3.3 COUNTIFS

对满足条件的数据计数

# 4. 判断函数

## 4.1 IF

判断是否满足某个条件，如果满足就返回一个值，不满足则返回另一个值。

## 4.2 IFERROR

如果指定表达式的结果是错误值，则返回指定的值，否则显示原表达式的计算结果。

## 4.3 AND

一个表达式不成立返回false，都成立才返回true。

> 可以搭配IF使用，自定义返回值

## 4.4 OR

一个成立返回true，都不成立返回false

## 4.5 ISODD 和 ISEVEN

**ISODD**：奇数返回true，偶数返回false

# 5. 文本函数

## 5.1 连接符

`&`

<img src = "C:\Archive\LanQiao\等级考试\Pictures\0014.png">

## 5.2 MID

从文本字符串的指定位置开始，提取所要的信息

<img src = "C:\Archive\LanQiao\等级考试\Pictures\0015.png">

> 使用LEFT, RIGHT函数也可以提取信息。起始位置正如函数命名的字面意思上所示。

## 5.3 FIND

查找字符在数据中的位置

> 可以结合上面的MID函数进行数据提取

## 5.4 CLEAN

清除非打印字符

## 5.5 TRIM

清除多余的空格

> SUBSTITUTE函数可以替换文本，将空格替换为没有内容

## 5.6 LEN 和 LENB

**LEN**: 返回文本字符串中的字符个数

**LENB**: 返回所有字符串个数

求汉字个数方法：**LENB - LEN**

## 5.7 N

将不是数值形式的值转换为数值形式

## 5.8 TEXT

将文本转换成指定格式

<img src = "C:\Archive\LanQiao\等级考试\Pictures\0016.png">

# 6. 日期函数

## 6.1 TODAY

根据电脑日期生成函数

> NOW 直接返回日期和时间

## 6.2 DATE 和 TIME

DATE年月日
TIME时分秒

## YEAR, MONTH 和 DAY

返回日期中特定的数值

> HOUR MINUTE SECOND 同理

## WEEKDAY

返回星期几。

## YEARFRAC

返回年与年之间的间隔时长

## DATEDIF

计算两个日期的时间间隔

# 7. 查找引用函数

## VLOOKUP

