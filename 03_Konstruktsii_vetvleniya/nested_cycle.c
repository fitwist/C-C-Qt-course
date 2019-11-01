#include <stdio.h>

int main() {
    int i = 0;
    int j = 0;
    int k = 0;
    int sum = 0;
    do {
        i++;
        printf("i is equal to %4d\n", i);
        while (j<9) {
            j++;
            printf("j is equal to %4d\n", j);
            for (; sum<6; k++) {
                sum += 1;
                printf("k is equal to %4d\n", k);
            };
        };
    } while (i<3);
    printf("sum is equal to %4d\n", sum);
    return 0;
}