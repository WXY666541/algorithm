#include<iostream>
#include<list>
#include<vector>
using namespace std;

/*
�ҵ���һ���뻷���
*/

struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(NULL)
	{}
};
//���ȵõ����е�һ�����
ListNode* MeetingNode(ListNode* head)
{
	//��������ж�
	if (head == NULL)
	{
		return NULL;
	}

	ListNode* fast = head;
	ListNode* slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
		{
			return slow;
		}
	}
	return NULL;
}

//�ҵ�һ���뻷���
ListNode* EntryNodeOfLoop(ListNode* head)
{
	//���ú����õ����е��������
	ListNode* meetingnode = MeetingNode(head);
	if (meetingnode == NULL)
	{
		return NULL;
	}

	//���㻷�еĽ������
	ListNode* Node = meetingnode->next;
	int count = 1;
	while (Node != meetingnode)
	{
		Node = Node->next;
		count++;
	}

	//��ʼ������ָ��
	ListNode* fast = head;
	ListNode* slow = head;

	//�ÿ�ָ�����߻��еĽ��������
	while (count)
	{
		fast = fast->next;
		count--;
	}

	//����ָ��һ����
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
