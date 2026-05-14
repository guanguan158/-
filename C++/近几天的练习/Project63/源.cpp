#include<iostream>
using namespace std;
struct Node
{
	Node* next;
	int m;
};
void Insert(Node* m, int input = 0)
{
	if (input != 0)
	{
		while (m->next != NULL)
			m = m->next;
		Node* prev = m->next;
		m->next = new Node;
		m->next->m = input;
		m->next->next = prev;
		return;
	}
	while (1)
	{

			cin >> input;
			if (input == -1)
			return;
			while (m->next != NULL)
				m = m->next;
		Node* prev = m->next;
		m->next = new Node;
		m->next->m = input;
		m->next->next = prev;

	}
}
int main()
{
	Node* r = new Node;
	Node* q = new Node;
	r->next = NULL;
	q->next = NULL;
	r->m = 0;
	q->m = 0;
	Insert(r);
	Insert(q);
	Node* e = new Node;
	e->next = NULL;
	e->m = 0;
	int c = 0;
	while (1)
	{
		while (r->next != NULL && q->next != NULL)
		{
			if (r->next->m < q->next->m)
				r = r->next;
			else if (r->next->m == q->next->m)
			{
				c = r->next->m;
				Insert(e, c);
				r = r->next;
				q = q->next;
			}
			else
				q = q->next;
		}
		break;
	}
	while (e->next != NULL)
	{
		cout << e->next->m << " ";
		e = e->next;
	}
}