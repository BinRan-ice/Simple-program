#pragma warning(disable:4996)
#include <iostream>
#include<list>
using namespace std;

void disp(list<int>&lst)				//���lst������Ԫ��
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
	list<int>lst;						//����list����lst
	list<int>::iterator it, start, end; 
	lst.push_back(5);					//����������5,2,4,1,3
	lst.push_back(2);
	lst.push_back(4);
	lst.push_back(1);
	lst.push_back(3);
	cout << "��ʼlst: ";
	disp(lst);
	it = lst.begin();					//itָ����Ԫ��5
	start = ++lst.begin();				//startָ��ڶ���Ԫ��2
	end = --lst.end();					//endָ��βԪ��3
	lst.insert(it, start, end);
	cout << "ִ��lst.insert(int,start,end)" << endl;
	cout << "�����lst: ";
	disp(lst);
	lst.reverse();
	cout << "��ת�����";
	disp(lst);
	system("pause");
}