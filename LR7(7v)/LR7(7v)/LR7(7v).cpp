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
		if (b == 0) throw '0';
		if (!cin) throw 0;
		result1 = a / b;
		result2 = a % b;
		cout << setfill('$') << setw(11) << result1 << endl;
		cout << setfill('$') << setw(11) << result2 << endl;
	}
	catch (char) { cout << "Second number is null!" << endl; }
	catch (int) { cout << "Problems with stream" << endl; }
	catch (...) { cout << "Unexpected problem :/" << endl; }

	try 
	{
		ofstream fout;
		fout.open("file.txt");
		if (!fout.is_open()) throw 0;
		if (b)
		{
			fout << result1 << endl;
			if (!fout) throw 0.0;
			fout << result2 << endl;
			if (!fout) throw 0.0;
		}
		fout.close();
		if (fout.is_open()) throw '0';
	}
	catch (int) { cout << "Can't open the file." << endl; return 1; }
	catch (char) { cout << "Can't close the file." << endl; return 1; }
	catch (double) { cout << "Can't be written to the file." << endl; return 1;	}
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
		cout << "Troubles with y." << endl;
		system("pause");
		return 1;
	}
	
	system("pause");
	return 0;
}