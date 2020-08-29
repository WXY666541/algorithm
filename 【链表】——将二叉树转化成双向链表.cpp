#include<iostream>
#include<list>
#include<vector>
using namespace std;
/*
��������˫������
*/
class Node
{
public:
	int val;
	Node* left;
	Node* right;

	Node(){}
	Node(int _val)
	{
		val = _val;
		left = NULL;
		right = NULL;
	}

	Node(int _val, Node* _left, Node* _right)
	{
		val = _val;
		left = _left;
		right = _right;
	}
};

void dfs(Node* root,Node* &head,Node* &pre)
{
	//�ݹ�����˳�����
	if (root == NULL) return;

	//����������ݹ����֮����������
	dfs(root->left, head, pre);

	//��ʾ���ڷ���ͷ��㣬�����ͷ����pre��ֵ
	if (head == NULL)
	{
		head = root;
		pre = root;//��pre���г�ʼ��
	}
	else//����˫�����������½��
	{
		pre->right = root;
		root->left = pre;
		pre = root;
	}
	//����������ݹ����֮����������
	dfs(root->right, head, pre);
}

Node* treeToDoubleList(Node* root)
{
	//��ʼ��head��pre���
	Node* head = NULL;
	Node* pre = NULL;

	//�����������
	if (root == NULL) 
		return NULL;

	//����ת��Ϊ˫������
	dfs(root,head,pre);

	//����ѭ������
	head->left = pre;
	pre->right = head;
	return head;
}

