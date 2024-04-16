using System;
using System.Collections;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using MySql.Data.MySqlClient;
public class UsrDatabaseManager : MonoBehaviour
{
    private MySqlConnection connection;
    private string serverName = "localhost";
    private string dbName = "UnityGame";//name of database
    private string userName = "root";
    private string password = "123456";
    private string port = "3306";
    public TMP_InputField _username, _password, confirmPassword;
    public Button loginButton;
    public int errorNum;//记录输入密码错误次数
    public GameObject loginStart;
    public GameObject Login_Wrong;
    public GameObject Login_Wrong_3;
    public GameObject UnknownUser;
    public GameObject pwd_usr_null;//错误01：账密为空
    public GameObject signup_success;//提示01：注册成功
    public Toggle toggle;

    void Start()
    {
        string connectionString = "Server=" +serverName + ";Database=" +dbName + ";Uid=" + userName + ";Pwd=" +password +";Port" + ";";
        connection = new MySqlConnection(connectionString);
        connection.Open()
        Debug.Log("连接数据库成功！");
    }
    public void Register()
    {
        string username = _username.text;
        string password = _password.text;
        if (username == "" || password == "")
        {
            pwd_usr_null.SetActive(true);
        }
        else
        {
            string query = "INSERT INTO usersinfo(username, password) VALUES (@username, @password)";
            MySqlCommand cmd = new MySqlCommand(query, connection);
            cmd.Parameters.AddWithValue("@username", username);
            cmd.Parameters.AddWithValue("@password", password);
        
            //执行SQL语句，获取影响的行数
            int rowsAffected = cmd.ExecuteNonQuery();


            if (rowsAffected > 0)
            {
                Debug.Log("注册成功！");
                signup_success.SetActive(true);
            }
            else
            {
                Debug.Log("注册失败！");
            }
            username.text = "";
            password.text = "";
        }
        
    }

    public void Login()
    {
        string username = _username.text;
        string password = _password.text;
        if (username == "" || password == "")
        {
            pwd_usr_null.SetActive(true);
        }
        else
        {
            string query = "SELECT COUNT(*) FROM usersinfo WHERE username=@username AND password=@password";
            MySqlCommand cmd = new MySqlCommand(query, connection);
            cmd.Parameters.AddWithValue("@username", username);
            cmd.Parameters.AddWithValue("@password", password);

	    	object result = cmd.ExecuteScalar();
            int count = Convert.ToInt32(result);
            if(count > 0)
            {
        
                Debug.Log("登录成功");
                loginStart.SetActive(true);
           }
           else
            {
                Login_Wrong.SetActive(true);
                errorNum++;
                password.text = "";
                if (errorNum >= 3)
                {
                    Login_Wrong_3.SetActive(true);

                    errorNum = 0;
                }
        
                else
               {
                    UnknownUser.SetActive(true);
                }
            }
        }
    }
}