#include<iostream>
#include<list>
#include<vector>
using namespace std;


/*
ԲȦ�����ʣ�µ����֡���Լɪ������
*/

//����һ������listģ��ѭ������ʹ�õ�����ָ�����
int LastNumber(int n, int m)
{
	//��������Ŀ���
	if (n < 1 || m < 1)
	{
		return -1;
	}

	//list�����ĳ�ʼ��
	list<int> l1;
	for (int i = 0; i < n; i++)
	{
		l1.push_back(i);
	}

	//��ʼ��һ��������ָ��ָ���������ײ�
	list<int>::iterator current = l1.begin();

	//ɾ�����Ĳ���
	while (l1.size() > 1)
	{
		for (int i = 1; i < m; i++)
		{
			current++;
			//�������������ĩβ����Ҫ������һ��ѭ������
			if (current == l1.end())
			{
				current = l1.begin();
			}
		}

		//��ʼ��һ��������ָ��next
		list<int>::iterator next = ++current;

		//����nextΪ����ĩβ���������
		if (next == l1.end())
		{
			next = l1.begin();
		}

		//ɾ��������
		--current;
		l1.erase(current);

		//����current����ֵ
		current = next;
	}
	return *(current);
}
//��������������ѧ��ʽ�Ƶ����
//���ĵĹ�ʽΪlast = (last+m)%i�����ҹؼ�����i�Ǵ�2��ʼ
int LastNumber(int n, int m)
{
	if (n < 1 || m < 1)
	{
		return -1;
	}

	int last = 0;
	for (int i = 2; i <= n; i++)
	{
		last = (last + m) % i;
	}
	return last;
}

int main()
{
	int n, m;
	cout << "n=";
	cin >> n;
	cout << "m=";
	cin >> m;
	cout << LastNumber(n, m);
}
