#pragma warning(disable:4996)
#include <iostream>
using namespace std;

#define MAXVEX 7   //������󶥵���
#define INFINITY 65535 //���������
#define INF 65535

typedef struct GraphNode
{
	int index;    //�±�
	struct GraphNode *next;  //ָ����һ����ָ��
}GraphNode;

typedef struct Gra
{
	char c;  //����Ԫ��
	GraphNode *first;
}Gra;

typedef struct Graph
{
	Gra vex[MAXVEX];
	int numvex, edge;  //����Ԫ�غͱߵ�����
}Graph;

//����һ�����У�����������ȱ���
typedef struct QNode
{
	int data;
	struct QNode *next;
}QNode, *Queueprt;

typedef struct
{
	Queueprt front, rear;
}LinkQueue;

//���еĳ�ʼ��
void InitQueue(LinkQueue *q)
{
	q->front = q->rear = (Queueprt)malloc(sizeof(QNode));
	q->front->next = NULL;
}

//�����
void EnQueue(LinkQueue *q, int e)
{
	Queueprt p;
	p = (Queueprt)malloc(sizeof(QNode));
	p->data = e;
	q->rear->next = p;
	p->next = NULL;
	q->rear = p;
}

//������
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

//�ж϶����Ƿ�Ϊ��
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
//����ͼ
void create(Graph *g)
{
	int i, j, m, n;
	GraphNode *p, *q;
	printf("���붥��Ԫ�ص������ͱߵ�������\n");
	scanf("%d %d", &(g->numvex), &(g->edge));
	printf("���붥��Ԫ�أ�\n");
	for (i = 0; i < g->numvex; i++)
	{
		getchar();
		scanf("%c", &(g->vex[i].c));
		g->vex[i].first = NULL;
	}
	//�����߼�
	printf("��������߶�����±꣺\n");
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

//DFS����

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

//BFS����
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
	int min, i, j, k;  // min Ϊ��ǰȨֵ��Сֵ
	int lowcost[MAXVEX];  /* ���涥���ߵ�Ȩֵ */
	int adjvex[MAXVEX];   /* ������ض�����±꣬���±�����ֵ������Ϊ��ǰ��СȨֵ�� */
	lowcost[0] = 0;  /* ѡȡ��һ������Ϊ��ʼ�㣬 �� v0 �������� lowcost��ֵΪ0����������Ǵ��±�Ķ����Ѿ����������� */
	adjvex[0] = 0;   /* ��ʼ����һ�������±�Ϊ0 */
	cout << "prim�㷨���Ϊ��" << endl;
	for (i = 1; i < graph.vertexNum; i++)  /* ѭ�����±�Ϊ 0 ���ȫ������ */
	{
		lowcost[i] = graph.arc[0][i];  /* ���� v0 �����бߵ�Ȩֵ��������   ���Ǳ���������v0���ڵı�*/
		adjvex[i] = 0;  /* ���������ж����ֵ��ʼ��Ϊ v0 ���±� */
	}
	for (i = 1; i < graph.vertexNum; i++)
	{
		min = INF;   /* ��ʼ����СȨֵΪ ����� */
		j = 1, k = 0;//��Ϊ����һ��ʼ�Ǵ�0��ʼ�� ���������j�ĳ��˴�1��ʼ
		while (j < graph.vertexNum)  /* ѭ��ȫ�����㣬Ѱ�ҵ�ǰ��С���������㼯������СȨֵ�ı� */
		{
			if (lowcost[j] != 0 && lowcost[j] < min)  /* ���Ȩֵ��Ϊ 0(����������),��!=0����˼����������㻹û�зŵ�����  ��ȨֵС�� min */
			{
				min = lowcost[j];  /* ���õ�ǰȨֵ��Ϊ��Сֵ */
				k = j;             /* ����ǰ��Сֵ���±����k */
			}
			j++;
		}
		lowcost[k] = 0;  /* ����ǰ�����Ȩֵ����Ϊ0, ��ʾ�˶����Ѽ������Ķ��㼯��  ȡkλ�õĶ��� ��������뵽����ȥ */
		printf("(%d, %d)", adjvex[k], k);  /* ��ӡ��ǰ�������Ȩֵ��С�ı� */
		for (j = 1; j < graph.vertexNum; j++)  /* ѭ�����ж��� */
		{
			/* ����±�Ϊ k �Ķ���߼���ȨֵС���Ѵ��ڵ�Ȩֵ, ���� (v0, v6)ȨֵΪINF, ��(v1, v6)ȨֵΪ 16�� ����*/
			if (lowcost[j] != 0 && graph.arc[k][j] < lowcost[j])
			{
				lowcost[j] = graph.arc[k][j];  /* ����С��Ȩֵ���� lowcost ��Ӧλ�� */
				adjvex[j] = k;   /* ���±�Ϊ k �Ķ������ adjvex */
			}
		}
	}
}

int main() {

	Graph g;
	create(&g);
	print(&g);
	printf("DFS���������\n");
	TraDFS(&g);
	printf("\nBFS�������Ϊ��\n");
	TraBFS(&g);
	printf("\n");

	int a[7] = { 0,1,2,3,4,5,6 };
	int n = 7;
	int e = 6;
	MGraph graph(a, n, e);
	graph.prim(graph);
	return 0;
}