#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
char* my_strcpy(char* p1, const char* p2)
{
	assert(p1);
	assert(p2);
	char* ret = *p1;
	while (*p1++ = *p2++);

	return ret;
}
char* my_strcat(char* p1, const char* p2)
{
	assert(p1);
	assert(p2);
	char* ret = *p1;
	while (*p1 != '\0')
	{
		*p1++;
	}
	while (*p1++ = *p2++);
	return ret;
}
int my_strcmp(const char* p1,const char* p2)
{
	while (*p1 - *p2 == 0)
	{
		if (*p1 == '\0')
			break;
		p1++;
		p2++;
	}
	return *p1 - *p2;
}
char* my_strstr(const char* p1, const char* p2)
{
	char* i = p2;
	while (1) 
	{
		if (*p2 == *p1)
		{
			char* m = p1;
			while (*p2 == *p1 || *p2 =='\0')
			{
				if (*p2 == '\0')
					return m;
				p2++;
				p1++;
			}
			p2 = i;
			p1 = m ;
		}
			if (*p1 == '\0')
				return NULL;
			p1++;
	}
}
int main()
{
	char arr1[20] = { "hello " };
	char arr2[20] = { 0 };
	printf("%s", my_strstr("abbbcdef", "bbc"));

	return 0;
}