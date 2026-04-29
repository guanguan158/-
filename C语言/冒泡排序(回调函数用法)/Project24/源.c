#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int ADD(int x, int y)
{
	return x + y;
}
int jian(int x, int y)
{
	return x - y;
}
int chen(int x, int y)
{
	return x * y;
}
int chu(int x, int y)
{
	return x / y;
}
void calu(int(*calu)(int, int))
{
	int x = 0;
	int y = 0;
	printf("请输入操作数\n");
	scanf("%d %d", &x, &y);
	printf("%d", calu(x, y));
	return 0;
}
void menu()
{
	printf("**************************************\n");
	printf("****1.加法            2.减法     *****\n");
	printf("****3.乘法            4.除法     *****\n");
	printf("****0.退出                       *****\n");
	printf("**************************************\n");
}
int main()
{
	int input = 1;
	menu();
	while (input)
	{
		int (*arr[5])(int, int) = { 0,ADD,jian,chen,chu };
		printf("选择你要进行的操作\n");
		scanf("%d", &input);
		if (input == 0)
		{
			printf("退出计算器\n");
		}
		else if (input > 0 && input <= 4)
		{
			int x = 0;
			int y = 0;
			printf("输入两个操作数\n");
			scanf("%d %d", &x, &y);
			printf("输出的结果是%d\n", arr[input](x, y));
		}
		else
		{
			printf("请重新选择\n");
		}
	}
}