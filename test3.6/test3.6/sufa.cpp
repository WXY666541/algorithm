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
		fun(++i, n);//һ�㲻�ú��üӼӣ�������ݹ飬ջ���
		fun(++i, n);
	}
}
int main()
{
	fun(0, 3);
}


//�����ã������ò�η�����������������ջ����ı�
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
     ������
********************************
*/
//�ݹ�ķ�ʽ
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
		fun(ar, br, i + 1, n);//����
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

//�ǵݹ�ķ�ʽ:�����д��󣬻����Խ������
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
	 ���ֲ�ѯ������
********************************
*/
//�д��� 1.0 ������˼����ѭ���ĵ����õݹ���
typedef struct
{
	int index;
	bool tag;//�ҵ���Ϊture,flase
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
		res.index = left;//�ݹ�Ҫ���ݣ��Ҳ����ڵ�ֵʱ�������˹���Ҫ�ҵ�ֵȫ��������
	}
	return res;
}
//������2.0�汾
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
	if (!res.tag && res.index == -1)//˵��û�и�ֵ�����Ը�����ֵ
	{
		res.index = mid;
	}
	return res;
}
//ѭ��
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
̰�Ե�СQ��
СQ�ĸ�ĸҪ����N�죬��֮ǰ��СQ������M���ɿ�����
СQ����ÿ��Ե��ɿ�������������ǰһ��Ե�һ�룬
�������ֲ����ڸ�ĸ����֮ǰ��ĳһ��û���ɿ����ԣ�
��������һ������ܳԶ��ٿ��ɿ�����

���磺

���������ö����ֲ���

*************************************************
*/
//1.0����
/*int Sum(int n, int mid)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += mid;
		//mid = (mid/ 2) + 1; ����
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
		if (sum > m)//��Ҫ���ʼ��ʱ����һ��ȷ����ֵ��m��ȷ�Ƚϣ���Ϊ���ǿ��ԳԶ���һ�������ֻ���ҵ���һ��Եľ��У�����Ե�û��ȷ�е�
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
//2.0��ȷ
int Sum(int n, int mid)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += mid;
		//mid = (mid/ 2) + 1; ����
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
  ���ֲ��ҵ����ӣ�
  Ѱ����ת���������е���Сֵ
********************************
