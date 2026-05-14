#include<iostream>
using namespace std;
struct Stack
{
	Stack* next;
	int data;
};
void Add(Stack*& a, int q)
{

	Stack* b = new Stack;//假设里面有一个元素 口;新建一个节点,他在栈顶,那么栈顶要指向里面第一个元素
	b->next = a;//则创建的新节点的next指针域就要指向那块地址,也就是第一个节点的地址
	b->data = q;//数值正常放
	a = b;//此时我们新建的节点已经成功指向了我们最初没加节点的栈顶地址,修改这个时候a的地址为b的地址那么a又重新指向栈顶,也就是对象穿过来的地址修改为新建地址的栈顶;
};
int out(Stack*& a)
{
	if (a == NULL)
	{
		cout << "栈已空" << endl;
		return -1;
	}
	int m = a->data;//要返回栈区的值
	Stack* b = a->next;//弹出后,进入下一个节点
	delete a;//把弹出的地址删除防止泄露
	a = b;//让a对象本身指向下一个节点;
	return m;
}