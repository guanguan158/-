#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int arr[10][10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		for (int m = 0; m < 10; m++)
		{
			if (m == 0)
			{
				arr[i][m] = 1;
			}
			if (i == m)
			{
				arr[i][m] = 1;
			}
			if (m > 0 && m < i)
			{
				arr[i][m] = arr[i - 1][m - 1] + arr[i - 1][m];
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int m = 0; m < i; m++)
		{
			printf("%3d ", arr[i][m]);
		}
		printf("\n");
	}
}