#pragma once

#include <vector>
#include <string>

class client
{
public:
	static int count_of_client_id;
	std::string give_first_name() { return first_name;}
	std::string give_second_name() { return second_name;}
	std::string give_address() { return address;}

	client(std::string f_n, std::string s_n, std::string ad) :
		first_name(f_n), second_name(s_n), address(ad), id(++count_of_client_id){};
	client() = delete;
	~client();

private:
	std::string first_name;		// ���
	std::string second_name;	// �������
	std::string address;		// ������
	std::vector<int> book_id;	// ������ �� ����, ������ ��������
	int id;						// �� �������
};

int client::count_of_client_id = 0;

