#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>

struct Vex//顶点结构体
{
	int num;			//景点编号
	char name[20];		//景点名字
	char desc[1024];	//景点介绍
};
struct Edge//边结构体
{
	int vex1;			//边的第一个顶点
	int vex2;			//边的第二个顶点
	int weight;			//权值
};
struct Graph {
	int m_aAdjMatrix[20][20];
	Vex m_aVexs[20];//顶点数组
	int m_nVexNum;//顶点个数
};//存储景区的景点图

typedef struct Path {
	int vexs[20];//保存一条路径
	Path* next;//下一条路径
}*PathList;

void Init(void);												//初始化图结构
int InsertVex(Vex sVex);										//将顶点保存到邻接矩阵
int InsertEdge(Edge sEdge);										//将边保存到邻接矩阵
Vex GetVex(int nVex);											//查询指定顶点信息
int FindEdge(int nVex, Edge aEdge[]);							//查询与指定顶点相连的边
int GetVexnum(void);											//获取当前顶点数
void DFS(int nVex, bool bVisted[], int& nIndex, PathList& pList);	//深度优先搜索
void DFSTraverse(int nVex, PathList& pList);					//调用深度优先搜索
int FindShortPath(int nVexStart, int nVexEnd, Edge aPath[]);	//寻找两点间最短路径
int FindMinTree(Edge aPath[]);									//寻找最小生成树

#endif