#include <graphics.h>
#include <conio.h>
#include<iostream>
#define MAX 500
using namespace std;
COLORREF color1 = 0, color2 = 0, color3 = 0, color4 = 0, color5 = 0;
//����ԭʼͼ��
void paint(int a[], int b[], COLORREF col[MAX + 1][MAX + 1])
{
	// ��ʼ����ͼ����
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
	//����ָ�����ͼ��6
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
	//���浱ǰ�����ϸ��������ֵ
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

//���з������仭����������ص�
void filling1(int c[], int d[], COLORREF col[MAX + 1][MAX + 1])
{
	Resize(NULL, 1000, 500);
	//����
	cleardevice();
	//������󻭲���û�����ص��λ��
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
			//�������������β�ֵ�����������ֵ
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
	//������ŵ�ǰ500*1000������ÿ�������ֵ
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
	//����
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
				//�������������β�ֵ�����������ֵ
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
	//����ԭʼͼ��
	paint(a, b, col);

	//���з������仭��500*1000
	filling1(c, d, col);

	//���з������仭��1000*1000
	filling2(c, d);

	// ��������˳�
	_getch();
	closegraph();
}