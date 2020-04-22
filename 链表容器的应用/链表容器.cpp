#pragma warning(disable:4996)
#include <iostream>
#include<list>
using namespace std;

void disp(list<int>&lst)				//输出lst的所有元素
{
	list<int>::iterator it;
	for ( it = lst.begin(); it != lst.end(); it++)
	{
		cout << *it <<"\t";
	}
	cout << endl;
}

void main()
{
	list<int>lst;						//定义list容器lst
	list<int>::iterator it, start, end; 
	lst.push_back(5);					//添加五个整数5,2,4,1,3
	lst.push_back(2);
	lst.push_back(4);
	lst.push_back(1);
	lst.push_back(3);
	cout << "初始lst: ";
	disp(lst);
	it = lst.begin();					//it指向首元素5
	start = ++lst.begin();				//start指向第二个元素2
	end = --lst.end();					//end指向尾元素3
	lst.insert(it, start, end);
	cout << "执行lst.insert(int,start,end)" << endl;
	cout << "插入后lst: ";
	disp(lst);
	lst.reverse();
	cout << "反转链表后：";
	disp(lst);
	system("pause");
}