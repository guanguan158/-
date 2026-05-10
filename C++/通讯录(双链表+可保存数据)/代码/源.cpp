#include"标头.h"
#pragma once
void menu()
{
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout <<"                                                 电话本软件                                      " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout <<"                  1.添加姓名                                                   2.删除全部姓名   " << endl;
	cout << "                                                                                                " << endl;
	cout << "                  3.查找姓名                                                   4.显示姓名   " << endl;
	cout << "                                                                                                " << endl;
	cout << "                  5.数据整理                                                   6.帮助   " << endl;
	cout << "                                                                                                " << endl;
	cout << "                  0.退出系统                                                          " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                                                                                                " << endl;
	cout << "                  请选择:";


}
void save(list* a)
{
	connect1* prev = a->head->next;
	ofstream out("Phone.txt");
	out << a->length << endl;
	if (!out)
	{
		cout << "保存失败" << endl;
		system("pause >nul");
		return ;
	}
	for (int i = 0; i < a->length; i++)
	{
		out << prev->data->email<<endl << prev->data->live << endl << prev->data->livetele << endl << prev->data->name << endl << prev->data->tele << endl << prev->data->web << endl
			<< prev->data->work << endl << prev->data->worktele << endl;
		prev = prev->next;
	}
	out.close();
	return;
}
void load(list* a)
{
	ifstream in("Phone.txt");
	in >> a->length;
	connect1* prev = a->head;
	connect1* prev1 = a->head;
	if (!in)
	{
		cout << "读取失败" << endl;
		system("pause >nul");
		return;
	}
	for (int m = 0; m < a->length; m++)
	{
		prev->next = new connect1;
		prev->next->last = prev;
		prev->next->data = new member;
		in >> prev->next->data->email >> prev->next->data->live >> prev->next->data->livetele >> prev->next->data->name >> prev->next->data->tele >> prev->next->data->web
			>> prev->next->data->work >> prev->next->data->worktele;
		prev = prev->next;
	}
	prev->next = NULL;
	in.close();
}
int main()
{

	int input = 1;
	list a;
	load(&a);
	menu();
		while (input)
		{
			cin >> input;
			switch (input)
			{
			case 1:
				ADDmember(&a);
				break;
			case 2:
				Deleteall(&a);
				break;
			case 3:
				Search(&a);
				break;
			case 4:
				check(&a);
				break;
			case 5:
				sort(&a);
				break;
			case 6:
				help();
				break;
			case 0:
				save(&a);
				break;
			}
			system("cls");
			menu();
		}
		return 0;
}
