#include <iostream>
#include <cstdlib>
#include<Windows.h>
using namespace std;

bool checkpassword(char* src)
{
	int a = 0;
	int b = 0;
	int c = 0;
	while (*src)		//�ж��ַ����Ƿ�ǿ�
	{
		if (*src >= '0'&&*src <= '9')		//�ж��ַ��Ƿ���0-9֮��
		{
			a++;
		}
		if ((*src >= 'A'&& *src <= 'Z') || (*src >= 'a'&&*src <= 'z'))		//�ж��ַ��Ƿ���a-z��A=Z֮��
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
			cout << "��Ч���룡���������벻�����λ�����ٴγ���" << endl;
			Sleep(2500);			//˯��һ��ʱ�䣬���û�������ʾ
			system("cls");			//�����Ļ�ϵĴ�������
		}
		if (a < 2)
		{
			cout << "��Ч���룡���� ������������������λ" << endl;
			Sleep(2600);
			system("cls");
		}
		if (b < 1)
		{
			cout << "��Ч���룡���� ���������Ҫ������ĸ" << endl;
			Sleep(2700);
			system("cls");
		}
		return false;
	}
}

int main()
{
	cout << "������һ�����룺" << endl;
	char ch[5000];
	fgets(ch, sizeof(ch), stdin);
	bool c = checkpassword(ch);						//��¼checkpassword�ķ���ֵ

	while (c == false)								//���û��������벻����Ҫ��ʱ�����ظ�����
	{
		cout << "�����ٴ�������Ҫ���õ����룺" << endl;
		fgets(ch, sizeof(ch), stdin);
		c = checkpassword(ch);			//��¼checkpassword�ķ���ֵ
	}
	cout << "��Ч���룡����    ��ϲ�����óɹ�" << endl;
	system("pause");
}
