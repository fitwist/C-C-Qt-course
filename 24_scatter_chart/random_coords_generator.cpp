#include <iostream>
#include <fstream>

int main() {
    double x, y;
    std::ofstream dataset;
    dataset.open ("/Users/helenkapatsa/Repositories/cpp-junior-itmo/assignment-practice/24/random_plotting_data/random_plotting_data/dataset.csv");
    
    for (int i = 0; i<1000; i++) {
        x = rand()% 99+1;
        y = rand()% 99+1;
        dataset << x << " " << y << std::endl;
    }
    dataset.close();
    return 0;
}
