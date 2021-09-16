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
	//Triangle& operator +();  смотреть 118 строку
	friend bool operator !(Triangle& other);
	void operator <<(Triangle& other);
	bool operator <=(Triangle& other);
	friend bool operator ==(Triangle& other1, Triangle& other2);
	friend istream& operator >>(istream& in, Triangle& other);
};

int main()
{
	cout << "Write sides of first triangle" << endl;
	Triangle tr1;
	operator>>(cin, tr1);

	if (operator!(tr1))
	{
		tr1.operator<<(tr1);
		system("pause");
	}
	else
	{
		cout << "This triangle cannot exist!" << endl;
		system("pause");
	}

	cout << "Write sides of second triangle" << endl;
	Triangle tr2;
	operator>>(cin, tr2);

	if (operator!(tr2))
	{
		tr2.operator<<(tr2);
		system("pause");
	}
	else
	{
		cout << "This triangle cannot exist!" << endl;
		system("pause");
	}
	
	cout << "Now compare two perimeters..." << endl;
	
	if (tr1 == tr2)
	{
		cout << "All sides of these triangles are equal!" << endl;
		system("pause");
	}
	else if (tr1.operator<=(tr2))
	{
		cout << "Second is larger or equal to." << endl;
		system("pause");
	}
	else
	{
		cout << "First is larger." << endl;
		system("pause");
	}

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
//Triangle& Triangle::operator +()
//{
//	Triangle temp;
//	temp.setA(getA() + getB() + getC());
//	return temp;
//}
int Triangle::operator+()
{
	int p = getA() + getB() + getC();
	return p;
}
bool operator !(Triangle& other)
{
	if ((other.a >= (other.b + other.c))
		|| (other.b >= (other.a + other.c))
			|| (other.c >= (other.b + other.a)))
			return false;
	return true;
}
void Triangle::operator <<(Triangle& other)
{
	//cout << "Perimeter: " << other.operator+().getA() << endl;
	cout << "Perimeter: " << other.operator+() << endl;
}
bool Triangle::operator <=(Triangle& other)
{
	if (this->operator+() <= other.operator+())
		return true;
	return false;
}
bool operator ==(Triangle& other1, Triangle& other2)
{
	if ((other1.a == other2.a) &&
		(other1.b == other2.b) &&
		(other1.c == other2.c)) return true;
	return false;
}
istream& operator >>(istream& in, Triangle& other)
{
	in >> other.a;
	in >> other.b;
	in >> other.c;
	return in;
}