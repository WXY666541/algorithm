#include<iostream>
#include<list>
#include<vector>
using namespace std;
/*
二叉树与双向链表
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
	//递归遍历退出条件
	if (root == NULL) return;

	//二叉树中序递归遍历之遍历左子树
	dfs(root->left, head, pre);

	//表示正在访问头结点，则更新头结点和pre的值
	if (head == NULL)
	{
		head = root;
		pre = root;//对pre进行初始化
	}
	else//构建双向链表，并更新结点
	{
		pre->right = root;
		root->left = pre;
		pre = root;
	}
	//二叉树中序递归遍历之遍历右子树
	dfs(root->right, head, pre);
}

Node* treeToDoubleList(Node* root)
{
	//初始化head和pre结点
	Node* head = NULL;
	Node* pre = NULL;

	//特殊情况的数
	if (root == NULL) 
		return NULL;

	//把树转化为双向链表
	dfs(root,head,pre);

	//构建循环链表
	head->left = pre;
	pre->right = head;
	return head;
}

