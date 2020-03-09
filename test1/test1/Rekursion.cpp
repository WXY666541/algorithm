/*
  分治策略：
  1、特征
     该问题的规模缩小到一定程度就容易解决
     该问题可以分解成若干个规模较小的相同问题
     ...
  递归：
  递归函数的执行分为："递推”和“回归”两个过程，这两个过程由种植条件控制，
  即逐层递推，直至递归终止条件满足，终止递归，然后逐层回归
  递归调用同普通函数的调用一样，每当调用发生时，就要分配新的栈帧（形参数据，现场保护，局部变量）
  而与普通的函数调用不同的是，由于递推的过程是一个逐层调用的过程，因此存在一个逐层连续的分配栈帧
  过程，直到遇到递归终止条件时，才开始回归，这是才逐层释放栈帧空间，返回上一层，直至最后返回主函数

  没有无穷递归，因为栈会溢出。vs 1M  linux 10M
  (1)如何修改栈的大小？
    在linux  gcc g++
  (2)在多进程多线程中的调试？
    在Linux 中dbg调试

*/
#if 0

#include<iostream>
using namespace std;
#include<vector>



/*
  1、求解阶乘
     分析：要求n的阶乘，则先求n-1的阶乘，以此类推
     栈帧的动态调动过程：递归的过程就是一个不断开辟栈帧的过程，随后又是逐步回归
*/


//不考虑整形溢出
//1、循环实现  O(n)  S(1)
int fun(int n)
{
    int sum = 1;
    for (int i = 1; i <= n; ++i)
    {
        sum = sum * i;
    }
    return sum;
}

//1.1改变----->死循环，但其他程序可以执行。因为每一个进程都有一个时间片，时间片一到就会到就绪态
int fun1(int n)
{
    int sum = 1;
    for (int i = 1; ; ++i)//代表死循环
//-----》在C语言中的死循环表示方式for( ; ; ){}(效率会高一点）   while(1){ }
    {
        sum = sum * i;
    }
    return sum;
}
//2、递归实现O(n) S(n)
int sum(int n)
{
    if (n <= 1)
        return 1;
    else
        return sum(n - 1) * n;
}
//2.1递归实现改进，解决溢出问题
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
  输入一个整数12345，输出 5 4 3 2 1

*/

//循环实现
void fun(unsigned int n)
{
    while (n)
    {
        cout << n % 10 << "";
        n = n / 10;
    }
}
//循环改进1：使循环打印出来的值为正序---》模拟实现栈
void fun1(unsigned int n)
{
    int ar[20] = { 0 };//无符号整形42亿多，为十位，大小大于十位就行
    int top = 0;
    while (n)
    {
        ar[top++] = n % 10;
        n = n / 10;
    }
    for (int i = top; i >= 0; --i)//如果i定义成unsigned就会出现问题----》因为i--过后，-1变成了一个很大的数，会是无限循环
    {
        cout << ar[i - 1] << "";
    }
    cout << endl;
}
//循环改进2：使用容器解决
void fun2(unsigned int n)
{
    vector<int> ivec;
    while (n)
    {
        ivec.push_back(n % 10);
        n = n / 10;
    }
    //输出逆转
    for (vector<int>::reverse_iterator rit = ivec.rbegin(); rit != ivec.rend(); ++rit)
    {
        cout << *rit << "";
    }
    cout << endl;
}

//递归实现
void fun1(unsigned int n)
{
    if (n > 0)
    {
        cout << n % 10 << "";
        fun1(n / 10);
    }
}

//递归实现改进1，将if改为while
void fun11(unsigned int n)
{
    while (n > 0)//不断的递归调用过程n一直是不变的，不断开辟栈帧，相当于死循环
    {
        cout << n % 10 << "";
        fun1(n / 10);
    }
}

//递归实现改进2，后面加一段程序n = n /10;
void fun111(unsigned int n)
{
    while (n > 0)//不断的递归调用过程n一直是不变的，不断开辟栈帧，相当于死循环
    {
        cout << n % 10 << "";
        n = n / 10;
        fun1(n / 10);
    }
}

//递归改进3，将程序顺序改变，将正序输出
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
   求最大公约数

*/

//常规算法
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

//欧几里得算法：辗转相除法
//循环实现
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
//递归实现
int fun(int a, int b)
{
    if (b == 0)
        return a;
    return(b, a % b);
}


/*
   斐波拉契数列

*/
//O(2^n) S(h)
int fib(int n)
{
    if (n < 2) return 1;
    else return fib(n - 1) + fib(n - 2);
}

//实现改进：消除计算重复项,并且使O(n),S(n)
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