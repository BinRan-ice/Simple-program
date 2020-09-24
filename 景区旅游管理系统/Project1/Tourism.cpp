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
	//初始化图
	Init();
	//设置图的顶点
	//读取VEX.txt;
	FILE* pVex = fopen("Vex.txt", "r");
	if (!pVex) {
		cout << "打开文件失败";
		return;
	}
	//读取景点数目数目
	int nSpotCout = 0;
	fscanf(pVex, "%d\n", &nSpotCout);
	cout << "顶点数目：" << nSpotCout << endl;
	//读取顶点信息
	cout << "-----顶点------" << endl;
	Vex sVex;
	while (fscanf(pVex, "%d\n%s\n%s\n", &sVex.num, sVex.name, sVex.desc) != -1) {
		cout << sVex.num << "--" << sVex.name << endl;
		InsertVex(sVex);
	}
	fclose(pVex);
	pVex = NULL;

	//读取边
	FILE* pEdge = fopen("Edge.txt", "r");
	if (!pEdge) {
		cerr << "打开文件失败";
		return;
	}
	Edge sEdge;

	while (fscanf(pEdge, "%d\t%d\t%d\n", &sEdge.vex1, &sEdge.vex2, &sEdge.weight) != -1) {
		cout << "(" << sEdge.vex1 << "," << sEdge.vex2 << ")	" << sEdge.weight << endl;
		InsertEdge(sEdge);
		if (InsertEdge(sEdge) == -1)cout << "插入失败" << endl;
	}
	cout << "按任意键返回主菜单！" << endl;
	getch();
	number = true;
}
void OutGraph(void)
{
	system("cls");
	if (number)
	{
		initgraph(619, 456, SHOWCONSOLE);
		loadimage(NULL, "E:\\景点地图.jpg");
		int vexNum = GetVexnum();
		cout << "输出景区景点分布图矩阵：" << endl;
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
		cout << "按任意键返回主菜单！" << endl;
		getch();
	}
	else
	{
		cout << "当前图还未初始化" << endl;
		cout << "按任意键返回主菜单！" << endl;
		getch();
		return;
	}
}
void GetSpotInfo(void)
{
	system("cls");
	if (number)
	{
		cout << "--------查询景点信息--------" << endl;
		//显示景点列表
		int vexNum = GetVexnum();
		for (int i = 0; i < vexNum; i++) {
			Vex sVex = GetVex(i);
			cout << sVex.num << "--" << sVex.name << endl;
		}
		//查询景点
		cout << "请输入您要查询的景点编号：";
		int nVex = 0;
		cin >> nVex;
		if (nVex < 0 || nVex >= vexNum) {
			cout << "输入错误" << endl;
			return;
		}

		Vex sVex = GetVex(nVex);
		cout << "**简介**" << endl;
		cout << sVex.name << endl;
		cout << sVex.desc << endl;
		Edge sEdge[20];

		//查询附近景点
		cout << endl << "**周围景点**" << endl;
		int nEdgNum = FindEdge(nVex, sEdge);
		for (int i = 0; i < nEdgNum; i++)
		{
			Vex v1 = GetVex(sEdge[i].vex1);
			Vex v2 = GetVex(sEdge[i].vex2);
			cout << v1.name << "->" << v2.name << " " << sEdge[i].weight << endl << endl;
		}
		cout << "按任意键返回主菜单！" << endl;
		getch();
	}
	else
	{
		cout << "当前图还未初始化" << endl;
		cout << "按任意键返回主菜单！" << endl;
		getch();
		return;
	}
}
void TravelPath()
{//通过调用DFSTraverse()函数,将查询到的景点导航路线显示在界面上
	system("cls");
	if (number)
	{
		cout << "--------景点导航--------" << endl;

		//显示景点列表
		int vexNum = GetVexnum();
		for (int i = 0; i < vexNum; i++) {
			Vex sVex = GetVex(i);
			cout << sVex.num << "--" << sVex.name << endl;
		}
		cout << "请输入开始编号:" << endl;
		int startNum;
		cin >> startNum;

		//从指定点开始的路径信息
		PathList pList = new Path;
		PathList pHead = pList;
		DFSTraverse(startNum, pList);
		pList = pHead;

		cout << "导游路线为:" << endl;
		int count = 1;    //记录路线的总数
		while (pList->next != NULL) {
			Vex curVex = GetVex(pList->vexs[0]);
			cout << "路线" << count << ":" << curVex.name;
			count++;
			for (int j = 1; j < m_Graph.m_nVexNum; j++) {
				curVex = GetVex(pList->vexs[j]);
				cout << "-->" << curVex.name;
			}
			cout << endl;
			pList = pList->next;
		}
		cout << "按任意键返回主菜单！" << endl;
		getch();
	}
	else
	{
		cout << "当前图还未初始化" << endl;
		cout << "按任意键返回主菜单！" << endl;
		getch();
		return;
	}
}
void TopoSort_matrix()
{
	system("cls");
	if (number)
	{
		cout << "--------有无回路--------" << endl;
		int N = GetVexnum();
		int row[7] = { 0 };//按照列来设置标志，为1表示已经输出（不再考虑），为0表示未输出。
		int v = 1;//标志符，1表示已经输出（不再考虑），为0表示未输出，赋给row数组
		int i, j, k, t, m;
		for (k = 0; k < N; k++)
		{
			for (j = 0; j < N; j++)
			{
				if (row[j] == 0)//活动j还未输出
				{
					t = 1;//标识符
					for (i = 0; i < N; i++)
						if (m_Graph.m_aAdjMatrix[i][j] != 0)//当前活动有入度（活动i必须在活动j之前）
						{
							t = 0;
							break;
						}
					if (t == 1)//活动j没有入度
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
					m_Graph.m_aAdjMatrix[m][i] = 0;//将已经输出的活动所到达的下个活动的入度置为0
				v++;
			}
			else
				break;
		}
		if (v - 1 < N)//当row中不是所有的元素都被赋予新值v时，说明有环存在
			printf("\n该图有环存在，需要进行人工优化！");
		cout << "按任意键返回主菜单！" << endl;
		getch();
	}
	else
	{
		cout << "当前图还未初始化" << endl;
		cout << "按任意键返回主菜单！" << endl;
		getch();
		return;
	}
}

void FindShortPath(void)
{
	system("cls");
	if (number)
	{
		cout << "==== 搜索最短路径 ====" << endl;
		Vex vex;
		//获得每个顶点信息并输出
		for (int i = 0; i < m_Graph.m_nVexNum; i++)
		{
			vex = GetVex(i);
			cout << vex.num << "-" << vex.name << endl;
		}
		int nVexStart, nVexEnd;
		cout << "请输入起点的编号：";
		cin >> nVexStart;
		cout << "请输入终点的编号：";
		cin >> nVexEnd;
		Edge aPath[20];
		int shortPath = FindShortPath(nVexStart, nVexEnd, aPath);
		cout << "最短路线为：";
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
		cout << "最短距离为：" << shortPath << endl;
		cout << "按任意键返回主菜单！" << endl;
		getch();
	}
	else
	{
		cout << "当前图还未初始化" << endl;
		cout << "按任意键返回主菜单！" << endl;
		getch();
		return;
	}
}

void DesignPath(void)
{
	system("cls");
	if (number)
	{
		cout << "==========铺设电路规划==========" << endl;
		Edge aPath[20];
		int length = FindMinTree(aPath);
		int nVexNum = m_Graph.m_nVexNum;
		cout << "在以下两个景点之间铺设电路：" << endl;
		for (int i = 0; i < m_Graph.m_nVexNum - 1; i++)
		{
			Vex nVex1 = GetVex(aPath[i].vex1);
			Vex nVex2 = GetVex(aPath[i].vex2);
			cout << nVex1.name << "-" << nVex2.name << "    " << aPath[i].weight << "m" << endl;
		}
		cout << "铺设电路的总长度是：" << length << "m" << endl;
		cout << "按任意键返回主菜单！" << endl;
		getch();
	}
	else
	{
		cout << "当前图还未初始化" << endl;
		cout << "按任意键返回主菜单！" << endl;
		getch();
		return;
	}
}