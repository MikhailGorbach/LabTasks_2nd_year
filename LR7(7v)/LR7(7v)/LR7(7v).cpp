#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
using namespace std;


int main()
{
	cout << "Write 1-st number: ";
	int a = 0;
	cin >> a;
	
	cout << "Write 2-nd number: ";
	int b = 0;
	cin >> b;

	int result1 = 0, result2 = 0;
	try
	{
		if (b==0) throw '0';
		if (b<0) throw 0;
		if (!cin) throw 0.1;
		result1 = a / b;
		result2 = a % b;
		cout << setfill('$') << setw(11) << result1 << endl;
		cout << setfill('$') << setw(11) << result2 << endl;
	}
	catch (char c) { cout << "Error: " << c << endl; }
	catch (int) {}
	catch (...)
	{
		cout << "Troubles with number." << endl;
		system("pause");
	}

	try 
	{
		ofstream fout;
		fout.open("file.txt");
		if (b)
		{
			fout << result1 << endl;
			fout << result2 << endl;
		}
		fout.close();
	}
	catch (...)
	{
		cout << "Troubles with file." << endl;
		system("pause");
	}

	// 2-ой пункт задания
	cout << "Write x: ";
	int x = 0;
	cin >> x;
	
	float y = 0;
	try
	{
		y = (cos(x) / sin(x)) * pow(x, 2);
		cout << "Result: " << scientific << y << endl;
	}
	catch (...)
	{
		cout << "Troubles with sinus." << endl;
		system("pause");
	}
	
	system("pause");
	return 0;
}