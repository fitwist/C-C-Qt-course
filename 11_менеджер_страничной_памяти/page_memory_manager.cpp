#include <iostream>
#include <vector>

int max_size = 10000;
int *heap = new int[max_size];
std::vector<int> memory;

void merge_pages() {
    int size, size2;
    std::cout << "Укажите размер первой страницы: ";
    scanf("%d", &size);
    std::cout << "Укажите размер второй страницы: ";
    scanf("%d", &size2);
    memory.push_back(size+size2);
    memory.erase(std::remove(memory.begin(), memory.end(), size), memory.end());
    memory.erase(std::remove(memory.begin(), memory.end(), size2), memory.end());
    for (auto &i : memory) {
        std::cout << &i << ": " << i << std::endl;
    }
}

void remove_page() {
    int size;
    std::cout << "Укажите размер удаляемой страницы: ";
    scanf("%d", &size);
    memory.erase(std::remove(memory.begin(), memory.end(), size), memory.end());
    for (auto &i : memory) {
        std::cout << &i << ": " << i << std::endl;
    }
}

int main() {
    int total_memory = 0;
    int i = 0;
    std::cout << "Страницы автосгенерированы:" << std::endl;
    while(total_memory <= max_size) {
        *(heap+i) = rand()% 2000+1;
        memory.push_back(heap[i]);
        total_memory += *(heap+i);
        std::cout << &heap[i] << ": " << *(heap + i) << std::endl;
        i++;
    }
    
    int choice;
    std::cout << "\n1. Удалить страницу" << "\n2. Объединить страницы" << std::endl;
    std::cout << "Выберите пункт меню: ";
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            remove_page();
            break;
        case 2:
            merge_pages();
            break;
        default:
            std::cout << "Укажите действительный пункт меню: " << std::endl;
    }
    return 0;
}
