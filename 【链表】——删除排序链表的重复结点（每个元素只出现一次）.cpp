#include<iostream>
#include<list>
#include<vector>
using namespace std;
/*
删除排序链表中的重复元素——每个元素只出现一次
*/
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(NULL)
	{}
};

//采用两个指针的方式
ListNode* deleteDuplicates(ListNode* head)
{
	//特殊情况的处理
	if (head == NULL)
	{
		return NULL;
	}

	//定义两个指针
	ListNode* slow = head;
	ListNode* fast = slow->next;

	//遇到相同的情况，就调整指针指向
	while (slow->next != NULL)
	{
		//找到了重复元素
		if (slow->val == fast->val)
		{
			//快指针后面没有元素
			if (fast->next == NULL)
			{
				slow->next = NULL;
			}

			//快指针后面还有元素
			{
				slow->next = fast->next;
				fast = fast->next;//更新快指针
			}
		}
		else//没有找到重复元素
		{
			fast = fast->next;
			slow = slow->next;
		}
		
	}
	return head;
}
