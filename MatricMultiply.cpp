#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;
/*
    矩阵连乘问题
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
//ra,矩阵a的行，ca矩阵a的列，rb矩阵b的行
void MatricMultiply(int** a, int** b, int** c, int ra, int ca, int rb, int cb)
{
    if (ca != rb) return;//如果a的列和b的行不相等，则没有计算的必要
    for (int i = 0; i < ra; ++i)
    {
        for (int j = 0; j < cb; ++j)
        {
            int sum = 0;
            for (int k = 0; k < ca; ++k)
            {
                sum += a[i][k] * b[k][j];//O(ra*ca*cb)
            }
            c[i][j] = sum;
        }
    }
}
int MatrixChain(int* p, int i, int j)
{
    if (i == j) return 0;
    else
    {
        //必须要有这个，不能没有这个让k从i开始
        int min = MatrixChain(p, i, i) + MatrixChain(p, i + 1, j) + p[i - 1] * p[i] * p[j];//k = i的情况下计算一个基准值
        for (int k = i + 1; k < j; k++)
        {
            int t = MatrixChain(p, i, k) + MatrixChain(p,k + 1, j) + p[i - 1] * p[k] * p[j];
            if (min > t)
            {
                min = t;
            }
        }
        return min;
    }
}
//解决重复计算项的问题
int MatrixChain1(int* p, int i, int j, vector<vector<int>> &m, vector<vector<int>> &c)
{
    if (i == j) return 0;
    else if (m[i][j] > 0) return m[i][j];
    else
    {
        //必须要有这个，不能没有这个让k从i开始
        m[i][j] = MatrixChain1(p, i + 1, j,m,c) + p[i - 1] * p[i] * p[j];//k = i的情况下计算一个基准值
        c[i][j] = i;
        for (int k = i + 1; k < j; k++)
        {
            int t = MatrixChain1(p, i, k,m,c) + MatrixChain1(p, k + 1, j,m,c) + p[i - 1] * p[k] * p[j];
            if (m[i][j] > t)
            {
                m[i][j] = t;
                c[i][j] = k;
            }
        }
        return m[i][j];
    }
}
//分析矩阵具体的乘的方法
void TrackBack(vector<vector<int>>& c, int i, int j)
{
    if (i < j)
    { 
        cout << "Martix A:" << i << "*" << c[i][j] << "AND";
        cout << c[i][j] + 1 << "*" << j << endl;
        TrackBack(c, i, c[i][j]);
        TrackBack(c, c[i][j]+1,j);
       
    }
}

int main()
{
    const int n = 6;
    int p[n + 1] = { 30,35,15,5,10,20,25 };
    vector<vector<int>> m,c;//用二维数组c来记录k值
    m.resize(n + 1);//对于计算机来说，是从0开始，所以要多开辟一行一列
    c.resize(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        m[i].resize(n + 1, 0);
        c[i].resize(n + 1, 0);
    }
    Print_Vector(m);
    int mix = MatrixChain1(p, 1, 6,m,c);//从第一个矩阵乘到第6个矩阵
    cout << mix << endl;
    Print_Vector(m);
    cout << endl;
    Print_Vector(c);
    TrackBack(c, 1, n);
    return 0;
}
