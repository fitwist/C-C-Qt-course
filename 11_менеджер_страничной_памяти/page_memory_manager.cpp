#include <iostream>
int max_size = 10000;
int *heap = new int[max_size];
int choice, page_size, page_size_2;

void merge_pages() {
    
}

void remove_page() {

}

int main() {
    int total_memory = 0;
    int i = 0;
	std::cout << "Страницы автосгенерированы:" << std::endl;
    while(total_memory <= max_size) {
		*(heap+i) = rand()% 2000+1;
        total_memory += *(heap+i);
        std::cout << &heap[i] << ": " << *(heap + i) << std::endl; 
        i++;
	}

    // std::cout << "\nВведите:" << std::endl;
    // std::cout << "1, если хотите удалить страницу" << std::endl;
    // std::cout << "2, если хотите объединить страницы" << std::endl;
    // std::cout << "3, чтобы выйти. \nВыберите действие: ";
    // scanf("%d", choice);
    while (choice != 3) {
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Удаление страницы" << std::endl;
                break;
            case 2:
                std::cout << "Объединение страниц" << std::endl;
                break;
            default:
                std::cout << "Выберите действительный пункт меню:" << std::endl; 
        }
    }

    delete heap;
	return 0;
}