#pragma warning(disable:4996)
#include <iostream>
using namespace std;

void disp(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void Merge(int a[], int low, int mid, int high)				//��a[low..mid]��a[mid+1..high]�������ڵ����������й鲢Ϊһ������������a[low..high]
{
	int *tmpa;
	int i = low, j = mid + 1, k = 0;						//k��tmpa���±꣬i,j�ֱ��������ӱ���±�
	tmpa = (int*)malloc((high - low + 1) * sizeof(int));
	while (i<=mid&&j<=high)									//�ڵ�һ���ӱ�͵ڶ����ӱ��δɨ����ʱѭ��
	{
		if (a[i]<=a[j])										//����һ���ӱ��е�Ԫ�ط���tmpa��
		{
			tmpa[k] = a[i];
			i++;
			k++;
		}
		else												//���ڶ����ӱ��е�Ԫ�ط���tmpa��
		{
			tmpa[k] = a[j];									
			tmpa[k] = a[j];									
			j++;
			k++;
		}
	}
	while (i<=mid)											//����һ���ӱ����µĲ��ָ��Ƶ�tmpa
	{
		tmpa[k] = a[i];
		i++;
		k++;
	}
	while (j<=high)											//���ڶ����ӱ����µĲ��ָ��Ƶ�tmpa
	{
		tmpa[k] = a[j];
		j++;
		k++;
	}
	for (k=0,i=low;i<=high;k++,i++)
	{
		a[i] = tmpa[k];
	}
	free(tmpa);
}


void MergePass(int a[], int length, int n)					//һ�˶�·�鲢����
{
	int i;
	for ( i = 0; i+2*length-1<n; i=i+2*length)
	{
		Merge(a, i, i + length - 1, i + 2 * length-1);
	}
	if (i+length-1<n)										//���������ӱ����ߵĳ���С��length
	{
		Merge(a, i, i + length - 1, n - 1);					//�鲢�������ӱ�
	}
}

void MergeSort(int a[], int n)								//��·�鲢�㷨
{
	int length;
	for ( length = 1; length < n; length=2*length)
	{
		MergePass(a, length,n);
	}
}

void main()
{
	int n = 10;
	int a[] = { 2,5,1,7,10,6,9,4,3,8 };
	printf("����ǰ��");
	disp(a, n);
	MergeSort(a, n);
	printf("�����");
	disp(a, n);
	system("pause");
}