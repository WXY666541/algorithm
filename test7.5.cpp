#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<limits.h>
#include<stack>
using namespace std;

//�޸Ĵ�����
char change(char x)
{
	char s = x;
	switch (x)
	{
	case'o':
	case'O':
		s = '0';
		break;
	case'l':
	case'L':
		s = '1';
		break;
	default:
		s = x;
	}
	return s;
}
int dec_atoi(const char* str, int len, int res, int temp, bool flag, int index)
{
	for (int i = 0; i < len; i++)
	{
		char x = change(str[i]);//���о���
		if (!isdigit(x))
		{
			break;
		}
		temp = x - '0';
		if (flag)
		{
			if (INT_MIN - res * 10 >= temp)
			{
				res = INT_MIN;
				break;
			}
			res = res * 10 + temp;
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
int hex_atoi(const char* str, int len, int res, int temp, int index)
{
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
int oct_atoi(const char* str, int len, int res, int temp, int index)
{
	for (int i = index; i < len; i++)
	{
		char x = change(str[i]);//���о���
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
	int len = (int)strlen(str);
	bool flag = false;//��ʶ���ţ�Ĭ��Ϊ����

	//����ո�
	int index = 0;
	while (str[index] == ' ')
		index++;

	//�������
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
		{
			flag = true;
		}
		index++;
	}

	if (str[index] != '0')//��ͨʮ���Ƶ�ת��
	{
		res = dec_atoi(str, len, res, temp, flag, index);
	}
	//����ʮ�����ƺ�8���Ƶ����
	else
	{
		index++;//��Ϊ������16���ƻ���8���ƣ�indexλΪ0
		if (str[index] == 'x')
		{
			res = hex_atoi(str, len, res, temp, index);
		}
		else
		{
			res = oct_atoi(str, len, res, temp, index);
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