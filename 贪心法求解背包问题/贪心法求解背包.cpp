#pragma warning(disable:4996)
#include <iostream>
#include<algorithm>
using namespace std;
#define MAXN 51
int n = 5;
double W = 100;
struct NodeType
{
	double w;
	double v;
	double p;
	bool operator<(const NodeType& s)const
	{
		return p > s.p;
	}
};
NodeType A[] = { {0},{10,20},{20,30},{30,66},{40,40},{50,60} };
double V;
double x[MAXN];
void Knip()
{
	V = 0;
	double weight = W;
	memset(x, 0, sizeof(x));
	int i = 1;
	while (A[i].w<weight)
	{
		x[i] = 1;
		weight -= A[i].w;
		V += A[i].v;
		i++;
	}
	if (weight>0)
	{
		x[i] = weight / A[i].w;
		V += x[i] * A[i].v;
	}
}

void dispA()
{
	int i;
	printf("\tW\tV\tV/W\n");
	for ( i = 1; i <=n ; i++)
	{
		printf("\t%g\t%g\t%3.1f\n", A[i].w, A[i].v, A[i].p);
	}
}

void main()
{
	printf("求解过程\n");
	for (int i = 1; i <=n ; i++)
	{
		A[i].p = A[i].v / A[i].w;
	}
	printf("(1)排序前\n");
	dispA();
	sort(A + 1, A + n + 1);
	printf("(2)排序后\n");
	dispA();
	Knip();
	printf("(3）求解结果\n");
	printf("x: [");
	for (int j = 1; j <=n ; j++)
	{
		printf("%g, ", x[j]);
	}
	printf("%g]\n", x[n]);
	printf(" 总价值=%g\n", V);
	system("pause");
}