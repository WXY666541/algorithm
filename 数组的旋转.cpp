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
数组的旋转
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

/*
思路分析:
该题的核心思想就在于旋转过后的数组前半部分和后半部分都是递增的
并且前半部分的所有数据都比后半部分大。所以巧用二分查找的思想
*/
int MinNumber(vector<int> arr)
{
	//进行合法性判断
	if (arr.empty())
	{
		return 0;
	}

	int low = 0;
	int high = arr.size() - 1;
	int mid = 0;
	while (arr[low] >= arr[high])
	{
		//当low和high相邻的时候说明找到了最小值，最小值就是下标为high的元素
		if (high - low == 1)
		{
			mid = high;
			break;
		}
		mid = (low + high) >> 1;
		//三个下标所指的值都相等情况下,采用线性查找的方式
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
		//中间的值比low下标的值还要大，说明最小值在右边区间
		if (arr[mid] >= arr[low])
		{
			low = mid;
		}
		//中间的值比low下标的值小，说明最小值在左边区间
		else
		{
			high = mid ;
		}
	}
	return arr[mid];
}
