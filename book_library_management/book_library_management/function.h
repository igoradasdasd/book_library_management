#pragma once
#include <vector>
#include "book.h"

void main_menu(void);		// ����� ��������� ����

void select_action(std::vector<book>&);	// ����� ��������

void add_book(std::vector<book>& books);

void delete_book(std::vector<book>& books);