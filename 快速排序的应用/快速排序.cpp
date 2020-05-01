#pragma warning(disable:4996)
#include <iostream>
using namespace std;

void disp(int a[], int n)								//���a�е�����Ԫ��
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	cout << endl;
}

int Partition(int a[], int s, int t)					//�����㷨
{
	int i = s, j = t;
	int tmp = a[s];										//�����еĵ�һ����¼��Ϊ��׼
	while (i != j)										//���������˽������м�ɨ�裬ֱ��i=jΪֹ
	{
		while (j > i&&a[j] >= tmp)
		{
			j--;										//��������ɨ�裬�ҵ�һ���ؼ���С��tmp��a[j]
		}
		a[i] = a[j];									//��a[j]ǰ�Ƶ�a[i]��λ��
		while (i < j&&a[i] <= tmp)
		{
			i++;										//��������ɨ�裬�ҵ�һ���ؼ��ִ���tmp��a[i]
		}
		a[j] = a[i];									//��a[i]���Ƶ�a[j]��λ��
	}
		a[i] = tmp;
		return i;

}

void QuickSort(int a[], int s, int t)					//��[s..t]Ԫ�����н��е�������
{
	if (s<t)											//���������ٴ�������Ԫ�ص����
	{
		int i = Partition(a, s, t);
		QuickSort(a, s, i - 1);
		QuickSort(a, i + 1, t);
	}
}

void main()
{
	int n = 10;
	int a[] = { 2,5,1,7,10,6,9,4,3,8 };
	printf("����ǰ��");
	disp(a, n);
	QuickSort(a, 0, n - 1);
	printf("�����");
	disp(a, n);
	system("pause");
}