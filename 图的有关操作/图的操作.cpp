#pragma warning(disable:4996)
#include <iostream>
using namespace std;

#define MAXVEX 7   //代表最大顶点数
#define INFINITY 65535 //代表无穷大
#define INF 65535

typedef struct GraphNode
{
	int index;    //下标
	struct GraphNode *next;  //指向下一个的指针
}GraphNode;

typedef struct Gra
{
	char c;  //顶点元素
	GraphNode *first;
}Gra;

typedef struct Graph
{
	Gra vex[MAXVEX];
	int numvex, edge;  //顶点元素和边的数量
}Graph;

//创建一个队列，用来广度优先遍历
typedef struct QNode
{
	int data;
	struct QNode *next;
}QNode, *Queueprt;

typedef struct
{
	Queueprt front, rear;
}LinkQueue;

//队列的初始化
void InitQueue(LinkQueue *q)
{
	q->front = q->rear = (Queueprt)malloc(sizeof(QNode));
	q->front->next = NULL;
}

//入队列
void EnQueue(LinkQueue *q, int e)
{
	Queueprt p;
	p = (Queueprt)malloc(sizeof(QNode));
	p->data = e;
	q->rear->next = p;
	p->next = NULL;
	q->rear = p;
}

//出队列
void DeQueue(LinkQueue *q, int *e)
{
	if (q->front == q->rear)
	{
		return;
	}
	Queueprt p;
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	if (p == q->rear)
	{
		q->rear = q->front;
	}
	free(p);
}

//判断队列是否为空
int QueueEmpty(LinkQueue *q)
{
	if (q->front == q->rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//创建图
void create(Graph *g)
{
	int i, j, m, n;
	GraphNode *p, *q;
	printf("输入顶点元素的数量和边的数量：\n");
	scanf("%d %d", &(g->numvex), &(g->edge));
	printf("输入顶点元素：\n");
	for (i = 0; i < g->numvex; i++)
	{
		getchar();
		scanf("%c", &(g->vex[i].c));
		g->vex[i].first = NULL;
	}
	//建立边集
	printf("输入边两边顶点的下标：\n");
	for (j = 0; j < g->edge; j++)
	{
		scanf("%d %d", &m, &n);
		p = (GraphNode *)malloc(sizeof(GraphNode));
		p->index = m;
		p->next = g->vex[n].first;
		g->vex[n].first = p;         


		q = (GraphNode *)malloc(sizeof(GraphNode));
		q->index = n;
		q->next = g->vex[m].first;
		g->vex[m].first = q;
	}
}

void print(Graph *g)
{
	int i;
	GraphNode *p;
	for (i = 0; i < g->numvex; i++)
	{
		p = g->vex[i].first;
		while (p)
		{
			printf("(%c,%c)", g->vex[i].c, g->vex[p->index].c);
			p = p->next;
		}
		printf("\n");
	}
}

//DFS遍历

void DFS(Graph *g, int i, int *visited)
{
	GraphNode *p;
	visited[i] = 1;
	printf("%c ", g->vex[i].c);
	p = g->vex[i].first;
	while (p)
	{
		if (!visited[p->index])
		{
			DFS(g, p->index, visited);
		}
		p = p->next;
	}

}

void TraDFS(Graph *g)
{
	int i;
	int visited[MAXVEX];
	for (i = 0; i < MAXVEX; i++)
	{
		visited[i] = 0;
	}
	for (i = 0; i < g->numvex; i++)
	{
		if (!visited[i])
		{
			DFS(g, i, visited);
		}
	}

}

//BFS遍历
void TraBFS(Graph *g)
{
	int i, j;
	LinkQueue q;
	int visited[MAXVEX];
	for (i = 0; i < MAXVEX; i++)
	{
		visited[i] = 0;
	}
	InitQueue(&q);
	for (i = 0; i < g->numvex; i++)
	{
		if (!visited[i])
		{
			printf("%c ", g->vex[i].c);
			visited[i] = 1;
			EnQueue(&q, i);
			while (!QueueEmpty(&q))
			{
				DeQueue(&q, &i);
				GraphNode *p = g->vex[i].first;
				while (p)
				{
					if (!visited[p->index])
					{
						printf("%c ", g->vex[p->index].c);
						visited[p->index] = 1;
						EnQueue(&q, p->index);
					}
					p = p->next;
				}
			}

		}
	}

}

class MGraph
{
public:
	MGraph(int a[], int n, int e);
	~MGraph(){}
	void prim(MGraph graph);
private:
	int vertex[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int vertexNum, arcNum;
};

MGraph::MGraph(int a[], int n, int e)
{
	vertexNum = n;
	arcNum = e;
	for (int i = 0; i < vertexNum; i++)
	{
		vertex[i] = a[i];
	}
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			arc[i][j] = 0;
		}
	}
	for (int k = 0; k < arcNum; k++)
	{
		int m, n;
		cin >> m >> n;
		arc[m][n] = 1;
		arc[n][m] = 1;
	}
}

void MGraph::prim(MGraph graph)
{
	int min, i, j, k;  // min 为当前权值最小值
	int lowcost[MAXVEX];  /* 保存顶点间边的权值 */
	int adjvex[MAXVEX];   /* 保存相关顶点的下标，即下标与其值所连边为当前最小权值边 */
	lowcost[0] = 0;  /* 选取第一个顶点为起始点， 即 v0 加入树， lowcost的值为0，在这里就是此下标的顶点已经加入生成树 */
	adjvex[0] = 0;   /* 初始化第一个顶点下标为0 */
	cout << "prim算法结果为：" << endl;
	for (i = 1; i < graph.vertexNum; i++)  /* 循环除下标为 0 外的全部顶点 */
	{
		lowcost[i] = graph.arc[0][i];  /* 将与 v0 顶点有边的权值存入数组   就是遍历所有与v0相邻的边*/
		adjvex[i] = 0;  /* 将其他所有顶点的值初始化为 v0 的下标 */
	}
	for (i = 1; i < graph.vertexNum; i++)
	{
		min = INF;   /* 初始化最小权值为 无穷大 */
		j = 1, k = 0;//因为我们一开始是从0开始的 所以这里的j改成了从1开始
		while (j < graph.vertexNum)  /* 循环全部顶点，寻找当前最小生成树顶点集合中最小权值的边 */
		{
			if (lowcost[j] != 0 && lowcost[j] < min)  /* 如果权值不为 0(即不在树中),这!=0的意思就是这个顶点还没有放到树中  且权值小于 min */
			{
				min = lowcost[j];  /* 则让当前权值成为最小值 */
				k = j;             /* 将当前最小值的下标存入k */
			}
			j++;
		}
		lowcost[k] = 0;  /* 将当前顶点的权值设置为0, 表示此顶点已加入树的顶点集合  取k位置的顶点 并将其加入到树中去 */
		printf("(%d, %d)", adjvex[k], k);  /* 打印当前顶点边中权值最小的边 */
		for (j = 1; j < graph.vertexNum; j++)  /* 循环所有顶点 */
		{
			/* 如果下标为 k 的顶点边集中权值小于已存在的权值, 比如 (v0, v6)权值为INF, 而(v1, v6)权值为 16， 更新*/
			if (lowcost[j] != 0 && graph.arc[k][j] < lowcost[j])
			{
				lowcost[j] = graph.arc[k][j];  /* 将较小的权值存入 lowcost 相应位置 */
				adjvex[j] = k;   /* 将下标为 k 的顶点存入 adjvex */
			}
		}
	}
}

int main() {

	Graph g;
	create(&g);
	print(&g);
	printf("DFS遍历结果：\n");
	TraDFS(&g);
	printf("\nBFS遍历结果为：\n");
	TraBFS(&g);
	printf("\n");

	int a[7] = { 0,1,2,3,4,5,6 };
	int n = 7;
	int e = 6;
	MGraph graph(a, n, e);
	graph.prim(graph);
	return 0;
}