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

int contrary(string str, int n)					//��������
{
	int count = 0;								//ͳ������������
	int i = 0;
	int k = 0;
	int j = n - 1;
	for (i; i != j; i++)								//����Ԫ�������Ƚ�
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
	int  n, m;					 //�ַ����ĳ��Ⱥ͸���
	vector<string>mystring;	//����һ��mystring���������洢�ַ���
	unordered_multimap<int, string>unmymap;	//����һ��mymap�����洢�����������Ӧ���ַ���
	unordered_multimap<int, string>::iterator it;//����һ��������ָ��mymap
	cout << "�������ַ����ĳ��Ⱥ��ַ����ĸ�����";
	cin >> n >> m;
	cout << "��������Ҫ������ַ�����" << endl;
	for (int i = 0; i < m; i++)		//��mystring�����д洢�ַ���
	{
		cin >> s;
		mystring.push_back(s);

	}
	for (int i = 0; i < m; i++)
	{
		int num = contrary(mystring[i], n);								//���������
		int number = 1;
		printf("��%d��������Ϊ��", number);
		cout << num << endl;
		unmymap.insert(pair<int, string>(num, mystring[i]));//�����������ַ����洢��mymap�У����Զ�����
	}
	cout << "�����Ľ���ǣ�" << endl;
	for (it = unmymap.begin(); it != unmymap.end(); it++)//����mymap
	{
		cout << it->second << endl;
	}
	system("pause");
}
