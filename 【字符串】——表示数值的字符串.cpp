#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
��ʾ��ֵ���ַ���
*/

//��֤�Ƿ�Ϊ�ַ�����
bool ScanB(const char** str)
{
	const char* before = *str;//����һ��ָ���ʶ��ʼλ��

	//�Ϸ�����Ĵ���
	if (**str >= '0' && **str <= '9' && **str != '\0')
	{
		(*str)++;
	}
	if (*str > before)//��ʾ���ַ����ʹ���
		return true;
}

bool ScanA(const char** str)
{
	if (**str == '+' || **str == '-')//���A�������������⴦��
	{
		*str++;
	}
	return  ScanB(str);
}

bool isNumber(const char* str)
{
	//����������ж�
	if (str == NULL)
	{
		return false;
	}
	//��֤A���������ַ�����
	bool isnumber = ScanA(&str);

	//����'.'��֤B
	if (*str == '.')
	{
		str++;
		isnumber = isnumber || ScanB(&str);
	}

	//����'E/e',��֤C
	if (*str == 'E' || *str == 'e')
	{
		str++;
		isnumber = isnumber && ScanB(&str);
	}

	//���ַ�����β���ؽ��
	if ((isnumber && *str) == '\0')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	if (isNumber("12e+5.4"))
	{
		cout << "�Ǳ�ʾ��ֵ���ַ���";
	}
	else
	{
		cout << "���Ǳ�ʾ��ֵ���ַ���";
	}
}
