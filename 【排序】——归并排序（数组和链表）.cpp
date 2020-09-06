#include<iostream>
using namespace std;

//�鲢����(���飩
void MergeSortCore(int* arr, int n, int gap)
{
	//��ʼ�����ε��±�
	int low1 = 0;
	int high1 = low1 + gap - 1;
	int low2 = high1 + 1;
	int high2 = low2 + gap > n ? n - 1 : low2 + gap - 1;

	//�¿���һ�������Ź鲢�õ�����
	int* brr = (int*)malloc(sizeof(int) * n);
	int j = 0;//��ʼ����������±�

	//������˵�������鲢�ε�ʱ��
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

		//ǰһ���鲢��������
		while (low1 <= high1)
		{
			brr[j++] = arr[low1++];
		}

		//��һ���鲢��������
		while (low2 <= high2)
		{
			brr[j++] = arr[low2++];
		}

		//��һ���鲢�μ���
		low1 = high2+1;
		high1 = low1 + gap - 1;
		low2 = high1 + 1;
		high2 = low2 + gap > n ? n - 1 : low2 + gap - 1;
	}

	//���û�л��ֳɹ鲢�Σ��������������
	while (low1 < n)
	{
		brr[j++] = arr[low1++];
	}

	//�������е�Ԫ������Ų����arr����
	for (int i = 0; i < n; i++)
	{
		arr[i] = brr[i];
	}

	//�ͷ�brr�Ŀռ�
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
	std::cout << "����ǰ�����飺";
	show(arrrr, n);
	MergeSort(arrrr, n);
	std::cout << "���������飺";
	show(arrrr, n);
}

//�鲢��������
struct ListNode
{
	int val;
	struct ListNode* next;
};
ListNode* MergeCore(ListNode* l1, ListNode* l2)
{
	//����һ���µ�ͷ���
	ListNode* newnode = new ListNode();
	ListNode* p = newnode;

	//���鲢�������ζ���Ϊ��ʱ
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

	//����鲢����������Ԫ��
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

	//����������ж�
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	//��ʼ������ָ��
	ListNode* pre;
	ListNode* slow = head;
	ListNode* fast = head;

	//����ָ�Ĺ���
	while (fast != NULL && fast->next != NULL)
	{
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	pre->next = NULL;

	//�ݹ����
	return MergeCore(sortList(head), sortList(slow));
}
