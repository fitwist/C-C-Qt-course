// Реализовать функцию, создающую 10 текстовых файлов и заполняющая каждый из них по 1000 случайных цифр.
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

main(){

    for (int i = 0; i< 10; i++) {
        int randomNumber = rand();
        string filename = to_string(randomNumber); 
        filename += ".txt";
        ofstream ofs (filename, ofstream::out);
        ofs << randomNumber;
        ofs.close();
        cout << randomNumber;
    }
    return 0;
}