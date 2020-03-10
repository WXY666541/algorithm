#include<stdio.h>
#include<iostream>
#include<vector>
#include<time.h>
#include<stack>
#include<queue>
#include<assert.h>
using namespace std;
/*
********************************
      �ݹ�ʵ�֣���������
********************************
*/
template<class Type>
void Print_Ar(Type* ar, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}
//���ֺ���
template<class Type>
int Partition(Type* ar, int left, int right)
{
    int i = left, j = right;
    Type tmp = ar[left];
    while (i < j)
    {
        while (i <j && ar[j] >tmp)--j;
        if (i < j)ar[i] = ar[j];
        while (i < j && ar[i] <= tmp)++i;
        if (i < j) ar[j] = ar[i];
    }
    ar[i] = tmp;
    return i;
}
//�������
template<class Type>
int RandPartition(Type* ar, int left, int right)
{
    srand(time(NULL));
    int pos = rand() % (right - left + 1) + left;
    swap(ar[pos], ar[left]);
    //int mid = (right - left+1)/2+left; ��λȡ�з�
    return Partion(ar, left, right);
}
template<class Type>
void QuickPass(Type* ar, int left, int right)
{
    if (left < right)
    {
        int mid = Partition(ar, left, right);
        QuickPass(ar, left, mid - 1);
        QuickPass(ar, mid + 1, right);
    }
}

template<class Type>
void QuickSort(Type* ar, int n)
{
    if (NULL == ar || n <= 1)return;
    QuickPass(ar, 0, n - 1);
}

/*
********************************
      �ǵݹ�ʵ�֣���������
      ջʵ��
********************************
*/
template<class Type>
void NiceQuickPass(Type* ar, int left, int right)
{
    stack<int> st;
    st.push(left);
    st.push(right);
    while (!st.empty())
    {
        right = st.top(); st.pop();
        left = st.top(); st.pop();
        int mid = Partition(ar, left, right);
        if (left < mid - 1)
        {
            st.push(left);
            st.push(mid - 1);
        }
        if (mid + 1 < right)
        {
            st.push(mid + 1);
            st.push(right);
        }
    }
}
template<class Type>
void QuickSort1(Type* ar, int n)
{
    if (NULL == ar || n <= 1)return;
    QuickPass(ar, 0, n - 1);
}

/*
********************************
      �ǵݹ�ʵ�֣���������
      ����ʵ��
********************************
*/
template<class Type>
void NiceQuickPass1(Type* ar, int left, int right)
{
    queue<int> st;
    st.push(left);
    st.push(right);
    while (!st.empty())
    {
        right = st.front(); st.pop();
        left = st.front(); st.pop();
        int mid = Partition(ar, left, right);
        if (left < mid - 1)
        {
            st.push(left);
            st.push(mid - 1);
        }
        if (mid + 1 < right)
        {
            st.push(mid + 1);
            st.push(right);
        }
    }
}
template<class Type>
void QuickSort2(Type* ar, int n)
{
    if (NULL == ar || n <= 1)return;
    QuickPass(ar, 0, n - 1);
}

/*
********************************
      �Ե�������п�������
      ���򻮷�
********************************
*/

typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node* next;
}Node;
typedef struct
{
    Node* head;
    int cursize;
}LinkList;
struct Node* Buynode()
{
    struct Node* s = (struct Node*)malloc(sizeof(struct Node));
    if (NULL == s)exit(EXIT_FAILURE);
    memset(s, 0, sizeof(struct Node));
    return s;
}
void Init_List(LinkList* plist)
{
    assert(plist != NULL);
    plist->head = Buynode();
    plist->cursize = 0;
}

void Print_List(LinkList* plist)
{
    assert(plist != NULL);
    struct Node* p = plist->head->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p -> next;
    }
    cout << endl;
}
void Push_front(LinkList* plist, ElemType val)
{
    assert(plist != NULL);
    struct Node* s = Buynode();
    s->data = val;
    s->next = plist->head->next;
    plist->head->next = s;
    plist->cursize += 1;
}


/*int OnePartition(Type* ar, int left, int right)
{
    int i = left + 1, j = i;
    while (j <= right)
    {
        if (ar[j] <= ar[left])
        {
            swap(ar[j], ar[i]);
            ++i;
            ++j;
        }
        ++j;
    }
    i = i - 1;
    swap(ar[left], ar[i]);
    return i;
}*/
struct Node* ListPartition(struct Node* begin, struct Node* end)
{
    struct Node* i = begin, * j = i -> next;
    while (j != end)
    {
        if (j->data <= begin->data)
        {
            swap(i->next->data, j->data);
            i = i->next;
            j = j->next;
        }
        else
        j = j->next;
    }
    swap(begin->data, i->data);
    return i;
}

void ListQuickSort(struct Node *begin,struct Node *end)
{
    if (begin != end)
    {
        struct Node* mid = ListPartition(begin, end);
        ListQuickSort(begin, mid);
        ListQuickSort(mid->next,end);
    }
}
int main()
{
    int ar[] = { 34,56,78,12,23,92,86,100,45,67 };
    int n = sizeof(ar) / sizeof(ar[0]);
    Print_Ar(ar, n);

    QuickSort(ar, n);
    Print_Ar(ar, n);

    QuickSort1(ar, n);
    Print_Ar(ar, n);

    QuickSort2(ar, n);
    Print_Ar(ar, n);
    
    LinkList mylist;
    Init_List(&mylist);
    for (int i = 0; i < 13; ++i)
    {
        Push_front(&mylist, rand() % 100);
    }
    ListQuickSort(mylist.head->next, NULL);
    Print_List(&mylist);
    return 0;
}
