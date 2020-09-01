#include<iostream>
#include<list>
#include<vector>
using namespace std;
/* 
返回链表的中间结点
*/
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(NULL)
	{}
};
ListNode* MiddleNode(ListNode* head)
{
	ListNode* fast = head;
	ListNode* slow = head;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
