#pragma warning(disable:4996)
#include <iostream>
using namespace std;

int answer(int a[], int n, int c)								//�����������ĸ���count
{
	int i = 0;
	int count = 0;
	for ( i ; i < n; i++)										//���������е������λ�������������������������������ͬʱ����
	{
		for (int j=0; j<n ; j++)
		{
			if ((a[i]-a[j])==c)
			{
				count++;
			}
		}
	}
	return count;
}

void main()
{
	int n, c;
	int a[1000];													//����һ���������ڴ��N����
	cout << "��������Ҫ�������������N(<1000)��������C��";
	cin >> n >> c;
	for (int i = 0; i < n; i++)										//��N�����ֱ��������
	{
		cin >> a[i];
	}
	int sum=answer(a, n, c);										//ͳ�Ʒ��������ĸ���
	cout << "����ʽ�ӵĴ𰸸���Ϊ��" << sum << endl;
	system("pause");
}