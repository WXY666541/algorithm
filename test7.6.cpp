#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<limits.h>
#include<stack>
using namespace std;

/*
��Ŀ1:(�����:10.0��)
���ʵ�ֽ��ַ���ת��Ϊ��������int  my_atoi(const char *str);

1.������������ĸ��ֹͣת����ʾ���� str = "234.324" ; ����ֵ��234��

2.���ȳ��ֿո���ַ�������ת����ת����ʼ�������ո�ֹͣת����ʾ��: str ="    342 456"; ����ֵ��342��

3.���Դ��������ţ�ʾ���� str = "    +234.bad" ; ����ֵ�� 234�� str = "   -342ab.234" ; ����ֵ�ǣ�-342��

4.���Դ���˽��ƣ���ʮ�����ƣ�ʾ���� str = "  +0xff";  ����ֵ�� 255��    str = " 0123" ;  ����ֵ�� 83��

5 ���Դ���int ������������
ʾ��: str = "567898765678987656789"; str = 2147483647; (INT_MAX ���� limits.h ͷ�ļ��У�
str = "-234324665544325345325; str = - 2147483648; (INT_MIN ����limits.h ͷ�ļ��У�
*/

//������
enum status { kvalue = 0, kInvalue };//����һ��ȫ�ֱ��������ֿմ����ַ�'\0�������
bool gstatus = kvalue;
long long Stringtonum(const char* str, bool flag);

int  my_atoi(const char* str)
{
	gstatus = kInvalue;
	long long num = 0;//����longlong ��������󷵻ص�ֵ

	while (*str == ' ' && *str != '\0')//�ַ����ײ��ǿո�����
	{
		str++;
	}

	while (str != NULL && *str != '\0')//���ǿմ������
	{
		bool flag = true;
		if (*str == '+')//�����������
			str++;
		else if (*str == '-')
		{
			str++;
			flag = false;
		}

		if (*str != '\0')//�ײ��ո�ͷ��Ŵ�����ϣ����ش�����ֵת������
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

	while (*str != '\0')//��ͷ��β����������
	{
		if (*str >= '0' && *str <= '9')//�����ֵĺϷ����
		{
			int title = flag ? 1 : -1;
			num = num * 10 + title * (*str - '0');//ʮ���Ƶ�ת��

			if (title > 0 && num > INT_MAX)//Խ������
			{
				num = 2147483647;
			}
			else if (title < 0 && num < -INT_MAX)
			{
				num = -2147483647;
			}
		}
		else//�Ƿ�����
		{
			break;
		}
		str++;
	}
	if (*str == '\0')//�ַ���\0�����������
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

//���װ�
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
//ʮ����ת��
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
	cout << "������������ĸ��ֹͣת����" << my_atoi("l34.324") << endl;
	cout << "���ȳ��ֿո���ַ�������ת����ת����ʼ�������ո�ֹͣת����" << my_atoi("    342 456") << endl;
	cout << "�������ţ�" << my_atoi("    +204.bad") << endl;
	cout << "�����ţ�" << my_atoi("   -342ab.234") << endl;
	cout << "ʮ�����ƣ�" << my_atoi("  +0xa1") << endl;
	cout << "�˽��ƣ�" << my_atoi("0123") << endl;
	cout << "�������" << my_atoi("567898765678987656789") << endl;
	cout << "�������" << my_atoi("-234324665544325345325") << endl;
}

/*2. ���ʵ�ֽ�������ֵת��Ϊ�ַ�����
char *my_itoa(int value, char *buffer, int radix);
����˵����
value����ת������ֵ��
buffer��Ŀ���ַ����ĵ�ַ��
radix��ת����Ľ�������������2���ƣ�10���ơ�16���Ƶȡ�
ʾ���� value = 10; radix = 2; string="1010"
������value Ϊ������
�뺯��int sprintf(char *string, char *format ,...);�Ƚϣ���ʲô��ͬ��
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