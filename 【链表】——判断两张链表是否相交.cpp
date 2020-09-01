#include<iostream>
#include<list>
#include<vector>
using namespace std;

/*
判断两张链表是否相交
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
	//特殊情况判断
	if (headA == NULL || headB == NULL)
	{
		return false;
	}

	//让两张链表都分别走向结尾处
	while (headA != NULL)
	{
		headA = headA->next;
	}
	while (headB != NULL)
	{
		headB = headB->next;
	}

	//比较尾结点是否相等
	if (headA == headB)
	{
		return true;
	}
	else
	{
		return false;
	}
}

