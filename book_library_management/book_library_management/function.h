#pragma once
#include <vector>
#include "book.h"
#include "client.h"

void main_menu(void);		// вывод соновного меню

void select_action(std::vector<book>&, std::vector<client>&, bool &);	// выбор действия

void add_book(std::vector<book> & books);

void delete_book(std::vector<book> & books);

void add_client(std::vector<client> & );

void delete_client(std::vector<client> & );

std::vector<book>::iterator find_book(std::vector<book>&);
std::vector<client>::iterator find_client(std::vector<client>&);

void give_book(std::vector<book>& books, std::vector<client>& clients);
void get_book(std::vector<book>& books, std::vector<client>& clients);