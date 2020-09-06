#include<iostream>
using namespace std;

//归并排序(数组）
void MergeSortCore(int* arr, int n, int gap)
{
	//初始化两段的下标
	int low1 = 0;
	int high1 = low1 + gap - 1;
	int low2 = high1 + 1;
	int high2 = low2 + gap > n ? n - 1 : low2 + gap - 1;

	//新开辟一个数组存放归并好的数组
	int* brr = (int*)malloc(sizeof(int) * n);
	int j = 0;//初始化新数组的下标

	//总体来说有两个归并段的时候
	while (low2 < n)
	{
		while (low1 <= high1 && low2 <= high2)
		{
			if (arr[low1] <= arr[low2])
			{
				brr[j++] = arr[low1++];
			}
			else
			{
				brr[j++] = arr[low2++];
			}
		}

		//前一个归并段有遗留
		while (low1 <= high1)
		{
			brr[j++] = arr[low1++];
		}

		//后一个归并段有遗留
		while (low2 <= high2)
		{
			brr[j++] = arr[low2++];
		}

		//下一个归并段继续
		low1 = high2+1;
		high1 = low1 + gap - 1;
		low2 = high1 + 1;
		high2 = low2 + gap > n ? n - 1 : low2 + gap - 1;
	}

	//最后没有划分成归并段，还有遗留的情况
	while (low1 < n)
	{
		brr[j++] = arr[low1++];
	}

	//将数组中的元素重新挪动到arr当中
	for (int i = 0; i < n; i++)
	{
		arr[i] = brr[i];
	}

	//释放brr的空间
	free(brr);
}


void MergeSort(int* arr, int n)
{
	for (int i = 1; i < n; i *= 2)
	{
		MergeSortCore(arr, n, i);
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
	int arrrr[] = { 10,6,7,1,3,9,4,2 };
	int n = sizeof(arrrr) / sizeof(arrrr[0]);
	std::cout << "排序前的数组：";
	show(arrrr, n);
	MergeSort(arrrr, n);
	std::cout << "排序后的数组：";
	show(arrrr, n);
}

//归并排序（链表）
struct ListNode
{
	int val;
	struct ListNode* next;
};
ListNode* MergeCore(ListNode* l1, ListNode* l2)
{
	//申请一个新的头结点
	ListNode* newnode = new ListNode();
	ListNode* p = newnode;

	//当归并的两个段都不为空时
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			p->next = l1;
			l1 = l1->next;
		}
		else
		{
			p->next = l2;
			l2 = l2->next;
		}
		p = p->next;
	}

	//处理归并遗留下来的元素
	if (l1 != NULL)
	{
		p->next = l1;
		l1 = l1->next;
		p = p->next;
	}

	if (l2 != NULL)
	{
		p->next = l2;
		l2 = l2->next;
		p = p->next;
	}

	return newnode->next;
}
ListNode* sortList(ListNode* head)
{

	//特殊情况的判断
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	//初始化三个指针
	ListNode* pre;
	ListNode* slow = head;
	ListNode* fast = head;

	//链表分割的过程
	while (fast != NULL && fast->next != NULL)
	{
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	pre->next = NULL;

	//递归过程
	return MergeCore(sortList(head), sortList(slow));
}
