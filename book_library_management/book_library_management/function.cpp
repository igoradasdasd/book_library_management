#include "function.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

void main_menu(void)
{
	cout << "�������� ��������: 0 - �������� �����,  1 - �������� ������� " << endl <<
		"2 - ������� �����, 3 - ������� �������" << endl <<
		"4 - ������ ����� �������, 5 - �������� ����� � �������" << endl;

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
			cout << " ��� ������ ��������" << endl;
			break;
		}
		main_menu();
	}


}