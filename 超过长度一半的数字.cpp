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
��������һ�������
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2��������
������5�Σ��������鳤�ȵ�һ�룬������2�������������
���0��
*/

//�ⷨһ����������ķ�����������ɺ��м�λ�õ�ֵһ�����Ǹ���������һ�������
int MoreThanHalfNum_Solution(vector<int> arr)
{
	//���кϷ����ж�
	if (arr.empty())
	{
		return 0;
	}
	//ʹ��������������򷽷�
	sort(arr.begin(),arr.end());
	//Ҫ�ҵ�Ŀ��ֵ���������м�λ�õ�ֵ
	int target = arr[arr.size() / 2];

	//�����Ŀ��ֵ�ĸ����Ƿ����Ҫ��
	int count = 0;
	for (int i = 0; i < arr.size() ; i++)
	{
		if (target == arr[i])
		{
			count++;
		}
	}
	if (count > arr.size() / 2)
	{
		return target;
	}
	return 0;
}

//�ⷨ�������ü����ķ�ʽ
int MoreThanHalfNum_Solution1(vector<int> arr)
{
	if (arr.empty())
	{
		return 0;
	}

	int target = arr[0];//��ʼ��һ��Ŀ��ֵ
	int time = 0;//����

	//�������������������ֵ
	for (int i = 0; i < arr.size(); i++)
	{
		//�������ֵΪ0������£�Ҫ����targetĿ��ֵ
		if (time == 0)
		{
			time = 1;
			target = arr[i];
		}
		//��Ŀ��ֵ��ȵ������
		else if (target == arr[i])
		{
			time++;
		}
		//��Ŀ��ֵ��ͬ�������
		else
		{
			time--;
		}
	}

	//��󰤸���������֤
	int count = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (target == arr[i])
		{
			count++;
		}
	}
	if (count > arr.size() / 2)
	{
		return target;
	}
	return 0;
}

//�ⷨ����ʹ��map
int MoreThanHalfNum_Solution2(vector<int> arr)
{
	//���ȶ���һ��map��Keyֵ���������е�Ԫ�أ�valueֵ�ʹ����ֵ���ֵĴ���
	map<int, int> map;
	int half = arr.size() / 2;
	for (int i = 0; i < arr.size(); i++)
	{
		auto it = map.find(arr[i]);
		//����ҵ��ˣ�valueֵ��һ����
		if (it != map.end())
		{
			map[arr[i]]++;
		}
		//���û���ҵ����ʹ������״γ��֣����뼴��
		else
		{
			map.insert({ arr[i],1 });
		}

		//�ߵ����˵����Ӧ��key,valһ������
		if (map[arr[i]] > half)
		{
			return arr[i];
		}
	}
	//�ߵ����˵��û���ҵ�
	return 0;
}
