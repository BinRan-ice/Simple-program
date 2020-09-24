#include"Graph.h"
struct Graph m_Graph;

void Init()
{//对图进行初始化
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			m_Graph.m_aAdjMatrix[i][j] = 0;
	m_Graph.m_nVexNum = 0;
}

int InsertVex(Vex sVex)
{//将顶点添加到顶点数组中
	m_Graph.m_aVexs[m_Graph.m_nVexNum++] = sVex;
	return 0;
}

int InsertEdge(Edge sEdge)
{//将边保存到矩阵中
	m_Graph.m_aAdjMatrix[sEdge.vex1][sEdge.vex2] = sEdge.weight;
	m_Graph.m_aAdjMatrix[sEdge.vex2][sEdge.vex1] = sEdge.weight;
	return 0;
}

Vex GetVex(int nVex)
{//查询顶点的信息
	return m_Graph.m_aVexs[nVex];
}

int FindEdge(int nVex, Edge aEdge[])
{//查询与指定顶点相连的边

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
{//获取当前顶点数
	return m_Graph.m_nVexNum;
}

void DFSTraverse(int nVex, PathList& pList)
{//根据输入的编号得到访问的结果
	int nIndex = 0;
	bool bVisited[20] = { false };//将访问标志设置为未访问状态
	DFS(nVex, bVisited, nIndex, pList);
}

void DFS(int nVex, bool bVisited[], int& nIndex, PathList& pList)
{//改进的图的深度优先遍历算法
	bVisited[nVex] = true;				//改为已访问
	pList->vexs[nIndex] = nVex;		//访问顶点nVex并赋值给链表，然后索引值自加
	nIndex++;

	//根据状态判断得到的路径是否完整									
	int countVisit = 0;
	for (int i = 0; i < m_Graph.m_nVexNum; i++)
	{
		if (bVisited[i] == true)
			countVisit++;
	}
	if (countVisit == m_Graph.m_nVexNum)
	{
		//保存一条路径
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
			//搜索所有的邻接点
			if (!bVisited[i] && m_Graph.m_aAdjMatrix[nVex][i] > 0) {
				DFS(i, bVisited, nIndex, pList);	//递归调用DFS
				bVisited[i] = false;	//回退
				nIndex--;	//深度减一
			}
		}
	}
}

int FindShortPath(int nVexStart, int nVexEnd, Edge aPath[])
{//使用迪杰斯特拉求最短路径
	bool fin[20];		//已获得最短路径
	int dist[20];		//从nVexStart到当前点的最短距离
	int prev[20];		//存储上一个点
	//初始化最短距离和两点间的距离
	for (int i = 0; i < m_Graph.m_nVexNum; i++)
	{
		//设置该点的状态
		fin[i] = false;
		if (m_Graph.m_aAdjMatrix[nVexStart][i] != 0)
			dist[i] = m_Graph.m_aAdjMatrix[nVexStart][i];   //有边的时候直接设置为边的长度
		else
			dist[i] = INT_MAX;	//将没有路径的点设权重为无穷
		if (dist[i] == INT_MAX)
			prev[i] = -1;
		else
			prev[i] = nVexStart;//已有路径设置上一个点为nVexStart
	}
	//初始化，将nVexStart顶点加入到集合中
	fin[nVexStart] = true;
	dist[nVexStart] = 0;
	prev[nVexStart] = nVexStart;
	int min;					//暂存路径的最小值
	for (int p = 0; p < m_Graph.m_nVexNum - 1; p++)
	{
		int v = nVexStart;
		min = INT_MAX;
		for (int i = 0; i < m_Graph.m_nVexNum; ++i)
		{
			if ((!fin[i]) && (dist[i] < min))
			{
				v = i;			//获取未获得最短路径的最小值点
				min = dist[i];	//获取未获得最短路径的最小值
			}
		}
		fin[v] = true;        //将i顶点加入到集合
		for (int i = 0; i < m_Graph.m_nVexNum; ++i)    //将i作为过渡顶点计算nVexStart通过i到每个顶点的距离
			if ((!fin[i]) && (dist[v] + m_Graph.m_aAdjMatrix[v][i] < dist[i]) && (m_Graph.m_aAdjMatrix[v][i] != 0))
			{
				dist[i] = dist[v] + m_Graph.m_aAdjMatrix[v][i];	//更新最短路径
				prev[i] = v;							//存储上一个点，当前i为最小值点
			}
	}
	int num = 0, last = nVexEnd;
	//记录路径中的边数，从后向前遍历
	while (prev[last] != nVexStart)
	{
		num++;
		last = prev[last];
	}
	last = nVexEnd;
	//保存路径信息
	while (num >= 0)
	{
		aPath[num].vex2 = last;
		aPath[num].vex1 = prev[last];
		aPath[num].weight = m_Graph.m_aAdjMatrix[last][prev[last]];
		last = prev[last];
		num--;
	}
	return dist[nVexEnd];		//返回最短路径距离
}

int FindMinTree(Edge aPath[])
{//使用普林姆算法求最小生成树
	bool aVisited[20] = { false };		//判断是否将某个顶点加入到了生成树中
	aVisited[0] = true;					//顶点0开始
	int length = 0;
	int min;
	int nVex1, nVex2;
	int minTreeNum = m_Graph.m_nVexNum - 1;	//计算得到最小生成树的边数
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
		length += min;	//更新长度
		//保存边的两个顶点
		aPath[k].vex1 = nVex1;
		aPath[k].vex2 = nVex2;
		aPath[k].weight = m_Graph.m_aAdjMatrix[nVex1][nVex2];
		//将两个顶点加入集合
		aVisited[nVex1] = true;
		aVisited[nVex2] = true;
	}
	return length;
}