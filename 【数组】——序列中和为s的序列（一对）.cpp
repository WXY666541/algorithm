#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

/*
�������ҳ���Ϊk������(ֻ���һ�ԣ�
*/

//˫��forѭ����ʱ�临�Ӷȹ���
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

//ʱ�临�Ӷ�ΪO(nlogn)�Ľⷨ�����ö��ֲ��ҵķ�ʽ
vector<int> twoSum1(vector<int> arr, int target)
{
	vector<int> vec;

	//���ȶ������������
	sort(arr.begin(), arr.end());
	int high = arr.size()-1;

	for (int i = 0; i < arr.size(); i++)
	{
		int index = i;
		int other = target - arr[i];
		
		//���ж��ֲ��ҳ�����һ����
		while (index <= high)
		{
			int mid = (high + index) / 2;
			if (arr[mid] == other)
			{
				vec.push_back(arr[i]);
				vec.push_back(arr[mid]);
				return vec;//�����ڲ�ѭ�������������break��Ϊ���forѭ��������룬������ܶ��
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
	return vec;//����Ķ�û���ҵ���������д���
}

//������������˫ָ��ķ�ʽ��ʱ�临�Ӷ���O(n)
vector<int> twoSum2(vector<int> arr, int target)
{
	sort(arr.begin(), arr.end());
	int low = 0;
	int high = arr.size()-1;

	vector<int> res;
	
	//�����������
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

