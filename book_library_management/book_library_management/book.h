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

	book(std::string t, std::string a, condition s) :
		title(t), author(a), status(s), id(++book_id)
	{ }
	~book();
private:
	string title;		// �������� �����
	string author;		// �����
	condition status;	// ������
	int id;				// �� �����
};

int book::book_id = 0;
