#pragma warning(disable:4996)
#include <iostream>
#include<map>
using namespace std;

void main()
{
	map<char, int>mymap;										//����map����mymap
	mymap.insert(pair<char, int>('a', 1));						//���뷽ʽ1
	mymap.insert(map<char, int>::value_type('b', 2));			//���뷽ʽ2
	mymap['c'] = 3;												//���뷽ʽ3
	map<char, int>::iterator it;
	for ( it = mymap.begin(); it != mymap.end(); it++)
	{
		printf("[%c,%d]", it->first, it->second);
	}
	cout << endl;
	system("pause");
}