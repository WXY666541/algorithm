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
//奇数偶数交换问题

/*
情景一：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分
*/


//解题思路：用两个指针，分别指向数组的头部和尾部，遍历寻找符合条
//件的数字，然后交换
void reOrderArray(vector<int> arr)
{
	int i = 0;
	int j = arr.size() - 1;
	while (i < j)
	{
		//i遇到奇数的情况
		while (i < j && (arr[i] & 1))
		{
			i++;
		}
		//j遇到偶数的情况
		while (i < j && !(arr[j] & 1 ))
		{
			j--;
		}
		//i遇到偶数，j遇到奇数，交换
		if (i < j)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		
	}
}
/*
情景二：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分
并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

//解题思路：类似于插入排序的方式。找到奇数的位置，把奇数前面的偶数
//挨个往后挪，最后空出来的位置由该奇数填充
void reOrderArray1(vector<int> arr)
{
	if (arr.empty())
	{
		return;
	}

	int k = 0;//用于保存已经挪动完成奇数的下标

	//挨个遍历，寻找第一个奇数
	for (int i = 0; i < arr.size(); i++)
	{
		//找到了奇数，就用一个临时量先进行保存，并把当前奇数的位置用变量j保存
		if (arr[i] & 1)
		{
			int temp = arr[i];
			int j = i;

			//挪奇数前面的偶数
			while (j > k)
			{
				arr[j] = arr[j - 1];
				j--;
			}

			//把空出来的位置由临时量保存的奇数填充
			arr[k++] = temp;
		}
	}
}
