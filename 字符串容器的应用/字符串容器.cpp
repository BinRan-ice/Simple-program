#pragma warning(disable:4996)
#include <iostream>
#include<string>
using namespace std;

void main()
{
	string s1 = "", s2, s3 = "Bye";
	s1.append("Good moring");				//s1=" Good moring"
	s2 = s1;								//s1=" Good moring"
	int i = s2.find("moring");				
	s2.replace(i, s2.length() - i, s3);		//Ïàµ±ÓÚs2.replace(5,7,s3);
	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	system("pause");
}