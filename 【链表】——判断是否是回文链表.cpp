#include<iostream>
#include<list>
#include<vector>
using namespace std;
/*
判断是否是回文链表
*/
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(NULL)
	{}
};
//方式一：利用快慢指针，链表反转
bool isPalindrome(ListNode* head)
{
	//特殊情况的判断——没有结点和只有一个结点
	if (head == NULL || head->next == NULL)
	{
		return true;
	}

	//初始化快慢指针，找到链表的中间结点
	ListNode* slow = head;
	ListNode* fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	//反转链表的后半部分
	ListNode* left = slow;
	ListNode* mid = left->next;

	while (mid)
	{
		ListNode* right = mid->next;

		//反转的过程
		mid->next = left;

		//后移更新操作
		left = mid;
		mid = right;
	}
	//最后反转后链表的尾结点
	slow->next = NULL;

	//两部分比较
	while (head && left)
	{
		if (head->val != left->val)
		{
			return false;
		}
		head = head->next;
		left = left->next;
	}
	return true;
}

//方法二：利用vector容器
bool isPalindrome(ListNode* head)
{
	//特殊情况的判断——没有结点或者只有一个结点
	if (head == NULL || head->next == NULL)
	{
		return true;
	}

	//初始化一个vector容器
	vector<int> vec;

	//遍历链表，将每个结点的值放入vector数组中
	while (head != NULL)
	{
		vec.push_back(head->val);
		head = head->next;
	}

	//for循环比较i和size()-i-1的值
	for (int i = 0; i < vec.size()/2; i++)
	{
		if (vec[i] != vec[vec.size() - i - 1])
		{
			return false;
		}
	}
	return true;
}
