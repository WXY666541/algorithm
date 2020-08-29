#include<iostream>
#include<list>
#include<vector>
using namespace std;
/*
�ж��Ƿ��ǻ�������
*/
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(NULL)
	{}
};
//��ʽһ�����ÿ���ָ�룬����ת
bool isPalindrome(ListNode* head)
{
	//����������жϡ���û�н���ֻ��һ�����
	if (head == NULL || head->next == NULL)
	{
		return true;
	}

	//��ʼ������ָ�룬�ҵ�������м���
	ListNode* slow = head;
	ListNode* fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	//��ת����ĺ�벿��
	ListNode* left = slow;
	ListNode* mid = left->next;

	while (mid)
	{
		ListNode* right = mid->next;

		//��ת�Ĺ���
		mid->next = left;

		//���Ƹ��²���
		left = mid;
		mid = right;
	}
	//���ת�������β���
	slow->next = NULL;

	//�����ֱȽ�
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

//������������vector����
bool isPalindrome(ListNode* head)
{
	//����������жϡ���û�н�����ֻ��һ�����
	if (head == NULL || head->next == NULL)
	{
		return true;
	}

	//��ʼ��һ��vector����
	vector<int> vec;

	//����������ÿ������ֵ����vector������
	while (head != NULL)
	{
		vec.push_back(head->val);
		head = head->next;
	}

	//forѭ���Ƚ�i��size()-i-1��ֵ
	for (int i = 0; i < vec.size()/2; i++)
	{
		if (vec[i] != vec[vec.size() - i - 1])
		{
			return false;
		}
	}
	return true;
}
