#include <graphics.h>
#include <conio.h>
#include<iostream>
#define MAX 500
using namespace std;
COLORREF color1 = 0, color2 = 0, color3 = 0, color4 = 0, color5 = 0;
//绘制原始图形
void paint(int a[], int b[], COLORREF col[MAX + 1][MAX + 1])
{
	// 初始化绘图窗口
	initgraph(500, 500);
	for (int i = 0; i <= MAX; i++)
	{
		a[i] = i;
		for (int j = 0; j <= MAX; j++)
		{
			b[j] = j;
			putpixel(b[j], a[i], 0x555555);

		}
	}
	//绘制指定填充图案6
	//setfillstyle(BS_HATCHED, HS_BDIAGONAL, NULL);
	setfillcolor(0xFFFFFF);
	solidrectangle(b[100], a[0], b[200], a[100]);
	solidrectangle(b[200], a[0], b[300], a[100]);
	solidrectangle(b[300], a[0], b[400], a[100]);
	solidrectangle(b[100], a[100], b[200], a[200]);
	solidrectangle(b[100], a[200], b[200], a[300]);
	solidrectangle(b[200], a[200], b[300], a[300]);
	solidrectangle(b[300], a[200], b[400], a[300]);
	solidrectangle(b[100], a[300], b[200], a[400]);
	solidrectangle(b[300], a[300], b[400], a[400]);
	solidrectangle(b[100], a[400], b[200], a[500]);
	solidrectangle(b[200], a[400], b[300], a[500]);
	solidrectangle(b[300], a[400], b[400], a[500]);
	//保存当前画布上各点的像素值
	for (int i = 0; i <= MAX; i++)
	{
		a[i] = i;
		for (int j = 0; j <= MAX; j++)
		{
			b[j] = j;
			color1 = getpixel(b[j], a[i]);
			putpixel(b[j], a[i], color1);
			col[i][j] = color1;
		}
	}
}

//沿行方向扩充画布并填充像素点
void filling1(int c[], int d[], COLORREF col[MAX + 1][MAX + 1])
{
	Resize(NULL, 1000, 500);
	//清屏
	cleardevice();
	//填充扩大画布后没有像素点的位置
	for (int i = 0; i <= MAX; i++)
	{
		c[i] = i;
		for (int j = 0; j <= MAX; j++)
		{
			d[2 * j] = 2 * j;
			putpixel(d[2 * j], c[i], col[i][j]);
		}
		for (int j = 0; j <= MAX; j++)
		{
			d[(2 * j) + 1] = (2 * j) + 1;
			//用拉格朗日三次插值计算插点的像素值
			color2 = (double)(-217 / 48) * (getpixel(d[(2 * j)], c[i]));
			color3 = (double)(-5 / 16)   * (getpixel(d[(2 * j) + 2], c[i]));
			color4 = (double)(15 / 16)   * (getpixel(d[(2 * j) + 4], c[i]));
			color5 = (double)(15 / 48)   * (getpixel(d[(2 * j) + 6], c[i]));
			putpixel(d[(2 * j) + 1], c[i], color2 + color3 + color4 + color5);
		}
	}
}


void filling2(int c[], int d[])
{
	//建立存放当前500*1000画布上每点的像素值
	COLORREF **col2 = new COLORREF*[MAX + 1];
	for (int i = 0; i < MAX + 1; ++i)
	{
		col2[i] = new COLORREF[1000 + 1];
		for (int j = 0; j < 1000 + 1; ++j)
		{
			col2[i][j] = getpixel(d[j], c[i]);
		}
	}
	Resize(NULL, 1000, 1000);
	//清屏
	cleardevice();
	for (int i = 0; i <= 1000; i++)
	{
		c[i] = i;
		if (c[i] % 2 == 0)
		{
			for (int j = 0; j <= 1000; j++)
			{
				putpixel(d[j], c[i], col2[i / 2][j]);
			}
		}
	}
	for (int i = 0; i <= 1000; i++)
	{
		c[i] = i;
		if (c[i] % 2 == 1)
		{
			for (int j = 0; j <= 1000; j++)
			{
				//用拉格朗日三次插值计算插点的像素值
				color2 = (double)(-217 / 48) * (getpixel(d[j], c[i - 1]));
				color3 = (double)(-5 / 16)   * (getpixel(d[j], c[i + 1]));
				color4 = (double)(15 / 16)   * (getpixel(d[j], c[i + 3]));
				color5 = (double)(15 / 48)   * (getpixel(d[j], c[i + 5]));
				putpixel(d[j], c[i], col2[i / 2][j]);
			}
		}
	}
	delete[] col2;
}

int main()
{
	int a[MAX + 1] = { 0 };
	int b[MAX + 1] = { 0 };
	int c[1000 + 1] = { 0 };
	int d[1000 + 1] = { 0 };
	COLORREF col[MAX + 1][MAX + 1] = { 0 };
	//绘制原始图形
	paint(a, b, col);

	//沿行方向扩充画布500*1000
	filling1(c, d, col);

	//沿列方向扩充画布1000*1000
	filling2(c, d);

	// 按任意键退出
	_getch();
	closegraph();
}
