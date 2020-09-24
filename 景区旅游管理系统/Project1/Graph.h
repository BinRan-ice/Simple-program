#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>

struct Vex//����ṹ��
{
	int num;			//������
	char name[20];		//��������
	char desc[1024];	//�������
};
struct Edge//�߽ṹ��
{
	int vex1;			//�ߵĵ�һ������
	int vex2;			//�ߵĵڶ�������
	int weight;			//Ȩֵ
};
struct Graph {
	int m_aAdjMatrix[20][20];
	Vex m_aVexs[20];//��������
	int m_nVexNum;//�������
};//�洢�����ľ���ͼ

typedef struct Path {
	int vexs[20];//����һ��·��
	Path* next;//��һ��·��
}*PathList;

void Init(void);												//��ʼ��ͼ�ṹ
int InsertVex(Vex sVex);										//�����㱣�浽�ڽӾ���
int InsertEdge(Edge sEdge);										//���߱��浽�ڽӾ���
Vex GetVex(int nVex);											//��ѯָ��������Ϣ
int FindEdge(int nVex, Edge aEdge[]);							//��ѯ��ָ�����������ı�
int GetVexnum(void);											//��ȡ��ǰ������
void DFS(int nVex, bool bVisted[], int& nIndex, PathList& pList);	//�����������
void DFSTraverse(int nVex, PathList& pList);					//���������������
int FindShortPath(int nVexStart, int nVexEnd, Edge aPath[]);	//Ѱ����������·��
int FindMinTree(Edge aPath[]);									//Ѱ����С������

#endif