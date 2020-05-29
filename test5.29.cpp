#include<stdio.h>
#include<stdlib.h>

int Erfen_Search(int arr[], int n,int key)
{
	int pos = -1;
	if (arr == nullptr || n <= 0)
		return pos;
	int low = 0;
	int high = n - 1;
	while (low <= high)
	{
		int mid = (high - low + 1) / 2 + low;
		if (arr[mid] > key)
		{
			high = mid - 1;
		}
		else if (arr[mid] < key)
		{
			low = mid + 1;
		}
		else
		{
			while (low < mid && arr[mid - 1] == key)
			{
				mid--;
			}
			pos = mid;
			break;
		}
	}
	return pos;
}

int Search(int arr[], int low, int high, int key)
{
	int pos = -1;
	if (low <= high)
	{
		int mid = (high - low + 1) / 2 + low;
		if (arr[mid] > key)
		{
			pos = Search(arr, low, mid - 1, key);
		}
		else if (arr[mid] < key)
		{
			pos = Search(arr, mid + 1, high, key);
		}
		else
		{
			while (low < mid && arr[mid - 1] == key)
			{
				mid--;
			}
			pos = mid;
		}
	}
	return pos;
}
int erfen_Search(int arr[], int n,int key)
{
	if (arr == nullptr || n <= 0) return -1;
	else  
		return Search(arr, 0, n - 1, key);
}


int main()
{
	int arr[] = { 1,2,2,2,3,7,3,4,6,8,9 };
	int n = sizeof(arr) / sizeof(int);
	int res = erfen_Search(arr, n,2);
	printf("%d\n", res);
	return 0;
}