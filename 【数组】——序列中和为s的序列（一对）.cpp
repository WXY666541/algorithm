#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

/*
数组中找出和为k的序列(只输出一对）
*/

//双重for循环，时间复杂度过高
vector<int> twoSum(vector<int> arr, int target)
{
	vector<int> vec;
	for (int i = 0; i < arr.size(); i++)
	{
		int temp = arr[i];
		for (int j = i+1; j < arr.size(); j++)
		{
			int sum = temp + arr[j];
			if (sum == target)
			{
				vec.clear();
				vec.push_back(arr[i]);
				vec.push_back(arr[j]);
				break;
			}
		}
	}
	return vec;
}

//时间复杂度为O(nlogn)的解法，利用二分查找的方式
vector<int> twoSum1(vector<int> arr, int target)
{
	vector<int> vec;

	//首先对数组进行排序
	sort(arr.begin(), arr.end());
	int high = arr.size()-1;

	for (int i = 0; i < arr.size(); i++)
	{
		int index = i;
		int other = target - arr[i];
		
		//进行二分查找出另外一个数
		while (index <= high)
		{
			int mid = (high + index) / 2;
			if (arr[mid] == other)
			{
				vec.push_back(arr[i]);
				vec.push_back(arr[mid]);
				return vec;//处理内层循环的情况，不能break因为外层for循环还会进入，会输出很多对
			}
			else if (arr[mid] < other)
			{
				index = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
	}
	return vec;//特殊的对没有找到的情况进行处理
}

//方法三：采用双指针的方式，时间复杂度是O(n)
vector<int> twoSum2(vector<int> arr, int target)
{
	sort(arr.begin(), arr.end());
	int low = 0;
	int high = arr.size()-1;

	vector<int> res;
	
	//考虑特殊情况
	if (arr.size() == 0)
	{
		return res;
	}

	while (low < high)
	{
		int sum = arr[low] + arr[high];
		if (sum < target)
		{
			low++;
		}
		else if (sum > target)
		{
			high--;
		}
		else
		{
			res.push_back(arr[low]);
			res.push_back(arr[high]);
			break;
		}
	}
	return res;
}

int main()
{
	vector<int> res;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		res.push_back(temp);
	}

	vector<int> arr = twoSum2(res, 8);
	for (int j = 0; j < arr.size(); j++)
	{
		cout << arr[j] << " ";
	}
	return 0;
}

