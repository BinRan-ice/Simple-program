#include <iostream>
#include <cstdlib>
#include<Windows.h>
using namespace std;

bool checkpassword(char* src)
{
	int a = 0;
	int b = 0;
	int c = 0;
	while (*src)		//判断字符串是否非空
	{
		if (*src >= '0'&&*src <= '9')		//判断字符是否在0-9之间
		{
			a++;
		}
		if ((*src >= 'A'&& *src <= 'Z') || (*src >= 'a'&&*src <= 'z'))		//判断字符是否在a-z和A=Z之间
		{
			b++;
		}
		if ((*src >= 'A'&&*src <= 'Z') || (*src >= 'a'&&*src <= 'z') || (*src >= '0'&&*src <= '9'))
		{
			c++;
		}
		src++;
	}
	if (a >= 2 && b >= 1 && c >= 8)
	{
		return true;
	}
	else
	{
		if (c < 8)
		{
			cout << "无效密码！！！该密码不满足八位数请再次尝试" << endl;
			Sleep(2500);			//睡眠一定时间，给用户错误提示
			system("cls");			//清除屏幕上的错误密码
		}
		if (a < 2)
		{
			cout << "无效密码！！！ 该密码中数字少于两位" << endl;
			Sleep(2600);
			system("cls");
		}
		if (b < 1)
		{
			cout << "无效密码！！！ 该密码必须要含有字母" << endl;
			Sleep(2700);
			system("cls");
		}
		return false;
	}
}

int main()
{
	cout << "请输入一个密码：" << endl;
	char ch[5000];
	fgets(ch, sizeof(ch), stdin);
	bool c = checkpassword(ch);						//记录checkpassword的返回值

	while (c == false)								//当用户输入密码不符合要求时进行重复操作
	{
		cout << "请您再次输入您要设置的密码：" << endl;
		fgets(ch, sizeof(ch), stdin);
		c = checkpassword(ch);			//记录checkpassword的返回值
	}
	cout << "有效密码！！！    恭喜您设置成功" << endl;
	system("pause");
}
