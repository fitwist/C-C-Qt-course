#include <fstream>
#include <iostream>

using namespace std;

int main() {
    char b[100000] = "";
    ifstream f("./dataset.txt"); // Вычитать файл

    f.read(b, sizeof(b) - 1); // Использовать оператор sizeof(), не считая символа окончания файла null
    cout << "Размер файла составляет " << sizeof(b) << " байт(-ов)\n";
}
