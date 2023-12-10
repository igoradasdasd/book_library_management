#include "client.h"

int client::count_of_client_id = 0;

void client::give_book(int in_book_id)
{
	decltype(book_id.begin()) iterator;
	iterator = find_if(book_id.begin(), book_id.end(), [=](int id) {
		return id == in_book_id; });
	if (iterator == book_id.end())
		std::cout << "This book was not issued to this client " << std::endl;
	else
	{
		book_id.erase(iterator);
		std::cout << "The book was successfully returned " << std::endl; // книга успешно возвращена
	}
		
}