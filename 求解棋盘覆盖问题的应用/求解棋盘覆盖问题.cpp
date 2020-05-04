#pragma warning(disable:4996)
#include <iostream>
#define MAX 1025
using namespace std;
//问题表示
int k;																//棋盘大小
int x, y;															//特殊方格的位置
//求解问题表示
int board[MAX][MAX];
int tile = 1;														//L型骨牌的编号，从1开始

void ChessBard(int tr, int tc, int dr, int dc, int size)
{
	if (size == 1)													//递归出口
	{
		return;
	}
	int t = tile++;													//取一个L型骨牌，其牌号为tile
	int s = size / 2;
	//考虑左上角象限
	if (dr < tr + s && dc < tc + s)											//特殊方格在此象限中
	{
		ChessBard(tr, tc, dr, dc, s);
	}
	else															//此象限中无特殊方格
	{
		board[tr + s - 1][tc + s - 1] = t;							//用t号L型骨牌覆盖右下角
		ChessBard(tr, tc, tr + s - 1, tc + s - 1, s);				//将右下角作为特殊方格继续处理该象限
	}
	//考虑右上角象限
	if (dr < tr + s && dc >= tc + s)									//特殊方格在此象限中
	{
		ChessBard(tr, tc + s, dr, dc, s);
	}
	else															//此象限中无特殊方格
	{
		board[tr + s - 1][tc + s] = t;							    //用t号L型骨牌覆盖右下角
		ChessBard(tr, tc + s, tr + s - 1, tc + s, s);				//将左下角作为特殊方格继续处理该象限
	}
	//考虑左下角象限
	if (dr >= tr + s && dc < tc + s)									//特殊方格在此象限中
	{
		ChessBard(tr + s, tc, dr, dc, s);
	}
	else															//此象限中无特殊方格
	{
		board[tr + s][tc + s - 1] = t;							    //用t号L型骨牌覆盖右下角
		ChessBard(tr + s, tc, tr + s, tc + s - 1, s);				    //将右上角作为特殊方格继续处理该象限
	}
	//考虑右下角象限
	if (dr >= tr + s && dc >= tc + s)								//特殊方格在此象限中
	{
		ChessBard(tr + s, tc + s, dr, dc, s);
	}
	else															//此象限中无特殊方格
	{
		board[tr + s][tc + s] = t;							        //用t号L型骨牌覆盖右下角
		ChessBard(tr + s, tc + s, tr + s, tc + s, s);			    //将左上角作为特殊方格继续处理该象限
	}
}

void main()
{
	k = 3;
	x = 5;
	y = 5;
	int size = 1 << k;
	ChessBard(0, 0, x, y, size);
	for (int i = 0; i < size; i++)									//输出覆盖方案
	{
		for (int j = 0; j < size; j++)
		{
			printf("%4d", board[i][j]);
		}
		printf("\n");
	}
	system("pause");
}