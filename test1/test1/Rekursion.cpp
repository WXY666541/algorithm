/*
  ���β��ԣ�
  1������
     ������Ĺ�ģ��С��һ���̶Ⱦ����׽��
     ��������Էֽ�����ɸ���ģ��С����ͬ����
     ...
  �ݹ飺
  �ݹ麯����ִ�з�Ϊ��"���ơ��͡��ع顱�������̣���������������ֲ�������ƣ�
  �������ƣ�ֱ���ݹ���ֹ�������㣬��ֹ�ݹ飬Ȼ�����ع�
  �ݹ����ͬ��ͨ�����ĵ���һ����ÿ�����÷���ʱ����Ҫ�����µ�ջ֡���β����ݣ��ֳ��������ֲ�������
  ������ͨ�ĺ������ò�ͬ���ǣ����ڵ��ƵĹ�����һ�������õĹ��̣���˴���һ����������ķ���ջ֡
  ���̣�ֱ�������ݹ���ֹ����ʱ���ſ�ʼ�ع飬���ǲ�����ͷ�ջ֡�ռ䣬������һ�㣬ֱ����󷵻�������

  û������ݹ飬��Ϊջ�������vs 1M  linux 10M
  (1)����޸�ջ�Ĵ�С��
    ��linux  gcc g++
  (2)�ڶ���̶��߳��еĵ��ԣ�
    ��Linux ��dbg����

*/
#if 0

#include<iostream>
using namespace std;
#include<vector>



/*
  1�����׳�
     ������Ҫ��n�Ľ׳ˣ�������n-1�Ľ׳ˣ��Դ�����
     ջ֡�Ķ�̬�������̣��ݹ�Ĺ��̾���һ�����Ͽ���ջ֡�Ĺ��̣���������𲽻ع�
*/


//�������������
//1��ѭ��ʵ��  O(n)  S(1)
int fun(int n)
{
    int sum = 1;
    for (int i = 1; i <= n; ++i)
    {
        sum = sum * i;
    }
    return sum;
}

//1.1�ı�----->��ѭ�����������������ִ�С���Ϊÿһ�����̶���һ��ʱ��Ƭ��ʱ��Ƭһ���ͻᵽ����̬
int fun1(int n)
{
    int sum = 1;
    for (int i = 1; ; ++i)//������ѭ��
//-----����C�����е���ѭ����ʾ��ʽfor( ; ; ){}(Ч�ʻ��һ�㣩   while(1){ }
    {
        sum = sum * i;
    }
    return sum;
}
//2���ݹ�ʵ��O(n) S(n)
int sum(int n)
{
    if (n <= 1)
        return 1;
    else
        return sum(n - 1) * n;
}
//2.1�ݹ�ʵ�ָĽ�������������
int sum1(int n)
{
    if (n <= 1)
        return 1;
    else
    {
        int x = sum(n - 1) * n;
        if (x > 0)
        {
            return x;
        }
        else
        {
            return -1;
        }
    }
}
int main()
{
    int n = 4;
    int sum = fun(n);
    cout << sum << endl;
    return 0;
}


/*
  ����һ������12345����� 5 4 3 2 1

*/

//ѭ��ʵ��
void fun(unsigned int n)
{
    while (n)
    {
        cout << n % 10 << "";
        n = n / 10;
    }
}
//ѭ���Ľ�1��ʹѭ����ӡ������ֵΪ����---��ģ��ʵ��ջ
void fun1(unsigned int n)
{
    int ar[20] = { 0 };//�޷�������42�ڶ࣬Ϊʮλ����С����ʮλ����
    int top = 0;
    while (n)
    {
        ar[top++] = n % 10;
        n = n / 10;
    }
    for (int i = top; i >= 0; --i)//���i�����unsigned�ͻ��������----����Ϊi--����-1�����һ���ܴ��������������ѭ��
    {
        cout << ar[i - 1] << "";
    }
    cout << endl;
}
//ѭ���Ľ�2��ʹ���������
void fun2(unsigned int n)
{
    vector<int> ivec;
    while (n)
    {
        ivec.push_back(n % 10);
        n = n / 10;
    }
    //�����ת
    for (vector<int>::reverse_iterator rit = ivec.rbegin(); rit != ivec.rend(); ++rit)
    {
        cout << *rit << "";
    }
    cout << endl;
}

//�ݹ�ʵ��
void fun1(unsigned int n)
{
    if (n > 0)
    {
        cout << n % 10 << "";
        fun1(n / 10);
    }
}

//�ݹ�ʵ�ָĽ�1����if��Ϊwhile
void fun11(unsigned int n)
{
    while (n > 0)//���ϵĵݹ���ù���nһֱ�ǲ���ģ����Ͽ���ջ֡���൱����ѭ��
    {
        cout << n % 10 << "";
        fun1(n / 10);
    }
}

//�ݹ�ʵ�ָĽ�2�������һ�γ���n = n /10;
void fun111(unsigned int n)
{
    while (n > 0)//���ϵĵݹ���ù���nһֱ�ǲ���ģ����Ͽ���ջ֡���൱����ѭ��
    {
        cout << n % 10 << "";
        n = n / 10;
        fun1(n / 10);
    }
}

//�ݹ�Ľ�3��������˳��ı䣬���������
void fun2(unsigned int n)
{
    if (n > 0)
    {
        fun2(n / 10);
        cout << n % 10 << "";
    }
}

int main()
{
    int n = 0;
    cin >> n;
    fun2(n);
    return 0;
}


/*
   �����Լ��

*/

//�����㷨
int fun(int a, int b)
{
    int i = a < b ? a : b;
    for (i -= 1; i > 0; --i)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
    }
}

//ŷ������㷨��շת�����
//ѭ��ʵ��
int fun(int a, int b)
{
    while (b <= 0)
    {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    cout << a << endl;
}
//�ݹ�ʵ��
int fun(int a, int b)
{
    if (b == 0)
        return a;
    return(b, a % b);
}


/*
   쳲���������

*/
//O(2^n) S(h)
int fib(int n)
{
    if (n < 2) return 1;
    else return fib(n - 1) + fib(n - 2);
}

//ʵ�ָĽ������������ظ���,����ʹO(n),S(n)
int fibs(int n, int a, int b)
{
    if (n <= 2) return a;
    else return fibs(n - 1, a + b, a);
}
int fib(int n)
{
    int a = 1, b = 1;
    return fibs(n, a, b);
}
#endif