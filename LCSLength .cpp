#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;
//动态规划问题
#if 0
/*
***************************************
    最长公共子序列--->可以应用于求回文序列
    X ={X1,X2,X3,X4……Xm} m（元素个数）
    Y ={Y1,Y2,Y3,Y4……Yn} n
    Z ={Z1,Z2,Z3,Z4……Zk} k
    找出X和Y的最长公共子序列s(m,n)
    m ==0 || n==0 0
    m>0 && n> 0
    X[m] = Y[n] = s(m-1,n-1) + 1
    X[m] != Y[n] =max{s(m-1,n) ,s(m,n-1)}
***************************************
*/
//递归实现
int LCSLength(char* X, char* Y, int i, int j,vector<vector<int>> &c, vector<vector<int>> &s)
{
    if (i <= 0 || j <= 0) return 0;//特殊情况，当序列中没有元素的时候，返回0
    if (c[i][j] > 0) return c[i][j];//当数组中有数字填充的时候，返回
    else
    if (X[i] == Y[j])//情况一： X[m] = Y[n] = s(m-1,n-1) + 1
    {
        c[i][j] = LCSLength(X, Y, i - 1, j - 1,c,s) + 1;//1
        s[i][j] = 1;
    }
    else
    {
        int max1 = LCSLength(X, Y, i, j - 1,c,s); //2 情况二： X[m] != Y[n] =s(m,n-1)
        int max2 = LCSLength(X, Y, i - 1, j,c,s); //3 情况三： X[m] != Y[n] =s(m-1,n)
        if (max1 > max2)
        {
            c[i][i] = max1;
            s[i][j] = 2;
        }
        else
        {
            c[i][i] = max2;
            s[i][j] = 3;
        }
    }
    return c[i][j];
}
void TrackBack(char X[], vector<vector<int>>& s, int i, int j)
{
    if (i <= 0 || j <= 0) return;
    if (s[i][j] == 1)
    {
        //应该先递归再打印值
        TrackBack(X, s, i - 1, j - 1);
        cout << X[i] << " ";
    }
    else if (s[i][j] == 2)
    {
        TrackBack(X, s, i , j - 1);//列减一
    }
    else
    {
        TrackBack(X, s, i - 1, j );//行减一
    }

}
//非递归实现
int NiceLCSLength(char* X, char* Y, int m, int n, vector<vector<int> >& c, vector<vector<int> >& s)
{
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (X[i] == Y[j])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                s[i][j] = 1; // 
            }
            else if (c[i][j - 1] > c[i - 1][j])
            {
                c[i][j] = c[i][j - 1];
                s[i][j] = 2;
            }
            else
            {
                c[i][j] = c[i - 1][j];
                s[i][j] = 3;
            }
        }
    }
    return c[m][n];
}
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
int main()
{
    char X[] = { "#ABCBDAB" };//0位置的哨兵位,让下标和个数相对应
    char Y[] = { "#BDCABA" };
    int xm = strlen(X) - 1;
    int yn = strlen(Y) - 1;
    vector<vector<int>> c;
    vector<vector<int>> s;
    c.resize(xm + 1);
    s.resize(xm + 1);
    for (int i = 0; i < xm + 1; i++)
    {
        c[i].resize(yn + 1, 0);
        s[i].resize(yn + 1, 0);
    }
    int maxlen = LCSLength(X, Y, xm, yn,c,s);
    cout << maxlen << endl;
    Print_Vector(c);
    TrackBack(X, s, xm, yn);
    Print_Vector(s);
    cout << endl;
    return 0;
}

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
j < w[i]----> m(i-1,j)
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
int Knapsack(int* W, int* V, int i, int j,vector<vector<int>> &m)
{
    if (i == 1)
    {
        m[i][j]= j >= W[1] ? V[1] : 0;//只有一个物品的情况
    }
    else
    {
        if (j < W[i])
        {
            m[i][j] = Knapsack(W, V, i - 1, j, m);
        }//第i个物品装不下的时候
        else//第i个物品能装下的时候，在装下和不装下中取最大值
        {
           m[i][j]= max(Knapsack(W, V, i - 1,j,m), Knapsack(W, V, i - 1, j - W[i],m) + V[i]);
        }
    }
    return m[i][j];
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
    return 0;
}
#endif
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
}

