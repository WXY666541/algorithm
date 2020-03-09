#include<stdio.h>
#include<iostream>
using namespace std;

#if 0
int fun(int i, int n)
{
	if (i >= n)
	{
	}
	else
	{
		fun(++i, n);//一般不用后置加加，会无穷递归，栈溢出
		fun(++i, n);
	}
}
int main()
{
	fun(0, 3);
}


//用引用：不能用层次分析法，整个调用链栈都会改变
int fun(int &i, int n)
{
	if (i >= n)
	{
	}
	else
	{
		fun(++i, n);
		fun(++i, n);
	}
}
int main()
{
	int a = 0;
	fun(a, 3);
}

/*
********************************
     排列树
********************************
*/
//递归的方式
void fun (int* ar, int* br, int i,int n)
{
	if (i >= n)
	{
		for (int j = 0; j < n; ++j)
		{
			if (br[j])
			{
				cout << ar[j] << "";
			}
		}
		cout << endl;
	}
	else
	{
		br[i] = 1;
		fun(ar, br, i + 1, n);//左孩子
		br[i] = 0;
		fun(ar, br, i + 1, n);
	}
}
int main()
{
	int ar[] = { 1,2,3 };
	int br[] = { 0,0,0 };
	fun(ar, br, 0, 3);
	return 0;
}

//非递归的方式:以下有错误，会存在越界问题
int main()
{
	int ar[] = { 1,2,3 };
	int br[] = { 0,0,0 };
	int n = 3;
	int i = 0;
	br[i] = -1;
	while (i >= 0)
	{
		br[i] += 1;
		if (i >= n)
		{
			//print _ar
			--i;
		}
		else if (br[i] == 2)
		{
			--i;
		}
		else
		{
			++i;
			br[i] = -1;
		}
	}
	return 0;
}
#endif
/*
********************************
	 二分查询的例子
********************************
*/
//有错误 1.0 分析的思想是循环的但是用递归解答
typedef struct
{
	int index;
	bool tag;//找到了为ture,flase
}Result;

Result Find1(int* ar, int left, int right, int val)
{
	Result res = { -1,false };
	int mid = (right - left + 1) / 2 + left;
	if (left <= right)
	{
		if (val < ar[mid])
		{
			res = Find1(ar, left, mid - 1,val);
		}
		else if (val > ar[mid])
		{
			res = Find1(ar, mid + 1, right, val);
		}
		else
		{
			res.index = mid;
			res.tag = true;
		}
	}
	if (!res.tag )
	{
		res.index = left;//递归要回溯，找不存在的值时回溯完了过后将要找的值全部覆盖了
	}
	return res;
}
//修正后2.0版本
Result Find2(int* ar, int left, int right, int val)
{
	Result res = { -1,false };
	int mid = (right - left + 1) / 2 + left;
	if (left <= right)
	{
		if (val < ar[mid])
		{
			res = Find2(ar, left, mid - 1, val);
		}
		else if (val > ar[mid])
		{
			res = Find2(ar, mid + 1, right, val);
		}
		else
		{
			res.index = mid;
			res.tag = true;
		}
	}
	if (!res.tag && res.index == -1)//说明没有赋值，所以给他赋值
	{
		res.index = mid;
	}
	return res;
}
//循环
Result Find(int* ar, int left, int right, int val)
{
	Result res = { -1,false };
	while(left <= right)
	{   
		int mid = (right - left + 1) / 2 + left;
		if (val < ar[mid])
		{
			right = mid - 1;
		}
		else if (val > ar[mid])
		{
			left = mid + 1;
		}
		else
		{
			res.index = mid;
			res.tag = true;
			break;
		}
	}
	if (!res.tag)
	{
		res.index = left;
	}
	return res;
}

Result FindValue(int* ar, int n, int val)
{
	Result res = { -1,false };
	if (ar != NULL && n > 0)
	{
		res = Find(ar, 0, n - 1, val);
	}
	return res;
}
int main()
{
	int ar[] = { 12,23,34,45,56,67,78,89,95,100 };
	int n = sizeof(ar) / sizeof(ar[0]);
	int val;
	while (cin >> val, val != -1)
	{
		Result res = FindValue(ar, n, val);
		cout << res.index << " " << res.tag << endl;
	}
	return 0;
}

/*
***************************************************
贪吃的小Q：
小Q的父母要出差N天，走之前给小Q留下了M块巧克力。
小Q决定每天吃的巧克力数量不少于前一天吃的一半，
但是他又不想在父母回来之前的某一天没有巧克力吃，
请问他第一天最多能吃多少块巧克力。

例如：

分析：利用而二分查找

*************************************************
*/
//1.0错误
/*int Sum(int n, int mid)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += mid;
		//mid = (mid/ 2) + 1; 错误
		mid = (mid + 1) / 2;
	}
	return sum;
}
int Get_Max(int n,int m)
{
	int pos = -1;
	int left = 1, right = m;
	while (left <= right)
	{
		int mid = (right + left) / 2;
		int sum = Sum(n, mid);
		if (sum > m)//不要在最开始的时候拿一个确定的值和m精确比较，因为还是可以吃多于一半的数。只用找到第一天吃的就行，后面吃的没有确切的
		{
			right = mid - 1;
		}
		else if (sum < m)
		{
			left = mid + 1;
		}
		else
		{
			pos = mid;
			break;
		}
	}
	return pos;
}*/
//2.0正确
int Sum(int n, int mid)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += mid;
		//mid = (mid/ 2) + 1; 错误
		mid = (mid + 1) / 2;
	}
	return sum;
}
int Get_Max(int n, int m)
{
	int left = 1, right = m;
	while (left <= right)
	{
		int mid = (right + left) / 2;
		int sum = Sum(n, mid);
		bool tag = sum > m;
		if (tag)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return right;
}
int main()
{
	int nday, m;
	while (cin >> nday >> m, nday != -1 && m > 0)
	{
		int maxm = Get_Max(nday, m);
		cout << maxm << endl;
	}
}

/*
********************************
  二分查找的例子：
  寻找旋转排序数组中的最小值
********************************
