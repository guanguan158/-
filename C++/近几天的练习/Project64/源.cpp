#include<iostream>
using namespace std;
struct Stack
{
	int top;
	int arr[100];
};
void solve(char q, Stack& m)
{
	if (q == 'P')
	{
		m.top++;
		int r = 0;
		cin >> r;
		m.arr[m.top -1] = r;
		
	}
	else if (q == 'O')
	{
		if (m.top == 0)
			return;
		m.top--;
		m.arr[m.top - 1] = 0;
		return;
		
	}
	else if (q == 'A')
	{
		if (m.top == 0)
		{
			cout << "E" << endl;
			return;
		}
		cout << m.arr[m.top -1]<< endl;
	}

};
int main()
{ 
	int num = 0;
	Stack m = { {0},{0} };
	Stack y = { {0},{0} };
	char f = '0';
	cin >> num;
	for (int q = 0; q < num; q++)
	{
		cin >> f;
		solve(f, m);
	}
	cin >> num;
	for (int q = 0; q < num; q++)
	{
		cin >> f;
		solve(f, y);
	}
	return 0;
}