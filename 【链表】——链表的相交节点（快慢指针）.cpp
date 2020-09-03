#include<iostream>
#include<assert.h>
using namespace std;

//得到链表长度
unsigned int GetListLength(ListNode* pHead)
{
	ListNode* pNode = pHead;
	unsigned int count = 0;
	while (pNode != nullptr)
	{
		count++;
		pNode = pNode->m_pnext;
	}
	return count;
}

ListNode* FindFirstCommonNode(ListNode* pHead1,ListNode* pHead2)
{
	unsigned int length1 = GetListLength(pHead1);
	unsigned int length2 = GetListLength(pHead2);
	int lengthDif = length1 - length2;

	ListNode* pListHeadlong = pHead1;
	ListNode* pListHeadshort = pHead2;
	if (length1 < length2)
	{
		ListNode* pListHeadlong = pHead2;
		ListNode* pListHeadshort = pHead1;
		lengthDif = length2 - length1;
	}

	for (int i = 0; i < lengthDif; i++)
	{
		pListHeadlong = pListHeadlong->m_pnext;
	}

	while ((pListHeadlong != nullptr) && (pListHeadshort != nullptr) && (pListHeadlong != pListHeadshort))
	{
		pListHeadlong = pListHeadlong->m_pnext;
		pListHeadshort = pListHeadshort->m_pnext;
	}

	ListNode* pFirstCommonNode = pListHeadlong;
	return pFirstCommonNode;
}


