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
//����ż����������

/*
�龰һ������һ���������飬ʵ��һ�����������������������ֵ�˳��
ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿��
*/


//����˼·��������ָ�룬�ֱ�ָ�������ͷ����β��������Ѱ�ҷ�����
//�������֣�Ȼ�󽻻�
void reOrderArray(vector<int> arr)
{
	int i = 0;
	int j = arr.size() - 1;
	while (i < j)
	{
		//i�������������
		while (i < j && (arr[i] & 1))
		{
			i++;
		}
		//j����ż�������
		while (i < j && !(arr[j] & 1 ))
		{
			j--;
		}
		//i����ż����j��������������
		if (i < j)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		
	}
}
/*
�龰��������һ���������飬ʵ��һ�����������������������ֵ�˳��
ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿��
����֤������������ż����ż��֮������λ�ò��䡣
*/

//����˼·�������ڲ�������ķ�ʽ���ҵ�������λ�ã�������ǰ���ż��
//��������Ų�����ճ�����λ���ɸ��������
void reOrderArray1(vector<int> arr)
{
	if (arr.empty())
	{
		return;
	}

	int k = 0;//���ڱ����Ѿ�Ų������������±�

	//����������Ѱ�ҵ�һ������
	for (int i = 0; i < arr.size(); i++)
	{
		//�ҵ�������������һ����ʱ���Ƚ��б��棬���ѵ�ǰ������λ���ñ���j����
		if (arr[i] & 1)
		{
			int temp = arr[i];
			int j = i;

			//Ų����ǰ���ż��
			while (j > k)
			{
				arr[j] = arr[j - 1];
				j--;
			}

			//�ѿճ�����λ������ʱ��������������
			arr[k++] = temp;
		}
	}
}
