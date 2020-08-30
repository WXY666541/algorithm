#include<iostream>
#include<list>
#include<vector>
using namespace std;
/*
ɾ�����������е��ظ�Ԫ�ء���ÿ��Ԫ��ֻ����һ��
*/
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(NULL)
	{}
};

//��������ָ��ķ�ʽ
ListNode* deleteDuplicates(ListNode* head)
{
	//��������Ĵ���
	if (head == NULL)
	{
		return NULL;
	}

	//��������ָ��
	ListNode* slow = head;
	ListNode* fast = slow->next;

	//������ͬ��������͵���ָ��ָ��
	while (slow->next != NULL)
	{
		//�ҵ����ظ�Ԫ��
		if (slow->val == fast->val)
		{
			//��ָ�����û��Ԫ��
			if (fast->next == NULL)
			{
				slow->next = NULL;
			}

			//��ָ����滹��Ԫ��
			{
				slow->next = fast->next;
				fast = fast->next;//���¿�ָ��
			}
		}
		else//û���ҵ��ظ�Ԫ��
		{
			fast = fast->next;
			slow = slow->next;
		}
		
	}
	return head;
}
