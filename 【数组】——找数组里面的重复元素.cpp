#include<iostream>
#include<vector>
using namespace std;

//���������е��ظ�Ԫ�ء�����������±������
vector<int> Numbers(vector<int> arr)
{
	//����һ���������ظ���Ԫ��
	vector<int> brr;
	//����������
	for (int i = 0; i < arr.size(); i++)
	{
		while (i != arr[i])//�±�ֵ�������е�Ԫ�ز�ͬʱ
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
