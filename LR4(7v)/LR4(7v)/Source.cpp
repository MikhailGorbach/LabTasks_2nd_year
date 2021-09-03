#include <iostream>
#include <cstdlib>
using namespace std;

class Matrix;
class Item
{
private: int number;
	   friend bool EqualValue(Item& item, Matrix& matrix);
public:
	Item(int number)
	{
		this->number = number;
	}
	~Item()
	{
		cout << "Destructor Item!" << endl;
	}
};
class Matrix
{
private:
	int** a;
	int m, n;
	int min;
public:
	Matrix(int m, int n)
	{
		this->m = m;
		this->n = n;
		//Выделение памяти для матрицы
		a = new int* [m];
		for (int i = 0; i < m; i++)
		{
			a[i] = new int[n];
		}
		//Заполнение матрицы рандомными значениями
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] = rand() % 10 + 1;
			}
		}
	}
	//Деструктор для удаления памяти матрицы
	~Matrix()
	{
			for (int i = 0; i < m; i++)
			{
				delete [] a[i];
			}
			delete [] a;
		cout << "Destructor Matrix!" << endl;
		
	}
	void FindMin()
	{
		min = 1;
		//Поиск минимального числа в матрице
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] < min) min = a[i][j];
			}
		}
		cout << min << endl;
	}
	//Вывод матрицы в консоль
	void Print()
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
	friend bool EqualValue(Item& item, Matrix& matrix);
};
//Проверка на равенство числа и минимального элемента в матрице
bool EqualValue(Item& item, Matrix& matrix)
{
	if (matrix.min == item.number) return true;
	return false;
}

int main()
{
	cout << "Enter your number -> ";
	int number = 0;
	cin >> number;
	Item item(number);

	cout << "Enter number of rows and columns -> ";
	int m, n;
	cin >> m >> n;
	Matrix matrix(m, n);
	matrix.Print();
	matrix.FindMin();

	if (EqualValue(item, matrix)) cout << "Equal!" << endl;
	else cout << "Not equal!" << endl;

	system("pause");
	return 0;
}