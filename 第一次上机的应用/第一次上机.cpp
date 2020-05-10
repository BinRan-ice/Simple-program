#pragma warning(disable:4996)
#include <iostream>
#include"SeqList.h"
using namespace std;

void main()
{
	int num1,num2,num3,num4;
	int search;
	cout << "请输入第一个表你要输入的元素个数:";
	cin >> num1;
	SeqList a(num1);
	a.InitList();
	a.PrintList();
	cout << "请输入你要查找的元素:";
	cin >> search;
	a.Locate(search);
	cout << endl;
	a.Symmetry();
	cout << "表中所有奇数在前偶数在后的结果：";
	a.ParitySort();
	puts(" ");
	cout << "请输入第二个表你要输入的元素个数:";
	cin >> num2;
	SeqList b(num2);
	b.InitList();
	cout << "排序前:" << endl;
	b.PrintList();
	b.Bubblesort(num2);
	cout << "排序后：" << endl;
	b.PrintList();
	puts(" ");
	cout << "请输入第三个表你要输入的元素个数:";
	cin >> num3;
	SeqList c(num3);
	c.InitList();
	c.Bubblesort(num3);
	cout << "排序后：" << endl;
	c.PrintList();
	puts(" ");
	cout << "请输入第四个表你要输入的元素个数:";
	cin >> num4;
	SeqList d(num4);
	d.InitList();
	d.Bubblesort(num4);
	cout << "排序后：" << endl;
	d.PrintList();
	SeqList e(num3 + num4);
	puts(" ");
	cout << "第三个表+第四个表后排序结果为：" << endl;
	e.CombineSort(c,d,num3+num4);
	e.PrintList();
	system("pause");
}