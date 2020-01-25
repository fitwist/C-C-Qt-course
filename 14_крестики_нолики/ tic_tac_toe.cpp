#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string enterNumber = "Укажите клетку ";
std::string player = "Игрок ";
std::string won = " победил!";
std::string error = "Выберите доступную клетку: ";
std::string draw = "Это ничья!\n";
std::string divider = "-------------------------";

int main() {
    
    char board[3][3];

    board[0][0] = '1';
    board[0][1] = '2';
    board[0][2] = '3';
    board[1][0] = '4';
    board[1][1] = '5';
    board[1][2] = '6';
    board[2][0] = '7';
    board[2][1] = '8';
    board[2][2] = '9';

    bool PlayerHasWon = false;
    bool xPlayerFin = false;
    bool yPlayerFin = false;
    int turn_count = 2;
    char inputLoc = NULL;
    int amount_of_players = NULL;

    std::cout << "Количество игроков (1 или 2): ";
    std::cin >> amount_of_players;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "\t";
            std::cout << board[i][j] << "\t|";
        }
        std::cout << std::endl << divider 
        << std::endl;
    }

    if (amount_of_players == 2) {

        while (PlayerHasWon == false) {

            if (turn_count % 2 == 0) {
                xPlayerFin = false;

                while (xPlayerFin == false) {
                    std::cout << enterNumber 
                    << "X: ";
                    std::cin >> inputLoc;
                    std::cout << '\n\n';

                    if (inputLoc == '1' 
                        && board[0][0] != 'O' 
                        && board[0][0] != 'X') 
                    {
                        board[0][0] = 'X';
                        xPlayerFin = true;
                    }
                    else if (inputLoc == '2' 
                        && board[0][1] != 'O' 
                        && board[0][1] != 'X') 
                    {
                        board[0][1] = 'X';
                        xPlayerFin = true;
                    }
                    else if (inputLoc == '3' 
                        && board[0][2] != 'O' 
                        && board[0][2] != 'X') 
                    {
                        board[0][2] = 'X';
                        xPlayerFin = true;
                    }
                    else if (inputLoc == '4' 
                        && board[1][0] != 'O' 
                        && board[1][0] != 'X') 
                    {
                        board[1][0] = 'X';
                        xPlayerFin = true;
                    }
                    else if (inputLoc == '5' 
                        && board[1][1] != 'O' 
                        && board[1][1] != 'X') 
                    {
                        board[1][1] = 'X';
                        xPlayerFin = true;
                    }
                    else if (inputLoc == '6' 
                        && board[1][2] != 'O' 
                        && board[1][2] != 'X') 
                    {
                        board[1][2] = 'X';
                        xPlayerFin = true;
                    }
                    else if (inputLoc == '7' 
                        && board[2][0] != 'O' 
                        && board[2][0] != 'X') 
                    {
                        board[2][0] = 'X';
                        xPlayerFin = true;
                    }
                    else if (inputLoc == '8' 
                        && board[2][1] != 'O' 
                        && board[2][1] != 'X') 
                    {
                        board[2][1] = 'X';
                        xPlayerFin = true;
                    }
                    else if (inputLoc == '9' 
                        && board[2][2] != 'O' 
                        && board[2][2] != 'X') 
                    {
                        board[2][2] = 'X';
                        xPlayerFin = true;
                    }
                    else {
                        std::cerr << error;
                    }
                    turn_count++;
                }
            } else if (turn_count % 2 != 0) {
                yPlayerFin = false;

                while (yPlayerFin == false) {
                    std::cout << enterNumber 
                    << "O: ";
                    std::cin >> inputLoc;

                    if (inputLoc == '1' 
                        && board[0][0] != 'O' 
                        && board[0][0] != 'X') 
                    {
                        board[0][0] = 'O';
                        yPlayerFin = true;
                    }
                    else if (inputLoc == '2' 
                        && board[0][1] != 'O' 
                        && board[0][1] != 'X') 
                    {
                        board[0][1] = 'O';
                        yPlayerFin = true;
                    }
                    else if (inputLoc == '3' 
                        && board[0][2] != 'O' 
                        && board[0][2] != 'X') 
                    {
                        board[0][2] = 'O';
                        yPlayerFin = true;
                    }
                    else if (inputLoc == '4' 
                        && board[1][0] != 'O' 
                        && board[1][0] != 'X') 
                    {
                        board[1][0] = 'O';
                        yPlayerFin = true;
                    }
                    else if (inputLoc == '5' 
                        && board[1][1] != 'O' 
                        && board[1][1] != 'X') 
                    {
                        board[1][1] = 'O';
                        yPlayerFin = true;
                    }
                    else if (inputLoc == '6' 
                        && board[1][2] != 'O' 
                        && board[1][2] != 'X') 
                    {
                        board[1][2] = 'O';
                        yPlayerFin = true;
                    }
                    else if (inputLoc == '7' 
                        && board[2][0] != 'O' 
                        && board[2][0] != 'X') 
                    {
                        board[2][0] = 'O';
                        yPlayerFin = true;
                    }
                    else if (inputLoc == '8' 
                        && board[2][1] != 'O' 
                        && board[2][1] != 'X') 
                    {
                        board[2][1] = 'O';
                        yPlayerFin = true;
                    }
                    else if (inputLoc == '9' 
                        && board[2][2] != 'O' 
                        && board[2][2] != 'X') 
                    {
                        board[2][2] = 'O';
                        yPlayerFin = true;
                    }
                    else {
                        std::cerr << error;
                    }

                    turn_count++;
                }
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    std::cout << "\t";
                    std::cout << board[i][j] 
                    << "\t|";
                }
                std::cout << std::endl 
                << divider << std::endl;
            }

            if (board[0][0] == board[1][1] 
                && board[0][0] == board[2][2]) 
            {
                PlayerHasWon = true;
                std::cout << player 
                << board[0][0] << won;
            }
            else if (board[0][2] == board[1][1] 
                && board[0][2] == board[2][0]) 
            {
                PlayerHasWon = true;
                std::cout << player << board[0][2] 
                << won;
            }
            else if (board[1][0] == board[1][1] 
                && board[1][0] == board[1][2])
            {
                PlayerHasWon = true;
                std::cout << player 
                << board[1][0] << won;
            }
            else if (board[0][1] == board[1][1] 
                && board[0][1] == board[2][1]) 
                    {
                PlayerHasWon = true;
                std::cout << player 
                << board[0][1] << won;
            }
            else if (board[0][0] == board[0][1] 
                && board[0][0] == board[0][2]) 
            {
                PlayerHasWon = true;
                std::cout << player 
                << board[0][0] << won;
            }
            else if (board[2][0] == board[2][1] 
                && board[2][0] == board[2][2]) 
            {
                PlayerHasWon = true;
                std::cout << player 
                << board[2][0] << won;
            }
            else if (board[0][0] == board[1][0] 
                && board[0][0] == board[2][0]) 
            {
                PlayerHasWon = true;
                std::cout << player 
                << board[0][0] << won;
            }
            else if (board[0][2] == board[1][2] 
                && board[0][2] == board[2][2]) 
            {
                PlayerHasWon = true;
                std::cout << player 
                << board[0][2] << won;
            }
            else if (turn_count) {
                PlayerHasWon = true;
                std::cout << draw;
            }
        }
    }
    else if (amount_of_players == 1) {
        while (PlayerHasWon == false) {
                xPlayerFin = false;
                while (xPlayerFin == false) {
                    std::cout << enterNumber 
                    << "X: ";
                    std::cin >> inputLoc;

                    if (inputLoc == '1' 
                        && board[0][0] != 'O' 
                        && board[0][0] != 'X') 
                    {
                        board[0][0] = 'X';
                        xPlayerFin = true;
                    }
                    else if (inputLoc == '2' 
                    && board[0][1] != 'O' 
                        && board[0][1] != 'X') 
                    {
                        board[0][1] = 'X';
                        xPlayerFin = true;
                    }
                    else if (inputLoc == '3' 
                        && board[0][2] != 'O' 
                        && board[0][2] != 'X') 
                    {
                        board[0][2] = 'X';
                        xPlayerFin = true;
                    }
                    else if (inputLoc == '4' 
                        && board[1][0] != 'O' 
                        && board[1][0] != 'X') 
                    {
                        board[1][0] = 'X';
                        xPlayerFin = true;
                    }
                    else if (inputLoc == '5' 
                        && board[1][1] != 'O' 
                        && board[1][1] != 'X') 
                    {
                        board[1][1] = 'X';
                        xPlayerFin = true;
                    }
                    else if (inputLoc == '6' 
                        && board[1][2] != 'O' 
                        && board[1][2] != 'X') 
                    {
                        board[1][2] = 'X';
                        xPlayerFin = true;
                    }
                    else if (inputLoc == '7' 
                        && board[2][0] != 'O' 
                        && board[2][0] != 'X') 
                    {
                        board[2][0] = 'X';
                        xPlayerFin = true;
                    }
                    else if (inputLoc == '8' 
                        && board[2][1] != 'O' 
                        && board[2][1] != 'X') 
                    {
                        board[2][1] = 'X';
                        xPlayerFin = true;
                    }
                    else if (inputLoc == '9' 
                        && board[2][2] != 'O' 
                        && board[2][2] != 'X')
                    {
                        board[2][2] = 'X';
                        xPlayerFin = true;
                    }
                    else {
                        std::cerr << error;
                    }
                    turn_count++;
                }

                bool O_AI_Logic = false;
                while (O_AI_Logic == false) {
                    srand((unsigned int) time(NULL));
                    int Rand_X, Rand_Y;
                    Rand_X = rand() % 3;
                    Rand_Y = rand() % 3;
                    if (board[Rand_X][Rand_Y] != 'X' 
                        && board[Rand_X][Rand_Y] != 'O') 
                    {
                        board[Rand_X][Rand_Y] = 'O';
                        O_AI_Logic = true;
                    }
                }

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) 
                    {
                        std::cout << "\t";
                        std::cout << board[i][j] 
                        << "\t|";
                    }
                    std::cout << std::endl 
                    << "-------------------------------------------------" 
                    << std::endl;
                }

                if (board[0][0] == board[1][1] 
                    && board[0][0] == board[2][2]) {
                    PlayerHasWon = true;
                    std::cout << player 
                    << board[0][0] << won;
                }
                else if (board[0][2] == board[1][1] 
                    && board[0][2] == board[2][0]) {
                    PlayerHasWon = true;
                    std::cout << player << board[0][2] 
                    << won;
                }
                else if (board[1][0] == board[1][1] 
                    && board[1][0] == board[1][2]) {
                    PlayerHasWon = true;
                    std::cout << player << board[1][0] 
                    << won;
                }
                else if (board[0][1] == board[1][1] 
                    && board[0][1] == board[2][1]) {
                    PlayerHasWon = true;
                    std::cout << player << board[0][1] 
                    << won;
                }
                else if (board[0][0] == board[0][1] 
                    && board[0][0] == board[0][2]) {
                    PlayerHasWon = true;
                    std::cout << player << board[0][0] 
                    << won;
                }
                else if (board[2][0] == board[2][1] 
                    && board[2][0] == board[2][2]) {
                    PlayerHasWon = true;
                    std::cout << player << board[2][0] 
                    << won;
                }
                else if (board[0][0] == board[1][0] 
                    && board[0][0] == board[2][0]) {
                    PlayerHasWon = true;
                    std::cout << player << board[0][0] 
                    << won;
                }
                else if (board[0][2] == board[1][2] 
                    && board[0][2] == board[2][2]) {
                    PlayerHasWon = true;
                    std::cout << player << board[0][2] 
                    << won;
                }
                else if (turn_count > 10) {
                    PlayerHasWon = true;
                    std::cout << draw;
                }
            }
        }
    }
    