#include<iostream>
#include<string>
using namespace std;

string Delete(string s1, string s2)
{
	int index;
	for (int i = 0; i < s2.size(); i++)
	{
		while ((index = s1.find(s2[i])) != -1)//find�����ҵ��˾ͷ��ض�Ӧ���±�,�����丳ֵ��index
		{
			s1.erase(index,1);//ɾ��s1�еĶ�Ӧ�±���ַ�
		}
	}
	return s1;
}
int main()
{
	string str1;
	getline(cin, str1);//�����س�����
	string str2;
	getline(cin, str2);
	str1 = Delete(str1, str2);
	cout << str1;
}

