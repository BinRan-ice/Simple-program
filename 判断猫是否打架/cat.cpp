#include iostream
#include stdlib.h
using namespace std;

int BlackFur = 0;
int GrayFur = 0;
int BrownFur = 0;
int GreenEye1 = 0;
int BlueEye1 = 0;
int BrownEye1 = 0;
int GreenEye2 = 0;
int BlueEye2 = 0;
int BrownEye2 = 0;
int GreenEye3 = 0;
int BlueEye3 = 0;
int BrownEye3 = 0;

class Cat		����һ��è��
{
	public
		string setfurc();
	string seteyec(int i);
	string setfurl();
	void show();
	void getcat();
	private
		int eyec;
	int furc;
	int furl;
};

void Catgetcat()	��ȡè���۾���ëɫ������
{
	eyec = rand() % 3 + 0;
	furc = rand() % 3 + 0;
	furl = rand() % 2 + 0;
}

string Catsetfurc()		�������è��ëɫ
{
	string fur;
	switch (furc)
	{
		case 0
			fur = BLACK;
			BlackFur++;
			seteyec(1);
			break;
			case 1
				fur = GRAY;
				GrayFur++;
				seteyec(2);
				break;
				case 2
					fur = BROWN;
					BrownFur++;
					seteyec(3);
					break;
	}
	return fur;
}

string Catseteyec(int i)	�������è�۾�����ɫ
{
	string eye;
	switch (eyec)
	{
		case 0
			eye = GREEN;
			if (i == 1)
				GreenEye1++;
			if (i == 2)
				GreenEye2++;
			if (i == 3)
				GreenEye3++;
			break;
			case 1
				eye = BLUE;
				if (i == 1)
					BlueEye1++;
				if (i == 2)
					BlueEye2++;
				if (i == 3)
					BlueEye3++;
				break;
				case 2
					eye = BROWN;
					if (i == 1)
						BrownEye1++;
					if (i == 2)
						BrownEye2++;
					if (i == 3)
						BrownEye3++;
					break;
	}
	return eye;
}

string Catsetfurl()		�������èë�ĳ���
{
	string fura;
	switch (furl)
	{
		case 0
			fura = LONG;
			break;
			case 1
				fura = SHORT;
				break;
	}
	return fura;
}

void Catshow()	��ʾ������Ϣ
{
	cout  This cat has;
	setfurc();
	cout   fur and;
	seteyec(0);
	cout   eyes and;
	setfurl();
	cout   fur.endl  endl;
}

void Cheak()		���ë�Ƿ���������д��
{
	if (BlackFur  GrayFur&&GrayFur != 0)
		cout  endl  ��è�ͻ�è����  endl  endl;
	else
	{
		if (GrayFur  BlackFur&&BlackFur != 0)
			cout  endl  ��è�ͻ�è����  endl  endl;
		else
			cout  endl  ��è�ͻ�è������  endl  endl;
	}

	if (BlackFur  BrownFur&&BrownFur != 0)
		cout  endl  ��è����è����  endl  endl;
	else
	{
		if (BrownFur  BlackFur&&BlackFur != 0)
			cout  endl  ��è����è����  endl  endl;
		else
			cout  endl  ��è����è������  endl  endl;
	}

	if (BrownFur  GrayFur&&GrayFur != 0)
		cout  endl  ��è�ͻ�è����  endl  endl;
	else
	{
		if (GrayFur  BrownFur&&BrownFur != 0)
			cout  endl  ��è����è����  endl  endl;
		else
			cout  endl  ��è����è������  endl  endl;
	}
}

int main()
{
	char ch;
	do
	{
		cout  ������س����������è(��ֹ����n)��;
		ch = getchar();
		if (ch == 'n')
		{
			Cat B;
			B.getcat();
			B.show();
		}

	} while (ch != 'n');
	cout  endl  ��è   BlackFur  endl;
	cout  ��è   GrayFur  endl;
	cout  ��è   BrownFur  endl  endl;
	cout---- - �ں�è��---- - endl  endl;
	cout  ����   GreenEye1  endl;
	cout  ����   BlueEye1  endl;
	cout  ����   BrownEye1  endl;
	cout---- - �ڻ�è��---- - endl  endl;
	cout  ����   GreenEye2  endl;
	cout  ����   BlueEye2  endl;
	cout  ����   BrownEye2  endl;
	cout---- - ����è��---- - endl  endl;
	cout  ����   GreenEye3  endl;
	cout  ����   BlueEye3  endl;
	cout  ����   BrownEye3  endl;
	Cheak();
	return 0;
}
