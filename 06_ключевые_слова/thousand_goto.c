#include <iostream>
#include <cmath>

int main() {
tryAgain: // Метка
    int i = 0;
    for (; i <= 100; i++) { // i объявлен выше, ибо области видимости
        std::cout << i << "\n"; // Вывод в консоль инкрементированного числа
    }
 
    if (i < 100)
        goto tryAgain; // оператор возврата к петле
 
    return 0;
}
