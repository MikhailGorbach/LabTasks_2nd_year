#include "Train.h"
#include <list>
using namespace std;

class List
{
private:
	list<Train> list;
public:
	List();
};

int main()
{
	setlocale(LC_ALL, "rus");

	List l;
	
	while (1)
	{
		system("cls");
		cout << "1 - Ввод данных о поездаx" << endl;
		cout << "2 - Вывод сведений по всем поездам" << endl;
		cout << "3 - Вывод сведений по поезду с запрошенным номером" << endl;
		cout << "4 - Вывод сведений по тем поездам, которые следуют до запрошенной станции назначения" << endl;
		cout << "5 - Сохранение данных в файл" << endl;
		cout << "6 - Выход" << endl;
		
		cout << "Введите номер пункта меню -> ";
		int key = 0;
		cin >> key;

		switch (key)
		{
		case 1:
			
			break;
		case 2:
			
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

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


