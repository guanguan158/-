#include <iostream>
using namespace std;
class Cretangle
{
private:
	static int num;
	static int Area;
	int wide;
	int length;
public:
	
	Cretangle(int x, int y) :wide(num), length(y) { num++; Area += x * y; };
	Cretangle()
	{
		num++;
		Area++;
		wide = 1;
		length = 1;
	}
	Cretangle(Cretangle& m)
	{
		wide = m.wide;
		length = m.length;
		num++;
		Area += m.Area;
	}
	~Cretangle()
	{
		num--;
		Area--;
	}
	void static show()
	{
		cout << num <<" " << Area;
	}
};
int Cretangle::num = 0;
int Cretangle::Area = 0;

int main()
{

	Cretangle p1(1, 10), p2(5, 16);
	p1.show();

}