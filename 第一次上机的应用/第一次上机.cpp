#pragma warning(disable:4996)
#include <iostream>
#include"SeqList.h"
using namespace std;

void main()
{
	int num1,num2,num3,num4;
	int search;
	cout << "�������һ������Ҫ�����Ԫ�ظ���:";
	cin >> num1;
	SeqList a(num1);
	a.InitList();
	a.PrintList();
	cout << "��������Ҫ���ҵ�Ԫ��:";
	cin >> search;
	a.Locate(search);
	cout << endl;
	a.Symmetry();
	cout << "��������������ǰż���ں�Ľ����";
	a.ParitySort();
	puts(" ");
	cout << "������ڶ�������Ҫ�����Ԫ�ظ���:";
	cin >> num2;
	SeqList b(num2);
	b.InitList();
	cout << "����ǰ:" << endl;
	b.PrintList();
	b.Bubblesort(num2);
	cout << "�����" << endl;
	b.PrintList();
	puts(" ");
	cout << "���������������Ҫ�����Ԫ�ظ���:";
	cin >> num3;
	SeqList c(num3);
	c.InitList();
	c.Bubblesort(num3);
	cout << "�����" << endl;
	c.PrintList();
	puts(" ");
	cout << "��������ĸ�����Ҫ�����Ԫ�ظ���:";
	cin >> num4;
	SeqList d(num4);
	d.InitList();
	d.Bubblesort(num4);
	cout << "�����" << endl;
	d.PrintList();
	SeqList e(num3 + num4);
	puts(" ");
	cout << "��������+���ĸ����������Ϊ��" << endl;
	e.CombineSort(c,d,num3+num4);
	e.PrintList();
	system("pause");
}