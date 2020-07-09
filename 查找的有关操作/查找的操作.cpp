#pragma warning(disable:4996)
#include <iostream>
#include <time.h>
using namespace std;
#define  n 9
#define KeyType int
typedef struct
{
	KeyType key;
}ElemType;
typedef struct node
{
	ElemType elem;
	struct node *next;
}NODE;
typedef NODE *HashTable[n];
//哈希函数 
int Hash(KeyType key)
{
	int i;
	i = key % n;
	return i;
}
/*动态查找哈希表*/
void search(HashTable H, KeyType k)
{
	int i;  NODE *p, *s;
	i = Hash(k);   p = H[i];
	while (p&&p->elem.key != k)p = p->next;
	if (!p) {/*表中无元素k则将其插入*/
		s = new NODE; s->elem.key = k;
		s->next = H[i]; H[i] = s;
	}
	else cout << "Found  " << k;
}
void create(HashTable H)//哈希表建立
{
	int i; KeyType k;
	for (i = 0; i < n; i++) H[i] = NULL;
	cout << "Create HashTable,input keys(End of 0)\n";
	cin >> k;
	while (k)
	{
		search(H, k); cin >> k;
	}
}
void main()
{
	HashTable H;
	int i; NODE *p;
	create(H);
	for (i = 0; i < n; i++)
	{
		cout << "\nThe keys of that hash_address is"<<i;
			for (p = H[i]; p; p = p->next)
				cout << p->elem.key <<" ";
	}
}
