#pragma warning(disable:4996)
#include<vector>
#include <iostream>
using namespace std;
vector<vector<int>> ps;							//����ݼ�

void PSet(int n)								//��1~n���ݼ�ps
{
	vector<vector<int>> ps1;					//���ݼ�
	vector<vector<int>>::iterator it;			//�ݼ�������
	vector<int> s;
	ps.push_back(s);							//��ӿռ���Ԫ��
	for (int i = 1; i <= n; i++)					//ѭ�����1~n
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
	printf("1~%d���ݼ�:\n", n);
	dispps();
	system("pause");
}