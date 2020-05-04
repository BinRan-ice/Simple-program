#pragma warning(disable:4996)
#include <iostream>
#define MAX 1025
using namespace std;
//�����ʾ
int k;																//���̴�С
int x, y;															//���ⷽ���λ��
//��������ʾ
int board[MAX][MAX];
int tile = 1;														//L�͹��Ƶı�ţ���1��ʼ

void ChessBard(int tr, int tc, int dr, int dc, int size)
{
	if (size == 1)													//�ݹ����
	{
		return;
	}
	int t = tile++;													//ȡһ��L�͹��ƣ����ƺ�Ϊtile
	int s = size / 2;
	//�������Ͻ�����
	if (dr < tr + s && dc < tc + s)											//���ⷽ���ڴ�������
	{
		ChessBard(tr, tc, dr, dc, s);
	}
	else															//�������������ⷽ��
	{
		board[tr + s - 1][tc + s - 1] = t;							//��t��L�͹��Ƹ������½�
		ChessBard(tr, tc, tr + s - 1, tc + s - 1, s);				//�����½���Ϊ���ⷽ��������������
	}
	//�������Ͻ�����
	if (dr < tr + s && dc >= tc + s)									//���ⷽ���ڴ�������
	{
		ChessBard(tr, tc + s, dr, dc, s);
	}
	else															//�������������ⷽ��
	{
		board[tr + s - 1][tc + s] = t;							    //��t��L�͹��Ƹ������½�
		ChessBard(tr, tc + s, tr + s - 1, tc + s, s);				//�����½���Ϊ���ⷽ��������������
	}
	//�������½�����
	if (dr >= tr + s && dc < tc + s)									//���ⷽ���ڴ�������
	{
		ChessBard(tr + s, tc, dr, dc, s);
	}
	else															//�������������ⷽ��
	{
		board[tr + s][tc + s - 1] = t;							    //��t��L�͹��Ƹ������½�
		ChessBard(tr + s, tc, tr + s, tc + s - 1, s);				    //�����Ͻ���Ϊ���ⷽ��������������
	}
	//�������½�����
	if (dr >= tr + s && dc >= tc + s)								//���ⷽ���ڴ�������
	{
		ChessBard(tr + s, tc + s, dr, dc, s);
	}
	else															//�������������ⷽ��
	{
		board[tr + s][tc + s] = t;							        //��t��L�͹��Ƹ������½�
		ChessBard(tr + s, tc + s, tr + s, tc + s, s);			    //�����Ͻ���Ϊ���ⷽ��������������
	}
}

void main()
{
	k = 3;
	x = 5;
	y = 5;
	int size = 1 << k;
	ChessBard(0, 0, x, y, size);
	for (int i = 0; i < size; i++)									//������Ƿ���
	{
		for (int j = 0; j < size; j++)
		{
			printf("%4d", board[i][j]);
		}
		printf("\n");
	}
	system("pause");
}