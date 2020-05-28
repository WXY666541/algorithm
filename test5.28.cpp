#include<stdio.h>
#include<stdlib.h>
/*
*****************************
直接插入排序
*****************************
*/
void InsertSort(int* arr, int n)
{
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
	return;
}
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/*
*****************************
选择排序
*****************************
*/

void selectsort(int* arr, int n)
{
	int i, j, min;
	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[min] > arr[j])
				min = j;
		}
		swap(&arr[i], &arr[min]);
	}
}
void Print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
}

/*
*****************************
堆排序
*****************************
*/
void HeapAdiust(int arr[], int i, int n)
{
	int temp;
	int j = 2 * i + 1;
	for (j; j < n; j = 2 * i + 1)
	{
		if ((j < n - 1) && (arr[j] < arr[j + 1]))
		{
			j++;
		}
		if (arr[i] > arr[j])
			break;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i = j;
	}

}
void HeapSort(int* arr, int n)
{
	int temp;
	int i = (n - 2) / 2;
	for (i; i >= 0; i--)
	{
		HeapAdiust(arr, i, n);
	}
	for (i = n - 1; i > 0; i--)
	{
		temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		HeapAdiust(arr, 0, i);
	}
}
/*
*****************************
冒泡排序
*****************************
*/
void swap1(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void BubbleSort(int* arr, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				swap1(&arr[j], &arr[j + 1]);
			}

		}
	}
}


/*
*****************************
快速排序
*****************************
*/

int Partition(int* arr, int low, int high)
{
	int flag = arr[low];
	while (low < high)
	{
		while ((low < high) && (flag <= arr[high]))
			high--;
		arr[low] = arr[high];
		while ((low < high) && (flag >= arr[low]))
			low++;
		arr[high] = arr[low];
	}
	arr[low] = flag;
	return low;
}

void Swap(int arr[], int first, int second)
{
	int temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}

//三数取中方法
void GetMiddleMaxNum(int arr[], int low, int mid, int high)
{
	if (arr[mid] > arr[high])
	{
		Swap(arr, mid, high);
	}
	if (arr[low] < arr[high])
	{
		Swap(arr, low, high);
	}
	if (arr[low] > arr[mid])
	{
		Swap(arr, low, mid);
	}
}
//插入排序
void InsertSort(int* arr, int low, int high)
{
	int i, j, temp;
	for (i = low + 1; i <= high; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= low && arr[j] > temp; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
	return;
}
void Qsort(int* arr, int low, int high)
{
	int pivot;
	while (low < high)
	{
		//随机取基准点法Swap(low, rand() % (high - low + 1) + low);

		/*三数取中的算法
		int mid = (low + high) / 2;
		GetMiddleMaxNum(arr, low, mid, high);*/

		if ((high - low) < 20)
		{
			InsertSort(arr, low, high);
		}
		pivot = Partition(arr, low, high);
		Qsort(arr, low, pivot - 1);
		Qsort(arr, pivot + 1, high);
	}
}

void QuickSort(int* arr, int n)
{
	Qsort(arr, 0, n - 1);
}

/*
*****************************
归并排序
*****************************
*/
void Merge(int arr[], int tmp[], int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;

	while ((i < mid + 1) && (j < high + 1))
	{
		if (arr[i] < arr[j])
		{
			tmp[k++] = arr[i++];
		}
		else
		{
			tmp[k++] = arr[j++];
		}
		while (j < high + 1)
			tmp[k++] = arr[j++];
		while (i < mid + 1)
			tmp[k++] = arr[i++];
	}
	for (i = low; i <= high; i++)
	{
		arr[i] = tmp[i];
	}
}
void Merges(int arr[], int tmp[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		Merges(arr, tmp, low, mid);
		Merges(arr, tmp, mid + 1, high);
		Merge(arr, tmp, low, mid, high);
	}
}
void MergeSort(int arr[], int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	Merges(arr, tmp, 0, n - 1);
	free(tmp);
}
int main()
{
	int arr[] = { 2,3,1,4,2,6,2,7,5,9,4 };
	int n = sizeof(arr) / sizeof(int);
	Print(arr, n);
	QuickSort(arr, n);
	Print(arr, n);
}
