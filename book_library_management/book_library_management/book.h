#pragma once
#include <string>


using std::string;

enum condition {IN_STOCK, ON_HAND}; //IN_STOCK - на скаладе, ON_HAND - на руках

class book
{
public:
	static int book_id;	//
	string give_title() { return title; };
	string give_author() { return author; };

	book(std::string t, std::string a, condition s) :
		title(t), author(a), status(s), id(++book_id)
	{ }
	~book();
private:
	string title;		// название книги
	string author;		// автор
	condition status;	// статус
	int id;				// ИД книги
};

int book::book_id = 0;
