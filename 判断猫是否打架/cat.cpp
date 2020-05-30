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

class Cat		定义一个猫类
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

void Catgetcat()	获取猫的眼睛，毛色，长度
{
	eyec = rand() % 3 + 0;
	furc = rand() % 3 + 0;
	furl = rand() % 2 + 0;
}

string Catsetfurc()		随机生成猫的毛色
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

string Catseteyec(int i)	随机生成猫眼睛的颜色
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

string Catsetfurl()		随机生成猫毛的长短
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

void Catshow()	显示最终信息
{
	cout  This cat has;
	setfurc();
	cout   fur and;
	seteyec(0);
	cout   eyes and;
	setfurl();
	cout   fur.endl  endl;
}

void Cheak()		检查毛是否会在笼子中打架
{
	if (BlackFur  GrayFur&&GrayFur != 0)
		cout  endl  黑猫和灰猫会打架  endl  endl;
	else
	{
		if (GrayFur  BlackFur&&BlackFur != 0)
			cout  endl  黑猫和灰猫会打架  endl  endl;
		else
			cout  endl  黑猫和灰猫不会打架  endl  endl;
	}

	if (BlackFur  BrownFur&&BrownFur != 0)
		cout  endl  黑猫和棕猫会打架  endl  endl;
	else
	{
		if (BrownFur  BlackFur&&BlackFur != 0)
			cout  endl  黑猫和棕猫会打架  endl  endl;
		else
			cout  endl  黑猫和棕猫不会打架  endl  endl;
	}

	if (BrownFur  GrayFur&&GrayFur != 0)
		cout  endl  棕猫和灰猫会打架  endl  endl;
	else
	{
		if (GrayFur  BrownFur&&BrownFur != 0)
			cout  endl  灰猫和棕猫会打架  endl  endl;
		else
			cout  endl  灰猫和棕猫不会打架  endl  endl;
	}
}

int main()
{
	char ch;
	do
	{
		cout  请输入回车键生成随机猫(终止输入n)：;
		ch = getchar();
		if (ch == 'n')
		{
			Cat B;
			B.getcat();
			B.show();
		}

	} while (ch != 'n');
	cout  endl  黑猫   BlackFur  endl;
	cout  灰猫   GrayFur  endl;
	cout  棕猫   BrownFur  endl  endl;
	cout---- - 在黑猫中---- - endl  endl;
	cout  绿眼   GreenEye1  endl;
	cout  蓝眼   BlueEye1  endl;
	cout  棕眼   BrownEye1  endl;
	cout---- - 在灰猫中---- - endl  endl;
	cout  绿眼   GreenEye2  endl;
	cout  蓝眼   BlueEye2  endl;
	cout  棕眼   BrownEye2  endl;
	cout---- - 在棕猫中---- - endl  endl;
	cout  绿眼   GreenEye3  endl;
	cout  蓝眼   BlueEye3  endl;
	cout  棕眼   BrownEye3  endl;
	Cheak();
	return 0;
}
