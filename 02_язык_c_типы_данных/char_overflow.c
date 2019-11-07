#include <stdio.h>

int main() {
    char x = (char)126; // Инициализировать char x 
    printf("x character: %c\n", ++x); // Переполнить x
    printf("x number: %d\n", ++x); // Переполнить x
    return 0;
}