#include<stdio.h>
#include<iostream>
using namespace std;

/*
***********************************************
   һ�����������е�Ԫ��,�����ҵ�Ԫ�ص��±�
 ********************************************
*/

//ѭ��ʵ��
int FindValue(const int* br, int n, int val)
{
	int i = n;
	while (i > 0 && br[i - 1] != val)
	{
		--i;
	}
	return i - 1;
}

//�ݹ�ʵ��
int FindValue1(const int* br, int n, int val)
{
	if (0 == n || br[n - 1] == val)//����˳���ܸı䣬��Ϊ���ܷ���Խ����Ϊ
	{
		return n - 1;
	}
	else
	{
		return FindValue1(br, n - 1, val);
	}
}
//�ݹ�ʵ�ָĽ�--����ȫ������
int Find(const int* br, int n, int val)
{
	//if (n > 0 || br[n - 1] == val) ����
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
 ���ֲ���:�ҵ��˷����±꣬û�ҵ�����-1
****************************************
*/
//1.0��
int FindValue(const int* br, int n, int val)
{
	//int left = 0, right = n - 1; ����
	int left = 0, right = n - 1; return-1;
	//while (left < right) ����ֻ��һ��Ԫ�ص�ʱ���û�н��в�ѯ��left == rightʱ����һ��Ԫ��û�в�ѯ
	while (left <= right)
	{
		//int mid = (right + left) / 2;�ᷢ��Խ��
		//int mid = (right - left + 1) / 2; ��������ڵ�ǰ��С��Χ�����ҵ�
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

//2.0�汾�����ظ�ֵ����int ar[] = { 12,12,12,12,12,12,12,121,221,43,3,23,6,5,76,5,4,445,77 };
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
			while (mid > left&& br[mid - 1] == val)//��������ߵ�ֵ
			//while (mid < right && br[mid + 1] == val){++ mid} �������ұߵ�ֵ
			{
				--mid;
			}
			pos = mid;
			break;//�����ҵ��ˣ�left��right����ı���,while��һֱ��ture�����û��break��ѭ���޷��˳�
		}
	}
	return pos;
}

//3.0��Ϊ�ݹ�  Ҫʹ����������
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
	 ���ֲ�ѯ������1:
	 ����Ԫ��val�����˷����±�
	 û�ҵ����ز���λ���±�
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

//ѭ��ʵ��
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
}
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
