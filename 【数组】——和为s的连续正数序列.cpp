#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

/*
和为s的连续正数序列
*/

//题型1：数组序列为1到target的有序序列
//采用双重for循环的方式
vector<vector<int>> twoSum4( int target)
{
	vector<int> temp;
	vector<vector<int>> result;

	for (int i = 1; i <= (target +1)/2; i++)//控制每一趟的起始元素
	{
		//两次循环结束的条件都应该数数组一半的时候，因为要保证序列里面至少要有两个数
		int sum = 0;
		for (int j = i + 1; j <= (target + 1) / 2; j++)
		{
			//连续子序列不断相加的过程
			sum += j;
			temp.push_back(j);

			if (sum > target)
			{
				temp.clear();
				break;
			}
			else if (sum == target)
			{
				result.push_back(temp);
				break;
			}
		}
	}
	return result;
}
int main()
{
	int target;
	cin >> target;

	vector<vector<int>> vec = twoSum4(9);

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
