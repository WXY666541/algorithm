#include<stdio.h>
#include<iostream>
using namespace std;

/*
***********************************************
   一、查找数组中的元素,返回找到元素的下标
 ********************************************
*/

//循环实现
int FindValue(const int* br, int n, int val)
{
	int i = n;
	while (i > 0 && br[i - 1] != val)
	{
		--i;
	}
	return i - 1;
}

//递归实现
int FindValue1(const int* br, int n, int val)
{
	if (0 == n || br[n - 1] == val)//条件顺序不能改变，因为可能发生越界行为
	{
		return n - 1;
	}
	else
	{
		return FindValue1(br, n - 1, val);
	}
}
//递归实现改进--》安全性问题
int Find(const int* br, int n, int val)
{
	//if (n > 0 || br[n - 1] == val) 有误
	if (n <= 0 || br[n - 1] == val)
	{
		return n - 1;
	}
	else
	{
		return FindValue2(br, n - 1, val);
	}
}
int FindValue2(const int* br, int n, int val)
{
	if (NULL == br || n < 1) return -1;
	else return Find(br, n, val);
}
int main()
{
	int ar[] = { 12,21 };
	int n = sizeof(ar) / sizeof(ar[0]);
	int val = 45;
	int pos = FindValue(ar, n, val);
	printf("%d", pos);
}


/*
***************************************
 二分查找:找到了返回下标，没找到返回-1
****************************************
*/
//1.0版
int FindValue(const int* br, int n, int val)
{
	//int left = 0, right = n - 1; 错误
	int left = 0, right = n - 1; return-1;
	//while (left < right) 错误，只有一个元素的时候就没有进行查询，left == right时候还有一个元素没有查询
	while (left <= right)
	{
		//int mid = (right + left) / 2;会发生越界
		//int mid = (right - left + 1) / 2; 这个不是在当前缩小范围里面找的
		int mid = (right - left + 1) / 2 + left;
		if (val < br[mid])
		{
			right = mid - 1;
		}
		else if (val > br[mid])
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

//2.0版本：有重复值问题int ar[] = { 12,12,12,12,12,12,12,121,221,43,3,23,6,5,76,5,4,445,77 };
int FindValue(const int* br, int n, int val)
{
	int pos = -1;
	int left = 0, right = n - 1;
	if (NULL == br || n < 1)return pos;
	while (left <= right)
	{
		int mid = (right - left + 1) / 2 + left;
		if (val < br[mid])
		{
			right = mid - 1;
		}
		else if (val > br[mid])
		{
			left = mid + 1;
		}
		else
		{
			while (mid > left&& br[mid - 1] == val)//返回最左边的值
			//while (mid < right && br[mid + 1] == val){++ mid} 返回最右边的值
			{
				--mid;
			}
			pos = mid;
			break;//假设找到了，left和right不会改变了,while就一直是ture。如果没有break，循环无法退出
		}
	}
	return pos;
}

//3.0改为递归  要使用两个函数
int Find(const int* br, int left, int right, int val)
{
	int pos = -1;
	if (left <= right)
	{

		int mid = (right - left + 1) / 2 + left;
		if (val < br[mid])
		{
			pos = Find(br, left, mid - 1, val);
		}
		else if (val > br[mid])
		{
			pos = Find(br, mid + 1, right, val);
		}
		else
		{
			while (mid > left&& br[mid - 1] == val) --mid;
			pos = mid;
		}
	}
	return pos;
}
int FindValue(const int* br, int n, int val)
{
	if (NULL == br || n < 1)return -1;
	else return Find(br, 0, n - 1, val);

}

int main()
{
	int ar[] = { 0,12,12,12,12,12,12,12,23,34,45,67,89,90 };
	int n = sizeof(ar) / sizeof(ar[0]);
	int val = 12;
	int pos = FindValue(ar, n, val);
	printf("%d\n", pos);
	return 0;
}

/*
********************************
	 二分查询的例子1:
	 查找元素val，找了返回下标
	 没找到返回插入位置下标
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
			res = Find1(ar, left, mid - 1, val);
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
	if (!res.tag)
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

//循环实现
Result Find(int* ar, int left, int right, int val)
{
	Result res = { -1,false };
	while (left <= right)
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
}
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
