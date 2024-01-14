// book_library_management.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "book.h"
#include "client.h"
#include <vector>
#include "function.h"
#include <fstream>
std::vector<book> list_of_books;
std::vector<client> list_of_clients;

int main()
{   
    bool repeat = true;
    std::ifstream file_in("books.txt");
    std::istream_iterator<book> in_iter(file_in), eof;
    std::vector<book> list_of_books{ in_iter, eof };

    std::ofstream file_out("books.txt");
    std::ostream_iterator<book> out(file_out, "\n");

    while (repeat)
    {
        main_menu();		// вывод оcновного меню
        select_action(list_of_books, list_of_clients, repeat);	// выбор действия

    }

    for (auto & a : list_of_books)
        file_out << a << std::endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
