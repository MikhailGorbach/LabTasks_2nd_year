#include "List.h"

List::List() {}
void List::NewList()
{
	int id;
	string end;
	int hours;
	int min;

	cout << "Введите номер поезда: "; cin >> id;
	cout << "Введите станцию назначения: "; cin.get(); getline(cin, end);
	cout << "Введите время отправления (часы, минуты): "; cin >> hours >> min;

	Train t(id, end, hours, min);
	_list.push_front(t);
}
void List::Print()
{
	cout << "Номер поезда " << "Станция назначения " << "Время отправления (часы, минуты) " << endl;
	for (Train train : _list)
	{
		cout
			<< train.getId() << "\t"
			<< train.getEnd() << "\t"
			<< train.getHours() << " : "
			<< train.getMin() << endl;
	}
	system("pause");
}
void List::PrintById(int id)
{
	cout << "Номер поезда " << "Станция назначения " << "Время отправления (часы, минуты) " << endl;
	for (Train train : _list)
	{
		if (train.getId() == id)
		{
			cout
				<< train.getId() << "\t"
				<< train.getEnd() << "\t"
				<< train.getHours() << " : "
				<< train.getMin() << endl;
		}
	}
	system("pause");
}
void List::PrintByStation(string station)
{
	cout << "Номер поезда " << "Станция назначения " << "Время отправления (часы, минуты) " << endl;
	for (Train train : _list)
	{
		if (train.getEnd() == station)
		{
			cout
				<< train.getId() << "\t"
				<< train.getEnd() << "\t"
				<< train.getHours() << " : "
				<< train.getMin() << endl;
		}
	}
	system("pause");
}
void List::Save()
{
	ofstream fout;
	fout.open("file.txt", ios::out);

	for (Train train : _list)
	{
		fout << train.getId() << endl;
		fout << train.getEnd() << endl;
		fout << train.getHours() << endl;
		fout << train.getMin() << endl;
	}
	fout.close();
}
void List::Upload()
{
	ifstream fin;
	fin.open("file.txt", ios::in);

	int id1 = 0;
	string end1 = "";
	int hours1 = 0;
	int min1 = 0;

	for (;fin >> id1;)
	{
		fin >> end1;
		fin >> hours1;
		fin >> min1;

		Train newtrain(id1, end1, hours1, min1);
		_list.push_front(newtrain);
	}
}