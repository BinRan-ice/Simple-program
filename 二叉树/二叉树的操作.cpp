#pragma warning(disable:4996)
#include <iostream>
using namespace std;
int num = 0;

template<class DataType>
struct BiNode
{
	DataType data;
	BiNode<DataType>* lchild, *rchild;
};

template<class DataType>
class BiTree
{
public:
	BiTree() { root = Create(root); }
	~BiTree() { Release(root); }
	void PreOrder() { PreOrder(root); }
	void InOrder() { InOrder(root); }
	void PostOrder() { PostOrder(root); }
	int Height() { int i = Height(root); return i; }
private:
	BiNode<DataType>* root;
	BiNode<DataType>* Create(BiNode<DataType>* bt);
	void Release(BiNode<DataType>* bt);
	void PreOrder(BiNode<DataType>* bt);
	void InOrder(BiNode<DataType>* bt);
	void PostOrder(BiNode<DataType>* bt);
	int Height(BiNode<DataType>*bt);
};

template<class DataType>
BiNode<DataType>* BiTree<DataType>::Create(BiNode<DataType>* bt)
{
	DataType ch;
	cin >> ch;
	if (ch=='#')
	{
		bt = NULL;
	}
	else
	{
		bt = new BiNode<DataType>;
		bt->data = ch;
		bt->lchild = Create(bt->lchild);
		bt->rchild = Create(bt->rchild);
	}
	return bt;
}

template<class DataType>
void BiTree<DataType>::Release(BiNode<DataType>*bt)
{
	if (bt!=NULL)
	{
		Release(bt->lchild);
		Release(bt->rchild);
		delete bt;
	}
}

template<class DataType>
void BiTree<DataType>::PreOrder(BiNode<DataType>*bt)
{
	if (bt == NULL)
	{
		return;
	}
	else
	{
		cout << bt->data;
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
		if (bt->lchild == NULL && bt->rchild == NULL)
		{
			num++;

		}
	}
}

template<class DataType>
void BiTree<DataType>::InOrder(BiNode<DataType>*bt)
{
	if (bt==NULL)
	{
		return;
	}
	else
	{
		InOrder(bt->lchild);
		cout << bt->data;
		InOrder(bt->rchild);
	}
}

template<class DataType>
void BiTree<DataType>::PostOrder(BiNode<DataType>*bt)
{
	if (bt==NULL)
	{
		return;
	}
	else
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		cout << bt->data;
	}
}

template<class DataType>
int BiTree<DataType>::Height(BiNode<DataType>*bt)
{
	if (bt == NULL)
		return 0;
	int m = Height(bt->lchild);
	int n = Height(bt->rchild);
	return (m > n) ? (m + 1) : (n + 1);
}

void main()
{
	BiTree<char> tree;
	cout << "前序遍历：";
	tree.PreOrder();
	puts(" ");
	cout << "中序遍历：";
	tree.InOrder();
	puts(" ");
	cout << "后序遍历：";
	tree.PostOrder();
	puts(" ");
	cout << "二叉树的高度为：";
	int i = tree.Height();
	cout << i << endl;
	cout << "二叉树的叶子结点为：";
	cout<<num;
	system("pause");
}