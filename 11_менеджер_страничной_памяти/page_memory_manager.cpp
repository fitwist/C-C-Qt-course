#include <iostream>
#include <iomanip>
#include <vector>

#define TOTAL_MEMORY 10000
#define MIN_PAGE_SIZE 1

struct page
{
    int id;
    int size;
};
std::vector<int> heap;

void generate_pages()
{ // автогенерация страниц
    int total_memory = 0;
    while (total_memory <= 10000) {
        int randomId = rand() % 999 + 1;
        int randomSize = rand() % 1999 + 1;
        page list_elt {}
    }
}

void remove_page() // удаление страницы
{
    std::cout << "Удаление страниц" << std::endl;
}

void merge_pages() // объединение страниц
{
    std::cout << "Объединение страниц" << std::endl;
}

int main()
{
    string separator = "   |   ";
    int choice;
    std::cout << "Добро пожаловать в менеджер памяти. Текущие страницы:" << std::endl;
    std::cout << "ID  " << separator << "Размер" << std::endl;
    std::cout << "——————————————————" << std::endl;
    std::cout << "1058" << separator << "2245" << std::endl;
    std::cout << "1001" << separator << "1024" << std::endl;
    std::cout << "2359" << separator << "1400" << std::endl << std::endl;
    
    std::cout << "1: Удаление задачи" << std::endl
              << "2: Объединение задач" << std::endl;
    std::cout << "Ваш выбор: ";
    std::cin >> choice;
    switch (choice) {
        case 1:
            remove_page();
            break;
        case 2:
            merge_pages();
            break;
        default:
            std::cout << "Выберите действительный пункт меню: " << std::endl;
    }
    return 0;
}