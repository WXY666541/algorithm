#include<iostream>
#include<string>
using namespace std;

string Delete(string s1, string s2)
{
	int index;
	for (int i = 0; i < s2.size(); i++)
	{
		while ((index = s1.find(s2[i])) != -1)//find函数找到了就返回对应的下标,并将其赋值给index
		{
			s1.erase(index,1);//删除s1中的对应下标的字符
		}
	}
	return s1;
}
int main()
{
	string str1;
	getline(cin, str1);//碰到回车结束
	string str2;
	getline(cin, str2);
	str1 = Delete(str1, str2);
	cout << str1;
}

