#pragma warning(disable:4996)
#include <iostream>
#include<string>
#include<stdlib.h>
using namespace std;


class myinteger
{
public:
	myinteger(int a = 0);


	~myinteger();



	int get() const;


	void setvalue(int a);



	int addition(myinteger &m2);

public:
	int parseint(const string& str);

private:
	int value;
};

myinteger::myinteger(int a)
{
	value = a;
	cout << "���캯��ִ��" << endl;
}


myinteger::~myinteger()
{
	cout << "��������ִ��" << endl;
}

int myinteger::get() const
{
	return this->value;
}

void myinteger::setvalue(int a)
{
	value = a;
}

int myinteger::addition(myinteger &m2)
{
	return  value + m2.value;

}


int myinteger::parseint(const string& str)
{
	const char* p = str.c_str();
	int i = atoi(p);
	return i;
}

void objplay()
{
	int a, b;
	string str;
	myinteger m1, m2;

	puts("");
	cout << "��������������" << endl;
	cin >> a >> b;
	m1.setvalue(a);
	m2.setvalue(b);
	int sum = m1.addition(m2);
	cout << "a��b�ĺ�Ϊ��" << sum << endl;


	puts("");
	cout << "��������Ҫ������ַ�����" << endl;
	cin >> str;
	cout << "�ַ���ת��Ϊ�������ǣ�" << m1.parseint(str) << endl;
	return;
}
void main()
{
	objplay();
	system("pause");
	return;
}
