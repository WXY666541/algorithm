#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

/*
��Ϊs��������������
*/

//����1����������Ϊ1��target����������
//����˫��forѭ���ķ�ʽ
vector<vector<int>> twoSum4( int target)
{
	vector<int> temp;
	vector<vector<int>> result;

	for (int i = 1; i <= (target +1)/2; i++)//����ÿһ�˵���ʼԪ��
	{
		//����ѭ��������������Ӧ��������һ���ʱ����ΪҪ��֤������������Ҫ��������
		int sum = 0;
		for (int j = i + 1; j <= (target + 1) / 2; j++)
		{
			//���������в�����ӵĹ���
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
