#include <iostream>
using namespace std;

class Triangle
{
private:
	int a;
	int b;
	int c;
public:
	Triangle();
	Triangle(int a, int b, int c);
	int getA();
	int getB();
	int getC();
	void setA(int a);
	void setB(int b);
	void setC(int c);
	int operator +();
};

int main()
{
	cout << "Write sides of triangle" << endl;
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;

	Triangle tr(a,b,c);

	cout << "Perimeter: " << tr.operator+() << endl;
	
	system("pause");
	return 0;
}

int Triangle::getA()
{
	return this->a;
}
int Triangle::getB()
{
	return this->b;
}
int Triangle::getC()
{
	return this->c;
}
Triangle::Triangle()
{
	this->a = 0;
	this->b = 0;
	this->c = 0;
}
void Triangle::setA(int a)
{
	this->a = a;
}
void Triangle::setB(int b)
{
	this->b = b;
}
void Triangle::setC(int c)
{
	this->c = c;
}
Triangle::Triangle(int a, int b, int c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}
int Triangle::operator +()
{
	int p = getA() + getB() + getC();
	return p;
}