#pragma once

#include <vector>
#include <string>
#include <iostream>

class client
{
public:
	static int count_of_client_id;
	std::string give_first_name() { return first_name;}
	std::string give_second_name() { return second_name;}
	std::string give_address() { return address;}
	int give_id() { return id; }
	void get_book(int in_book_id) { book_id.push_back(in_book_id); }	// ������ �������� �����
	void give_book(int in_book_id);	// ������ ���������� �����

	client(std::string f_n, std::string s_n, std::string ad) :
		first_name(f_n), second_name(s_n), address(ad), id(++count_of_client_id){};
	client() = delete;
	~client() = default;;

private:
	std::string first_name;		// ���
	std::string second_name;	// �������
	std::string address;		// ������
	std::vector<int> book_id;	// ������ �� ����, ������ ��������
	int id;						// �� �������
};



