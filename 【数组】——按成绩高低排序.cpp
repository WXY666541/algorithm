#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> x(n, 0);//�洢ѧ��
	vector<int> c(n, 0);//�洢����

	//ѭ�����������ѧ�ţ�Ϊһһ��Ӧ������һλ����
	for (int i = 0; i < n; i++)
	{
		int t1;
		int t2;
		cin >> t1 >> t2;
		x[i] = t1;
		c[i] = t2;
	}

	//ʹ��ð�������˼�룬ÿ�ν�����Ԫ�س����ף�������������
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (c[j] > c[j + 1])//��Ϊ������ѧ����һһ��Ӧ�Ĺ�ϵ�������ڽ���������ʱ��Ҫ����Ӧ��ѧ�Ž���
			{
				int temp1 = c[j + 1];//��������
				c[j + 1] = c[j];
				c[j] = temp1;
				int temp2 = x[j + 1];//����ѧ��
				x[j + 1] = x[j];
				x[j] = temp2;
			}
			else if (c[j] == c[j + 1])//�ɼ����
			{
				if (x[j] > x[j + 1])//�ж�ѧ��
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
