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
	deque<int>dq;				//����һ��˫�˶���dq
	dq.push_front(1);			//�ڶ�ͷ����1
	dq.push_back(2);			//�ڶ�β����2
	dq.push_front(3);			//�ڶ�ͷ����3
	dq.push_back(4);			//�ڶ�β����4
	cout << "dq: "<<endl;
	disp(dq);
	dq.pop_front();				//ɾ����ͷԪ��
	dq.pop_back();				//ɾ����βԪ��
	cout << "dq: "<<endl;
	disp(dq);
	system("pause");
}