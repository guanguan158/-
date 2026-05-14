#include<iostream>
using namespace std;
class Node
{
public:
	int m;
	Node* next;
	static int num;
};
int Node::num;
void Add(Node*& r, int e)
{
	Node* m = r;
	Node::num++;
	if (r == NULL)
	{
		r = new Node;
		r->m = e;
		r->next = NULL;
		
		return;
	}
	while (r->next != NULL)
	{
		r = r->next;
	}
	r->next = new Node;
	r->next->m = e;
	r->next->next = NULL;
	r = m;
	return;
}
int main()
{
	int input = 0;
	Node* f = NULL;
	Node* q = NULL;
	while ( 1)
	{
		cin >> input;
		if (input == -1)
			break;
		Add(f,input);
	}
	
	while (1)
	{
		cin >> input;
		if (input == -1)
			break;
		Add(q, input);
	}
	Node* r = NULL;
	int s = 0;
	int h = Node::num;
	for (int j = 0; j < h;j++)
	{
		if((f != NULL)&&( q != NULL))
		{
			if (q->m >= f->m)
			{
				s = f->m;
				f = f->next;
			}
			else
			{
				s = q->m;
				q = q->next;
			}
			
		}
		else if (f == NULL)
		{
			s = q->m;
			q = q->next;
		}
		else
		{
			s = f->m;
			f = f->next;
		}
		Add(r, s);
	}
	while (r != NULL)
	{
		cout << r->m << " ";
		r = r->next;
	}
}