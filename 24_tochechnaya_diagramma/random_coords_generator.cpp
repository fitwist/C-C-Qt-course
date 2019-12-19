#include <stdio.h>
#include <fstream>

int main() {
    double x, y;
    std::ofstream dataset;
    dataset.open ("/home/helen/Документы/C-C-Qt-course/24_tochechnaya_diagramma/dataset.csv");
    
    for (int i = 0; i<1000; i++) {
        x = rand()% 99+1;
        y = rand()% 99+1;
        dataset << x << " " << y << std::endl;
    }
    dataset.close();
    return 0;
}
