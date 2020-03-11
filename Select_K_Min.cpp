#include<iostream>
#include<assert.h>
#include<limits.h>
#include<algorithm>
using namespace std;
/*
***************************************
在一个无序数组中里面找最小和第二小的元素
***************************************
*/

void Select_2Min(int* br, int n)
{
	if (NULL == br || n < 2)return;
	int min1 = br[0] < br[1] ? br[0] : br[1];
	int min2 = br[0] < br[1] ? br[1] : br[0];
	for (int i = 2; i < n; i++)
	{
		if ( min1 > br[i] )
		{
			min2 = min1;
			min1 = br[i];
		}
		else if (min2 > br[i])
		{
			min2 = br[i];
		}
	}
	cout << "min1:" << min1 << " "<<"min2:" << min2 << endl;
}

/*
***************************************
在一个无序数组中里面找前k小的元素
反向冒泡排序、堆、直接排序找前k个
此题用快排来实现，分治策略的思想
***************************************
*/
template<class Type>
int Partition(Type* ar, int left, int right)
{
	int i = left, j = right;
	Type tmp = ar[i];
	while (i < j)
	{
		while (i <j && ar[j] >tmp)--j;
		if (i < j) ar[i] = ar[j];
		while (i < j && ar[i] <= tmp)++i;
		if (i < j) ar[j] = ar[i];
	}
	ar[i] = tmp;
	return i;
}
template<class Type>
const Type& Select_K(Type* ar, int left, int right, int k)
{
	if (left == right && k == 1) return ar[left];
	int index = Partition(ar, left, right);
	int pos = index - left + 1;//表示在该区域里面逻辑的第k小
	if (k <= pos) return Select_K(ar, left, index, k);//如果k == pos直接返回的话，就不是分治策略的思想，退出条件就不同了
	else return Select_K(ar, index + 1, right, k - pos);
}
template<class Type>
const Type& Select_K_Min(Type* ar, int n, int k)
{
	assert(ar != NULL && n > 0 && k >= 1 && k <= n);//if语句不知道返回的值是什么，因为他是模板的引用类型

	return Select_K(ar, 0, n - 1, k);
}
/*
***************************************
   最近点对问题——一位数组中
***************************************
*/
int MaxS1(int* br, int left, int right)
{
	return br[right];
}
int MinS2(int* br, int left, int right)
{
	int min = br[left];
	for (int i = left + 1; i <= right; ++i)
	{
		if (min > br[i])
		{
			min = br[i];
		}
	}
	return min;
}
int Min3d(int a, int b, int c)
{
	return min(a,min( b, c));
}
int  Cpair_min(int* br, int left, int right)
{
	if (right - left <= 0) return INT_MAX;
	int k = (right - left + 1) / 2;//表示在该区域里面逻辑的第k小
	int index = k + left - 1;//在数组中的实际的物理地址
	Select_K(br, left, right, k);
	int mind1 = Cpair_min(br, left, index);//s1区域
	int mind2 = Cpair_min(br, index+1, right);//s2区域
	int smax = MaxS1(br, left, index);
	int smin = MinS2(br, index + 1, right);

	return Min3d(mind1, mind2, smin - smax);
}
int Cpair_ar(int* br, int n)
{
	if (br == NULL || n < 2)return INT_MAX;//代表最大整形，引入宏
	return Cpair_min(br, 0, n - 1);
}
int main()
{
	int ar[] = { 56,12,89,90,23,34,100,45,67,78 };
	int n = sizeof(ar) / sizeof(ar[0]);
	Select_2Min(ar, n);
	for (int k = 1; k <= n; k++)
	{
		cout << k << "-->" << Select_K_Min(ar, n, k) << endl;
	}
	cout << Cpair_ar(ar, n) << endl;
	return 0;
}