#include "ClassList.h"
int main()
{
	Inf p;
	List l;
	while (1)
	{
		int flag;
		system("cls");
		cout << "=======<Menu>=======" << endl;
		if (!l.getValue())
		{
			flag = 0;
			cout << "1 - Add first list" << endl;
		}
		else
		{
			flag = 1;
			cout << "1 - Add list" << endl;
		}
		cout << "2 - Print information" << endl;
		cout << "3 - Search student after certain date" << endl;
		cout << "4 - Delete first element" << endl;
		cout << "5 - Constructor with parameters" << endl;
		cout << "6 - Copy constructor" << endl;
		cout << "7 - Exit" << endl;
		int key;
		cout << "Select your item-> ";
		cin >> key;
		switch (key)
		{
		case 1:
			if (flag) l.AddList();
			else l.AddFirst();
			break;
		case 2:
			l.Print();
			system("pause");
			break;
		case 3:
			int day, month, year;
			cout << "Write your date -> "; cin >> day >> month >> year;
			l.SearchAfterDate(day, month, year);
			system("pause");
			break;
		case 4:
			l.Del();
			system("pause");
			break;
		case 5:
		{
			Inf a;
			cout << "*Fill information*" << endl;
			cout << "Student full name: "; cin.get(); getline(cin, a.fullname);
			cout << "Date of birth (use whitespace): "; cin >> a.day >> a.month >> a.year;
			List l1(a);
			cout << "Now add new element." << endl;
			l1.AddList();
			l1.Print();
			cout << "Now delete last element." << endl;
			cin.get();
			l1.Del();
			l1.Print();
			system("pause");
			break;
		}
		case 6:
		{
			cout << "Copy list" << endl;
			List l3(l);
			l3.Print();
			system("pause");
			break;
		}
		case 7: return 0;
		default: cout << "Choose an another option." << endl; system("pause");
		}
	}
}
