#include<stdio.h>
#include<iostream>
using namespace std;

/*
********************************
	 排列树
********************************
*/
//递归的方式
void fun(int* ar, int* br, int i, int n)
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

/*
***************************************
 全排列
 归纳定义：
 当n = 1 时，perm(R) = (r),其中r是集合R中唯一的元素
 当n > 1 时，perm(R)由（r1)perm(R1),(r2)perm(R2),.....,(rn)perm(Rn)构成
****************************************
*/
void Perm(int* br, int k, int m)
{
	if (k = m)
	{
		for (int i = 0; i <= m; ++i)
		{
			cout << br[i] << " ";
		}
	}
	else
	{
		for (int j = k; j <= m; j++)
		{
			swap(br[j], br[k]);
			Perm(br, k + 1, m);
			swap(br[j], br[k]);
		}
	}
}
int main()
{
	int ar[] = { 1,2,3 };
	int n = sizeof(ar) / sizeof(ar[0]);
	Perm(ar, 0, n - 1);
	return 0;
}