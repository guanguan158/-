#include<iostream>
using namespace std;
class Array {
private:
	int n;//数组大小 
	int* a;//数组 
public:
	Array() {
		cin >> n;
		a = new int[n];
		for (int i = 0; i < n; i++) cin >> a[i];
	}

	~Array() {
		delete[]a;
	}
	int getlen() {
		return n;
	}
	int get(int i) {
		return a[i];
	}
	Array(Array& e)
	{
		n = e.getlen();
		a = new int[n];
		for (int m = 0; m < n; m++)
		{
			*(a + m) = get(m);
		}

	}

	void show() {
		for (int i = 0; i < n; i++) cout << a[i] << ' ';
	}
};
int main() {
	Array a;
	Array b = a;
	b.show();
	return 0;
}

