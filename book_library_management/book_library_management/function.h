#pragma once
#include <vector>
#include "book.h"

void main_menu(void);		// вывод соновного меню

void select_action(std::vector<book>&);	// выбор действия

void add_book(std::vector<book>& books);

void delete_book(std::vector<book>& books);