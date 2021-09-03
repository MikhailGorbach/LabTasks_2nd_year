#include <iostream>
#include <conio.h>
using namespace std;

//Абстракнтный класс
class Equation abstract
{
public:
	virtual int FindYByX() = 0;
protected:
	int x;
	int y = 0;
};

class Linear : public Equation //Наследник Линейное уравнение
{

public:
	Linear(int& x)
	{
		this->x = x;
	}
	int FindYByX() override
	{
		return y = x * (rand() % 9 + 1) + rand() % 9 + 1;
	}
};

class Quadratic : public Equation //Наследник Квадратное уравнение
{
public:
	Quadratic(int& x)
	{
		this->x = x;
	}
	int FindYByX() override
	{
		return y = pow(x, 2) * (rand() % 9 + 1) + (rand() % 9 + 1) * x + rand() % 9 + 1;
	}
};

class Cubic : public Equation //Наследник Кубическое уравнение
{
public:
	Cubic(int& x)
	{
		this->x = x;
	}
	int FindYByX() override
	{
		return y = pow(x, 3) * (rand() % 9 + 1) + pow(x, 2) * (rand() % 9 + 1) + (rand() % 9 + 1) * x + rand() % 9 + 1;
	}
};
//Класс для решения
class Solver
{
public:
	int FindYByX(Equation* eq)
	{
		return eq->FindYByX();
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
			cout << "Write x = ";
			int x;
			cin >> x;
			Linear L(x);
			cout << "Result: " << S.FindYByX(&L) << endl;
			_getch();
			break;
		}
		case 2:
		{
			cout << "Write x = ";
			int x;
			cin >> x;
			Quadratic Q(x);
			cout << "Result: " << S.FindYByX(&Q) << endl;
			_getch();
			break;
		}
		case 3:
		{
			cout << "Write x = ";
			int x;
			cin >> x;
			Cubic C(x);
			cout << "Result: " << S.FindYByX(&C) << endl;
			_getch();
			break;
		}
		case 4: return 0;
		default: cout << "Choose another item." << endl; _getch();
		}
	}
}