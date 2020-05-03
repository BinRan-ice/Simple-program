#pragma warning(disable:4996)
#include<vector>
#include <iostream>
using namespace std;
vector<vector<int>> ps;							//存放幂集

void PSet(int n)								//求1~n的幂集ps
{
	vector<vector<int>> ps1;					//子幂集
	vector<vector<int>>::iterator it;			//幂集迭代器
	vector<int> s;
	ps.push_back(s);							//添加空集合元素
	for (int i = 1; i <= n; i++)					//循环添加1~n
	{
		ps1 = ps;
		for ( it = ps1.begin(); it !=ps1.end(); ++it)
		{
			(*it).push_back(i);
		}
		for (it = ps1.begin(); it != ps1.end(); ++it)
		{
			ps.push_back(*it);
		}
	}
}

void dispps()
{
	vector<vector<int>>::iterator it;
	vector<int>::iterator sit;
	for (it = ps.begin(); it != ps.end(); ++it)
	{
		printf("{");
		for (sit=(*it).begin(); sit!=(*it).end(); ++sit)
		{
			printf("%d", *sit);
		}
		printf("}");
	}
	printf("\n");
}

void main()
{
	int n = 3;
	PSet(n);
	printf("1~%d的幂集:\n", n);
	dispps();
	system("pause");
}