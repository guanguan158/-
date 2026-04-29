#define _CRT_SECURE_NO_WARNINGS
#include"info.h"
void menu()
{
	printf("*************************************\n");
	printf("**            通讯录                *\n");
	printf("**                                  *\n");
	printf("*1.添加联系人         2.查找联系人  *\n");
	printf("*3.删除联系人         4.修改联系人  *\n");
	printf("*5.对联系人进行排序   6.显示联系人  *\n");
	printf("*0.退出                             *\n");
	printf("*************************************\n");
}
int main()
{
	int input = 0;
	telebook telebook;
	init(&telebook);
	do
	{
		menu();
		
		printf("请选择:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Addmember(&telebook);
			break;
		case 2:
			Serach(&telebook);
			break;
		case 3:
			Deletele(&telebook);
			break;
		case 4:
			retele(&telebook);
			break;
		
		case 5:
			sortpeo(&telebook);
			break;
		case 6:
			show(&telebook);
			break;
		case 0:
			break;
		default:
			printf("输入错误请重试\n");
			break;
		}
	} while (input);

}