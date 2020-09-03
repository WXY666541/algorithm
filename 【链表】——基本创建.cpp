#include<iostream>
#include<assert.h>
using namespace std;

//定义结点和链表
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode,*List;

//初始化操作
void InitList(ListNode* plist)
{
	assert(plist != NULL);
	if (plist == NULL)
	{
		return;
	}
	plist->next = NULL;
}

//头插
bool Insert_Head(ListNode* plist, int val)
{
	assert(plist != NULL);
	if (plist == NULL)
	{
		return false;
	}
	ListNode* p = new ListNode();
	p->val = val;

	p->next = plist->next;
	plist->next = p;
	return true;
}

//尾插
bool Insert_Tail(ListNode* plist, int val)
{
	assert(plist != NULL);
	if (plist == NULL)
	{
		return false;
	}
	//先申请结点
	ListNode* p = new ListNode();
	p->val = val;

	//找尾结点
	ListNode* q = plist;
	while (q->next != NULL)
	{
		q = q->next;
	}

	//插入
	p->next = NULL;
	q->next = p;
	return true;
}

//打印结点
void Print(ListNode* plist)
{
	while (plist)
	{
		cout << plist->next->val<<" ";
		plist = plist->next;
	}
}


int main()
{
	ListNode plist ;
	InitList(&plist);
	for (int i = 0; i < 10; i++)
	{
		Insert_Tail(&plist, i);
	}
	Print(&plist);
}
