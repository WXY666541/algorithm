#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
#include<stack>
#include<map>
using namespace std;
/*
�������ת
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
*/

/*
˼·����:
����ĺ���˼���������ת���������ǰ�벿�ֺͺ�벿�ֶ��ǵ�����
����ǰ�벿�ֵ��������ݶ��Ⱥ�벿�ִ��������ö��ֲ��ҵ�˼��
*/
int MinNumber(vector<int> arr)
{
	//���кϷ����ж�
	if (arr.empty())
	{
		return 0;
	}

	int low = 0;
	int high = arr.size() - 1;
	int mid = 0;
	while (arr[low] >= arr[high])
	{
		//��low��high���ڵ�ʱ��˵���ҵ�����Сֵ����Сֵ�����±�Ϊhigh��Ԫ��
		if (high - low == 1)
		{
			mid = high;
			break;
		}
		mid = (low + high) >> 1;
		//�����±���ָ��ֵ����������,�������Բ��ҵķ�ʽ
		if (arr[mid] == arr[low] && arr[mid] == arr[high])
		{
			int min = arr[low];
			for (int i = low; i <= high; i++)
			{
				if (arr[i] < min)
				{
					min = arr[i];
				}
			}
			return mid;
		}
		//�м��ֵ��low�±��ֵ��Ҫ��˵����Сֵ���ұ�����
		if (arr[mid] >= arr[low])
		{
			low = mid;
		}
		//�м��ֵ��low�±��ֵС��˵����Сֵ���������
		else
		{
			high = mid ;
		}
	}
	return arr[mid];
}
