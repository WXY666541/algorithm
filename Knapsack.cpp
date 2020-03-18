#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#if 0
/*
***************************************
  0-1背包问题
***************************************
*/
//方法一：
/*
从前往后：
从题目大意可以推导出：
SUM(xi*wi)<=c && MAX(SUM(xi*vi)
SUM(xi*wi)<=c-w[n] && MAX(SUM(xi*vi) i = 1,2,3,4..n-1
数学公式为：
m(i,j)
i == 1----> j>=w[i] ? v[1] : 0
当i>1 i<= n
j < w[i]（放不进去）----> m(i-1,j)
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
//递归方式
int Knapsack(int* W, int* V, int i, int j, vector<vector<int>>& m)
{
    if (i == 1)
    {
        m[i][j] = j >= W[1] ? V[1] : 0;//只有一个物品的情况
    }
    else
    {
        if (j < W[i])
        {
            m[i][j] = Knapsack(W, V, i - 1, j, m);
        }//第i个物品装不下的时候
        else//第i个物品能装下的时候，在装下和不装下中取最大值
        {
            m[i][j] = max(Knapsack(W, V, i - 1, j, m), Knapsack(W, V, i - 1, j - W[i], m) + V[i]);
        }
    }
    return m[i][j];
}

//非递归方式
int NiceKnapsack(int* W, int* V, int n, int c, vector<vector<int>>& m)
{
    int i = 1, j = 1;
    for (j = 1; j <= c; ++j)
    {
        m[i][j] = j >= W[1] ? V[1] : 0;//填充0列
    }
    for (i = 2; i <= n; i++)
    {
        for (j = 1; j <= c; ++j)
        {
            if (j < W[i])//装不下去
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
    vector<vector<int>> m;//创建一个二维数组行
    m.resize(n + 1);//列
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
方法二：从后往前
SUM(xi*wi)<=c && MAX(SUM(xi*vi)
SUM(xi*wi)<=c-w[1] && MAX(SUM(xi*vi) i = 1,2,3,4..n-1
数学公式为：
m(i,j)
i == n----> j>=w[n] ? v[n] : 0
当i>1 i<= n
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