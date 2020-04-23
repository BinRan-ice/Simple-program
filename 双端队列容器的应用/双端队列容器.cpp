#pragma warning(disable:4996)
#include <iostream>
#include <deque>
using namespace std;

void disp(deque<int>&dq)
{
	deque<int>::iterator iter;
	for ( iter = dq.begin(); iter < dq.end(); iter++)
	{
		cout << *iter << endl;
	}
}

void main()
{
	deque<int>dq;				//建立一个双端队列dq
	dq.push_front(1);			//在队头插入1
	dq.push_back(2);			//在队尾插入2
	dq.push_front(3);			//在队头插入3
	dq.push_back(4);			//在队尾插入4
	cout << "dq: "<<endl;
	disp(dq);
	dq.pop_front();				//删除队头元素
	dq.pop_back();				//删除队尾元素
	cout << "dq: "<<endl;
	disp(dq);
	system("pause");
}