#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    // Создаем массив символов
    char alphabets[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char rString[20];

    srand((unsigned int) time(NULL)); //

    int i=0;
    while(i<20) {
        int temp = rand() % 26;
        rString[i] = alphabets[temp];
        i++;
    }

    for(i=0; i<1000; i++)
        cout << rString[i] << "\n";

    return 0;
}