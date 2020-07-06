#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<limits.h>
#include<stack>
using namespace std;

/*
题目1:(简答题:10.0分)
编程实现将字符串转换为整型数；int  my_atoi(const char *str);

1.遇到非数字字母，停止转换；示例： str = "234.324" ; 返回值是234；

2.首先出现空格的字符串可以转换，转换开始后，遇到空格停止转换；示例: str ="    342 456"; 返回值是342；

3.可以处理正负号；示例： str = "    +234.bad" ; 返回值是 234； str = "   -342ab.234" ; 返回值是：-342；

4.可以处理八进制，和十六进制；示例： str = "  +0xff";  返回值是 255；    str = " 0123" ;  返回值是 83；

5 可以处理int 型溢出的情况；
示例: str = "567898765678987656789"; str = 2147483647; (INT_MAX 宏在 limits.h 头文件中）
str = "-234324665544325345325; str = - 2147483648; (INT_MIN 宏在limits.h 头文件中）
*/

//基础版
enum status { kvalue = 0, kInvalue };//定义一个全局变量来区分空串和字符'\0’的情况
bool gstatus = kvalue;
long long Stringtonum(const char* str, bool flag);

int  my_atoi(const char* str)
{
	gstatus = kInvalue;
	long long num = 0;//先用longlong 来保存最后返回的值

	while (*str == ' ' && *str != '\0')//字符串首部是空格的情况
	{
		str++;
	}

	while (str != NULL && *str != '\0')//不是空串的请款
	{
		bool flag = true;
		if (*str == '+')//处理符号问题
			str++;
		else if (*str == '-')
		{
			str++;
			flag = false;
		}

		if (*str != '\0')//首部空格和符号处理完毕，着重处理数值转换问题
		{
			num = Stringtonum(str, flag);
			break;
		}
	}
	return (int)num;
}
long long Stringtonum(const char* str, bool flag)
{
	long long num = 0;

	while (*str != '\0')//从头到尾挨个儿遍历
	{
		if (*str >= '0' && *str <= '9')//是数字的合法情况
		{
			int title = flag ? 1 : -1;
			num = num * 10 + title * (*str - '0');//十进制的转换

			if (title > 0 && num > INT_MAX)//越界的情况
			{
				num = 2147483647;
			}
			else if (title < 0 && num < -INT_MAX)
			{
				num = -2147483647;
			}
		}
		else//非法输入
		{
			break;
		}
		str++;
	}
	if (*str == '\0')//字符‘\0’的特殊情况
	{
		gstatus = kvalue;
	}
	return num;
}
int main()
{
	cout << my_atoi("234.234") << endl;
	cout << my_atoi(" ") << endl;
	cout << my_atoi("\0") << endl;
	cout << my_atoi("   234 345") << endl;
	cout << my_atoi("   +234.abc") << endl;
	cout << my_atoi("   -324ab.324") << endl;
	cout << my_atoi("567898765678987656789") << endl;
	return 0;
}

//进阶版
char change(char x)
{
	char s = x;
	switch (x)
	{
	case'o':
	case 'O':
		s = '0';
		break;
	case'l':
	case 'L':
		s = '1';
		break;

	default:
		s = x;
		break;
	}
	return s;
}
//十进制转换
int dec_atoi(const char* str, int len, int temp, bool flag, int res, int index)
{
	for (int i = index; i < len; i++)
	{
		char x = change(str[i]);
		if (!isdigit(x))
		{
			break;
		}
		temp = x - '0';
		if (flag)
		{
			if (INT_MAX - res * 10 >= temp - 1)
			{
				res = res * 10 + temp;
			}
			else
			{
				res = INT_MIN;
				break;
			}
		}
		else
		{
			if (INT_MAX - res * 10 <= temp)
			{
				res = INT_MAX;
				break;
			}
			res = res * 10 + temp;
		}
	}
	return res;
}

int hex_atoi(const char* str, int len, int temp, int index)
{
	int res = 0;
	index++;
	for (int i = index; i < len; i++)
	{
		char x = change(str[i]);
		if (isxdigit(x))
		{
			if (isdigit(x))
			{
				temp = x - '0';
				res = res * 16 + temp;
			}
			else
			{
				char s = tolower(x);
				temp = s - 'a' + 10;
				res = res * 16 + temp;
			}
		}
		else
			break;
	}
	return res;
}

int oct_atoi(const char* str, int len, int temp, int index)
{
	int res = 0;
	for (int i = index; i < len; i++)
	{
		char x = change(str[i]);
		if (x >= '0' && x <= '7')
		{
			temp = x - '0';
			res = res * 8 + temp;
		}
		else
			break;
	}
	return res;
}
int  my_atoi(const char* str)
{
	int temp = 0;
	int res = 0;
	bool flag = false;
	int len = (int)strlen(str);

	int index = 0;
	while (str[index] == ' ')
	{
		index++;
	}

	while (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
		{
			flag = true;
		}
		index++;
	}

	if (str[index] != '0')
	{
		res = dec_atoi(str, len, temp, flag, res, index);
	}
	else
	{
		index++;
		if (str[index] == 'x' || str[index] == 'X')
		{
			res = hex_atoi(str, len, temp, index);
		}
		else
		{
			res = oct_atoi(str, len, temp, index);
		}
	}
	if (flag)
	{
		res = 0 - res;
	}
	return res;
}

int main()
{
	cout << "遇到非数字字母，停止转换：" << my_atoi("l34.324") << endl;
	cout << "首先出现空格的字符串可以转换，转换开始后，遇到空格停止转换：" << my_atoi("    342 456") << endl;
	cout << "处理正号：" << my_atoi("    +204.bad") << endl;
	cout << "处理负号：" << my_atoi("   -342ab.234") << endl;
	cout << "十六进制：" << my_atoi("  +0xa1") << endl;
	cout << "八进制：" << my_atoi("0123") << endl;
	cout << "上溢出：" << my_atoi("567898765678987656789") << endl;
	cout << "下溢出：" << my_atoi("-234324665544325345325") << endl;
}

/*2. 编程实现将整型数值转换为字符串。
char *my_itoa(int value, char *buffer, int radix);
参数说明：
value：欲转换的数值。
buffer：目标字符串的地址。
radix：转换后的进制数，可以是2进制，10进制、16进制等。
示例： value = 10; radix = 2; string="1010"
不考虑value 为负数。
与函数int sprintf(char *string, char *format ,...);比较，有什么不同；
*/

char* my_itoa(int value, char* buffer, int radix)
{
	static const char* stra = { "0123456789abcdefghijklonopqrstuvwxyz" };
	static const char* strb = { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" };


	if (buffer == NULL)
	{
		return NULL;
	}
	if (value == 0)
	{
		buffer[0] = '\0';
		return 0;
	}
	int n = strlen(stra);
	if (radix < 2 || radix > n)
	{
		return NULL;
	}

	stack<int> res;
	while (value != 0)
	{
		res.push(stra[value % radix]);
		value /= radix;
	}
	int i = 0;
	while (!res.empty())
	{
		buffer[i++] = res.top();
		res.pop();
	}
	buffer[i] = '\0';
	return buffer;
}
int main()
{
	char str[256] = {};
	int x = 0X1234;
	int x1 = 01234;
	int x2 = 1234;
	for (int i = 2; i <= 20; i++)
	{
		cout << x << "-->:" << i << "=" << my_itoa(x, str, i) << endl;
		//cout << x << "-->:" << i << "=" << my_itoa(x1, str, i) << endl;
		//cout << x << "-->:" << i << "=" << my_itoa(x2, str, i) << endl;
	}
	return 0;
}