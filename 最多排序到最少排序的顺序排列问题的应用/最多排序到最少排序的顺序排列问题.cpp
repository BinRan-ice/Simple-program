#pragma warning(disable:4996)
#include <iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<map>
using namespace std;

struct MyStruct
{
	int
};

int contrary(string str, int n)					//求逆序数
{
	int count = 0;								//统计逆序数数量
	int i = 0;
	int k = 0;
	int j = n - 1;
	for (i; i != j; i++)								//所有元素两两比较
	{
		k = i + 1;
		for (k; k < n; k++)
		{
			if (str[i] > str[k])
			{
				count++;
			}
		}
	}
	return count;
}

void main()
{
	string s;
	int  n, m;					 //字符串的长度和个数
	vector<string>mystring;	//定义一个mystring容器用来存储字符串
	unordered_multimap<int, string>unmymap;	//定义一个mymap容器存储逆序数与其对应的字符串
	unordered_multimap<int, string>::iterator it;//定义一个迭代器指向mymap
	cout << "请输入字符串的长度和字符串的个数：";
	cin >> n >> m;
	cout << "请输入你要输入的字符串：" << endl;
	for (int i = 0; i < m; i++)		//向mystring容器中存储字符串
	{
		cin >> s;
		mystring.push_back(s);

	}
	for (int i = 0; i < m; i++)
	{
		int num = contrary(mystring[i], n);								//获得逆序数
		int number = 1;
		printf("第%d组逆序数为：", number);
		cout << num << endl;
		unmymap.insert(pair<int, string>(num, mystring[i]));//将逆序数和字符串存储到mymap中，并自动升序
	}
	cout << "排序后的结果是：" << endl;
	for (it = unmymap.begin(); it != unmymap.end(); it++)//遍历mymap
	{
		cout << it->second << endl;
	}
	system("pause");
}
