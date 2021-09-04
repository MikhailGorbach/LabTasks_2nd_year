#include <iostream>
#include <conio.h>
using namespace std;

class Tool // Класс Прибор с двумя полями
{
protected:
	int delim; //Цена деления
	int inaccuracy; //Погрешность
public:
	Tool(int delim, int inaccuracy)
	{
		this->delim = delim;
		this->inaccuracy = inaccuracy;
	}
	void PrintInfTool()
	{
		cout << "Delimeters" << endl;
		cout << this->delim << endl;
		cout << "Inaccuracy" << endl;
		cout << this->inaccuracy << endl;
	}
};
class Spectrum // Класс Спектр с одним полем
{
protected:
	int counter; //Количество составляющих
public:
	Spectrum(int counter)
	{
		this->counter = counter;
	}
	void PrintInfSpectrum()
	{
		cout << "Counter" << endl;
		cout << this->counter << endl;
	}
};
//Класс наследник от двух классов
class Spectrometer : public Tool, public Spectrum
{
public:
	/*Spectrometer()
	{
		this->counter = spectrum.counter;
		this->inaccuracy = Tool::inaccuracy;
		this->delim = Tool::delim;
	}*/
	void PrintInfSpmtmr()
	{
		cout << "Information about your spectrometer:" << endl;
		cout << "Delimeters" << endl;
		cout << this->delim << endl;
		cout << "Inaccuracy" << endl;
		cout << this->inaccuracy << endl;
		cout << "Counter" << endl;
		cout << this->counter << endl;
	}
};

int main()
{
	while (1)
	{
		system("cls");
		cout << "1 - Create objects of base classes" << endl;
		cout << "2 - Create object of derived class" << endl;
		cout << "3 - Call derived method" << endl;
		cout << "4 - Call basic methods by derived object" << endl;
		cout << "5 - Exit" << endl;
		cout << "Choose item -> ";
		int key;
		cin >> key;
		switch (key)
		{
		case 1:
		{
			cout << "Write the number of components of the spectrum" << endl;
			int k;
			cin >> k;
			Spectrum spectrum(k);
			cout << "Write delimeters and inaccuracy of your tool" << endl;
			int del, inacc;
			cin >> del >> inacc;
			Tool tool(del, inacc);
			break;
		}
		case 2:
			/*Spectrometer spectrometer();
			break;*/
		case 3:
			/*spectrometer().PrintInfSpmtmr();*/
			system("pause");
			break;
		case 4:
			/*spectrometer().PrintInfTool();
			spectrometer().PrintInfSpectrum();*/
			system("pause");
			break;
		case 5:
			return 0;
		default:
			cout << "Choose correct number." << endl;
			_getch();
		}
	}
}