#pragma warning(disable:4996)
#include <iostream>
#include<set>
using namespace std;

void main()
{
	set<int>s;						//定义set容器s
	set<int>::iterator it;			//定义set容器迭代器it
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(4);
	s.insert(2);
	cout << "s: ";
	for ( it = s.begin(); it != s.end(); it++)
	{
		cout << *it;
	}
	cout << endl;
	multiset<int>ms;				//定义multiset容器ms
	multiset<int>::iterator mit;	//定义multiset容器迭代器mit
	ms.insert(1);
	ms.insert(3);
	ms.insert(2);
	ms.insert(4);
	ms.insert(2);
	cout << "ms: ";
	for (mit = s.begin(); mit != s.end(); mit++)
	{
		cout << *mit;
	}
	cout << endl;
	system("pause");
}