#include<iostream>
#include<assert.h>
using namespace std;
/*
分割链表
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
	//特殊情况处理
	if (head == NULL)
	{
		return NULL;
	}

	//新定义两个链表
	ListNode* smalllist = new ListNode(-1);
	ListNode* biglist = new ListNode(-1);

	//初始化两个链表的指针和当前指针
	ListNode* slow = smalllist;
	ListNode* fast = biglist;
	ListNode* cur = head;

	while (cur )
	{
		//填充smalllist
		if (cur->val < x)
		{
			slow->next = cur;
			slow = slow->next;
		}
		else//填充biglist
		{
			fast->next = cur;
			fast = fast->next;
		}
		cur = cur->next;
	}
	//拼接过程
	slow->next = biglist->next;
	fast->next = NULL;//处理尾结点
	return smalllist->next;
}

