#pragma once
#include <string>


using std::string;

enum condition {IN_STOCK, ON_HAND}; //IN_STOCK - �� �������, ON_HAND - �� �����

class book
{
public:
	static int book_id;	//
	string give_title() { return title; };
	string give_author() { return author; };
	int give_id() { return id;};

	book(std::string t, std::string a) :
		title(t), author(a), status(IN_STOCK), id(++book_id)
	{ }
	~book() = default;
private:
	string title;		// �������� �����
	string author;		// �����
	condition status;	// ������
	int id;				// �� �����
};


