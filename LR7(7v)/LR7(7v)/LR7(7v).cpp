﻿#include <iostream>
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

	int result1, result2;
	try
	{
		result1 = a / b;
		result2 = a % b;
		cout << setw(11) << setfill('$') << result1 << setfill('$') << endl;
		cout << setw(11) << setfill('$') << result2 << setfill('$') << endl;
	}
	catch (exception e)
	{
		e.what();
		system("pause");
	}

	try
	{
		ofstream fout;
		fout.open("file.txt");
		fout << result1 << endl;
		fout << result2 << endl;
		fout.close();
	}
	catch (exception e)
	{
		e.what();
		cout << "Troubles with file." << endl;
		system("pause");
	}

	cout << "Write x: ";
	int x = 0;
	cin >> x;
	
	float y = 0;
	try
	{
		y = (cos(x) / sin(x)) * pow(x, 2);
		cout << "Result: " << y << endl;
	}
	catch (exception e)
	{
		e.what();
	}
	
	system("pause");
	return 0;
}