#include<iostream>
#include<assert.h>
using namespace std;
/*
删除排序链表中的重复结点——复杂
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
	//特殊情况判断
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	//新申请一个头结点
	ListNode* newhead = new ListNode(-1);
	newhead->next = head;

	//初始化两个快慢指针
	ListNode* slow = newhead;
	ListNode* fast = newhead->next;

	//循环处理
	while (fast != NULL)
	{
		//结点值相同
		if (fast->next != NULL && fast->val == fast->next->val)
		{
			//让slow定点，fast去寻找相同的结点
			while (fast->next != NULL && fast->val == fast->next->val)
			{
				fast = fast->next;
			}
			//找到相同结点的区域后，做删除操作
			slow->next = fast->next;
			fast = fast->next;//更新fast结点
		}
		else
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	return newhead->next;
}

