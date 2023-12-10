#include "function.h"
#include <iostream>
#include <string>
#include <vector>
#include "book.h"
#include "client.h"

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

void select_action(std::vector<book> & books, std::vector<client> & clients)
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
			add_client(clients);
			break;
		case 2:
			if (!books.empty())
				delete_book(books);
			else
				std::cout << "List of books is empty" << std::endl;
			break;
		case 3: 
			if (!clients.empty())
				delete_client(clients);
			else
				std::cout << "List of clients is empty" << std::endl;
			break;
		case 4: 
			if (books.empty())
			{
				std::cout << "List of books is empty" << std::endl;
				break;
			}
			if (clients.empty())
			{
				std::cout << "List of clients is empty" << std::endl;
				break;
			}
			give_book(books, clients);
			break;
		case 5:
			if (books.empty())
			{
				std::cout << "List of books is empty" << std::endl;
				break;
			}
			if (clients.empty())
			{
				std::cout << "List of clients is empty" << std::endl;
				break;
			}
			get_book(books, clients);
			break;
		default:
			cout << " нет такого действия" << endl;
			break;
		}
		main_menu();
	}
}
// выдача книги
void give_book(std::vector<book>& books, std::vector<client>& clients)
{
	decltype(books.end()) book_iterator;
	decltype(clients.end()) client_iterator;

	book_iterator = find_book(books);
	if (book_iterator == books.end())
		std::cout << "There is no such book " << std::endl;	// такой книги нет
	else
		if ((*book_iterator).get_status() == ON_HAND)
		{
			std::cout << "The book is in hands" << std::endl;	// книга на руках
		}
		else
			{
				client_iterator = find_client(clients);
				if (client_iterator == clients.end())
					std::cout << "There is no such client " << std::endl; // такого клиента нет
			else
				{
					(*book_iterator).set_status(ON_HAND);
					(*client_iterator).get_book((*book_iterator).give_id());
					std::cout << "The book has been issued " << std::endl; // книга успешно выдана
				} 
	}
}

// возвращение книги
void get_book(std::vector<book>& books, std::vector<client>& clients)
{
	decltype(books.end()) book_iterator;
	decltype(clients.end()) client_iterator;

	book_iterator = find_book(books);
	if (book_iterator == books.end())
		std::cout << "There is no such book " << std::endl;	// такой книги нет
	else
		if ((*book_iterator).get_status() == IN_STOCK)
		{
			std::cout << "Such a book was not issued" << std::endl;	// такая книга не выдавалась
		}
		else
		{
			client_iterator = find_client(clients);
			if (client_iterator == clients.end())
				std::cout << "There is no such client " << std::endl; // такого клиента нет
			else
			{
				(*book_iterator).set_status(IN_STOCK);
				(*client_iterator).get_book((*book_iterator).give_id());
			}
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
	decltype(books.end()) return_iterator;
	return_iterator = find_book(books);

	if (return_iterator != books.end())
		books.erase(return_iterator);
	else
		std::cout << "There is no such book " << std::endl;
}

void add_client(std::vector<client>& clients)
{
	std::string f_n, s_n, a;

	std::cout << "Enter first name" << endl;
	std::cin >> f_n;

	std::cout << "Enter second name" << endl;
	std::cin >> s_n;

	std::cout << "Enter address" << endl;
	std::cin >> a;

	client c(f_n, s_n, a);
	clients.push_back(c);
}

void delete_client(std::vector<client>& clients)
{
	decltype(clients.end()) return_iterator;

	return_iterator = find_client(clients);
	if (return_iterator !=  clients.end() )
		clients.erase(return_iterator);
	else
		std::cout << "There is no such client " << std::endl;
}

std::vector<book>::iterator find_book(std::vector<book>& books)
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
	return iterator;
}

std::vector<client>::iterator find_client(std::vector<client>& clients)
{
	int find_type = 0;
	decltype(clients.begin()) iterator = clients.end();	//здесь будет сохраняться итеретор, удаляемой книги
	string search_criteria;
	int id;

	std::cout << "Ener the parameter by which the clients will be found: " << std::endl <<
		"0 - find by first name " << std::endl <<
		"1 - find by second_name " << std::endl <<
		"2 - find by address " << std::endl <<
		"3 - find by id " << std::endl;
	std::cin >> find_type;
	switch (find_type)
	{
	case 0:
		std::cout << "Enter the first name of the client ";
		std::cin >> search_criteria;
		iterator = find_if(clients.begin(), clients.end(), [=](client& b) {
			return (search_criteria == b.give_first_name());
			});
		break;
	case 1:
		std::cout << "Enter the second_name of the client ";
		std::cin >> search_criteria;
		iterator = find_if(clients.begin(), clients.end(), [=](client& b) {
			return (search_criteria == b.give_second_name());
			});
		break;
	case 3:
		std::cout << "Enter address of the client ";
		std::cin >> search_criteria;
		iterator = find_if(clients.begin(), clients.end(), [=](client& b) {
			return (search_criteria == b.give_address());
			});
		break;
	case 4:
		std::cout << "Enter id of the client ";
		std::cin >> search_criteria;
		iterator = find_if(clients.begin(), clients.end(), [=](client& b) {
			return (id == b.give_id());
			});
		break;
	default:

		break;
	}
	return iterator;
}