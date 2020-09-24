#pragma warning(disable:4996)
#include"Tourism.h"
#include<windows.h>
#include<conio.h>
#include<iostream>
#include<graphics.h>
#include<time.h>
using namespace std;
extern Graph m_Graph;
bool number = false;
void CreateGraph(void)
{
	system("cls");
	//��ʼ��ͼ
	Init();
	//����ͼ�Ķ���
	//��ȡVEX.txt;
	FILE* pVex = fopen("Vex.txt", "r");
	if (!pVex) {
		cout << "���ļ�ʧ��";
		return;
	}
	//��ȡ������Ŀ��Ŀ
	int nSpotCout = 0;
	fscanf(pVex, "%d\n", &nSpotCout);
	cout << "������Ŀ��" << nSpotCout << endl;
	//��ȡ������Ϣ
	cout << "-----����------" << endl;
	Vex sVex;
	while (fscanf(pVex, "%d\n%s\n%s\n", &sVex.num, sVex.name, sVex.desc) != -1) {
		cout << sVex.num << "--" << sVex.name << endl;
		InsertVex(sVex);
	}
	fclose(pVex);
	pVex = NULL;

	//��ȡ��
	FILE* pEdge = fopen("Edge.txt", "r");
	if (!pEdge) {
		cerr << "���ļ�ʧ��";
		return;
	}
	Edge sEdge;

	while (fscanf(pEdge, "%d\t%d\t%d\n", &sEdge.vex1, &sEdge.vex2, &sEdge.weight) != -1) {
		cout << "(" << sEdge.vex1 << "," << sEdge.vex2 << ")	" << sEdge.weight << endl;
		InsertEdge(sEdge);
		if (InsertEdge(sEdge) == -1)cout << "����ʧ��" << endl;
	}
	cout << "��������������˵���" << endl;
	getch();
	number = true;
}
void OutGraph(void)
{
	system("cls");
	if (number)
	{
		initgraph(619, 456, SHOWCONSOLE);
		loadimage(NULL, "E:\\�����ͼ.jpg");
		int vexNum = GetVexnum();
		cout << "�����������ֲ�ͼ����" << endl;
		for (int i = 0; i < vexNum; i++)
		{
			Vex sVex = GetVex(i);
			cout << "     " << sVex.name;
		}
		cout << endl;
		for (int i = 0; i < vexNum; i++)
		{
			Vex sVex = GetVex(i);
			cout << sVex.name << "  ";
			for (int j = 0; j < vexNum; j++)
			{
				printf("%-8d", m_Graph.m_aAdjMatrix[i][j]);
			}
			cout << endl;
		}
		cout << "��������������˵���" << endl;
		getch();
	}
	else
	{
		cout << "��ǰͼ��δ��ʼ��" << endl;
		cout << "��������������˵���" << endl;
		getch();
		return;
	}
}
void GetSpotInfo(void)
{
	system("cls");
	if (number)
	{
		cout << "--------��ѯ������Ϣ--------" << endl;
		//��ʾ�����б�
		int vexNum = GetVexnum();
		for (int i = 0; i < vexNum; i++) {
			Vex sVex = GetVex(i);
			cout << sVex.num << "--" << sVex.name << endl;
		}
		//��ѯ����
		cout << "��������Ҫ��ѯ�ľ����ţ�";
		int nVex = 0;
		cin >> nVex;
		if (nVex < 0 || nVex >= vexNum) {
			cout << "�������" << endl;
			return;
		}

		Vex sVex = GetVex(nVex);
		cout << "**���**" << endl;
		cout << sVex.name << endl;
		cout << sVex.desc << endl;
		Edge sEdge[20];

		//��ѯ��������
		cout << endl << "**��Χ����**" << endl;
		int nEdgNum = FindEdge(nVex, sEdge);
		for (int i = 0; i < nEdgNum; i++)
		{
			Vex v1 = GetVex(sEdge[i].vex1);
			Vex v2 = GetVex(sEdge[i].vex2);
			cout << v1.name << "->" << v2.name << " " << sEdge[i].weight << endl << endl;
		}
		cout << "��������������˵���" << endl;
		getch();
	}
	else
	{
		cout << "��ǰͼ��δ��ʼ��" << endl;
		cout << "��������������˵���" << endl;
		getch();
		return;
	}
}
void TravelPath()
{//ͨ������DFSTraverse()����,����ѯ���ľ��㵼��·����ʾ�ڽ�����
	system("cls");
	if (number)
	{
		cout << "--------���㵼��--------" << endl;

		//��ʾ�����б�
		int vexNum = GetVexnum();
		for (int i = 0; i < vexNum; i++) {
			Vex sVex = GetVex(i);
			cout << sVex.num << "--" << sVex.name << endl;
		}
		cout << "�����뿪ʼ���:" << endl;
		int startNum;
		cin >> startNum;

		//��ָ���㿪ʼ��·����Ϣ
		PathList pList = new Path;
		PathList pHead = pList;
		DFSTraverse(startNum, pList);
		pList = pHead;

		cout << "����·��Ϊ:" << endl;
		int count = 1;    //��¼·�ߵ�����
		while (pList->next != NULL) {
			Vex curVex = GetVex(pList->vexs[0]);
			cout << "·��" << count << ":" << curVex.name;
			count++;
			for (int j = 1; j < m_Graph.m_nVexNum; j++) {
				curVex = GetVex(pList->vexs[j]);
				cout << "-->" << curVex.name;
			}
			cout << endl;
			pList = pList->next;
		}
		cout << "��������������˵���" << endl;
		getch();
	}
	else
	{
		cout << "��ǰͼ��δ��ʼ��" << endl;
		cout << "��������������˵���" << endl;
		getch();
		return;
	}
}
void TopoSort_matrix()
{
	system("cls");
	if (number)
	{
		cout << "--------���޻�·--------" << endl;
		int N = GetVexnum();
		int row[7] = { 0 };//�����������ñ�־��Ϊ1��ʾ�Ѿ���������ٿ��ǣ���Ϊ0��ʾδ�����
		int v = 1;//��־����1��ʾ�Ѿ���������ٿ��ǣ���Ϊ0��ʾδ���������row����
		int i, j, k, t, m;
		for (k = 0; k < N; k++)
		{
			for (j = 0; j < N; j++)
			{
				if (row[j] == 0)//�j��δ���
				{
					t = 1;//��ʶ��
					for (i = 0; i < N; i++)
						if (m_Graph.m_aAdjMatrix[i][j] != 0)//��ǰ�����ȣ��i�����ڻj֮ǰ��
						{
							t = 0;
							break;
						}
					if (t == 1)//�jû�����
					{
						m = j;
						break;
					}
				}
			}
			if (j != N)
			{
				row[m] = v;
				printf("%c", m_Graph.m_aVexs[m]);
				for (i = 0; i < N; i++)
					m_Graph.m_aAdjMatrix[m][i] = 0;//���Ѿ�����Ļ��������¸���������Ϊ0
				v++;
			}
			else
				break;
		}
		if (v - 1 < N)//��row�в������е�Ԫ�ض���������ֵvʱ��˵���л�����
			printf("\n��ͼ�л����ڣ���Ҫ�����˹��Ż���");
		cout << "��������������˵���" << endl;
		getch();
	}
	else
	{
		cout << "��ǰͼ��δ��ʼ��" << endl;
		cout << "��������������˵���" << endl;
		getch();
		return;
	}
}

void FindShortPath(void)
{
	system("cls");
	if (number)
	{
		cout << "==== �������·�� ====" << endl;
		Vex vex;
		//���ÿ��������Ϣ�����
		for (int i = 0; i < m_Graph.m_nVexNum; i++)
		{
			vex = GetVex(i);
			cout << vex.num << "-" << vex.name << endl;
		}
		int nVexStart, nVexEnd;
		cout << "���������ı�ţ�";
		cin >> nVexStart;
		cout << "�������յ�ı�ţ�";
		cin >> nVexEnd;
		Edge aPath[20];
		int shortPath = FindShortPath(nVexStart, nVexEnd, aPath);
		cout << "���·��Ϊ��";
		int i = 0;
		while (i < m_Graph.m_nVexNum)
		{
			if (aPath[i].vex1 != aPath[i].vex2)
				cout << GetVex(aPath[i].vex1).name << "->";
			else
			{
				cout << GetVex(aPath[i - 1].vex2).name << endl;
				break;
			}
			i++;
		}
		cout << "��̾���Ϊ��" << shortPath << endl;
		cout << "��������������˵���" << endl;
		getch();
	}
	else
	{
		cout << "��ǰͼ��δ��ʼ��" << endl;
		cout << "��������������˵���" << endl;
		getch();
		return;
	}
}

void DesignPath(void)
{
	system("cls");
	if (number)
	{
		cout << "==========�����·�滮==========" << endl;
		Edge aPath[20];
		int length = FindMinTree(aPath);
		int nVexNum = m_Graph.m_nVexNum;
		cout << "��������������֮�������·��" << endl;
		for (int i = 0; i < m_Graph.m_nVexNum - 1; i++)
		{
			Vex nVex1 = GetVex(aPath[i].vex1);
			Vex nVex2 = GetVex(aPath[i].vex2);
			cout << nVex1.name << "-" << nVex2.name << "    " << aPath[i].weight << "m" << endl;
		}
		cout << "�����·���ܳ����ǣ�" << length << "m" << endl;
		cout << "��������������˵���" << endl;
		getch();
	}
	else
	{
		cout << "��ǰͼ��δ��ʼ��" << endl;
		cout << "��������������˵���" << endl;
		getch();
		return;
	}
}