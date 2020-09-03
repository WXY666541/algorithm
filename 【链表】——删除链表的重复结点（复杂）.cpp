#include<iostream>
#include<assert.h>
using namespace std;
/*
ɾ�����������е��ظ���㡪������
*/
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(NULL)
	{}
};

ListNode* DeleteNode(ListNode* head)
{
	//��������ж�
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	//������һ��ͷ���
	ListNode* newhead = new ListNode(-1);
	newhead->next = head;

	//��ʼ����������ָ��
	ListNode* slow = newhead;
	ListNode* fast = newhead->next;

	//ѭ������
	while (fast != NULL)
	{
		//���ֵ��ͬ
		if (fast->next != NULL && fast->val == fast->next->val)
		{
			//��slow���㣬fastȥѰ����ͬ�Ľ��
			while (fast->next != NULL && fast->val == fast->next->val)
			{
				fast = fast->next;
			}
			//�ҵ���ͬ�����������ɾ������
			slow->next = fast->next;
			fast = fast->next;//����fast���
		}
		else
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	return newhead->next;
}

