#include "book.h"


int book::book_id = 0;

std::ostream & operator<< (std::ostream & os, book & b)
{
	os << b.give_title() << "\n" <<
		b.give_author() << "\n" <<
		b.give_id() << "\n" <<
		b.give_status();
	return os;
}


std::istream& operator>> (std::istream& is, book & b)
{
	string title, author;
	size_t id, status;

	is >> title >> author >> id >> status;
	b.get_title(title);
	b.get_author(author);
	b.get_id(id);
	b.set_status(static_cast<condition>(status));
	return is;
}

