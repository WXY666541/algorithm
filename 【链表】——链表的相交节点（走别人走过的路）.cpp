#include<iostream>
#include<assert.h>
using namespace std;
/*
���������ཻ���
*/
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(NULL)
	{}
};

//����ָ�룬�߱����߹���·
ListNode* FindFirstCommentNode(ListNode* headA,ListNode* headB)
{
	//��������ж�
	if (headA == NULL || headB == NULL)
	{
		return NULL;
	}

	//��ʼ������ָ��
	ListNode* la = headA;
	ListNode* lb = headB;

	//ѭ������
	while (la != lb)
	{
		//��la��
		if (la != NULL)
		{
			la = la->next;
		}
		else
		{
			la = headB;
		}

		//��lb��
		if (lb != NULL)
		{
			lb = lb->next;
		}
		else
		{
			lb = headA;
		}
	}
	return la;
}
