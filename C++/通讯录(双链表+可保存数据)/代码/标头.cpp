#include"标头.h"
void ascanf(list* a,connect1* prev)
{
	cout << "请输入姓名" << endl;
	cin >> prev->next->data->name;
	cout << "请输入手机号" << endl;
	cin >> prev->next->data->tele;
	cout << "请输入住宅电话" << endl;
	cin >> prev->next->data->livetele;
	cout << "请输入办公电话" << endl;
	cin >> prev->next->data->worktele;
	cout << "请输入电子邮箱" << endl;
	cin >> prev->next->data->email;
	cout << "请输入个人网站" << endl;
	cin >> prev->next->data->web;
	cout << "请输入工作单位" << endl;
	cin >> prev->next->data->work;
	cout << "请输入家庭地址" << endl;
	cin >> prev->next->data->live;
	cout << "请问是否进行保存(按其他保存，按0不保存" << endl;
	int input = 0;
	cin >> input;
	switch (input)
	{
	case 0:
		delete prev->next;
		prev->next = NULL;
		break;
	default:
		a->length +=1;
		cout << "保存成功" << endl;
		system("pause >nul");
	}

	return;
}
back DSearch( list* a,char b[100])
{
	connect1* prev = a->head->next;
	back r ;
	int i = 0;
	char c = 0;
	int y = 0;
	for (int m = 0; m < a->length; m++)
	{
		if (strlen(prev->data->name) < strlen(b))
		{
			 y = strlen(prev->data->name);
			 c = b[y];
			b[y] = '\0';
		}
		if ((strstr(prev->data->name, b) != NULL))
		{
			r.arr[i] = prev->data;
			r.number[i] = m;
			i++;
			
		}
		prev = prev->next;
		b[y] = c;
		c = 0;
		y = 0;
		
	}
	r.max = i;
	return r;
}
void detailshow(back m)
{
	cout << "姓名                            电话                   住址                         序号           " << endl;
	int i = 1;
	for(int r = 0 ; r < m.max; r++)
	{
		cout << left << setw(32) << m.arr[r]->name << left << setw(23) << m.arr[r]->tele << left << setw(30) << m.arr[r]->live << left << setw(35) << i << endl;
		i++;
	}
	cout << "你要具体查看第几个" << endl;
	return;
}
temp record(list* a)
{
	int i = 0;
	temp q;
	connect1* prev = a->head;
	for (i = 0; i < a->length; i++)
	{
		q.arr[i] = prev->next->data;
		prev = prev->next;
	}
	return q;
}
int sortname_UP(const void * a ,const void* b)
{
	member* m = (*(member**)a);
	member* q = (*(member**)b);
	return strcmp(m->name,q->name);

}
int sortname_Down(const void* a, const void* b)
{
	member* m = (*(member**)a);
	member* q = (*(member**)b);
	return -strcmp(m->name,q->name);

}
void edit(temp b,list * a)
{
	connect1* prev = a->head;
	for (int i = 0; i < a->length; i++)
	{
		prev->next->data = b.arr[i];
		prev = prev->next;
	}
}
void sort(list* a)
{
	if (a->length <= 0)
	{
		cout << "列表为空" << endl;
		system("pause > nul");
		return;
	}
	temp b = record(a);
	cout << "按名字升序排列还是降序排列(按其他升序,0降序)" << endl;
	int input = 0;
	cin >> input;
	int (*compare) (const void*,const void*) = NULL;
	switch (input)
	{
	case 0:
		compare = sortname_Down;
		break;
	default:
		compare = sortname_UP;
	}
	int r = sizeof(member*);
	qsort(b.arr, a->length, r, compare);
	edit(b,a);
	cout << "排序完成" << endl;
	system("pause > nul");
}
void Delete(list* a, connect1* prev)
{
	int input = 0;
	cout << "你真的要删除吗?按其他确认,按0取消" << endl;
	cin >> input;
	if (input == 0)
	{
		cout << "取消删除" << endl;
		return;
	}
	connect1* r = prev->next;
	connect1* m = prev->last;
	delete prev->data;
	delete prev;
	m->next = r;
	if (r != NULL)
	{
		r->last = m;
	}
	cout << "删除成功" << endl;
	system("pause >nul");
	a->length--;
	return;
}
void Deleteall(list* a)
{
	system("cls");
	if (a->head->next == NULL)
	{
		cout << "列表为空" << endl;
		system("pause > nul");
		return;
	}
	int input = 0;
	cout << "你要删除全部的列表吗?(其他取消,0确认)" << endl;
	cin >> input;
	if (input != 0)
	{
		cout << "取消删除" << endl;
		system("pause > nul");
		return;
	}
	cout << "你真的要删除全部的列表吗?(其他取消,0确认)" << endl;
	cin >> input;
	if (input != 0)
	{
		cout << "取消删除" << endl;
		system("pause > nul");
		return;
	}
	connect1* prev = a->head;//首元节点
	for (int r = 0; r < a->length; r++)
	{
		prev = prev->next;
	}
	for (int r = 0; r < a->length; r++)
	{
		prev = prev->last;
		delete prev->next->data;
		prev->next->data = NULL;
		delete prev->next;
		prev->next = NULL;
	}
	cout << "删除成功" << endl;
	a->length = 0;
	system("pause > nul");
	return;
}
void detailshow( list* a , int m)
{
	system("cls");
	connect1* prev = a->head->next;
	if (m <= 0 || m > a->length)
	{
		cout << "输入非法 " << endl;
		system("pause >nul");
		return;
	}
	int r = 1;
	for (int b = 0; b < m - 1; b++)
	{
		prev = prev->next;
		r++;
	}
	cout << "                                                  第" << r << "位联系人,共" << a->length << "位" << endl;
	cout << endl;
	cout << "                                                  姓    名:" << prev->data->name << endl;
	cout << "                                                  手    机:" << prev->data->tele << endl;
	cout << "                                                  住宅电话:" << prev->data->livetele << endl;
	cout << "                                                  办公电话:" << prev->data->worktele << endl;
	cout << "                                                  e_mali__ :" << prev->data->email << endl;
	cout << "                                                  个人主页:" << prev->data->web << endl;
	cout << "                                                  单    位:" << prev->data->work << endl;
	cout << "                                                  家庭住址:" << prev->data->live << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "1.删除                                           2.修改                                 3.返回到主界面  " << endl;
	cout << " 4.前一位                                   其他键显示后一位                            请选择:";
	int input = 0;
	int e = a->length;
	cin >> input;
	switch (input)
	{
	case 1:
		Delete(a, prev);
		break;
	case 2:
		
		ascanf(a, prev->last);
		a->length = e;
		detailshow(a, m);
		break;
	case 3:
		break;
	case 4:
		detailshow(a, m - 1);
		return;
		break;
	default:
		detailshow(a, m + 1);
		return;
		break;
	}
	return;
}
void ADDmember1(list* a)
{
	connect1* prev = a->head;//prev指向第一节点的指针域

	while (prev->next != NULL)
	{
		prev = prev->next;//如果节点里的指针域不为空,进入下一个直到为空
	}
	prev->next = new connect1;//找到了创建指针域,是最后一个与新建立的连接起来
	prev->next->data = new member;
	prev->next->next = NULL;
	prev->next->last = prev;//让下一个指针域的前置指针指向上一个
	ascanf(a, prev);
	return;

}
void simpleshow( list* a)
{
	connect1* m = a->head->next;
	if (m == NULL)
	{
		cout << "列表为空" << endl;
		return;
	}
	cout << "姓名                            电话                   住址                         序号           " << endl;
	int i = 1;
	while(m != NULL)
	{
		
		cout << left << setw(32) <<m->data->name <<left<<setw(23)<<m->data->tele<<left<<setw(30)<<m->data->live <<left<<setw(35)<<i <<endl;
		m = m->next;
		i++;
	}
	return;
}
void insert(list* a)
{
	cout << "请问你要插入进第几个后" << endl;
	int num = 0;
	cin >> num;
	connect1* prev = a->head;
	for (int i = 0; i < num; i++)
	{
		prev = prev->next;
	} 
	if (num > a->length || num <0)
	{
		cout << "插入位置无效" << endl;
		system("pause >nul");
		return;
		
	}
	connect1* record = prev->next;
	prev->next = new connect1;
	prev->next->last = prev;
	prev->next->data = new member;
	prev->next->next = record;
	if(record != NULL)
	record->last = prev->next;
	ascanf(a, prev);
}
void ADDmember(list* a)
{
	int input = 0;

	cout << "按其他添加联系人,按0插入联系人" << endl;
	cin >> input;
	switch (input)
	{

	case 0:
	{
		int live = 0;
		simpleshow(a);
		insert(a);
		break;
	}
	default:
	{
		ADDmember1(a);
		break;
	}

	}
}
void check(list* a)
{
	system("cls");
	simpleshow(a);
	if (a->head->next == NULL)
	{
		system("pause > nul");
		return;
		
	}
	cout << "你要仔细查看第几个" << endl;
	int input = 0;
	cin >> input;
	detailshow(a , input);

}
void Search(list* a)
{
	cout << "输入要查找的姓名" << endl;
	char b[100] = { '0' };
	cin >> b;
	back m = DSearch(a, b);
	if (m.max <= 0)
	{
		cout << "未查找到符合结果" << endl;
		system("pause >nul");
		return;
	}
	detailshow(m);
	int q = 0;
	cin >> q;
	int y = q - 1;
	detailshow(a, m.number[y] + 1);
}
void help ()
{
	cout << "                                软件帮助:                       " << endl;
	cout << "                                本软件是模拟手机电话本管理方式实现的电话本管理软件" << endl;
	system("pause >nul");
	return;
}