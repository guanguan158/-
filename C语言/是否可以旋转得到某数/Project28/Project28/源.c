#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
//void reserve(char* left, char* right)//方法一
//{
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void leftshift(char* arr, int k,int sz)
//{
//	char* ret = arr;//总共有多少元素
//	reserve(arr, arr + k - 1);//左边交换
//	reserve(arr + k, arr + sz - 1);//右边交换
//	reserve(arr, arr + sz - 1);//整体
//
//}
//void my_strcmp(char* arr1, char* arr2)
//{
//	while (*arr1 == *arr2 &&*arr1 !='\0')
//	{
//		arr1++;
//		arr2++;
//	}
//	if ((*arr1 - *arr2) != '\0')
//	{
//		printf("不符合\n");
//	}
//	else
//	{
//		printf("符合\n");
//	}
//}
int main()
{

	char arr[30] = "abcdefg";
	int sz = strlen(arr);
	char arr1[] = "efgabcd";
	memmove(arr+7, arr, 7);
	//printf("%s", arr);
	char* a = strstr(arr, arr1);
	if (a != NULL &&sz==strlen(arr1))
		printf("找到了");
	else
		printf("没找到");
	/*int k = 4;*/
	/*leftshift(arr, k,sizeof(arr)-1);
	printf("%s\n", arr);
	my_strcmp(arr, arr1);*/
	return 0;
}