#include<iostream>
#include<vector>
using namespace std;

//查找数组中的重复元素——充分利用下标的性质
vector<int> Numbers(vector<int> arr)
{
	//申请一个数组存放重复的元素
	vector<int> brr;
	//外层控制趟数
	for (int i = 0; i < arr.size(); i++)
	{
		while (i != arr[i])//下标值和数组中的元素不同时
		{
			if (arr[i] == arr[arr[i]])
			{
				brr.push_back(arr[i]);
				break;
			}
			else
			{
				int temp = arr[arr[i]];
				arr[arr[i]] = arr[i];
				arr[i] = temp;
			}
		}
	}
	return brr;
}

int main()
{
	vector<int> a;
	a.push_back(2);
	a.push_back(3);
	a.push_back(1);
	a.push_back(0);
	a.push_back(2);
	a.push_back(5);
	a.push_back(3);
	vector<int> vec= Numbers(a);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i]<<" ";
	}
	return 0;
}
