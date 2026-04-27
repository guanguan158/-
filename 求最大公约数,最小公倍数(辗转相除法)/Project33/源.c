#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	printf("输入两个数:>");
	scanf("%d %d", &a, &b);
	if (a < b)
	{
		int r = a;
		a = b;
		b = r;
	}
	if (a < 0)
	{
		a = -a;
	}
	if (b < 0)
	{
		b = -b;
	}
	int m = a;
	int n = b;
	while (1)
	{
		int c = b;
		if (a % b != 0)
		{
			b = a % b;
			a = c;
		}
		else
		{
			break;
		}
	}
	int d = (m * n) / b;
	int sum = b + d;
	printf("最大公约数:%d\n最小公倍数:%d\n两个数之和:%d\n", b ,d,sum);
}