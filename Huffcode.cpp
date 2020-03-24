#include<iostream>
#include<vector>
#include<queue>
#include<iomanip>
#include<functional>
#include<algorithm>
using namespace std;

#define HUFFSIZE 8
typedef unsigned int WeightType;
typedef struct
{
	WeightType weight;
	int parent;
	int leftchild;
	int rightchild;
}HuffNode;
typedef HuffNode HuffTree[HUFFSIZE * 2];

typedef struct
{
	char ch;
	char code[HUFFSIZE + 1];
}HuffCoding;

typedef HuffCoding HuffCode[HUFFSIZE + 1];
void Init_HuffTree(HuffTree ht)
{
	memset(ht, 0, sizeof(HuffTree));
	WeightType ar[] = {
#include"Huff.data"
	};
		int n = sizeof(ar) / sizeof(ar[0]);
	for (int i = 0; i < n; ++i)
	{
		ht[i + 1].weight = ar[i];//设置权值
	}

}
void Init_HuffCode(HuffCode hc)
{
	memset(hc, 0, sizeof(HuffCode));
	char ar[] = {
#include"Tite.data"
	};
	int n = sizeof(ar) / sizeof(ar[0])-1;
	for (int i = 0; i < n; ++i)
	{
		hc[i+1].ch = ar[i];
		hc[i+1].code[0] = '\0';
	}
}
void Print_HuffTree(HuffTree ht)
{
	cout << setw(-10)<<"Index"<<setw(10)<<"Weight" << setw(10)<<"Parent"<< setw(10)<<"Left"<< setw(10)<<"Right" << endl;
	for (int i = 1; i < HUFFSIZE * 2; ++i)
	{
		cout << setw(-10) << i;
		cout << setw(10)<< ht[i].weight;
		cout << setw(10) << ht[i].parent;
		cout << setw(10) << ht[i].leftchild;
		cout << setw(10)<< ht[i].rightchild << endl;
	}
}
void Print_HuffCode(HuffCode hc)
{
	for (int i = 1; i < HUFFSIZE; ++i)
	{
		cout << hc[i].ch << "=>" << hc[i].code << endl;
	}
}
void Create_HuffTree(HuffTree ht)
{
	struct StkNode//局部结构体
	{
		int index;
		WeightType weight;
		operator WeightType() const { return weight; }
	};
	priority_queue<StkNode, vector<StkNode>, greater<StkNode>> qu;
	for (int i = 1; i <= HUFFSIZE; ++i)
	{
		StkNode x = { i,ht[i].weight };
		qu.push(x);
	}
	int k = HUFFSIZE+1;//标识放得数据位置
	while (!qu.empty())
	{
		if (!qu.empty()) break;
		StkNode left = qu.top(); qu.pop();
		if (qu.empty())break;
		StkNode right = qu.top(); qu.pop();
		ht[k].weight = left.weight + right.weight;
		ht[k].leftchild = left.index;
		ht[k].rightchild = left.index;
		ht[left.index].parent = k;
		ht[right.index].parent = k;
		StkNode x = { k,ht[k].weight };
		qu.push(x);
		k += 1;
	}
}
void Create_HuffCode(HuffTree ht, HuffCode hc)
{
	char code[HUFFSIZE + 1];
	//        0 1 2 3 4 5 6 7 8 
	//                  1 1 0 \0
	//                  k
	for (int i = 1; i <= HUFFSIZE; ++i)
	{
		int c = i;
		int pa = ht[c].parent;
		int k = HUFFSIZE;
		code[k] = '\0';
		while (pa != 0)
		{
			code[--k] = ht[pa].leftchild == c ? '0' : '1';
			c = pa;
			pa = ht[c].parent;
		}
		strcpy(hc[i].code, &code[k]);
	}
}
char* my_strcpy(char* sdi, const char* src)
{
	char* p = sdi;
	while (*src != '\0')
	{
		*p++ = *src++;
	}
	*p = '\0';
	return sdi;
}
int main()
{
	HuffTree ht;
	HuffCode hc;
	Init_HuffTree(ht);
	Init_HuffCode(hc);
	Print_HuffTree(ht);
	Create_HuffTree(ht);
	Create_HuffCode(ht,hc);
	Print_HuffTree(ht);
	Print_HuffCode(hc);
	////优先级队列
	////priority_queue<int, vector<int>> qu;默认的为大顶堆
	//priority_queue<int, vector<int>,greater<int>> qu;//小顶堆
	//int x;
	//while (cin >> x, x != -1)//入队列
	//{
	//	qu.push(x);
	//}
	//while (!qu.empty())//出队列
	//{
	//	int x = qu.top();//先取得队头数据
	//	qu.pop();
	//	cout << x << endl;
	//}
	return 0;
}

