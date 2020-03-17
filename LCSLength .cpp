#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;
//��̬�滮����
#if 0
/*
***************************************
    �����������--->����Ӧ�������������
    X ={X1,X2,X3,X4����Xm} m��Ԫ�ظ�����
    Y ={Y1,Y2,Y3,Y4����Yn} n
    Z ={Z1,Z2,Z3,Z4����Zk} k
    �ҳ�X��Y�������������s(m,n)
    m ==0 || n==0 0
    m>0 && n> 0
    X[m] = Y[n] = s(m-1,n-1) + 1
    X[m] != Y[n] =max{s(m-1,n) ,s(m,n-1)}
***************************************
*/
//�ݹ�ʵ��
int LCSLength(char* X, char* Y, int i, int j,vector<vector<int>> &c, vector<vector<int>> &s)
{
    if (i <= 0 || j <= 0) return 0;//�����������������û��Ԫ�ص�ʱ�򣬷���0
    if (c[i][j] > 0) return c[i][j];//������������������ʱ�򣬷���
    else
    if (X[i] == Y[j])//���һ�� X[m] = Y[n] = s(m-1,n-1) + 1
    {
        c[i][j] = LCSLength(X, Y, i - 1, j - 1,c,s) + 1;//1
        s[i][j] = 1;
    }
    else
    {
        int max1 = LCSLength(X, Y, i, j - 1,c,s); //2 ������� X[m] != Y[n] =s(m,n-1)
        int max2 = LCSLength(X, Y, i - 1, j,c,s); //3 ������� X[m] != Y[n] =s(m-1,n)
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
        //Ӧ���ȵݹ��ٴ�ӡֵ
        TrackBack(X, s, i - 1, j - 1);
        cout << X[i] << " ";
    }
    else if (s[i][j] == 2)
    {
        TrackBack(X, s, i , j - 1);//�м�һ
    }
    else
    {
        TrackBack(X, s, i - 1, j );//�м�һ
    }

}
//�ǵݹ�ʵ��
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
    char X[] = { "#ABCBDAB" };//0λ�õ��ڱ�λ,���±�͸������Ӧ
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
        m[i][j]= j >= W[1] ? V[1] : 0;//ֻ��һ����Ʒ�����
    }
    else
    {
        if (j < W[i])
        {
            m[i][j] = Knapsack(W, V, i - 1, j, m);
        }//��i����Ʒװ���µ�ʱ��
        else//��i����Ʒ��װ�µ�ʱ����װ�ºͲ�װ����ȡ���ֵ
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
    return 0;
}
#endif
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

