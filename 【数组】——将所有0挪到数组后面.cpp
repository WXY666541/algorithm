#include<iostream>
#include<string>
using namespace std;

/*
将数组中为0的元素移动到末尾
相对位置改变
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
将数组中为0的元素移动到末尾
相对位置不变
*/
void MoveZero1(int* arr, int n)
{
	int k = 0;//表示为已经挪动完成的非零数的下标
	for (int i = 0; i < n; i++)
	{
		//挨个遍历，寻找第一个非零数
		if (arr[i] != 0)
		{
			int temp = arr[i];
			int j = i;

			//挪动非零数前面的零
			while (j > k)
			{
				arr[j] = arr[j - 1];
				j--;
			}
			arr[k++] = temp;//把空出来的位置0填充
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
