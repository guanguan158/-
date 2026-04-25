#define _CRT_SECURE_NO_WARNINGS
#include"info.h"
void init(telebook* telebook)
{
	memset(telebook->num, 0, sizeof(telebook->num));
	telebook->count = 0;
};
void Addmember(telebook* telebook)
{
	assert(telebook);
	if (telebook->count == Max)//处理通讯录满员情况
	{
		printf("联系人已满无法添加\n");
		return;
	}
	printf("请添加联系人\n");
	printf("请输入姓名\n");
	scanf("%s", &(telebook->num[telebook->count].name));
	printf("请输入年龄\n");
	scanf("%d", &(telebook->num[telebook->count].age));
	printf("请输入性别\n");
	scanf("%s", &(telebook->num[telebook->count].sex));
	printf("请输入电话号码\n");
	scanf("%s", &(telebook->num[telebook->count].tele));
	printf("请输入地址\n");
	scanf("%s", &(telebook->num[telebook->count].live));
	printf("是否保存,输入0不保存,输入1保存\n");
	int input = 0;
	scanf("%d", &input);
	if (input == 0)
	{
		printf("修改失败\n");
		return;
	}
	else
	{
		printf("保存成功\n");
		telebook->count++;
	}
}
void show(telebook* telebook)
{
	int i = 0;
	if (telebook->count == 0)
	{
		printf("目录为空\n");
		return;
	}
	printf("%-20s\t%-3s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "住址");
	for (i = 0; i < telebook->count; i++)
	{
		printf(("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n"), telebook->num[i].name, telebook->num[i].age, telebook->num[i].sex, telebook->num[i].tele, telebook->num[i].live);
	}
	return;
}
char* search_name(telebook* p1,char* p2,int i)
{
	return  strstr(p1->num[i].name, p2);
}
char* search_age(telebook* p1, int p2, int i)
{
	if (p1->num[i].age == p2)
	{
		return &(p1->num[0].age);
	}
	else
	{
		return NULL;
	}
}
char* search_sex(telebook* p1, char* p2, int i)
{
	return  strstr(p1->num[i].sex, p2);
}char* search_tele(telebook* p1, char* p2, int i)
{
	return  strstr(p1->num[i].tele, p2);
}
char* search_live(telebook* p1, char* p2, int i)
{
	return  strstr(p1->num[i].live, p2);
}
back Serach(telebook* telebook1)
{
	if (telebook1->count == 0)
	{
		printf("通讯录为空 \n");
		return;
	}
	printf("请选择你要进行查找的方向\n");
	printf("1.按姓名查找\n");
	printf("2.按年龄查找\n");
	printf("3.按性别查找\n");
	printf("4.按电话查找\n");
	printf("5.按住址查找\n");
	int input = 0;
	back p1;//创建返回类型
	memset(&p1, 0, sizeof(p1));//返回类型初始化
	scanf("%d", &input);
	char* (*calu)(telebook*, char*, int) = 0;
	switch (input)
	{
	case 1:
		printf("请输入姓名\n");
		calu = &search_name;
		break;
	case 2:
		printf("请输入年龄\n");
		calu = &search_age;
		break;
	case 3:
		printf("请输入性别\n");
		calu = &search_sex;
		break;
	case 4:
		printf("请输入电话\n");
		calu = &search_tele;
		break;
	case 5:
		printf("请输入住址 \n");
		calu = &search_live;
		break;
	default:
		printf("选择错误\n");
		return p1;
	}
	//设置回调函数,方便后续调用
	char s1[20] = { 0 };
	int s2 = 0;
	if (input == 2)
	{
		scanf("%d", &s2);
	}
	else
	{
		scanf("%s", &s1);
	}
	int n = 0;
	int i = 0;
	int m = 0;
	char* ret = 0;
	for (i = 0; i < telebook1->count; i++)//查找逻辑
	{
		if (input != 2)
		{
			 ret = calu(telebook1, s1, i);//遍历通讯录里所有的名字,是否有关键字
		}
		else
		{
			ret = calu(telebook1, s2, i);
		}
		if (ret != NULL)
		{
			p1.arr[m] = i;//记录此时的i的数值也就是位于第几个
			p1.m1 = m + 1;
			m++;
		}
	}
	m = 0;
	if (p1.m1 == 0)
	{
		printf("未找到目标\n");
		return p1;
	}
	printf("%-20s\t%-3s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "住址");
	for (int i = 0; i < p1.m1; i++)//打印查找结果
	{
		n = p1.arr[i];
		printf(("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n"),telebook1->num[n].name, telebook1->num[n].age, telebook1->num[n].sex, telebook1->num[n].tele, telebook1->num[n].live);
	}
	return p1;
}
void retele(telebook* p1)
{
	if (p1->count == 0)
	{
		printf("没有可修改目标\n");
		return;
	}
	back p2 =Serach(p1);
	if (p2.m1 == 0)
	{
		return;
	}
	printf("请选择要修改第几个\n");
	int n = 0;
	scanf("%d", &n);
	n = n - 1;
	if (n < 0 || n >p2.m1 -1)
	{
		printf("输入错误\n");
		return;
	}
	printf("请修改姓名:>\n");
	int m = p2.arr[n];
	telebook p3;
	memset(&p3, 0, sizeof(p3));
	p3.num[m] = p1->num[m];
	scanf("%s", p1->num[m].name);
	printf("请修改年龄:>\n");
	scanf("%d", &p1->num[m].age);
	printf("请修改性别:>\n");
	scanf("%s", p1->num[m].sex);
	printf("请修改电话:>\n");
	scanf("%s", p1->num[m].tele);
	printf("请修改地址:>\n");
	scanf("%s", p1->num[m].live);
	int input = 0;
	printf("是否保存修改,选择1保存,选择0不保存\n");
	scanf("%d", &input);
	if (input == 1)
	{
		printf("修改成功\n");
	}
	else
	{
		p1->num[m] = p3.num[m];
		printf("修改取消\n");
	}
	return;
}
void Deletele(telebook* p1)
{
	if (p1->count == 0)
	{
		printf("没有可删除目标\n");
		return;
	}
	back p2 = Serach(p1);
	if (p2.m1 == 0)
	{
		return;
	}
	printf("请选择要删除第几个\n");
	int n = 0;
	scanf("%d", &n);
	n = n - 1;
	if (n < 0 || n>p2.m1 -1)
	{
		printf("输入错误\n");
		return;
	}
	int m = p2.arr[n];
	telebook p3;
	memset(&p3, 0, sizeof(p3));
	p3.num[m] = p1->num[m];
	printf("是否保存修改,选择0取消,选择1确认\n");
	int input = 0;
	scanf("%d", &input);
	if (input == 0)
	{
		printf("修改已取消\n");
	}
	else
	{
			memset(&(p1->num[m]), 0, sizeof(p1->num[m]));

		while (m + 1 < p1->count)//让修改位后面的所有元素前移一位
		{
			Peoinfo s = p1->num[m];
			p1->num[m] = p1->num[m + 1];
			p1->num[m + 1] = s;
			m++;
		}
		p1->count--;
		printf("修改成功\n");
	}
}
int sort_name(const void* a,const void* b)
{
	Peoinfo* s1 = (Peoinfo*)a;
	Peoinfo* s2 = (Peoinfo*)b;
	return (strcmp(s1->name,s2->name));
}
int sort_name1(const void* a, const void* b)
{
	Peoinfo* s1 = (Peoinfo*)a;
	Peoinfo* s2 = (Peoinfo*)b;
	return -(strcmp(s1->name, s2->name));
}
int sort_age(const void* a, const void* b)
{
	Peoinfo* s1 = (Peoinfo*)a;
	Peoinfo* s2 = (Peoinfo*)b;
	return s1->age - s2->age;
}
int sort_age1(const void* a, const void* b)
{
	Peoinfo* s1 = (Peoinfo*)a;
	Peoinfo* s2 = (Peoinfo*)b;
	return -(s1->age - s2->age);
}
int sort_sex(const void* a, const void* b)
{
	Peoinfo* s1 = (Peoinfo*)a;
	Peoinfo* s2 = (Peoinfo*)b;
	return strcmp(s1->sex, s2->sex);
}
int sort_sex1(const void* a, const void* b)
{
	Peoinfo* s1 = (Peoinfo*)a;
	Peoinfo* s2 = (Peoinfo*)b;
	return -(strcmp(s1->sex, s2->sex));
}
int sort_tele(const void* a, const void* b)
{
	Peoinfo* s1 = (Peoinfo*)a;
	Peoinfo* s2 = (Peoinfo*)b;
	return (strcmp(s1->tele, s2->tele));
}
int sort_tele1(const void* a, const void* b)
{
	Peoinfo* s1 = (Peoinfo*)a;
	Peoinfo* s2 = (Peoinfo*)b;
	return -(strcmp(s1->tele, s2->tele));
}
int sort_live(const void* a, const void* b)
{
	Peoinfo* s1 = (Peoinfo*)a;
	Peoinfo* s2 = (Peoinfo*)b;
	return (strcmp(s1->live, s2->live));
}
int sort_live1(const void* a, const void* b)
{
	Peoinfo* s1 = (Peoinfo*)a;
	Peoinfo* s2 = (Peoinfo*)b;
	return -(strcmp(s1->live, s2->live));
}
void sortpeo(telebook* p1)
{
	printf("请选择排序方式\n");
	printf("1.按姓名排序\n");
	printf("2.按年龄排序\n");
	printf("3.按性别排序\n");
	printf("4.按电话号码排序\n");
	printf("5.按地址排序\n");
	int input = 0;
	scanf("%d", &input);
	if (input > 5 || input < 0)
	{
		printf("选择错误\n");
		return;
	}
	printf("请选择升降序\n");
	printf("1.升序\n");
	printf("0.降序\n");
	int shift = 0;
	scanf("%d", &shift);
	int (*sort)(const void*, const void*) = NULL;
	switch (input)
	{
	case 1:
	{
		if (shift == 0)
		{
			sort = sort_name1;
		}
		else
			sort = sort_name;
		break;
	}
	case 2:
		if (shift == 0)
		{
			sort = sort_age1;
		}
		else
			sort = sort_age;
		break;
	case 3:
		if (shift == 0)
		{
			sort = sort_sex1;
		}
		else
			sort = sort_sex;
		break;
	case 4:
		if (shift == 0)
		{
			sort = sort_tele1;
		}
		else
			sort = sort_tele;
		break;
	case 5:
		if (shift == 0)
		{
			sort = sort_live1;
		}
		else
			sort = sort_live;
		break;
	}
	int n = p1->count;
	int sz = sizeof(Peoinfo);
	qsort(p1->num, n, sz, sort);
	printf("排序完成\n");
}