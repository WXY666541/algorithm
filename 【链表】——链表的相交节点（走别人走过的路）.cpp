#include<iostream>
#include<assert.h>
using namespace std;
/*
两张链表相交结点
*/
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(NULL)
	{}
};

//两个指针，走别人走过的路
ListNode* FindFirstCommentNode(ListNode* headA,ListNode* headB)
{
	//特殊情况判断
	if (headA == NULL || headB == NULL)
	{
		return NULL;
	}

	//初始化两个指针
	ListNode* la = headA;
	ListNode* lb = headB;

	//循环查找
	while (la != lb)
	{
		//让la走
		if (la != NULL)
		{
			la = la->next;
		}
		else
		{
			la = headB;
		}

		//让lb走
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
