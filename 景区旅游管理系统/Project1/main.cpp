#pragma warning(disable:4996)
#include<iostream>
#include"Tourism.h"
#include<graphics.h>
#include<time.h>
#include<conio.h>
using namespace std;

void doChoose();
void output();

int main()
{

	doChoose();
	system("pause");
	return 0;
}

void doChoose()
{
	int nSection = -1;
	do {
		system("cls");
		output();//չʾ�˵�
		nSection = -1;
		cin >> nSection;
		switch (nSection) {
		case 1: {
			CreateGraph();
			break;
		}
		case 2: {
			OutGraph();
			break;
		}
		case 3: {
			GetSpotInfo();
			break;
		}
		case 4: {
			TravelPath();
			break;
		}
		case 5: {
			TopoSort_matrix();
			break;
		}
		case 6: {
			FindShortPath();
			break;
		}
		case 7: {
			DesignPath();
			break;
		}
		default:
			break;
		}
	} while (nSection != 0);
}

void output()
{
	cout << "!!!!!!!!!!!!!��ȷ���������в����ڽ���ͼ�����!!!!!!!!!!!!!!!!" << endl;
	cout << "================��ӭ������������ϵͳ=============" << endl;
	cout << "*************************************************" << endl;
	cout << "*                1.��������ͼ                   *" << endl;
	cout << "*                2.�������ֲ�ͼ����           *" << endl;
	cout << "*                3.��ѯ������Ϣ                 *" << endl;
	cout << "*                4.���ξ��㵼��                 *" << endl;
	cout << "*                5.���޻�·                     *" << endl;
	cout << "*                6.���·������                 *" << endl;
	cout << "*                7.�����·�滮                 *" << endl;
	cout << "*                0.�˳�                         *" << endl;
	cout << "*************************************************" << endl;
	cout << "����������ѡ��:";
}
