#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	int arr[5][5] = { 0 };
	int c = 0;
	for (int m = 0; m < 5; m++)
	{
		for (int i = 0; i < 5; i++)
		{
			arr[m][i] =c;
			c++;
		}
	}
	
	int x = 1;
	int n = 168;
	//二分查找法
	//for (int m = 0; m < 5; m++)
	//{
	//	int left = 0;//左边界
	//	int right = sizeof(arr[0]) / sizeof(arr[0][0]) - 1;//右边界
	//	while (left <= right)
	//	{
	//		if (n > arr[m][right])//如果比最右边大跳过一行
	//		{
	//			break;
	//		}
	//		else if(n > arr[m][(left+right)/2])
	//		{
	//			left = (left + right) / 2 + 1;
	//		}
	//		else if (n == arr[m][(left + right) / 2])
	//		{
	//			x = 0;
	//			break;
	//		}
	//		else if (n < arr[m][(left + right) / 2])
	//		{
	//			right = (left + right) / 2 - 1;
	//		}

	//	}
	//	if (x == 0)
	//	{
	//		printf("找到了位置是arr[%d][%d]\n", m, (left + right) / 2);
	//		break;
	//	}
	//}
	//if (x == 1)
	//{
	//	printf("没找到\n");
	//}
	int m = 0;
	int a = sizeof(arr[0]) / sizeof(arr[0][0])-1;
	int q = sizeof(arr[0]) / sizeof(arr[0][0]) - 1;
	while (m < q && a>0)
	{
		if (n < arr[m][a])
		{
			a--;
		}
		else if (n == arr[m][a])
		{
			printf("找到了");
			x = 0;
			break;
		}
		else if (n > arr[m][a])
		{
			m++;
		}
	}
	if(x==1)
	printf("没找到");
}