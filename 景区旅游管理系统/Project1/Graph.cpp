#include"Graph.h"
struct Graph m_Graph;

void Init()
{//��ͼ���г�ʼ��
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			m_Graph.m_aAdjMatrix[i][j] = 0;
	m_Graph.m_nVexNum = 0;
}

int InsertVex(Vex sVex)
{//��������ӵ�����������
	m_Graph.m_aVexs[m_Graph.m_nVexNum++] = sVex;
	return 0;
}

int InsertEdge(Edge sEdge)
{//���߱��浽������
	m_Graph.m_aAdjMatrix[sEdge.vex1][sEdge.vex2] = sEdge.weight;
	m_Graph.m_aAdjMatrix[sEdge.vex2][sEdge.vex1] = sEdge.weight;
	return 0;
}

Vex GetVex(int nVex)
{//��ѯ�������Ϣ
	return m_Graph.m_aVexs[nVex];
}

int FindEdge(int nVex, Edge aEdge[])
{//��ѯ��ָ�����������ı�

	int k = 0;
	for (int i = 0; i < m_Graph.m_nVexNum; i++) {
		if (m_Graph.m_aAdjMatrix[nVex][i] != 0) {
			aEdge[k].vex1 = nVex;
			aEdge[k].vex2 = i;
			aEdge[k].weight = m_Graph.m_aAdjMatrix[nVex][i];
			k++;
		}

	}
	return k;
}

int GetVexnum(void)
{//��ȡ��ǰ������
	return m_Graph.m_nVexNum;
}

void DFSTraverse(int nVex, PathList& pList)
{//��������ı�ŵõ����ʵĽ��
	int nIndex = 0;
	bool bVisited[20] = { false };//�����ʱ�־����Ϊδ����״̬
	DFS(nVex, bVisited, nIndex, pList);
}

void DFS(int nVex, bool bVisited[], int& nIndex, PathList& pList)
{//�Ľ���ͼ��������ȱ����㷨
	bVisited[nVex] = true;				//��Ϊ�ѷ���
	pList->vexs[nIndex] = nVex;		//���ʶ���nVex����ֵ������Ȼ������ֵ�Լ�
	nIndex++;

	//����״̬�жϵõ���·���Ƿ�����									
	int countVisit = 0;
	for (int i = 0; i < m_Graph.m_nVexNum; i++)
	{
		if (bVisited[i] == true)
			countVisit++;
	}
	if (countVisit == m_Graph.m_nVexNum)
	{
		//����һ��·��
		pList->next = new Path;
		for (int i = 0; i < m_Graph.m_nVexNum; i++)
		{
			pList->next->vexs[i] = pList->vexs[i];
		}
		pList = pList->next;
		pList->next = NULL;
	}
	else
	{
		for (int i = 0; i < m_Graph.m_nVexNum; i++) {
			//�������е��ڽӵ�
			if (!bVisited[i] && m_Graph.m_aAdjMatrix[nVex][i] > 0) {
				DFS(i, bVisited, nIndex, pList);	//�ݹ����DFS
				bVisited[i] = false;	//����
				nIndex--;	//��ȼ�һ
			}
		}
	}
}

int FindShortPath(int nVexStart, int nVexEnd, Edge aPath[])
{//ʹ�õϽ�˹���������·��
	bool fin[20];		//�ѻ�����·��
	int dist[20];		//��nVexStart����ǰ�����̾���
	int prev[20];		//�洢��һ����
	//��ʼ����̾���������ľ���
	for (int i = 0; i < m_Graph.m_nVexNum; i++)
	{
		//���øõ��״̬
		fin[i] = false;
		if (m_Graph.m_aAdjMatrix[nVexStart][i] != 0)
			dist[i] = m_Graph.m_aAdjMatrix[nVexStart][i];   //�бߵ�ʱ��ֱ������Ϊ�ߵĳ���
		else
			dist[i] = INT_MAX;	//��û��·���ĵ���Ȩ��Ϊ����
		if (dist[i] == INT_MAX)
			prev[i] = -1;
		else
			prev[i] = nVexStart;//����·��������һ����ΪnVexStart
	}
	//��ʼ������nVexStart������뵽������
	fin[nVexStart] = true;
	dist[nVexStart] = 0;
	prev[nVexStart] = nVexStart;
	int min;					//�ݴ�·������Сֵ
	for (int p = 0; p < m_Graph.m_nVexNum - 1; p++)
	{
		int v = nVexStart;
		min = INT_MAX;
		for (int i = 0; i < m_Graph.m_nVexNum; ++i)
		{
			if ((!fin[i]) && (dist[i] < min))
			{
				v = i;			//��ȡδ������·������Сֵ��
				min = dist[i];	//��ȡδ������·������Сֵ
			}
		}
		fin[v] = true;        //��i������뵽����
		for (int i = 0; i < m_Graph.m_nVexNum; ++i)    //��i��Ϊ���ɶ������nVexStartͨ��i��ÿ������ľ���
			if ((!fin[i]) && (dist[v] + m_Graph.m_aAdjMatrix[v][i] < dist[i]) && (m_Graph.m_aAdjMatrix[v][i] != 0))
			{
				dist[i] = dist[v] + m_Graph.m_aAdjMatrix[v][i];	//�������·��
				prev[i] = v;							//�洢��һ���㣬��ǰiΪ��Сֵ��
			}
	}
	int num = 0, last = nVexEnd;
	//��¼·���еı������Ӻ���ǰ����
	while (prev[last] != nVexStart)
	{
		num++;
		last = prev[last];
	}
	last = nVexEnd;
	//����·����Ϣ
	while (num >= 0)
	{
		aPath[num].vex2 = last;
		aPath[num].vex1 = prev[last];
		aPath[num].weight = m_Graph.m_aAdjMatrix[last][prev[last]];
		last = prev[last];
		num--;
	}
	return dist[nVexEnd];		//�������·������
}

int FindMinTree(Edge aPath[])
{//ʹ������ķ�㷨����С������
	bool aVisited[20] = { false };		//�ж��Ƿ�ĳ��������뵽����������
	aVisited[0] = true;					//����0��ʼ
	int length = 0;
	int min;
	int nVex1, nVex2;
	int minTreeNum = m_Graph.m_nVexNum - 1;	//����õ���С�������ı���
	for (int k = 0; k < minTreeNum; k++)
	{
		min = INT16_MAX;
		for (int i = 0; i < m_Graph.m_nVexNum; i++)
		{
			if (aVisited[i])
			{
				for (int j = 0; j < m_Graph.m_nVexNum; j++)
				{
					if (!aVisited[j] && m_Graph.m_aAdjMatrix[i][j] != 0 && m_Graph.m_aAdjMatrix[i][j] < min) {
						nVex1 = i;
						nVex2 = j;
						min = m_Graph.m_aAdjMatrix[nVex1][nVex2];
					}
				}
			}
		}
		length += min;	//���³���
		//����ߵ���������
		aPath[k].vex1 = nVex1;
		aPath[k].vex2 = nVex2;
		aPath[k].weight = m_Graph.m_aAdjMatrix[nVex1][nVex2];
		//������������뼯��
		aVisited[nVex1] = true;
		aVisited[nVex2] = true;
	}
	return length;
}