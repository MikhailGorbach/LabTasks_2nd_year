#include "List.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	List l;
	
	while (1)
	{
		system("cls");
		cout << "1 - Ввод данных о поездаx" << endl;
		cout << "2 - Вывод сведений по всеx поездам" << endl;
		cout << "3 - Вывод сведений по поезду с запрошенным номером" << endl;
		cout << "4 - Вывод сведений по тем поездам, которые следуют до запрошенной станции назначения" << endl;
		cout << "5 - Сохранение данных в файл" << endl;
		cout << "6 - Выход" << endl;
		
		cout << "Введите номер пункта меню -> ";
		int key = 0;
		cin >> key;
		cout << endl;
		switch (key)
		{
		case 1:
		{	
			cout << "Нажмите +, чтобы создать новую таблицу или другой символ для загрузки из файла." << endl;
			char check;
			cin >> check;
			if (check == '+') l.NewList();
			else l.Upload();
			break;
		}
		case 2:
			l.Print();
			break;
		case 3:
		{
			cout << "Введите номер поезда: ";
			int id;
			cin >> id;
			l.PrintById(id);
			break;
		}
		case 4:
		{
			cout << "Введите станцию назначения: ";
			string station;
			cin.get(); getline(cin, station);
			l.PrintByStation(station);
			break;
		}
		case 5:
			l.Save();
			break;
		case 6:
			return 0;
		default:
			cout << "Введите другой пункт меню." << endl;
			system("pause");
			break;
		}
	}
}