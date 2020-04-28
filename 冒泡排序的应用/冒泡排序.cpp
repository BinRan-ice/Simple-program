#pragma warning(disable:4996)
#include <iostream>
using namespace std;

void disp(int a[], int n)											//���a�е�����Ԫ��
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void BubbleSort(int a[], int n, int i)								//�ݹ��ð������
{
	int j;
	bool exchange;
	if (i==n-1)
	{
		return;
	}
	else
	{
		exchange = false;
		for (j = n - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
				exchange = true;
			}
		}
		if (exchange == false)
		{
			return;
		}
		else
		{
			BubbleSort(a, n, i + 1);
		}
	}
}

void main()
{
	int n = 10;
	int a[] = { 2,5,1,7,10,6,9,4,3,8 };
	printf("����ǰ:");
	disp(a, n);
	BubbleSort(a, n, 0);
	printf("�����");
	disp(a, n);
	system("pause");
}