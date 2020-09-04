#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
表示数值的字符串
*/

//验证是否为字符类型
bool ScanB(const char** str)
{
	const char* before = *str;//定义一个指针标识起始位置

	//合法情况的处理
	if (**str >= '0' && **str <= '9' && **str != '\0')
	{
		(*str)++;
	}
	if (*str > before)//表示有字符类型存在
		return true;
}

bool ScanA(const char** str)
{
	if (**str == '+' || **str == '-')//针对A会有正负号特殊处理
	{
		*str++;
	}
	return  ScanB(str);
}

bool isNumber(const char* str)
{
	//特殊情况的判断
	if (str == NULL)
	{
		return false;
	}
	//验证A，必须是字符类型
	bool isnumber = ScanA(&str);

	//遇到'.'验证B
	if (*str == '.')
	{
		str++;
		isnumber = isnumber || ScanB(&str);
	}

	//遇到'E/e',验证C
	if (*str == 'E' || *str == 'e')
	{
		str++;
		isnumber = isnumber && ScanB(&str);
	}

	//到字符串结尾返回结果
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
		cout << "是表示数值的字符串";
	}
	else
	{
		cout << "不是表示数值的字符串";
	}
}
