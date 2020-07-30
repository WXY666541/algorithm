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
超过长度一半的数字
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中
出现了5次，超过数组长度的一半，因此输出2。如果不存在则
输出0。
*/

//解法一：采用排序的方法，排序完成后，中间位置的值一般是那个超过长度一半的数字
int MoreThanHalfNum_Solution(vector<int> arr)
{
	//进行合法性判断
	if (arr.empty())
	{
		return 0;
	}
	//使用容器里面的排序方法
	sort(arr.begin(),arr.end());
	//要找的目标值就是数组中间位置的值
	int target = arr[arr.size() / 2];

	//计算该目标值的个数是否符合要求
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

//解法二：采用计数的方式
int MoreThanHalfNum_Solution1(vector<int> arr)
{
	if (arr.empty())
	{
		return 0;
	}

	int target = arr[0];//初始化一个目标值
	int time = 0;//计数

	//挨个儿遍历数组里面的值
	for (int i = 0; i < arr.size(); i++)
	{
		//如果计数值为0的情况下，要更新target目标值
		if (time == 0)
		{
			time = 1;
			target = arr[i];
		}
		//和目标值相等的情况下
		else if (target == arr[i])
		{
			time++;
		}
		//和目标值不同的情况下
		else
		{
			time--;
		}
	}

	//最后挨个儿遍历验证
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

//解法三：使用map
int MoreThanHalfNum_Solution2(vector<int> arr)
{
	//首先定义一个map，Key值代表数组中的元素，value值就代表该值出现的次数
	map<int, int> map;
	int half = arr.size() / 2;
	for (int i = 0; i < arr.size(); i++)
	{
		auto it = map.find(arr[i]);
		//如果找到了，value值加一即可
		if (it != map.end())
		{
			map[arr[i]]++;
		}
		//如果没有找到，就代表是首次出现，插入即可
		else
		{
			map.insert({ arr[i],1 });
		}

		//走到这里，说明对应的key,val一定存在
		if (map[arr[i]] > half)
		{
			return arr[i];
		}
	}
	//走到这里，说明没有找到
	return 0;
}
