#include<iostream>
using namespace std;

/*
链表排序
*/
struct ListNode
{
	int val;
	struct ListNode* next;
};


//冒泡排序实现，但是超出了时间复杂度
ListNode* Sort(ListNode* head)
{
	//特殊情况的判断
	if (head == NULL)
	{
		return NULL;
	}

	//初始化第一个结点
	ListNode* node1 = head;

	//双重for循环冒泡排序
	for (; node1 != NULL; node1 = node1->next)//控制趟数
	{
		ListNode* node2 = head;//一趟过后node2已经走到链表末尾，所以需要重新初始化
		for (; node2->next != NULL; node2 = node2->next)
		{
			if (node2->val > node2->next->val)
			{
				int temp = node2->val;
				node2->val = node2->next->val;
				node2->next->val = temp;
			}
		}
	}
}

/*
数组元素排序
*/
#include<iostream>


void BubbleSort(int* arr, int n)
{
	int temp;//用于交换顺序

	//外层循环，控制趟数
	for (int i = 0; i < n - 1; i++)
	{
		//内存循环，选出最大的数字排到最后面
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j +1])
			{
				temp = arr[j];
				arr[j] = arr[j +1];
				arr[j + 1] = temp;
			}
		}
	}
}
void show(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
int main()
{
	int arrrr[] = { 7,4,5,9,8,2,1 };
	int n = sizeof(arrrr) / sizeof(arrrr[0]);
	std::cout << "排序前的数组：";
	show(arrrr, n);
	BubbleSort(arrrr, n);
	std::cout << "排序后的数组：";
	show(arrrr, n);
}

 
