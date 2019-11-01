#include <stdio.h>

int main() {
    char x = (char)126;
    printf("x character: %c\n", ++x);
    printf("x number: %d\n", ++x);
    return 0;
}