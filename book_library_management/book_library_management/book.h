#pragma once
#include <string>
#include <ostream>
#include <iostream>


using std::string;

enum condition {IN_STOCK, ON_HAND}; //IN_STOCK - на скаладе, ON_HAND - на руках

class book
{
public:
	static int book_id;	//

	string give_title() { return title; };
	string give_author() { return author; };
	int give_id() { return id;};
	void set_status(condition cond) { status = cond; }
	condition give_status() { return status; }

	void get_title(string in) {  title = in; };
	void get_author(string in) { author = in; };
	void get_id(size_t in) { id = in; };
	book() {};
	book(std::string t, std::string a) :
		title(t), author(a), status(IN_STOCK), id(++book_id)
	{ }
	~book() = default;
private:
	string title;		// название книги
	string author;		// автор
	condition status;	// статус
	int id;				// ИД книги
};

std::ostream& operator<< (std::ostream& os, book& b);

std::istream& operator>> (std::istream& is, book& b);

