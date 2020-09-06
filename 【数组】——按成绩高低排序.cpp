#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> x(n, 0);//存储学号
	vector<int> c(n, 0);//存储分数

	//循环输入分数和学号，为一一对应的两个一位数组
	for (int i = 0; i < n; i++)
	{
		int t1;
		int t2;
		cin >> t1 >> t2;
		x[i] = t1;
		c[i] = t2;
	}

	//使用冒泡排序的思想，每次将最大的元素沉到底（放在数组的最后）
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (c[j] > c[j + 1])//因为分数和学号是一一对应的关系，所以在交换分数的时候要把相应的学号交换
			{
				int temp1 = c[j + 1];//交换分数
				c[j + 1] = c[j];
				c[j] = temp1;
				int temp2 = x[j + 1];//交换学号
				x[j + 1] = x[j];
				x[j] = temp2;
			}
			else if (c[j] == c[j + 1])//成绩相等
			{
				if (x[j] > x[j + 1])//判断学号
				{
					int temp3 = x[j + 1];
					x[j + 1] = x[j];
					x[j] = temp3;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << x[i] << " " << c[i] << endl;
	}
}
