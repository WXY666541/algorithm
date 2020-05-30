#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<cctype>

#if 0
/*
************************
字符串的拷贝
************************
*/

char* my_strcpy(char* dest, const char* str)
{
	//char* start = dest;

	while (*str != '\0')
	{
		*dest++ = *str++;
	}
	*dest = '\0';
	return dest;
}

/*
************************
字符串连接
************************
*/

char* My_strcat(char* des,const char* src)
{
	while (*des != '\0')
		des++;
	while (*src != '\0')
	{
		*des++ = *src++;
	}
	*des = '\0';
	return des;
}
int main()
{
	char str[30] = "hello qqqqqqqqqqqq";
	My_strcat(str, "world");
	printf("%s\n", str);
	return 0;
}

/*
************************
统计字符串中单词的数目
************************
*/

int main()
{
	char str[100];
	int i;
	int num = 0;
	int flag = 0;
	char c;
	gets_s(str);
	for (i = 0; (c = str[i]) != '\0'; i++)
	{
		if (c == ' ')
			flag = 0;
		else if (flag == 0)
		{
			num++;
			flag = 1;
		}
	}
	printf("字符串中单词的数量是%d\n", num);
}

/*
************************
实现字符串转成数字 atoi
************************
*/

int atoi(const char* str)
{
	int result = 0;
	int flag = 1;
	assert(str != NULL);
	while (*str == ' ' || *str == '\n' || *str == '\t')
		str++;
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else if (*str == '+')
		str++;

	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return flag * result;
}

int main()
{
	const char str[] = "1234567";
	int num = atoi(str);
	printf("%d", num);
	return 0;
}


/*
************************
实现数字转成字符串
************************
*/

char* Itoa(int number, char str[],unsigned int radix)
{
	int i = 0;
	int j = 0;
	char* temp = (char*)malloc(sizeof(char) * 20);

	while (number)
	{
		temp[i] = number % 10 + '0';
		i++;
		number = number / 10;
	}
	temp[i] = 0;

	i = i - 1;
	while (i >= 0)
	{
		str[j] = temp[i];
		j++;
		i--;
	}
	str[j] = 0;
	free(temp);
	return str;
}

int main()
{
	char str1[20];
	Itoa(1234567,str1,10);
	printf("%s\n", str1);
	return 0;
}


/*
******************************************
自己实现strncpy——拷贝指定长度的字符串
如果不够字符串的长度，自动补0
******************************************
*/
char* My_strncpy(char* des, const char* src, int count)
{
	while (*src && count)
	{
		*des++ = *src++;
		count--;
	}
	while (count)
	{
		*des++ = '\0';
		count--;
	}
	return des;
}
int main()
{
	char str[20] = "hello world";
	My_strncpy(str, "this is data_struct", 10);
	printf("%s\n", str);
	return 0;
}
#endif

/*
******************************************
自己实现strstr——判断是不是其子串
若找到字符串，返回从该字符串开始的后面所有
字符串，若是没找到，则返回空串
******************************************
*/
const char* My_strstr(const char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);

	if (*src == '\0')
		return NULL;
	const char* s1 = dest;
	const char* s2 = src;

	while (*s1)
	{
		const char* flag = s1;

		while (*s1 == *s2 && *s1 != '\0')
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return flag;
		if (*s1 == '\0')
			return NULL;
		s1++;
	}
	return NULL;
}

int main()
{
	const char* tmp = My_strstr("abcdefgggg", "bcdefgg");
	printf("%s\n", tmp);
	return 0;
}
