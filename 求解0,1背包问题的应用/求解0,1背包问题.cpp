#pragma warning(disable:4996)
#include <iostream>
#include<stdio.h>
#include<vector>
using namespace std;
//����ݼ�
vector<vector<int>> ps;						

//���1~n���ݼ�ps
void Pset(int n)							
{
	//���ݼ�
	vector<vector<int>> ps1;	
	//�ݼ�������
	vector<vector<int>>::iterator it;
	vector<int>s;
	//���{}�ռ���Ԫ��
	ps.push_back(s);
	//ѭ�����1~n
	for (int i = 1; i <= n; i++)
	{
		//ps�����һ���õ����ݼ�
		ps1 = ps;
		for ( it = ps1.begin(); it!=ps1.end(); ++it)
		{
			//��ps1��ÿ��Ԫ�ص�ĩβ���i
			(*it).push_back(i);
		}
		for (it = ps1.begin(); it != ps1.end(); ++it)
		{
			//��ps1��ÿ������Ԫ����ӵ�ps��
			ps.push_back(*it);
		}
	}
}

//�����еķ�������ѷ���
void Knap(int w[], int v[], int W)
{
	//�����ı��
	int count = 0;
	//��ǰ���������������ܼ�ֵ
	int sumw, sumv;
	//��ѷ����ı�ţ����������ܼ�ֵ
	int maxi, maxsumw = 0, maxsumv = 0;
	//�ݼ�������
	vector<vector<int>>::iterator it;
	//�ݼ�Ԫ�ص�����
	vector<int>::iterator sit;
	printf("���\tѡ����Ʒ\t������\t�ܼ�ֵ\t�ܷ�װ��\n");
	//ɨ��ps�е�ÿһ������Ԫ��
	for (it = ps.begin(); it != ps.end(); ++it)
	{
		printf(" %d\t", count + 1);
		sumw = sumv = 0;
		printf("{");
		for (sit = (*it).begin(); sit != (*it).end(); ++sit)
		{
			printf("%d", *sit);
			//w�����±��0��ʼ
			sumw += w[*sit - 1];
			//v�����±��0��ʼ
			sumv += v[*sit - 1];
		}
		printf("}\t\t%d\t%d", sumw, sumv);
		if (sumw<=W)
		{
			printf("\t��\n");
			//�Ƚ������ŷ���
			if (sumv>maxsumv)
			{
				maxsumv = sumv;
				maxsumw = sumw;
				maxi = count;
			}
		}
		else
		{
			printf("\t��\n");
		}
		count++;
	}
	printf("��ѷ���Ϊ��");
	printf("ѡ����Ʒ");
	printf("{");
	for (sit = ps[maxi].begin(); sit != ps[maxi].end(); sit++)
	{
		printf("%d ", *sit);
	}
	printf("},");
	printf("������:%d,�ܼ�ֵ��%d\n", maxsumw, maxsumv);
}

void main()
{
	int n = 4;
	int W = 6;
	int w[] = { 5,3,2,1 };
	int v[] = { 4,4,3,1 };
	Pset(n);
	printf("0/1��������ⷽ��\n",n);
	Knap(w, v, W);
	system("pause");
}