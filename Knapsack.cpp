#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#if 0
/*
***************************************
  0-1��������
***************************************
*/
//����һ��
/*
��ǰ����
����Ŀ��������Ƶ�����
SUM(xi*wi)<=c && MAX(SUM(xi*vi)
SUM(xi*wi)<=c-w[n] && MAX(SUM(xi*vi) i = 1,2,3,4..n-1
��ѧ��ʽΪ��
m(i,j)
i == 1----> j>=w[i] ? v[1] : 0
��i>1 i<= n
j < w[i]���Ų���ȥ��----> m(i-1,j)
        ---->m(i-1,j-w[i])+v[i]
*/

void  Print_Vector(vector<vector<int>>& c)
{
    for (int i = 0; i < c.size(); i++)
    {
        for (int j = 0; j < c.size(); j++)
        {
            cout << setw(5) << c[i][j] << " ";
        }
        cout << endl;
    }
}
//�ݹ鷽ʽ
int Knapsack(int* W, int* V, int i, int j, vector<vector<int>>& m)
{
    if (i == 1)
    {
        m[i][j] = j >= W[1] ? V[1] : 0;//ֻ��һ����Ʒ�����
    }
    else
    {
        if (j < W[i])
        {
            m[i][j] = Knapsack(W, V, i - 1, j, m);
        }//��i����Ʒװ���µ�ʱ��
        else//��i����Ʒ��װ�µ�ʱ����װ�ºͲ�װ����ȡ���ֵ
        {
            m[i][j] = max(Knapsack(W, V, i - 1, j, m), Knapsack(W, V, i - 1, j - W[i], m) + V[i]);
        }
    }
    return m[i][j];
}

//�ǵݹ鷽ʽ
int NiceKnapsack(int* W, int* V, int n, int c, vector<vector<int>>& m)
{
    int i = 1, j = 1;
    for (j = 1; j <= c; ++j)
    {
        m[i][j] = j >= W[1] ? V[1] : 0;//���0��
    }
    for (i = 2; i <= n; i++)
    {
        for (j = 1; j <= c; ++j)
        {
            if (j < W[i])//װ����ȥ
            {
                m[i][j] = m[i - 1][j];
            }
            else
            {
                m[i][j] = max(m[i - 1][j], m[i - 1][j - W[i]] + V[i]);
            }
        }
    }
    return m[n][c];
}
void TrackBack(int* W, int* X, int n, int c, vector<vector<int> >& m)
{
    int i = 1;
    for (i = 1; i < n; ++i)
    {
        if (m[i][c] != m[i - 1][c])
        {
            X[i] = 1;
            c = c - W[i];
        }
    }
    if (m[n][c] != 0)
    {
        X[n] = 1;
    }
}
int main()
{
    const int n = 5;
    const int c = 10;
    int W[] = { 0,9,2,6,5,4 };
    int V[] = { 0,6,3,5,4,16 };
    int X[] = { 0,0,0,0,0,0 };
    vector<vector<int>> m;//����һ����ά������
    m.resize(n + 1);//��
    for (int i = 0; i <= n; ++i)
    {
        m[i].resize(c + 1, 0);
    }
    Print_Vector(m);
    int maxv = Knapsack(W, V, n, c, m);
    cout << maxv << endl;
    Print_Vector(m);
    TrackBack(W, X, n, c, m);
    return 0;
}

/*
���������Ӻ���ǰ
SUM(xi*wi)<=c && MAX(SUM(xi*vi)
SUM(xi*wi)<=c-w[1] && MAX(SUM(xi*vi) i = 1,2,3,4..n-1
��ѧ��ʽΪ��
m(i,j)
i == n----> j>=w[n] ? v[n] : 0
��i>1 i<= n
j < w[i]----> m(i+1,j)
        ---->m(i+1,j-w[i])+v[i]
*/
/*void  Print_Vector(vector<vector<int>>& c)
{
    for (int i = 0; i < c.size(); i++)
    {
        for (int j = 0; j < c.size(); j++)
        {
            cout << setw(5) << c[i][j] << " ";
        }
        cout << endl;
    }
}
int Knapsack1(int* W, int* V, int i, int n, int j, vector<vector<int> >& m)
{
    if (i == n)
    {
        m[i][j] = j >= W[n] ? V[n] : 0;
    }
    else if (m[i][j] > 0) return m[i][j];
    else
    {
        if (j < W[i])
        {
            m[i][j] = Knapsack1(W, V, i + 1, n, j, m);
        }
        else
        {
            m[i][j] = max(Knapsack1(W, V, i + 1, n, j, m), Knapsack1(W, V, i + 1, n, j - W[i], m) + V[i]);
        }
    }
    return m[i][j];
}
void TrackBack(int* W, int* X, int n, int c, vector<vector<int> >& m)
{
    int i = 1;
    for (i = 1; i < n; ++i)
    {
        if (m[i][c] != m[i + 1][c])
        {
            X[i] = 1;
            c = c - W[i];
        }
    }
    if (m[n][c] != 0)
    {
        X[n] = 1;
    }
}
int main()
{
    const int n = 5;
    const int c = 10;
    int W[] = { 0,2,2,6,5,4 };
    int V[] = { 0,6,3,5,4,6 };
    int X[] = { 0,0,0,0,0,0 };
    vector<vector<int> > m;
    m.resize(n + 1);
    for (int i = 0; i <= n; ++i)
    {
        m[i].resize(c + 1, 0);
    }
    Print_Vector(m);
    int maxv = Knapsack1(W, V, 1, n, c, m);
    cout << maxv << endl;
    Print_Vector(m);
    TrackBack(W, X, n, c, m);


    return 0;
}*/
#endif