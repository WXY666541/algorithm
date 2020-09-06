#include<iostream>
#include<string>
using namespace std;

/*
��������Ϊ0��Ԫ���ƶ���ĩβ
���λ�øı�
*/
void MoveZero(int* arr, int n)
{
	int low = 0;
	int high = n - 1;
	while (low < high)
	{
		while( low < high && arr[high] == 0)
		{
			high--;
		}
		while(low < high && arr[low] != 0)
		{
			low++;
		}
		if (low < high)
		{
			int temp = arr[low];
			arr[low] = arr[high];
			arr[high] = temp;
		}
	}
}

/*
��������Ϊ0��Ԫ���ƶ���ĩβ
���λ�ò���
*/
void MoveZero1(int* arr, int n)
{
	int k = 0;//��ʾΪ�Ѿ�Ų����ɵķ��������±�
	for (int i = 0; i < n; i++)
	{
		//����������Ѱ�ҵ�һ��������
		if (arr[i] != 0)
		{
			int temp = arr[i];
			int j = i;

			//Ų��������ǰ�����
			while (j > k)
			{
				arr[j] = arr[j - 1];
				j--;
			}
			arr[k++] = temp;//�ѿճ�����λ��0���
		}
	}
}
int main()
{
	int arr[] = { 2,0,1,0,2,0,3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	MoveZero1(arr, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
