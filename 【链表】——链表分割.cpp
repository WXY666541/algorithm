#include<iostream>
#include<assert.h>
using namespace std;
/*
�ָ�����
*/
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(NULL)
	{}
};
ListNode* Partition(ListNode* head, int x)
{
	//�����������
	if (head == NULL)
	{
		return NULL;
	}

	//�¶�����������
	ListNode* smalllist = new ListNode(-1);
	ListNode* biglist = new ListNode(-1);

	//��ʼ�����������ָ��͵�ǰָ��
	ListNode* slow = smalllist;
	ListNode* fast = biglist;
	ListNode* cur = head;

	while (cur )
	{
		//���smalllist
		if (cur->val < x)
		{
			slow->next = cur;
			slow = slow->next;
		}
		else//���biglist
		{
			fast->next = cur;
			fast = fast->next;
		}
		cur = cur->next;
	}
	//ƴ�ӹ���
	slow->next = biglist->next;
	fast->next = NULL;//����β���
	return smalllist->next;
}

