#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
using namespace std;
class Object
{
public:
    int id;//编号 
    int weight;//重量 
    int price;//价值 
    float d;//单位重量价值 
};
class MaxHeapQNode
{
public:
    MaxHeapQNode *parent;//父结点，可以记录下路径 
    int lchild;//左子结点 
    int upprofit;//值  就是bound 优先级按照这个来 
    int profit;//当前价值 
    int weight;//重量 
    int lev;//层次 
};
//建立优先队列时使用的 
struct cmp
{
    bool operator()(MaxHeapQNode *&a, MaxHeapQNode *&b) const
    {
        return a->upprofit < b->upprofit;
    }
};
 
//用于预处理的重排 
bool compare(const Object &a, const Object &b)
{
    return a.d >= b.d;
}
 
int n;//物品件数 
int c;//背包容量 
int cw;//当前重量 
int cp;//当前解 
int bestp;//最优解的值 
Object obj[100];//物品集合 
int bestx[100];//最优解的物品集合 
ifstream in("input.txt");
ofstream out("output.txt");
 
//添加节点到优先队列 
void AddAliveNode(priority_queue<MaxHeapQNode *, vector<MaxHeapQNode *>, cmp> &q, MaxHeapQNode *E, int up, int wt, int curp, int i, int ch)
{
    MaxHeapQNode *p = new MaxHeapQNode;
    p->parent=E;//父节点 
    p->lchild=ch;//ch=1左子节点 
    p->weight=wt;
    p->upprofit=up;//bound 
    p->profit=curp;
    p->lev=i+1;//层次 
    q.push(p);//将节点p加入队列q 
}
//分支限界法求解 
void MaxKnapsack()
{
	//优先队列，以cmp来确定优先级 ,maxheapqnode*是类型，还可以是int string.... 
    priority_queue<MaxHeapQNode *, vector<MaxHeapQNode *>, cmp > q;  
    //初始化 
    MaxHeapQNode *E=NULL;
    cw=cp=bestp=0;
    int i=1;
    int up=Bound(1);
    //当处理的层次没有达到叶子结点，不断处理队列中的结点 
    while(i!=n+1)
    {
    	//左子结点 :加入后不超出容量就可以加入 
        int wt=cw+obj[i].weight; 
        if(wt<=c)
        {
            if(bestp<cp+obj[i].price)
                bestp=cp+obj[i].price;
            AddAliveNode(q,E,up,cw+obj[i].weight,cp+obj[i].price,i,1);
            //参数顺序：优先队列q 节点E 当前重量 bound 当前价值 层数  1表示左节点 
        }
        
        //右子结点，如果可能产生最优解，可以加入 
        up=Bound(i + 1);
        if(up>=bestp) //（注意这里必须是大于等于） 
        {
            AddAliveNode(q,E,up,cw,cp,i,0);
        }
        //取出队首结点给下一次循环来处理 
        E=q.top();
        q.pop();
        cw=E->weight;//（结点的重量） 
        cp=E->profit;//（结点的价值） 
        up=E->upprofit;//（结点的值） 就是bound 
        i=E->lev;//（结点的层次） 
    }
    //构造最优解的物品集合 
    for(int j = n; j > 0; --j)
    {
        bestx[obj[E->lev-1].id] = E->lchild;
        E = E->parent;
    }
}
//输入&&预处理
int InPut()
{
	if(in>>c){
		in>>n; 
	    for(int i=1;i<=n;++i)
	    {
	        in>>obj[i].weight>>obj[i].price;
	    	obj[i].id = i;
	    	obj[i].d = 1.0 *obj[i].price/obj[i].weight;
	    }
	 	//重排 
	    sort(obj+1,obj+n+1,compare);
	    return 1;
	}
	return 0;
}
 
//输出 
void OutPut()
{
    out<<bestp<<'\n';
    for(int i = 1; i <= n; ++i)
        if(bestx[i] == 1)
           out<<i<<' ';
	out<<'\n'; 
}
 
int main()
{
    while(InPut()){
	    MaxKnapsack();
	    OutPut();
	}
	in.close();
	out.close();
    return 0;
}
 
