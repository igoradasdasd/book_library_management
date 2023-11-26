#include "function.h"
#include <iostream>
#include <string>
#include <vector>
#include "book.h"

using std::cin;
using std::cout;
using std::endl;

void main_menu(void)
{	
	std::cout << std::endl;
	cout << "select action: 0 - add the book,  1 - add the client " << endl <<
		"2 - delete the book, 3 - delete the client" << endl <<
		"4 - give the book to the client, 5 - get a book from a client" << endl;

}

void select_action(std::vector<book> & books)
{
	int action;
	while (cin >> action)
	{
		switch (action)
		{
		case 0:
			add_book(books);
			break;
		case 1:
//			add_client()
			break;
		case 2:
			if (!books.empty())
				delete_book(books);
			else
				std::cout << "List of books is empty" << std::endl;
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

void add_book(std::vector<book>& books)
{
	std::string title, author;
	std::cout << "Enter the title of the book: ";
	std::cin >> title;
	std::cout << std::endl;
	std::cout << "Enter the author of the bood: ";
	std::cin >> author;
	book b(title, author);
	books.push_back(b);
}

void delete_book(std::vector<book>& books)
{
	int find_type = 0;
	decltype(books.begin()) iterator = books.end();	//здесь будет сохраняться итеретор, удаляемой книги
	string title_author;
	int id;

	std::cout << "Ener the parameter by which the book will be found: " << std::endl <<
		"0 - find by title " << std::endl <<
		"1 - find by author " << std::endl <<
		"3 - find by id " << std::endl;
	std::cin >> find_type;
	switch (find_type)
	{
	case 0:
		std::cout << "Enter the title of the book ";
		std::cin >> title_author;
		iterator = find_if(books.begin(), books.end(), [=](book& b) {
			return (title_author == b.give_title());
			});
		break;
	case 1:
		std::cout << "Enter the author of the book ";
		std::cin >> title_author;
		iterator = find_if(books.begin(), books.end(), [=](book& b) {
			return (title_author == b.give_author());
			});
		break;
	case 3:
		std::cout << "Enter id of the book ";
		std::cin >> id;
		iterator = find_if(books.begin(), books.end(), [=](book& b) {
			return (id == b.give_id());
			});
		break;
	default:

		break;
	}

	if (iterator != books.end())
		books.erase(iterator);
	else
		std::cout << "There is no such book " << std::endl;

	
}