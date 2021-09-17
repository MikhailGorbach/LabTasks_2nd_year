#include <iostream>
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
	Linear(int x);
	int FindYByX() override;
};

class Quadratic : public Equation //Наследник Квадратное уравнение
{
public:
	Quadratic(int x);
	int FindYByX() override;
};

class Cubic : public Equation //Наследник Кубическое уравнение
{
public:
	Cubic(int x);
	int FindYByX() override;
};

int main()
{
	srand(time(0));
	while (1)
	{
		system("cls");
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
			Equation* lin = new Linear(x);
			cout << "Result: " << lin->FindYByX() << endl;
			delete lin;
			system("pause");
			break;
		}
		case 2:
		{
			cout << "Write x = ";
			int x;
			cin >> x;
			Equation* quad = new Quadratic(x);
			cout << "Result: " << quad->FindYByX() << endl;
			delete quad;
			system("pause");
			break;
		}
		case 3:
		{
			cout << "Write x = ";
			int x;
			cin >> x;
			Equation* cub = new Quadratic(x);
			cout << "Result: " << cub->FindYByX() << endl;
			delete cub;
			system("pause");
			break;
		}
		case 4: return 0;
		default: cout << "Choose another item." << endl; system("pause");
		}
	}
}

Cubic::Cubic(int x)
{
	this->x = x;
}
Linear::Linear(int x)
{
	this->x = x;
}
Quadratic::Quadratic(int x)
{
	this->x = x;
}
int Quadratic::FindYByX()
{
	return y = pow(x, 2) * (rand() % 9 + 1) + (rand() % 9 + 1) * x + rand() % 9 + 1;
}
int Linear::FindYByX()
{
	return y = x * (rand() % 9 + 1) + rand() % 9 + 1;
}
int Cubic::FindYByX()
{
	return y = pow(x, 3) * (rand() % 9 + 1) + pow(x, 2) * (rand() % 9 + 1) + (rand() % 9 + 1) * x + rand() % 9 + 1;
}