#include<iostream>
using namespace std;

/*
��������
*/
struct ListNode
{
	int val;
	struct ListNode* next;
};


//ð������ʵ�֣����ǳ�����ʱ�临�Ӷ�
ListNode* Sort(ListNode* head)
{
	//����������ж�
	if (head == NULL)
	{
		return NULL;
	}

	//��ʼ����һ�����
	ListNode* node1 = head;

	//˫��forѭ��ð������
	for (; node1 != NULL; node1 = node1->next)//��������
	{
		ListNode* node2 = head;//һ�˹���node2�Ѿ��ߵ�����ĩβ��������Ҫ���³�ʼ��
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
����Ԫ������
*/
#include<iostream>


void BubbleSort(int* arr, int n)
{
	int temp;//���ڽ���˳��

	//���ѭ������������
	for (int i = 0; i < n - 1; i++)
	{
		//�ڴ�ѭ����ѡ�����������ŵ������
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
	std::cout << "����ǰ�����飺";
	show(arrrr, n);
	BubbleSort(arrrr, n);
	std::cout << "���������飺";
	show(arrrr, n);
}

 
