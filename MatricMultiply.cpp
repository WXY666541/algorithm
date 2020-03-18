#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;
/*
    ������������
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
//ra,����a���У�ca����a���У�rb����b����
void MatricMultiply(int** a, int** b, int** c, int ra, int ca, int rb, int cb)
{
    if (ca != rb) return;//���a���к�b���в���ȣ���û�м���ı�Ҫ
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
        //����Ҫ�����������û�������k��i��ʼ
        int min = MatrixChain(p, i, i) + MatrixChain(p, i + 1, j) + p[i - 1] * p[i] * p[j];//k = i������¼���һ����׼ֵ
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
//����ظ������������
int MatrixChain1(int* p, int i, int j, vector<vector<int>> &m, vector<vector<int>> &c)
{
    if (i == j) return 0;
    else if (m[i][j] > 0) return m[i][j];
    else
    {
        //����Ҫ�����������û�������k��i��ʼ
        m[i][j] = MatrixChain1(p, i + 1, j,m,c) + p[i - 1] * p[i] * p[j];//k = i������¼���һ����׼ֵ
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
//�����������ĳ˵ķ���
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
    vector<vector<int>> m,c;//�ö�ά����c����¼kֵ
    m.resize(n + 1);//���ڼ������˵���Ǵ�0��ʼ������Ҫ�࿪��һ��һ��
    c.resize(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        m[i].resize(n + 1, 0);
        c[i].resize(n + 1, 0);
    }
    Print_Vector(m);
    int mix = MatrixChain1(p, 1, 6,m,c);//�ӵ�һ������˵���6������
    cout << mix << endl;
    Print_Vector(m);
    cout << endl;
    Print_Vector(c);
    TrackBack(c, 1, n);
    return 0;
}
