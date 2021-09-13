#include <iostream>
using namespace std;

class Tool // Класс Прибор с двумя полями
{
protected:
	int delim; //Цена деления
	int inaccuracy; //Погрешность
public:
	int getDelim()
	{
		return delim;
	}
	int getInaccuracy()
	{
		return inaccuracy;
	}
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
	int getCounter()
	{
		return counter;
	}
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
	Spectrometer(Tool& tool, Spectrum& spectrum) : Tool(tool.getDelim(), tool.getInaccuracy()), Spectrum(spectrum.getCounter())
	{
		cout << "Derived object." << endl;
	}
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

	Spectrometer spectrometer(tool, spectrum);
	spectrometer.PrintInfSpmtmr();
	system("pause");

	cout << "Tool method." << endl;
	spectrometer.PrintInfTool();
	cout << "Spectrum method." << endl;
	spectrometer.PrintInfSpectrum();
	system("pause");
	return 0;
}