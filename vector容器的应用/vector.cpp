#pragma warning(disable:4996)
#include<vector>
#include <iostream>
using namespace std;

void main()
{
	vector <int> myv;				//����vector����myv
	vector <int>::iterator it;		//����myv�����������it
	myv.push_back(1);				//��myvĩβ���Ԫ��1
	it = myv.begin();				//it������ָ��ͷԪ��1
	myv.insert(it, 2);				//��itָ���Ԫ��֮ǰ����Ԫ��2
	myv.push_back(3);				//��myvĩβ���Ԫ��3
	myv.push_back(4);				//��myvĩβ���Ԫ��4
	it = myv.end();					//it������ָ��βԪ��4�ĺ���
	it--;							//it������ָ��βԪ��4
	myv.erase(it);					//ɾ��Ԫ��4
	for ( it = myv.begin(); it < myv.end(); ++it)
	{
		cout << *it << endl;
	}
	system("pause");
}