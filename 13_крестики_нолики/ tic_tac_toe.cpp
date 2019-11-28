#include <cstdlib>
#include <iostream>
#include <unistd.h>

char b[9];

// Класс "Игральная доска"
class Board {
public:
    void makeTableCell(){
        for (int i = 0; i < 9; i++) {
            b[i] = (char)('0' + i + 1);
        }
    }
};

void printBoard();
bool checkWin(char);
void printWin(char);
bool checkDraw();
void printDraw();
std::string enterNumber = "аберите цифру от 1 до 9 (или 0, чтобы выйти из игры): ";

char player;

void printBoard() {
    std::cout << "\t     |     |     " << std::endl;
    std::cout << "\t  " << b[0] << "  |  " << b[1] << "  |  " << b[2] << std::endl;
    std::cout << "\t     |     |     " << std::endl;
    std::cout << "\t-----|-----|-----" << std::endl;
    std::cout << "\t     |     |     " << std::endl;
    std::cout << "\t  " << b[3] << "  |  " << b[4] << "  |  " << b[5] << std::endl;
    std::cout << "\t     |     |     " << std::endl;
    std::cout << "\t-----|-----|-----" << std::endl;
    std::cout << "\t     |     |     " << std::endl;
    std::cout << "\t  " << b[6] << "  |  " << b[7] << "  |  " << b[8] << std::endl;
    std::cout << "\t     |     |     " << std::endl;
}

/*
До тех пор, пока служебная переменная who
не будет равна трем символам по прямой / диагонали,
checkWin перебирает всевозможные комбинации и
игра продолжается.
*/
bool checkWin(char who) {
    if (b[0] == who && b[1] == who && b[2] == who) return true;
    if (b[3] == who && b[4] == who && b[5] == who) return true;
    if (b[6] == who && b[7] == who && b[8] == who) return true;
    if (b[0] == who && b[3] == who && b[6] == who) return true;
    if (b[1] == who && b[4] == who && b[7] == who) return true;
    if (b[2] == who && b[5] == who && b[8] == who) return true;
    if (b[0] == who && b[4] == who && b[8] == who) return true;
    if (b[2] == who && b[4] == who && b[6] == who) return true;

    return false;
}


void printWin(char who) {
    // Удаление цифровых меток
    for (int i = 0; i < 9; i++)
        if (b[i] == (char)('0' + i + 1))
            b[i] = ' ';

    std::cout << std::endl << "\tРезультаты игры" << std::endl;
    printBoard();
    std::cout << "\nПоздравляем! Игрок " << who << " выиграл!" << std::endl;
}

/*
Функция ищет незаполненные
крестиками / ноликами ячейки
*/
bool checkDraw() {
    for (int i = 0; i < 9; i++)
        if (b[i] == (char)('0' + i + 1))
            return false;
    return true;
}

void printDraw() {
    printBoard();
    std::cout << "\nНичья! Зато с обидой бороться не надо" << std::endl;
}

void checkInequality(int chAuto, int ch) {
    if(b[chAuto - 1] == (char)('0' + ch) && b[chAuto - 1] == (char)('0' + chAuto)){
        b[chAuto - 1] = '0';
    } else
        checkInequality(chAuto, ch);
}

int main() {
    std::cout << "Добро пожаловать в Крестики-нолики! Выберите режим игры:" << std::endl;

    int a;
    // Объект класса "Игральная доска"
    Board TTTBoard;
    TTTBoard.makeTableCell();

    int ch = -1;
    int chAuto = -1;
    player = 'X';

    do {
        std::cout << "1. Играть с NPC\n" <<
                  "2. Играть вдвоем\n" <<
                  "0. Выйти из программы.\n" <<
                  "Выберите действие: ";
        std::cin >> a;
        switch(a) {
            case 1:
                while (ch != 0) {
                    printBoard();
                    std::cout << "\nИгрок " << player << ", н" << enterNumber;
                    std::cin >> ch;
                    if (ch > 0 && ch < 10) { // Если введенная цифра больше нуля и меньше десяти
                        if (b[ch - 1] == (char)('0' + ch)) { // Если ячейка еще не была использована,
                            b[ch - 1] = 'X'; // поставить в нее имя "живого" игрока

                            if (checkWin(player)) { // Если проверка выигрыша сработала,
                                printWin(player); // Вывести имя игрока
                                break;
                            }
                            if (checkDraw()) { // Если проверка заполненности возвращает true
                                printDraw(); // Выводится сообщение о ничьей
                                break;
                            }

                            //  Ход NPC
                            chAuto = rand () % 9+1; // Генерация случайного хода NPC
                            checkInequality(chAuto, ch);

                        }
                        else {
                            std::cout << "\n Эта ячейка занята. Н" << enterNumber << std::endl;
                            std::cin >> ch;
                        }
                    }

                    else if (ch != 0) {
                        std::cout << "\n Неверный выбор. Н" << enterNumber << std::endl;
                        std::cin >> ch;
                    }
                }

                std::cout << "\nСпасибо за игру!" << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cin.get();
                return EXIT_SUCCESS;
                break;

            case 2:
                while (ch != 0) {
                    printBoard();
                    std::cout << "\n Игрок " << player << ", н" << enterNumber;
                    std::cin >> ch;
                    if (ch > 0 && ch < 10) {
                        if (b[ch - 1] == (char)('0' + ch)) {
                            b[ch - 1] = player;
                            if (checkWin(player)) {
                                printWin(player);
                                break;
                            }
                            if (checkDraw()) {
                                printDraw();
                                break;
                            }
                            player = player == 'X' ? 'O' : 'X';
                        }
                        else {
                            std::cout << "\n Эта ячейка занята. Н" << enterNumber << std::endl;
                            std::cin >> ch;
                        }
                    }
                    else if (ch != 0) {
                        std::cout << "\n Неверный выбор. Н" << enterNumber << std::endl;
                        std::cin >> ch;
                    }
                }

                std::cout << "\nСпасибо за игру!" << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cin.get();
                return EXIT_SUCCESS;
                break;

            default:
                std::cout << "Ваш выбор:\n";
        }
    } while (a != '0');
    std::cout << "Выход из программы..." <<
              std::endl;
    return 0;
}

