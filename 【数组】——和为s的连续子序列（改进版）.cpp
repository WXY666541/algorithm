#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

vector<vector<int>> twoSum5(vector<int> arr, int target)
{
	sort(arr.begin(), arr.end());
	vector<int> temp;
	vector<vector<int>> result;

	for (int i = 0; i < arr.size(); i++)
	{
		int sum = arr[i];
		temp.push_back(arr[i]);
		for (int j = i + 1; j < arr.size(); j++)
		{
			sum += arr[j];
			temp.push_back(arr[j]);
			if (sum > target)
			{
				temp.clear();
				break;
			}
			else if(sum == target)
			{
				result.push_back(temp);
				temp.clear();
				break;
			}
		}
	}
	return result;
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

	vector<vector<int>> arr = twoSum5(res, 7);
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
