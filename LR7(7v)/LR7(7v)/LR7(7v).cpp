#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	cout << "Write 1-st number: ";
	int a = 0;
	cin >> a;
	
	cout << "Write 2-nd number: ";
	int b = 0;
	cin >> b;

	cout << a / b << endl;
	cout << a % b << endl;

	system("pause");
	return 0;
}