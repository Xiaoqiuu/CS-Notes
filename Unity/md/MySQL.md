-------------
Unity 与 MySQL の 奇妙故事
=============

[TOC]

# 1. 安装环境

## 1. 安装MySQL

在镜像站：http://mirrors.sohu.com/mysql/MySQL-8.0/ 选择`mysql-8.0.28-winx64.msi`

<img src = "C:\Archive\LanQiao\Unity\md\Pictures\0004.png">

运行msi文件，Setup Type选择`custom`，记一下MySQL的安装位置（等一下一会要考）

## 2. 配置环境

选择`计算机 -> 属性 -> 系统高级属性（win11此时已进入设置界面） -> 环境变量`

<img src = "C:\Archive\LanQiao\Unity\md\Pictures\0005.png">

选择系统变量中的`Path`后按下`编辑`，进入编辑环境变量的窗口后选择`新建`，把你刚才安装的MySQL中的Bin文件夹地址填入当中。我这里是安装到了C盘，所以我这里填的是`C:\Program Files\MySQL\MySQL Server 8.0\bin`
（如果你是没有修改安装位置并且找不到MySQL安装位置，你可以尝试在program files里找一下MySQL文件夹，我试了两台电脑，都是默认安装在这里的）
<img src = "C:\Archive\LanQiao\Unity\md\Pictures\0006.png">

## 3. 安装MySQL服务

（因为我安装完了，没截图演示了）

输入以下指令安装MySQL服务
```xml{.line-numbers}
mysqld -install
```

找一下MySQL里的MySQL程序文件夹中有无名叫`data`的文件夹，没有就新建一个空文件夹，就叫`data`

<img src = "C:\Archive\LanQiao\Unity\md\Pictures\0007.png">

控制台cd到刚刚的bin文件夹下，输入初始化指令：

```xml{.line-numbers}
mysqld --initialize
```

如果输入以下指令后能显示服务已启动成功（记得以管理员身份运行cmd），则说明成功安装服务了

```xml{.line-numbers}
net start mysql
```

<img src = "C:\Archive\LanQiao\Unity\md\Pictures\0008.png">

使用下面的指令可以在cmd中关闭MySQL服务：

```xml{.line-numbers}
net stop mysql
```

<img src= "C:\Archive\LanQiao\Unity\md\Pictures\0009.png">

此时还需要修改一下root密码，输入以下指令后，就先不要动这个cmd窗口了：

```xml
mysqld --console --skip-grant-tables --shared-memory
```
新建一个cmd窗口，依次执行以下指令：
```xml{.line-numbers}
mysql

use mysql
```
<a id = "Xiaoqiu_1"></a>
输入以下指令进行密码重置，并修改root密码为`123456`：
```xml{.line-numbers}
update mysql.user set authentication_string="" where user="root";

flush privileges;

ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY '123456';

flush privileges;

quit
```
这时候可以关闭第一个cmd窗口了，在第二个窗口输入以下指令就可以使用MySQL了：

```xml{.line-numbers}
net start mysql

mysql -u root -p
```

## Navicat安装

偷懒了哎嘿>3< 学习为主，学习为主嘛（）

<img src = "C:\Archive\LanQiao\Unity\md\Pictures\0010.png">

## unity plugin (巨坑)

<img src = "C:\Archive\LanQiao\Unity\md\Pictures\0011.png">

在unity导出的工程中调用MyMQL，需要准备`I18N`、`MySql.Data`、`I18N.West`三个插件，这样可以使作品中的MySQL在Windows平台正常运行。

尝试过打包到Android平台，第一是因为`I18N`插件是unity准备给x86平台的，第二是考虑到mysql一般都是安装在server上的，因此放弃安卓平台的mysql内置。（挖坑unity与mysql server对接）

# 2. 创建usersinfo表

## 连接数据库

 打开navicat，点击左上角的`连接`按钮，命名连接名为`UnityFunction`，密码就是刚才设置的。如果你是按照这个教程一步一步来的，密码设置的过程[在这里](#Xiaoqiu_1)。

 <img src = "C:\Archive\LanQiao\Unity\md\Pictures\0012.png">

## 新建数据库

 在左边的导航栏里在UnityGame(你刚刚给连接起的名字)的位置`右键 -> 新建数据库`，配置如图所示（我因为配置过一遍了，新建的界面可能会略有不同，把utf8和数据库名字命好就行，我这里起名为`unitygame`）

 <img src = "C:\Archive\LanQiao\Unity\md\Pictures\0013.png">

 在`表`的位置新建名为`usersinfo`的表，添加字段，名分别为`id`,`username`,`password`,`createtime`。

 <img src = "C:\Archive\LanQiao\Unity\md\Pictures\0014.png">

## 代码实现

创建一个`UsrDatabaseManager`的脚本，

```csharp{.line-numbers}
//using System.Security.Cryptography;//以后的SHA256加密
using UnityEngine;
using UnityEngine.UI;
using TMPro;//我这里文本框使用的TextMeshPro，巨坑
using MySql.Data.MySqlClient;//MySQL调用


public class UsrDatabaseManager : MonoBehaviour
{
    private MySqlConnection connection;
    private string serverName = "localhost";
    private string dbName = "UnityGame";//name of database
    private string userName = "root";
    private string password = "123456";
    private string port = "3306";

    void Start()
    {
        string connectionString = "Server=" + serverName + ";Database=" + dbName + ";Uid=" + userName + ";Pwd=" + password + ";Port=" + port + ";";
        connection = new MySqlConnection(connectionString);
        connection.Open();
        Debug.Log("连接数据库成功！");
    }

    public void Register()
    {
        string username = _username.text;
        string password = _password.text;
        //if (username == "" || password == "")
        //{
        //    Register_panel.SetActive(false);
        //    pwd_usr_null_r.SetActive(true);
        //}
        //else
        //{


        // 检查数据库中是否存在具有给定用户名的用户记录
            string query1 = "SELECT COUNT(*) FROM usersinfo WHERE username = @Username";
            MySqlCommand cmd1 = new MySqlCommand(query1, connection);
            cmd1.Parameters.AddWithValue("@Username", username);
            int count = Convert.ToInt32(cmd1.ExecuteScalar());

        // 根据查询结果提示用户
            if (count > 0)
            {
                //Accout_Same.SetActive(true);
                Debug.Log("用户名已存在，请选择不同的用户名！");
            
            }
            else
            {

                string query2 = "INSERT INTO usersinfo(username, password) VALUES (@username, @password)";
                MySqlCommand cmd = new MySqlCommand(query2, connection);
                cmd.Parameters.AddWithValue("@username", username);
                cmd.Parameters.AddWithValue("@password", password);

                //执行SQL语句，获取影响的行数
                int rowsAffected = cmd.ExecuteNonQuery();


                if (rowsAffected > 0)
                {
                    Debug.Log("注册成功！");
                    //Debug.Log(_password.text);
                    //signup_success.SetActive(true);
                }
                else
                {
                    Debug.Log("注册失败！");
                }
                _username.text = "";
                _password.text = "";
            //}
        }
    }
}
```
