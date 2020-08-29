#include<iostream>
#include<list>
#include<vector>
using namespace std;


/*
圆圈中最后剩下的数字——约瑟夫环问题
*/

//方法一：借用list模拟循环链表，使用迭代器指针遍历
int LastNumber(int n, int m)
{
	//特殊情况的考虑
	if (n < 1 || m < 1)
	{
		return -1;
	}

	//list容器的初始化
	list<int> l1;
	for (int i = 0; i < n; i++)
	{
		l1.push_back(i);
	}

	//初始化一个迭代器指针指向容器的首部
	list<int>::iterator current = l1.begin();

	//删除结点的操作
	while (l1.size() > 1)
	{
		for (int i = 1; i < m; i++)
		{
			current++;
			//如果到达了链表末尾，就要构建出一个循环链表
			if (current == l1.end())
			{
				current = l1.begin();
			}
		}

		//初始化一个迭代器指针next
		list<int>::iterator next = ++current;

		//避免next为链表末尾的特殊情况
		if (next == l1.end())
		{
			next = l1.begin();
		}

		//删除结点操作
		--current;
		l1.erase(current);

		//更新current结点的值
		current = next;
	}
	return *(current);
}
//方法二：采用数学公式推导求解
//核心的公式为last = (last+m)%i。并且关键在于i是从2开始
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
