#include<stdio.h>
#include<iostream>
#include<vector>
#if 0
using namespace std;
/*
********************************
      递归实现：合并排序
********************************
*/

//数组打印函数
template<class Type>
void Print_Ar(Type* ar, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}

//数组拷贝函数
template<class Type>
void copy(Type* dsr, Type* src, int left, int right)
{
    for (int i = left; i <= right; i++)
    {
        dsr[i] = src[i];
    }
}

//并轨操作
template<class Type>
void Merge(Type* dsr, Type* src, int left, int m, int right)
{
    int i = left;
    int j = m + 1;
    int k = left;
    while (i <= m && j <= right)
    {
        dsr[k++] = src[i] < src[j] ? src[i++] : src[j++];
    }
    while (i <= m)
    {
        dsr[k++] = src[i++];
    }
    while (j <=right )
    {
        dsr[k++] = src[j++];
    }
}

template<class Type>
void MergePass(Type* br, Type* ar, int left, int right)
{
    if (left < right)
    {
        int m = (right - left) / 2 + left;
        MergePass(br, ar, left, m);
        MergePass(br, ar, m + 1, right);
        Merge(br, ar, left, m, right);
        copy(ar, br, left, right);
    }
}
template<class Type>
void MergeSort(Type* ar, int n)
{
    if (NULL == ar || n <= 1)return;
    Type* br = new Type[n];
    MergePass(br, ar, 0, n - 1);
    delete[]br;
}

/*
********************************
      非递归实现：合并排序
********************************
*/
template<class Type>
void NiceMergePass(Type* dsr, Type* src, int s, int n)
{
    int i = 0;
    for (i = 0; i+2*s-1 <= n-1  ; i = i + 2 * s)
    {
        Merge(dsr, src, i, i + s - 1, i + 2 * s - 1);
    }
    if (n - 1 > i + s - 1)
    {
        Merge(dsr, src, i, i + s - 1, n - 1);
    }
    else
    {
        for (int j = i; j < n; ++j)
        {
            dsr[i] = src[j];
        }
    }
}
template<class Type>
void NiceMergeSort(Type* ar, int n)
{
    if (NULL == ar || n <= 1)return;
    Type* br = new Type[n];
    int s = 1;
    while (s < n)
    {
        MergePass(br, ar, s, n );
        s += s;
        MergePass(ar, br, s, n);
        s += s;
    }
    delete[]br;
}
int main()
{
    int ar[] = { 34,56,78,12,23,92,86,100,45,67 };
    int n = sizeof(ar) / sizeof(ar[0]);
    Print_Ar(ar, n);
    MergeSort(ar, n);
    NiceMergeSort(ar, n);
    Print_Ar(ar, n);
    return 0;
}
#endif

