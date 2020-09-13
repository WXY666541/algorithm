#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


//改编：输出和为s的所有数对
int twoSum3(vector<int> arr, int target)
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
			low++;
			high--;
		}
	}
	return res;
}

//改编：输出和为s的对数
int twoSum3(vector<int> arr, int target)
{
	//考虑特殊情况
	if (arr.size() == 0)
	{
		return 0;
	}

	sort(arr.begin(), arr.end());

	int low = 0;
	int high = arr.size() - 1;
	int count = 0;

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
			count++;//表示找到了一对，接着继续在剩下的序列里面查找
			low++;
			high--;
		}
	}
	return count;
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
