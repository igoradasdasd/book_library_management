#include "function.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

void main_menu(void)
{
	cout << "выберете действие: 0 - добавить книгу,  1 - добавить клиента " << endl <<
		"2 - удалить книгу, 3 - удалить клиента" << endl <<
		"4 - выдать книгу клиенту, 5 - получить книгу у клиента" << endl;

}

void select_action(void)
{
	int action;
	main_menu();
	while (cin >> action)
	{
		switch (action)
		{
		case 0:

			break;
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
		default:
			cout << " нет такого действия" << endl;
			break;
		}
		main_menu();
	}


}