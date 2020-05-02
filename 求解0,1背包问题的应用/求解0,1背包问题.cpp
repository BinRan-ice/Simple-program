#pragma warning(disable:4996)
#include <iostream>
#include<stdio.h>
#include<vector>
using namespace std;
//存放幂集
vector<vector<int>> ps;						

//存放1~n的幂集ps
void Pset(int n)							
{
	//子幂集
	vector<vector<int>> ps1;	
	//幂集迭代器
	vector<vector<int>>::iterator it;
	vector<int>s;
	//添加{}空集合元素
	ps.push_back(s);
	//循环添加1~n
	for (int i = 1; i <= n; i++)
	{
		//ps存放上一步得到的幂集
		ps1 = ps;
		for ( it = ps1.begin(); it!=ps1.end(); ++it)
		{
			//在ps1的每个元素的末尾添加i
			(*it).push_back(i);
		}
		for (it = ps1.begin(); it != ps1.end(); ++it)
		{
			//将ps1的每个集合元素添加到ps中
			ps.push_back(*it);
		}
	}
}

//求所有的方案和最佳方案
void Knap(int w[], int v[], int W)
{
	//方案的编号
	int count = 0;
	//当前方案的总重量和总价值
	int sumw, sumv;
	//最佳方案的编号，总重量和总价值
	int maxi, maxsumw = 0, maxsumv = 0;
	//幂集迭代器
	vector<vector<int>>::iterator it;
	//幂集元素迭代器
	vector<int>::iterator sit;
	printf("序号\t选中物品\t总重量\t总价值\t能否装入\n");
	//扫描ps中的每一个集合元素
	for (it = ps.begin(); it != ps.end(); ++it)
	{
		printf(" %d\t", count + 1);
		sumw = sumv = 0;
		printf("{");
		for (sit = (*it).begin(); sit != (*it).end(); ++sit)
		{
			printf("%d", *sit);
			//w数组下标从0开始
			sumw += w[*sit - 1];
			//v数组下标从0开始
			sumv += v[*sit - 1];
		}
		printf("}\t\t%d\t%d", sumw, sumv);
		if (sumw<=W)
		{
			printf("\t能\n");
			//比较求最优方案
			if (sumv>maxsumv)
			{
				maxsumv = sumv;
				maxsumw = sumw;
				maxi = count;
			}
		}
		else
		{
			printf("\t否\n");
		}
		count++;
	}
	printf("最佳方案为：");
	printf("选中物品");
	printf("{");
	for (sit = ps[maxi].begin(); sit != ps[maxi].end(); sit++)
	{
		printf("%d ", *sit);
	}
	printf("},");
	printf("总重量:%d,总价值：%d\n", maxsumw, maxsumv);
}

void main()
{
	int n = 4;
	int W = 6;
	int w[] = { 5,3,2,1 };
	int v[] = { 4,4,3,1 };
	Pset(n);
	printf("0/1背包的求解方案\n",n);
	Knap(w, v, W);
	system("pause");
}