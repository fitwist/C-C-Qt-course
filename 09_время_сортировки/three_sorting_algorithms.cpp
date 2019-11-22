#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <time.h>

#define SIZE 100

int i;
int arr[SIZE];

void quickSort() { // БЫСТРАЯ СОРТИРОВКА
    constexpr size_t size = sizeof arr / sizeof *arr;
    qsort(arr, size, sizeof *arr, [](const void* a, const void* b) {
        int arg1 = *static_cast<const int*>(a);
        int arg2 = *static_cast<const int*>(b);

        if(arg1<arg2) return -1;
        if(arg1>arg2) return 1;
        return 0;
    });
}

void bubbleSort() { // СОРТИРОВКА МАССИВА ПУЗЫРЬКОМ
    int temp;
    for (int k = 0; k<SIZE-1; k++) {
        for (int l = 0; l<SIZE-k-1; l++) {
            if (arr[l] > arr[l + 1]) {
                temp = arr[l]; // Смена мест элементов
                arr[l] = arr[l + 1];
                arr[l + 1] = temp;
            }
        }
    }
}

void choiceSort() { // СОРТИРОВКА ПОИСКОМ МИНИМУМА
    for (int m = 0; m<SIZE-1; ++m) {
       int n = m; // Индекс наименьшего значения (изначально равен нулю)
       for (int o = m + 1; o<SIZE; ++o) { // Поиск наименьшего элемента
           if (arr[o]<arr[n])
               n = o;
       }
       std::swap(arr[m], arr[n]); // Замена начального наименьшего значения найденным
    }
}

void countExecTime(void (*f)()) { // Подсчет скорости функции
    unsigned long int start = clock();
    for (int j = 0; j<100; j++) { // Стократный запуск сортировки
        f();
    }
    unsigned long int stop = clock();
    unsigned long int duration = (stop-start)/100;
    std::cout << "Сортировка заняла " << duration << " мкс" << std::endl;
}

int main() {
    srand((unsigned int) time(NULL));

    for (int j = 0; j<SIZE; j++) {
        i = rand() % (SIZE+1);
        
        if (i != i-1) // Проверка неравенства предыдущему элементу
            arr[j]=i;
        else {
            i = rand() % (SIZE+1);
            arr[j]=i;
        }
    }
    
    countExecTime(&choiceSort);
    countExecTime(&bubbleSort);
    countExecTime(&quickSort);
    
    return 0;
}