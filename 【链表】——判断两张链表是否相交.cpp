#include<iostream>
#include<list>
#include<vector>
using namespace std;

/*
�ж����������Ƿ��ཻ
*/
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(NULL)
	{}
};

bool IsMeeting(ListNode* headA, ListNode* headB)
{
	//��������ж�
	if (headA == NULL || headB == NULL)
	{
		return false;
	}

	//�����������ֱ������β��
	while (headA != NULL)
	{
		headA = headA->next;
	}
	while (headB != NULL)
	{
		headB = headB->next;
	}

	//�Ƚ�β����Ƿ����
	if (headA == headB)
	{
		return true;
	}
	else
	{
		return false;
	}
}

