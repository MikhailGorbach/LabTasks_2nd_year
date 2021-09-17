#include <iostream>
using namespace std;

class Tool // Класс Прибор с двумя полями
{
protected:
	int delim; //Цена деления
	int inaccuracy; //Погрешность
public:
	int getDelim();
	int getInaccuracy();
	Tool(int delim, int inaccuracy);
	void Print();
};
class Spectrum // Класс Спектр с одним полем
{
protected:
	int counter; //Количество составляющих
public:
	int getCounter();
	Spectrum(int counter);
	void Print();
};
//Класс наследник от двух классов
class Spectrometer : public Tool, public Spectrum
{
private:
	string name;
public:
	Spectrometer(int delim, int inaccuracy, int counter, string name) : Tool(delim, inaccuracy), Spectrum(counter)
	{
		this->name = name;
	}
	void Print();
};

int main()
{
	cout << "Write the number of components of the spectrum" << endl;
	int k = 0;
	cin >> k;
	Spectrum spectrum(k);
	system("pause");

	cout << "Write delimeters and inaccuracy of your tool" << endl;
	int del, inacc;
	cin >> del >> inacc;
	Tool tool(del, inacc);
	system("pause");

	cout << "Write the name of spectrometer: " << endl;
	string name;
	cin >> name;
	Spectrometer spectrometer(del, inacc, k, name);
	spectrometer.Print();
	system("pause");

	cout << "Tool method." << endl;
	spectrometer.Tool::Print();
	cout << "Spectrum method." << endl;
	spectrometer.Spectrum::Print();
	system("pause");
	return 0;
}

int Tool::getDelim()
{
	return delim;
}
int Tool::getInaccuracy()
{
	return inaccuracy;
}
Tool::Tool(int delim, int inaccuracy)
{
	this->delim = delim;
	this->inaccuracy = inaccuracy;
}
void Tool::Print()
{
	cout << "Delimeters" << endl;
	cout << this->delim << endl;
	cout << "Inaccuracy" << endl;
	cout << this->inaccuracy << endl;
}
int Spectrum::getCounter()
{
	return counter;
}
Spectrum::Spectrum(int counter)
{
	this->counter = counter;
}
void Spectrum::Print()
{
	cout << "Counter" << endl;
	cout << this->counter << endl;
}
void Spectrometer::Print()
{
	cout << "Information about your spectrometer:" << endl;
	cout << "Name" << endl;
	cout << this->name << endl;
	cout << "Delimeters" << endl;
	cout << this->delim << endl;
	cout << "Inaccuracy" << endl;
	cout << this->inaccuracy << endl;
	cout << "Counter" << endl;
	cout << this->counter << endl;
}