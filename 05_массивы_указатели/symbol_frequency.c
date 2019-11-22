#include <fstream>
#include <iostream>
 
int main()
{
    
    std::ifstream input("/Users/helenkapatsa/Репозитории/cpp-itmo/Xcode/05/symbol_frequency/symbol_frequency/dataset.txt", std::ios_base::binary);
    
    if (!input) {
        std::cerr << "Файл не удается открыть. Проверьте, на месте ли он и верно ли назван\n";
        return -1;
    }
 
    size_t count[256];
    std::fill_n(count, 256, 0);
 
    for (char c; input.get(c); ++count[uint8_t(c)]); // Вычитать входной файл
 
    for (size_t i = 0; i < 256; ++i) {
        if (count[i] && isgraph(i)) { // Подсчитать символы
            std::cout << char(i) << " = " << count[i] << '\n';
        }
    }
}
