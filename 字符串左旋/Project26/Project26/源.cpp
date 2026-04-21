#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
void reserve(char* left, char* right)
{
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void leftshift(char arr[], int k)
{
	char* ret = arr;
	int sz = strlen(arr);//总共有多少元素
	reserve(arr, arr + k -1);//左边交换
	reserve(arr + k , arr + sz - 1);//右边交换
	reserve(arr, arr + sz - 1);//整体
	printf("%s", ret);

}
int main()
{

	char arr[] = "abcdefg";
	int k = 4;
	leftshift(arr,k);
	return 0;
}