#include <stdio.h>

int calcsum(int *, int);

int main()
{
    int s = 0, n = 3, i, a[10];

    for (i = 0; i < n; i++)
    {
        printf("Укажите свой День рождения в формате дд-мм-гггг (через пробел): \n");
        scanf("%d", &a[i]);
    }

    s = calcsum(a, 3);
    printf("Сумма чисел Вашего Дня рождения составляет %d \n", s);

    return (0);
}

int calcsum(int *a, int n)
{
    int i, sum = 0;
    for (i = 0; i < n; i++)
    {
        sum = sum + *(a + i);
    }
    return sum;
}