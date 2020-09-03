#include<iostream>
#include<assert.h>
using namespace std;

//�����������
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode,*List;

//��ʼ������
void InitList(ListNode* plist)
{
	assert(plist != NULL);
	if (plist == NULL)
	{
		return;
	}
	plist->next = NULL;
}

//ͷ��
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

//β��
bool Insert_Tail(ListNode* plist, int val)
{
	assert(plist != NULL);
	if (plist == NULL)
	{
		return false;
	}
	//��������
	ListNode* p = new ListNode();
	p->val = val;

	//��β���
	ListNode* q = plist;
	while (q->next != NULL)
	{
		q = q->next;
	}

	//����
	p->next = NULL;
	q->next = p;
	return true;
}

//��ӡ���
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
