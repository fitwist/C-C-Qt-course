// Использовать ветвление switch-case. В switch передавать цифру, на выходе получать первую букву цифры.
#include <stdio.h>

int main() {
    int digit;
    printf("Введите цифру от 0 до 9:\n");
    scanf("%d", &digit); // Получить входную цифру
    switch(digit) { // "Конвертировать" цифру в соответствующую букву
        case 0: 
            printf("н\n");
            break;
        case 1: 
            printf("о\n");
            break;
        case 2: 
            printf("д\n");
            break;
        case 3: 
            printf("т\n");
            break;
        case 4: 
            printf("ч\n");
            break;
        case 5: 
            printf("п\n");
            break;
        case 6: 
            printf("ш\n");
            break;
        case 7: 
            printf("с\n");
            break;
        case 8: 
            printf("в\n");
            break;
        case 9: 
            printf("д\n");
            break;
    };
    return 0;
}