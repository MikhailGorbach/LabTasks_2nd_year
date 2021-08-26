#include <iostream>
#include <conio.h>
using namespace std;
class Equation abstract
{
public: virtual int FindYByX(int) = 0;
protected:
	int y = 0;
};
class Linear : public Equation
{
public:
	int FindYByX(int valueX) override
	{
		int x;
		cout << "Write x = ";
		cin >> x;
		return y = x * (rand() % 9 + 1) + rand() % 9 + 1;
	}
};
class Quadratic : public Equation
{
public:
	int FindYByX(int valueX) override
	{
		int x;
		cout << "Write x = ";
		cin >> x;
		return y = pow(x, 2) * (rand() % 9 + 1) + (rand() % 9 + 1) * x + rand() % 9 + 1;
	}
};
class Cubic : public Equation
{
public:
	int FindYByX(int valueX) override
	{
		int x;
		cout << "Write x = ";
		cin >> x;
		return y = pow(x, 3) * (rand() % 9 + 1) + pow(x, 2) * (rand() % 9 + 1) + (rand() % 9 + 1) * x + rand() % 9 + 1;
	}
};
class Solver
{
private:
	int valX;
public:
	int FindYByX(Equation* eq)
	{
		return eq->FindYByX(valX);
	}
};
int main()
{
	while (1)
	{
		system("cls");
		Solver S;
		int x;
		cout << "Equations:" << endl;
		cout << "1 - Linear" << endl;
		cout << "2 - Quadratic" << endl;
		cout << "3 - Cubic" << endl;
		cout << "4 - Exit" << endl;
		cout << "Select item-> ";
		int key;
		cin >> key;
		switch (key)
		{
		case 1:
		{
			Linear L;
			cout << "Result: " << S.FindYByX(&L) << endl;
			_getch();
			break;
		}
		case 2:
		{
			Quadratic Q;
			cout << "Result: " << S.FindYByX(&Q) << endl;
			_getch();
			break;
		}
		case 3:
		{
			Cubic C;
			cout << "Result: " << S.FindYByX(&C) << endl;
			_getch();
			break;
		}
		case 4: return 0;
		default: cout << "Choose another item." << endl; _getch();
		}
	}
}