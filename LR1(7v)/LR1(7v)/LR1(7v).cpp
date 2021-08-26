#include <iostream>
#include <string>
using namespace std;

struct Inf
{
	string fullname;
	int day;
	int month;
	int year;
};

struct Profile
{
	Inf data;
	Profile* next, * prev;
};

class List
{

private:
	struct Inf p;
	struct Profile* top, * left, * right;

public:
	List()
	{
		top = 0;
		left = 0;
		right = 0;
		cout << "Consturtor without parameters was completed." << endl;
		system("pause");
	}
	List(struct Inf information)
	{
		struct Profile* top = new Profile;
		top->data = information;
		top->next = 0;
		top->prev = 0;
		left = top;
		right = top;
		cout << "Consturtor with parameters was completed." << endl;
		system("pause");
	}
	List(const List& other)
	{
		if (!other.left)
		{
			left = 0;
			right = 0;
			cout << "Copy consturtor was completed without information." << endl;
			system("pause");
		}
		else
		{
			Profile* top = new Profile;
			top->data = other.left->data;
			top->next = 0;
			left = top;
			right = top;
			Profile* temp1 = top;
			Profile* temp2 = other.left->next;
			while (temp2)
			{
				Profile* newE = new Profile;
				temp1->next = newE;
				newE->data = temp2->data;
				newE->next = 0;
				right = newE;
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			cout << "Copy consturtor was completed with information." << endl;
			system("pause");
		}
	}
	~List()
	{
		struct Profile* temp = top;

		while (temp)
		{
			top = top->next;
			top->next->prev = 0;
			delete temp;
			temp = top;
		}
		cout << "Destructor was completed." << endl;
		system("pause");
	}
	void AddFirst();
	void AddList();
	void Print();
	void SearchAfterDate(int Day, int Month, int Year);
	void Del();
	struct Profile* getValue();
};

void List::AddFirst()
{
	struct Inf p;
	cout << "*Fill information*" << endl;
	cout << "Student full name: "; cin.get(); getline(cin, p.fullname);
	cout << "Date of birth (use whitespace): "; cin >> p.day >> p.month >> p.year;
	Profile* top = new Profile;
	top->next = 0;
	top->prev = 0;
	top->data = p;
	left = top;
	right = top;
}
void List::AddList()
{
	if (!left)
	{
		struct Inf p;
		cout << "*Fill information*" << endl;
		cout << "Student full name: "; cin.get(); getline(cin, p.fullname);
		cout << "Date of birth (use whitespace): "; cin >> p.day >> p.month >> p.year;
		Profile* top = new Profile;
		top->next = 0;
		top->prev = 0;
		top->data = p;
		left = top;
		right = top;
	}
	else
	{
		struct Inf p;
		cout << "*Fill information*" << endl;
		cout << "Student full name: "; cin.get(); getline(cin, p.fullname);
		cout << "Date of birth (use whitespace): "; cin >> p.day >> p.month >> p.year;
		Profile* temp = right;
		Profile* newE = new Profile;
		newE->next = 0;
		newE->prev = temp;
		temp->next = newE;
		temp->next->prev = temp;
		newE->data = p;
		right = newE;
	}
}
void List::Print()
{
	struct Profile* temp = left;
	if (!temp) { cout << "List is empty!" << endl; return; }
	else
	{
		cout << "Full name\tDate\t" << endl;
		cout << "================================" << endl;
		while (temp)
		{
			cout << temp->data.fullname << "\t" << temp->data.day << "." << temp->data.month << "." << temp->data.year << endl;
			temp = temp->next;
		}
		cout << "================================" << endl;
	}
}
void List::SearchAfterDate(int Day, int Month, int Year)
{
	if (left)
	{
		struct Profile* temp = left;
		int counter = 0;
		cout << "Searching students..." << endl;
		cout << "Full name\tDate\t" << endl;
		cout << "================================" << endl;
		while (temp)
		{
			if ((temp->data.day >= Day) && (temp->data.month >= Month) && (temp->data.year >= Year))
			{
				counter++;
				cout << temp->data.fullname << "\t" << temp->data.day << "." << temp->data.month << "." << temp->data.year << endl;
			}
			temp = temp->next;
		}
		cout << "================================" << endl;
		cout << "There is(are) " << counter << " student(s)." << endl;
	}
	else
	{
		cout << "List is empty!" << endl;
	}
}
void List::Del()
{
	struct Profile* temp = left;
	if (!temp) { cout << "List is empty!" << endl; return; }
	else
	{
		cout << "Are you sure? If not - Enter *. Yes - any key." << endl;
		char check;
		cin >> check;
		if (check == '*') return;
		left = left->next;
		delete temp;
		cout << "First element was succesfully deleted." << endl;
	}
}
struct Profile* List::getValue()
{
	struct Profile* temp = left;
	return temp;
}
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
