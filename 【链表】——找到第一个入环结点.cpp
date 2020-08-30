#include<iostream>
#include<list>
#include<vector>
using namespace std;

/*
找到第一个入环结点
*/

struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(NULL)
	{}
};
//首先得到环中的一个结点
ListNode* MeetingNode(ListNode* head)
{
	//特殊情况判断
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

//找第一个入环结点
ListNode* EntryNodeOfLoop(ListNode* head)
{
	//调用函数得到环中的相遇结点
	ListNode* meetingnode = MeetingNode(head);
	if (meetingnode == NULL)
	{
		return NULL;
	}

	//计算环中的结点数量
	ListNode* Node = meetingnode->next;
	int count = 1;
	while (Node != meetingnode)
	{
		Node = Node->next;
		count++;
	}

	//初始化快慢指针
	ListNode* fast = head;
	ListNode* slow = head;

	//让快指针先走环中的结点数量步
	while (count)
	{
		fast = fast->next;
		count--;
	}

	//快慢指针一起走
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
