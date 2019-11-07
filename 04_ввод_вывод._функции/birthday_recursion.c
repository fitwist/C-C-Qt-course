#include <stdio.h>

int calcsum(int *, int);

int main() {
    int s = 0, n = 3, i, a[10];

    printf("Укажите свой День рождения в формате дд-мм-гггг (через пробел): \n");

    for (i = 0; i < n; i++) { // Получить слагаемые с помощью трехэтапного цикла
        scanf("%d", &a[i]); 
    }

    s = calcsum(a, 3); // Суммировать полученные слагаемые
    printf("Сумма чисел Вашего Дня рождения составляет %d \n", s);

    return (0);
}

int calcsum(int *a, int n) { // Определить функцию суммирования
    int i, sum = 0;
    for (i = 0; i < n; i++) {
        sum = sum + *(a + i);
    }
    return sum;
}