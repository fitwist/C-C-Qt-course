#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;
char board[10][10];
char boardPl2[10][10];
char boardAttack[10][10];
char boardPl2Attack[10][10];
void displayBoard (char gameboard[10][10]);
void initializeBoard();
void displayBoardPl2 (char gameboardPl2[10][10]);
void initializeBoardPl2();
void displayBoardAttack (char gameboardAttack[10][10]);
void initializeBoardAttack();
void displayBoardPl2Attack (char gameboardPl2Attack[10][10]);
void initializeBoardPl2Attack();
bool Pl1WinCheck();
bool Pl2WinCheck();
string player1;
string player2;

int main() {
    cout << "Введите имя первого игрока: ";
    cin >> player1;
    cout << "Введите имя второго игрока: ";
    cin >> player2;
    initializeBoard();
    displayBoard(board);
    char letAc1;
    while (true) {
        cout << player1 << ", введите первую букву координаты вашего пятипалубного авианосца (убедитесь, что координаты попадают на доску): ";
        cin >> letAc1;
        letAc1 = toupper(letAc1);
        if (letAc1 >= 'A' && letAc1 <= 'J')
            break;
    }
    int numAc1 = 0;
    while (numAc1 <= 0 || numAc1 >= 11) {
        cout << player1 << ", введите первое число координаты вашего пятипалубного авианосца (убедитесь, что координаты попадают на доску): ";
        cin >> numAc1;
    }
    char letAc2;
    while (true) {
        cout << player1 << ", введите вторую букву координаты вашего пятипалубного авианосца (убедитесь, что у него есть пять клеток пространства по горизонтали / вертикали): ";
        cin >> letAc2;
        letAc2 = toupper(letAc2);
        if (letAc2 >= 'A' && letAc2 <= 'J')
            break;
    }
    if (letAc1 != letAc2) {
        while (true) {
            if (letAc1 == letAc2)
                break;
            if (letAc2 == (letAc1+4))
                break;
            if (letAc2 == (letAc1-4))
                break;
            cout << player1 << " убедитесь, что рассчитали положение конечной координаты корабля верно (5) Введите вторую букву снова: ";
            cin >> letAc2;
            letAc2 = toupper(letAc2);
        }
    }
    int numAc2 = 0;
    while (numAc2 <= 0 || numAc2 >= 11) {
        cout << player1 << ", введите второе число координаты вашего пятипалубного авианосца (убедитесь, что у него есть пять клеток пространства по горизонтали / вертикали): ";
        cin >> numAc2;
    }
    while (true) {
        if (letAc1 == letAc2) {
            if (numAc2 == (numAc1+4))
                break;
            if (numAc2 == (numAc1-4) && (numAc2>0 || numAc2<11))
                break;
        }
        if (letAc1 != letAc2) {
            if (numAc1 == numAc2)
                break;
        }
        cout << player1 << " Убедитесь, что кораблю хватает места (5) Введите второе число снова: ";
        cin >> numAc2;
    }
    char Pos1 = 'A';
    char Pos2 = 'A';
    int letPos;
    int letPos2;
    letPos = letAc1-'A';
    letPos2 = letAc2-'A';
    board[letPos][numAc1-1] = Pos1;
    board[letPos2][numAc2-1] = Pos2;
    if (letAc1 == letAc2) {
        if (numAc1<numAc2) {
            for (int x = numAc1-1; x <= numAc2-1; x++)
                board[letPos][x] = 'A';
        }
        if (numAc2<numAc1) {
            for (int x = numAc2-1; x <= numAc1-1; x++)
                board[letPos][x] = 'A';
        }
    }
    if (numAc1 == numAc2) {
        if (letPos<letPos2) {
            for (int y = letPos; y <= letPos2; y++) {
                board[y][numAc1-1] = 'A';
            }
        }
        if (letPos2<letPos) {
            for (int y = letPos2; y <= letPos; y++) {
                board[y][numAc1-1] = 'A';
            }
        }
    }
    displayBoard(board);
    char letBs1;
    while (true) {
        cout << player1 << ", введите первую букву координаты вашего четырехпалубного боевого корабля (убедитесь, что координаты попадают на доску): ";
        cin >> letBs1;
        letBs1 = toupper(letBs1);
        if (letBs1 >= 'A' && letBs1 <= 'J')
            break;
    }
    int numBs1 = 0;
    while (numBs1 <= 0 || numBs1 >= 11) {
        cout << player1 << ", введите первое число координаты вашего четырехпалубного боевого корабля (убедитесь, что у корабля есть 4 клетки по горизонтали / вертикали): ";
        cin >> numBs1;
    }
    
loop:
    for (;;) {
        if (board[letBs1-'A'][numBs1-1] == 'O')
            break;
        for (;;) {
            cout << "Координата уже использована или находится вне игрового поля. Выберите другую: " << endl;
            cout << player1 << ", введите первую букву координаты вашего четырехпалубного боевого корабля (убедитесь, что координаты попадают на доску): ";
            cin >> letBs1;
            letBs1 = toupper(letBs1);
            if (letBs1 >= 'A' && letBs1 <= 'J')
                break;
        }
        for (;;) {
            cout << player1 << ", введите первое число координаты вашего четырехпалубного боевого корабля (убедитесь, что у корабля есть 4 клетки по горизонтали / вертикали): ";
            cin >> numBs1;
            if (numBs1 >= 1 && numBs1 <= 10)
                break;
        }
        if (board[letBs1-'A'][numBs1-1] == 'O')
            break;
        else
            goto loop;
    }
    char letBs2;
    while (true) {
        cout << player1 << ", введите вторую букву координаты вашего четырехпалубного боевого корабля (убедитесь, что координаты попадают на доску): ";
        cin >> letBs2;
        letBs2 = toupper(letBs2);
        if (letBs2 >= 'A' && letBs2 <= 'J')
            break;
    }
    if (letBs1 != letBs2) {
        if (letBs2 != letBs1) {
            while (true) {
                if (letBs1 == letBs2)
                    break;
                if (letBs2 == (letBs1+3))
                    break;
                if (letBs2 == (letBs1-3))
                    break;
                cout << player1 << ", введите вторую букву координаты вашего четырехпалубного боевого корабля (убедитесь, что координаты попадают на доску): ";
                cin >> letBs2;
                letBs2 = toupper(letBs2);
            }
        }
    }
    int numBs2 = 0;
    while (numBs2 <= 0 || numBs2 >= 11) {
        cout << player1 << ", введите второе число координаты вашего четырехпалубного боевого корабля (убедитесь, что у корабля есть 4 клетки по горизонтали / вертикали): ";
        cin >> numBs2;
    }
    
loop2:
    for (;;) {
        if (board[letBs2-'A'][numBs2-1] == 'O')
            break;
        for (;;) {
            cout << "Координата уже использована или находится вне игрового поля. Выберите другую: " << endl;
            cout << player1 << ", введите вторую букву координаты вашего четырехпалубного боевого корабля (убедитесь, что координаты попадают на доску): ";
            cin >> letBs2;
            letBs2 = toupper(letBs2);
            if (letBs2 >= 'A' && letBs2 <= 'J')
                break;
        }
        for (;;) {
            cout << player1 << ", введите второе число координаты вашего четырехпалубного боевого корабля (убедитесь, что у корабля есть 4 клетки по горизонтали / вертикали): ";
            cin >> numBs2;
            if (numBs2 >= 1 && numBs2 <= 10)
                break;
        }
        if (board[letBs2-'A'][numBs2-1] == 'O')
            break;
        else
            goto loop2;
    }
    while (true) {
        if (letBs1 == letBs2) {
            if (numBs2 == (numBs1+3))
                break;
            if (numBs2 == (numBs1-3) && (numBs2>0 || numBs2<11))
                break;
        }
        if (letBs1 != letBs2) {
            if (numBs1 == numBs2)
                break;
        }
        cout << player1 << " Убедитесь, что кораблю хватает места (4) Введите второе число снова: ";
        cin >> numBs2;
    }
    char Pos1a = 'B';
    char Pos2a = 'B';
    int letBsPos;
    int letBsPos2;
    letBsPos = letBs1-'A';
    letBsPos2 = letBs2-'A';
    board[letBsPos][numBs1-1] = Pos1a;
    board[letBsPos2][numBs2-1] = Pos2a;
    if (letBs1 == letBs2) {
        if (numBs1<numBs2) {
            for (int x1 = numBs1-1; x1 <= numBs2-1; x1++)
                board[letBsPos][x1] = 'B';
        }
        if (numBs2<numBs1) {
            for (int x1 = numBs2-1; x1 <= numBs1-1; x1++)
                board[letBsPos][x1] = 'B';
        }
    }
    if (numBs1 == numBs2) {
        if (letBsPos<letBsPos2) {
            for (int y1 = letBsPos; y1 <= letBsPos2; y1++) {
                board[y1][numBs1-1] = 'B';
            }
        }
        if (letBsPos2<letBsPos) {
            for (int y1 = letBsPos2; y1 <= letBsPos; y1++) {
                board[y1][numBs1-1] = 'B';
            }
        }
    }
    displayBoard(board);
    char letSm1;
    while (true) {
        cout << player1 << ", введите первую букву координаты вашей трехклеточной Субмарины (убедитесь, что координаты попадают на доску): ";
        cin >> letSm1;
        letSm1 = toupper(letSm1);
        if (letSm1 >= 'A' && letSm1 <= 'J')
            break;
    }
    int numSm1 = 0;
    while (numSm1 <= 0 || numSm1 >= 11) {
        cout << player1 << ", введите первое число координаты вашей трехклеточной Субмарины убедитесь, что кораблю хватает трех клеток по горизонтали / вертикали: ";
        cin >> numSm1;
    }
    
loop3:
    for (;;) {
        if (board[letSm1-'A'][numSm1-1] == 'O')
            break;
        for (;;) {
            cout << "Координата уже использована или находится вне игрового поля. Выберите другую: " << endl;
            cout << player1 << ", введите первую букву координаты вашей трехклеточной Субмарины (убедитесь, что координаты попадают на доску): ";
            cin >> letSm1;
            letSm1 = toupper(letSm1);
            if (letSm1 >= 'A' && letSm1 <= 'J')
                break;
        }
        for (;;) {
            cout << player1 << ", введите первое число координаты вашей трехклеточной Субмарины убедитесь, что кораблю хватает трех клеток по горизонтали / вертикали: ";
            cin >> numSm1;
            if (numSm1 >= 1 && numSm1 <= 10)
                break;
        }
        if (board[letSm1-'A'][numSm1-1] == 'O')
            break;
        else
            goto loop3;
    }
    char letSm2;
    while (true) {
        cout << player1 << ", введите вторую букву координаты вашей трехклеточной Субмарины (убедитесь, что координаты попадают на доску): ";
        cin >> letSm2;
        letSm2 = toupper(letSm2);
        if (letSm2 >= 'A' && letSm2 <= 'J')
            break;
    }
    if (letSm1 != letSm2) {
        while (true) {
            if (letSm1 == letSm2)
                break;
            if (letSm2 == (letSm1+2))
                break;
            if (letSm2 == (letSm1-2))
                break;
            cout << player1 << ", введите вторую букву координаты вашей трехклеточной Субмарины (убедитесь, что координаты попадают на доску): ";
            cin >> letSm2;
            letSm2 = toupper(letSm2);
        }
    }
    int numSm2 = 0;
    while (numSm2 <= 0 || numSm2 >= 11) {
        cout << player1 << ", введите второе число координаты вашей трехклеточной Субмарины убедитесь, что кораблю хватает трех клеток по горизонтали / вертикали: ";
        cin >> numSm2;
    }
    
loop4:
    for (;;) {
        if (board[letSm2-'A'][numSm2-1] == 'O')
            break;
        for (;;) {
            cout << "Координата уже использована или находится вне игрового поля. Выберите другую: " << endl;
            cout << player1 << ", введите вторую букву координаты вашей трехклеточной Субмарины (убедитесь, что координаты попадают на доску): ";
            cin >> letSm2;
            letSm2 = toupper(letSm2);
            if (letSm2 >= 'A' && letSm2 <= 'J')
                break;
        }
        for (;;) {
            cout << player1 << ", введите второе число координаты вашей трехклеточной Субмарины убедитесь, что кораблю хватает трех клеток по горизонтали / вертикали: ";
            cin >> numSm2;
            if (numSm2 >= 1 && numSm2 <= 10)
                break;
        }
        if (board[letSm2-'A'][numSm2-1] == 'O')
            break;
        else
            goto loop4;
    }
    while (true) {
        if (letSm1 == letSm2) {
            if (numSm2 == (numSm1+2))
                break;
            if (numSm2 == (numSm1-2) && (numSm2>0 || numSm2<11))
                break;
        }
        if (letSm1 != letSm2) {
            if (numSm1 == numSm2)
                break;
        }
        cout << player1 << " Убедитесь, что кораблю хватает места (3) Введите второе число снова: ";
        cin >> numSm2;
    }
    char Pos1b = 'S';
    char Pos2b = 'S';
    int letSmPos;
    int letSmPos2;
    letSmPos = letSm1-'A';
    letSmPos2 = letSm2-'A';
    board[letSmPos][numSm1-1] = Pos1b;
    board[letSmPos2][numSm2-1] = Pos2b;
    if (letSm1 == letSm2) {
        if (numSm1<numSm2) {
            for (int x2 = numSm1-1; x2 <= numSm2-1; x2++)
                board[letSmPos][x2] = 'S';
        }
        if (numSm2<numSm1) {
            for (int x2 = numSm2-1; x2 <= numSm1-1; x2++)
                board[letSmPos][x2] = 'S';
        }
    }
    if (numSm1 == numSm2) {
        if (letSmPos<letSmPos2) {
            for (int y2 = letSmPos; y2 <= letSmPos2; y2++) {
                board[y2][numSm1-1] = 'S';
            }
        }
        if (letSmPos2<letSmPos) {
            for (int y2 = letSmPos2; y2 <= letSmPos; y2++) {
                board[y2][numSm1-1] = 'S';
            }
        }
    }
    displayBoard(board);
    char letCr1;
    while (true) {
        cout << player1 << ", введите первую букву координаты вашего двухпалубного Крейсера (убедитесь, что координаты попадают на доску): ";
        cin >> letCr1;
        letCr1 = toupper(letCr1);
        if (letCr1 >= 'A' && letCr1 <= 'J')
            break;
    }
    int numCr1 = 0;
    while (numCr1 <= 0 || numCr1 >= 11) {
        cout << player1 << ", введите первое число координаты вашего двухпалубного Крейсера (убедитесь, что кораблю хватает трех клеток по горизонтали / вертикали: ";
        cin >> numCr1;
    }
    
loop5:
    for (;;) {
        if (board[letCr1-'A'][numCr1-1] == 'O')
            break;
        for (;;) {
            cout << "Координата уже использована или находится вне игрового поля. Выберите другую: " << endl;
            cout << player1 << ", введите первую букву координаты вашего двухпалубного Крейсера (убедитесь, что координаты попадают на доску): ";
            cin >> letCr1;
            letCr1 = toupper(letCr1);
            if (letCr1 >= 'A' && letCr1 <= 'J')
                break;
        }
        for (;;) {
            cout << player1 << ", введите первое число координаты вашего двухпалубного Крейсераубедитесь, что кораблю хватает трех клеток по горизонтали / вертикали: ";
            cin >> numCr1;
            if (numCr1 >= 1 && numCr1 <= 10)
                break;
        }
        if (board[letCr1-'A'][numCr1-1] == 'O')
            break;
        else
            goto loop5;
    }
    char letCr2;
    while (true) {
        cout << player1 << ", введите вторую букву координаты вашего двухпалубного Крейсера (убедитесь, что координаты попадают на доску): ";
        cin >> letCr2;
        letCr2 = toupper(letCr2);
        if (letCr2 >= 'A' && letCr2 <= 'J')
            break;
    }
    if (letCr1 != letCr2) {
        if (letCr2 != letCr1) {
            while (true) {
                if (letCr1 == letCr2)
                    break;
                if (letCr2 == (letCr1+2))
                    break;
                if (letCr2 == (letCr1-2))
                    break;
                cout << player1 << ", введите вторую букву координаты вашего двухпалубного Крейсера (убедитесь, что координаты попадают на доску): ";
                cin >> letCr2;
                letCr2 = toupper(letCr2);
            }
        }
    }
    int numCr2 = 0;
    while (numCr2 <= 0 || numCr2 >= 11) {
        cout << player1 << ", введите второе число координаты вашего двухпалубного Крейсера (убедитесь, что кораблю хватает трех клеток по горизонтали / вертикали): ";
        cin >> numCr2;
    }
    
loop6:
    for (;;) {
        if (board[letCr2-'A'][numCr2-1] == 'O')
            break;
        for (;;) {
            cout << "Координата уже использована или находится вне игрового поля. Выберите другую: " << endl;
            cout << player1 << ", введите вторую букву координаты вашего двухпалубного Крейсера (убедитесь, что координаты попадают на доску): ";
            cin >> letCr2;
            letCr2 = toupper(letCr2);
            if (letCr2 >= 'A' && letCr2 <= 'J')
                break;
        }
        for (;;) {
            cout << player1 << ", введите второе число координаты вашего двухпалубного Крейсера (убедитесь, что кораблю хватает трех клеток по горизонтали / вертикали): ";
            cin >> numCr2;
            if (numCr2 >= 1 && numCr2 <= 10)
                break;
        }
        if (board[letCr2-'A'][numCr2-1] == 'O')
            break;
        else
            goto loop6;
    }
    while (true) {
        if (letCr1 == letCr2) {
            if (numCr2 == (numCr1+2))
                break;
            if (numCr2 == (numCr1-2) && (numCr2>0 || numCr2<11))
                break;
        }
        if (letCr1 != letCr2) {
            if (numCr1 == numCr2)
                break;
        }
        cout << player1 << " Убедитесь, что кораблю хватает места (3) Введите второе число снова: ";
        cin >> numCr2;
    }
    char Pos1c= 'C';
    char Pos2c= 'C';
    int letCrPos;
    int letCrPos2;
    letCrPos = letCr1-'A';
    letCrPos2 = letCr2-'A';
    board[letCrPos][numCr1-1] = Pos1c;
    board[letCrPos2][numCr2-1] = Pos2c;
    if (letCr1 == letCr2) {
        if (numCr1<numCr2) {
            for (int x3= numCr1-1; x3 <= numCr2-1; x3++)
                board[letCrPos][x3] = 'C';
        }
        if (numCr2<numCr1) {
            for (int x3= numCr2-1; x3 <= numCr1-1; x3++)
                board[letCrPos][x3] = 'C';
        }
    }
    if (numCr1 == numCr2) {
        if (letCrPos<letCrPos2) {
            for (int y3= letCrPos; y3 <= letCrPos2; y3++) {
                board[y3][numCr1-1] = 'C';
            }
        }
        if (letCrPos2<letCrPos) {
            for (int y3= letCrPos2; y3 <= letCrPos; y3++) {
                board[y3][numCr1-1] = 'C';
            }
        }
    }
    displayBoard(board);
    char letDs1;
    while (true) {
        cout << player1 << ", введите первую букву координаты вашего однопалубного Разрушителя (убедитесь, что координаты попадают на доску): ";
        cin >> letDs1;
        letDs1 = toupper(letDs1);
        if (letDs1 >= 'A' && letDs1 <= 'J')
            break;
    }
    int numDs1 = 0;
    while (numDs1 <= 0 || numDs1 >= 11) {
        cout << player1 << ", введите первое число координаты вашего однопалубного Разрушителя (убедитесь, что кораблю хватает двух клеток по горизонтали / вертикали): ";
        cin >> numDs1;
    }
    
loop7:
    for (;;) {
        if (board[letDs1-'A'][numDs1-1] == 'O')
            break;
        for (;;) {
            cout << "Координата уже использована или находится вне игрового поля. Выберите другую: " << endl;
            cout << player1 << ", введите первую букву координаты вашего однопалубного Разрушителя (убедитесь, что координаты попадают на доску): ";
            cin >> letDs1;
            letDs1 = toupper(letDs1);
            if (letDs1 >= 'A' && letDs1 <= 'J')
                break;
        }
        for (;;) {
            cout << player1 << ", введите первое число координаты вашего однопалубного Разрушителя (убедитесь, что кораблю хватает двух клеток по горизонтали / вертикали): ";
            cin >> numDs1;
            if (numDs1 >= 1 && numDs1 <= 10)
                break;
        }
        if (board[letDs1-'A'][numDs1-1] == 'O')
            break;
        else
            goto loop7;
    }
    char letDs2;
    while (true) {
        cout << player1 << ", введите вторую букву координаты вашего однопалубного Разрушителя (убедитесь, что координаты попадают на доску): ";
        cin >> letDs2;
        letDs2 = toupper(letDs2);
        if (letDs2 >= 'A' && letDs2 <= 'J')
            break;
    }
    if (letDs1 != letDs2) {
        while (true) {
            if (letDs1 == letDs2)
                break;
            if (letDs2 == (letDs1+1))
                break;
            if (letDs2 == (letDs1-1))
                break;
            cout << player1 << ", введите вторую букву координаты вашего однопалубного Разрушителя (убедитесь, что координаты попадают на доску): ";
            cin >> letDs2;
            letDs2 = toupper(letDs2);
        }
    }
    int numDs2 = 0;
    while (numDs2 <= 0 || numDs2 >= 11) {
        cout << player1 << ", введите второе число координаты вашего однопалубного Разрушителя (убедитесь, что кораблю хватает двух клеток по горизонтали / вертикали): ";
        cin >> numDs2;
    }
    
loop8:
    for (;;) {
        if (board[letDs2-'A'][numDs2-1] == 'O')
            break;
        for (;;) {
            cout << "Координата уже использована или находится вне игрового поля. Выберите другую: " << endl;
            cout << player1 << ", введите вторую букву координаты вашего однопалубного Разрушителя (убедитесь, что координаты попадают на доску): ";
            cin >> letDs2;
            letDs2 = toupper(letDs2);
            if (letDs2 >= 'A' && letDs2 <= 'J')
                break;
        }
        for (;;) {
            cout << player1 << ", введите второе число координаты вашего однопалубного Разрушителя (убедитесь, что кораблю хватает двух клеток по горизонтали / вертикали): ";
            cin >> numDs2;
            if (numDs2 >= 1 && numDs2 <= 10)
                break;
        }
        if (board[letDs2-'A'][numDs2-1] == 'O')
            break;
        else
            goto loop8;
    }
    while (true) {
        if (letDs1 == letDs2) {
            if (numDs2 == (numDs1+1))
                break;
            if (numDs2 == (numDs1-1) && (numDs2>0 || numDs2<11))
                break;
        }
        if (letDs1 != letDs2) {
            if (numDs1 == numDs2)
                break;
        }
        cout << player1 << " Убедитесь, что кораблю хватает места (2) Введите второе число снова: ";
        cin >> numDs2;
    }
    char Pos1d= 'D';
    char Pos2d= 'D';
    int letDsPos;
    int letDsPos2;
    letDsPos = letDs1-'A';
    letDsPos2 = letDs2-'A';
    board[letDsPos][numDs1-1] = Pos1d;
    board[letDsPos2][numDs2-1] = Pos2d;
    if (letDs1 == letDs2) {
        if (numDs1<numDs2) {
            for (int x4 = numDs1-1; x4 <= numDs2-1; x4++)
                board[letDsPos][x4] = 'D';
        }
        if (numDs2<numDs1) {
            for (int x4 = numDs2-1; x4 <= numDs1-1; x4++)
                board[letDsPos][x4] = 'D';
        }
    }
    if (numDs1 == numDs2) {
        if (letDsPos<letDsPos2) {
            for (int y4 = letDsPos; y4 <= letDsPos2; y4++) {
                board[y4][numDs1-1] = 'D';
            }
        }
        if (letDsPos2<letDsPos) {
            for (int y4 = letDsPos2; y4 <= letDsPos; y4++) {
                board[y4][numDs1-1] = 'D';
            }
        }
    }
    displayBoard(board);
    cout << "Это Ваша игральная доска";
    cout << "Сейчас очередь второго игрока расположить корабли. Первый игрок, пожалуйста, отвернитесь. Введите любой символ, чтобы продолжить: " << endl;
    char input;
    cin >> input;
    initializeBoardPl2();
    displayBoardPl2(boardPl2);
    char Pl2letAc1;
    while (true) {
        cout << player2 << ", введите первую букву координаты вашего пятипалубного авианосца (убедитесь, что координаты попадают на доску): ";
        cin >> Pl2letAc1;
        Pl2letAc1 = toupper(Pl2letAc1);
        if (Pl2letAc1 >= 'A' && Pl2letAc1 <= 'J')
            break;
    }
    int Pl2numAc1 = 0;
    while (Pl2numAc1 <= 0 || Pl2numAc1 >= 11) {
        cout << player2 << ", введите первое число координаты вашего пятипалубного авианосца(убедитесь, что у него есть пять клеток пространства по горизонтали / вертикали): ";
        cin >> Pl2numAc1;
    }
    
loop9:
    for (;;) {
        if (boardPl2[Pl2letAc1-'A'][Pl2numAc1-1] == 'O')
            break;
        for (;;) {
            cout << "Координата уже использована или находится вне игрового поля. Выберите другую: " << endl;
            cout << player2 << ", введите первую букву координаты вашего пятипалубного авианосца (убедитесь, что координаты попадают на доску): ";
            cin >> Pl2letAc1;
            Pl2letAc1 = toupper(Pl2letAc1);
            if (Pl2letAc1 >= 'A' && Pl2letAc1 <= 'J')
                break;
        }
        for (;;) {
            cout << player2 << ", введите первое число координаты вашего пятипалубного авианосца(убедитесь, что у него есть пять клеток пространства по горизонтали / вертикали): ";
            cin >> Pl2numAc1;
            if (Pl2numAc1 >= 1 && Pl2numAc1 <= 10)
                break;
        }
        if (boardPl2[Pl2letAc1-'A'][Pl2numAc1-1] == 'O')
            break;
        else
            goto loop9;
    }
    char Pl2letAc2;
    while (true) {
        cout << player2 << ", введите вторую букву координаты вашего пятипалубного авианосца (убедитесь, что координаты попадают на доску): ";
        cin >> Pl2letAc2;
        Pl2letAc2 = toupper(Pl2letAc2);
        if (Pl2letAc2 >= 'A' && Pl2letAc2 <= 'J')
            break;
    }
    if (Pl2letAc1 != Pl2letAc2) {
        while (true) {
            if (Pl2letAc1 == Pl2letAc2)
                break;
            if (Pl2letAc2 == (Pl2letAc1+4))
                break;
            if (Pl2letAc2 == (Pl2letAc1-4))
                break;
            cout << player2 << ", введите вторую букву координаты вашего пятипалубного авианосца (убедитесь, что координаты попадают на доску): ";
            cin >> Pl2letAc2;
            Pl2letAc2 = toupper(Pl2letAc2);
        }
    }
    int Pl2numAc2 = 0;
    while (Pl2numAc2 <= 0 || Pl2numAc2 >= 11) {
        cout << player2 << ", введите второе число координаты вашего пятипалубного авианосца(убедитесь, что у него есть пять клеток пространства по горизонтали / вертикали): ";
        cin >> Pl2numAc2;
    }
    
loop10:
    for (;;) {
        if (boardPl2[Pl2letAc2-'A'][Pl2numAc2-1] == 'O')
            break;
        for (;;) {
            cout << "Координата уже использована или находится вне игрового поля. Выберите другую: " << endl;
            cout << player2 << ", введите вторую букву координаты вашего пятипалубного авианосца (убедитесь, что координаты попадают на доску): ";
            cin >> Pl2letAc2;
            Pl2letAc2 = toupper(Pl2letAc2);
            if (Pl2letAc2 >= 'A' && Pl2letAc2 <= 'J')
                break;
        }
        for (;;) {
            cout << player2 << ", введите второе число координаты вашего пятипалубного авианосца (убедитесь, что у него есть пять клеток пространства по горизонтали / вертикали): ";
            cin >> Pl2numAc2;
            if (Pl2numAc2 >= 1 && Pl2numAc2 <= 10)
                break;
        }
        if (boardPl2[Pl2letAc2-'A'][Pl2numAc2-1] == 'O')
            break;
        else
            goto loop10;
    }
    while (true) {
        if (Pl2letAc1 == Pl2letAc2) {
            if (Pl2numAc2 == (Pl2numAc1+4))
                break;
            if (Pl2numAc2 == (Pl2numAc1-4) && (Pl2numAc2>0 || Pl2numAc2<11))
                break;
        }
        if (Pl2letAc1 != Pl2letAc2) {
            if (Pl2numAc1 == Pl2numAc2)
                break;
        }
        cout << player2 << " Убедитесь, что кораблю хватает места (5) Введите второе число снова: ";
        cin >> Pl2numAc2;
    }
    char Pl2Pos1 = 'A';
    char Pl2Pos2 = 'A';
    int Pl2letPos;
    int Pl2letPos2;
    Pl2letPos = Pl2letAc1-'A';
    Pl2letPos2 = Pl2letAc2-'A';
    boardPl2[Pl2letPos][Pl2numAc1-1] = Pl2Pos1;
    boardPl2[Pl2letPos2][Pl2numAc2-1] = Pl2Pos2;
    if (Pl2letAc1 == Pl2letAc2) {
        if (Pl2numAc1<Pl2numAc2) {
            for (int Pl2x= Pl2numAc1-1; Pl2x <= Pl2numAc2-1; Pl2x++)
                boardPl2[Pl2letPos][Pl2x] = 'A';
        }
        if (Pl2numAc2<Pl2numAc1) {
            for (int Pl2x= Pl2numAc2-1; Pl2x <= Pl2numAc1-1; Pl2x++)
                boardPl2[Pl2letPos][Pl2x] = 'A';
        }
    }
    if (Pl2numAc1 == Pl2numAc2) {
        if (Pl2letPos<Pl2letPos2) {
            for (int Pl2y= Pl2letPos; Pl2y <= Pl2letPos2; Pl2y++) {
                boardPl2[Pl2y][Pl2numAc1-1] = 'A';
            }
        }
        if (Pl2letPos2<Pl2letPos) {
            for (int Pl2y= Pl2letPos2; Pl2y <= Pl2letPos; Pl2y++) {
                boardPl2[Pl2y][Pl2numAc1-1] = 'A';
            }
        }
    }
    displayBoardPl2(boardPl2);
    char Pl2letBs1;
    while (true) {
        cout << player2 << ", введите первую букву координаты вашего четырехпалубного боевого корабля (убедитесь, что координаты попадают на доску): ";
        cin >> Pl2letBs1;
        Pl2letBs1 = toupper(Pl2letBs1); {
            if (Pl2letBs1 >= 'A' && Pl2letBs1 <= 'J')
                break;
        }
    }
    int Pl2numBs1 = 0;
    while (Pl2numBs1 <= 0 || Pl2numBs1 >= 11) {
        cout << player2 << ", введите первое число координаты вашего четырехпалубного боевого корабля (убедитесь, что у корабля есть 4 клетки по горизонтали / вертикали): ";
        cin >> Pl2numBs1;
    }
    
loop11:
    for (;;) {
        if (boardPl2[Pl2letBs1-'A'][Pl2numBs1-1] == 'O')
            break;
        for (;;) {
            cout << "Координата уже использована или находится вне игрового поля. Выберите другую: " << endl;
            cout << player2 << ", введите первую букву координаты вашего четырехпалубного боевого корабля (убедитесь, что координаты попадают на доску): ";
            cin >> Pl2letBs1;
            Pl2letBs1 = toupper(Pl2letBs1);
            if (Pl2letBs1 >= 'A' && Pl2letBs1 <= 'J')
                break;
        }
        for (;;) {
            cout << player2 << ", введите первое число координаты вашего четырехпалубного боевого корабля (убедитесь, что у корабля есть 4 клетки по горизонтали / вертикали): ";
            cin >> Pl2numBs1;
            if (Pl2numBs1 >= 1 && Pl2numBs1 <= 10)
                break;
        }
        if (boardPl2[Pl2letBs1-'A'][Pl2numBs1-1] == 'O')
            break;
        else
            goto loop11;
    }
    char Pl2letBs2;
    while (true) {
        cout << player2 << ", введите вторую букву координаты вашего четырехпалубного боевого корабля (убедитесь, что координаты попадают на доску): ";
        cin >> Pl2letBs2;
        Pl2letBs2 = toupper(Pl2letBs2);
        if (Pl2letBs2 >= 'A' && Pl2letBs2 <= 'J')
            break;
    }
    if (Pl2letBs1 != Pl2letBs2) {
        while (true) {
            if (Pl2letBs1 == Pl2letBs2)
                break;
            if (Pl2letBs2 == (Pl2letBs1+3))
                break;
            if (Pl2letBs2 == (Pl2letBs1-3))
                break;
            cout << player2 << ", введите вторую букву координаты вашего четырехпалубного боевого корабля (убедитесь, что координаты попадают на доску): ";
            cin >> Pl2letBs2;
            Pl2letBs2 = toupper(Pl2letBs2);
        }
    }
    int Pl2numBs2 = 0;
    while (Pl2numBs2 <= 0 || Pl2numBs2 >= 11) {
        cout << player2 << ", введите второе число координаты вашего четырехпалубного боевого корабля (убедитесь, что у корабля есть 4 клетки по горизонтали / вертикали): ";
        cin >> Pl2numBs2;
    }
    
loop12:
    for (;;) {
        if (boardPl2[Pl2letBs2-'A'][Pl2numBs2-1] == 'O')
            break;
        for (;;) {
            cout << "Координата уже использована или находится вне игрового поля. Выберите другую: " << endl;
            cout << player2 << ", введите вторую букву координаты вашего четырехпалубного боевого корабля (убедитесь, что координаты попадают на доску): ";
            cin >> Pl2letBs2;
            Pl2letBs2 = toupper(Pl2letBs2);
            if (Pl2letBs2 >= 'A' && Pl2letBs2 <= 'J')
                break;
        }
        for (;;) {
            cout << player2 << ", введите второе число координаты вашего четырехпалубного боевого корабля (убедитесь, что у корабля есть 4 клетки по горизонтали / вертикали): ";
            cin >> Pl2numBs2;
            if (Pl2numBs2 >= 1 && Pl2numBs2 <= 10)
                break;
        }
        if (boardPl2[Pl2letBs2-'A'][Pl2numBs2-1] == 'O')
            break;
        else
            goto loop12;
    }
    while (true) {
        if (Pl2letBs1 == Pl2letBs2) {
            if (Pl2numBs2 == (Pl2numBs1+3))
                break;
            if (Pl2numBs2 == (Pl2numBs1-3) && (Pl2numBs2>0 || Pl2numBs2<11))
                break;
        }
        if (Pl2letBs1 != Pl2letBs2) {
            if (Pl2numBs1 == Pl2numBs2)
                break;
        }
        cout << player2 << " Убедитесь, что кораблю хватает места (4) Введите второе число снова: ";
        cin >> Pl2numBs2;
    }
    char Pl2Pos1a = 'B';
    char Pl2Pos2a = 'B';
    int Pl2letBsPos;
    int Pl2letBsPos2;
    Pl2letBsPos = Pl2letBs1-'A';
    Pl2letBsPos2 = Pl2letBs2-'A';
    boardPl2[Pl2letBsPos][Pl2numBs1-1] = Pl2Pos1a;
    boardPl2[Pl2letBsPos2][Pl2numBs2-1] = Pl2Pos2a;
    if (Pl2letBs1 == Pl2letBs2) {
        if (Pl2numBs1<Pl2numBs2) {
            for (int Pl2x1 = Pl2numBs1-1; Pl2x1 <= Pl2numBs2-1; Pl2x1++)
                boardPl2[Pl2letBsPos][Pl2x1] = 'B';
        }
        if (Pl2numBs2<Pl2numBs1) {
            for (int Pl2x1 = Pl2numBs2-1; Pl2x1 <= Pl2numBs1-1; Pl2x1++)
                boardPl2[Pl2letBsPos][Pl2x1] = 'B';
        }
    }
    if (Pl2numBs1 == Pl2numBs2) {
        if (Pl2letBsPos<Pl2letBsPos2) {
            for (int Pl2y1 = Pl2letBsPos; Pl2y1 <= Pl2letBsPos2; Pl2y1++) {
                boardPl2[Pl2y1][Pl2numBs1-1] = 'B';
            }
        }
        if (Pl2letBsPos2<Pl2letBsPos) {
            for (int Pl2y1 = Pl2letBsPos2; Pl2y1 <= Pl2letBsPos; Pl2y1++) {
                boardPl2[Pl2y1][Pl2numBs1-1] = 'B';
            }
        }
    }
    displayBoardPl2(boardPl2);
    char Pl2letSm1;
    while (true) {
        cout << player2 << ", введите первую букву координаты вашей трехклеточной Субмарины (убедитесь, что координаты попадают на доску): ";
        cin >> Pl2letSm1;
        Pl2letSm1 = toupper(Pl2letSm1); {
            if (Pl2letSm1 >= 'A' && Pl2letSm1 <= 'J')
                break;
        }
    }
    int Pl2numSm1 = 0;
    while (Pl2numSm1 <= 0 || Pl2numSm1 >= 11) {
        cout << player2 << ", введите первое число координаты вашей трехклеточной Субмарины (убедитесь, что кораблю хватает трех клеток по горизонтали / вертикали: ";
        cin >> Pl2numSm1;
    }
    
loop13:
    for (;;) {
        if (boardPl2[Pl2letSm1-'A'][Pl2numSm1-1] == 'O')
            break;
        for (;;) {
            cout << "Координата уже использована или находится вне игрового поля. Выберите другую: " << endl;
            cout << player2 << ", введите первую букву координаты вашей трехклеточной Субмарины (убедитесь, что координаты попадают на доску): ";
            cin >> Pl2letSm1;
            Pl2letSm1 = toupper(Pl2letSm1);
            if (Pl2letSm1 >= 'A' && Pl2letSm1 <= 'J')
                break;
        }
        for (;;) {
            cout << player2 << ", введите первое число координаты вашей трехклеточной Субмарины (убедитесь, что кораблю хватает трех клеток по горизонтали / вертикали: ";
            cin >> Pl2numSm1;
            if (Pl2numSm1 >= 1 && Pl2numSm1 <= 10)
                break;
        }
        if (boardPl2[Pl2letSm1-'A'][Pl2numSm1-1] == 'O')
            break;
        else
            goto loop13;
    }
    char Pl2letSm2;
    while (true) {
        cout << player2 << ", введите вторую букву координаты вашей трехклеточной Субмарины (убедитесь, что координаты попадают на доску): ";
        cin >> Pl2letSm2;
        Pl2letSm2 = toupper(Pl2letSm2);
        if (Pl2letSm2 >= 'A' && Pl2letSm2 <= 'J')
            break;
    }
    if (Pl2letSm1 != Pl2letSm2) {
        while (true) {
            if (Pl2letSm1 == Pl2letSm2)
                break;
            if (Pl2letSm2 == (Pl2letSm1+2))
                break;
            if (Pl2letSm2 == (Pl2letSm1-2))
                break;
            cout << player2 << ", введите вторую букву координаты вашей трехклеточной Субмарины (убедитесь, что координаты попадают на доску): ";
            cin >> Pl2letSm2;
            Pl2letSm2 = toupper(Pl2letSm2);
        }
    }
    int Pl2numSm2 = 0;
    while (Pl2numSm2 <= 0 || Pl2numSm2 >= 11) {
        cout << player2 << ", введите второе число координаты вашей трехклеточной Субмарины (убедитесь, что кораблю хватает трех клеток по горизонтали / вертикали): ";
        cin >> Pl2numSm2;
    }
    
loop14:
    for (;;) {
        if (boardPl2[Pl2letSm2-'A'][Pl2numSm2-1] == 'O')
            break;
        for (;;) {
            cout << "Координата уже использована или находится вне игрового поля. Выберите другую: " << endl;
            cout << player2 << ", введите вторую букву координаты вашей трехклеточной Субмарины (убедитесь, что координаты попадают на доску): ";
            cin >> Pl2letSm2;
            Pl2letSm2 = toupper(Pl2letSm2);
            if (Pl2letSm2 >= 'A' && Pl2letSm2 <= 'J')
                break;
        }
        for (;;) {
            cout << player2 << ", введите второе число координаты вашей трехклеточной Субмарины (убедитесь, что кораблю хватает трех клеток по горизонтали / вертикали): ";
            cin >> Pl2numSm2;
            if (Pl2numSm2 >= 1 && Pl2numSm2 <= 10)
                break;
        }
        if (boardPl2[Pl2letSm2-'A'][Pl2numSm2-1] == 'O')
            break;
        else
            goto loop14;
    }
    while (true) {
        if (Pl2letSm1 == Pl2letSm2) {
            if (Pl2numSm2 == (Pl2numSm1+2))
                break;
            if (Pl2numSm2 == (Pl2numSm1-2) && (Pl2numSm2>0 || Pl2numSm2<11))
                break;
        }
        if (Pl2letSm1 != Pl2letSm2) {
            if (Pl2numSm1 == Pl2numSm2)
                break;
        }
        cout << player2 << " Убедитесь, что кораблю хватает места (3) Введите второе число снова: ";
        cin >> Pl2numSm2;
    }
    char Pl2Pos1b= 'S';
    char Pl2Pos2b= 'S';
    int Pl2letSmPos;
    int Pl2letSmPos2;
    Pl2letSmPos = Pl2letSm1-'A';
    Pl2letSmPos2 = Pl2letSm2-'A';
    boardPl2[Pl2letSmPos][Pl2numSm1-1] = Pl2Pos1b;
    boardPl2[Pl2letSmPos2][Pl2numSm2-1] = Pl2Pos2b;
    if (Pl2letSm1 == Pl2letSm2) {
        if (Pl2numSm1<Pl2numSm2) {
            for (int Pl2x2 = Pl2numSm1-1; Pl2x2 <= Pl2numSm2-1; Pl2x2++)
                boardPl2[Pl2letSmPos][Pl2x2] = 'S';
        }
        if (Pl2numSm2<Pl2numSm1) {
            for (int Pl2x2 = Pl2numSm2-1; Pl2x2 <= Pl2numSm1-1; Pl2x2++)
                boardPl2[Pl2letSmPos][Pl2x2] = 'S';
        }
    }
    if (Pl2numSm1 == Pl2numSm2) {
        if (Pl2letSmPos<Pl2letSmPos2) {
            for (int Pl2y2 = Pl2letSmPos; Pl2y2 <= Pl2letSmPos2; Pl2y2++) {
                boardPl2[Pl2y2][Pl2numSm1-1] = 'S';
            }
        }
        if (Pl2letSmPos2<Pl2letSmPos) {
            for (int Pl2y2 = letSmPos2; Pl2y2 <= Pl2letSmPos; Pl2y2++) {
                boardPl2[Pl2y2][Pl2numSm1-1] = 'S';
            }
        }
    }
    displayBoardPl2(boardPl2);
    char Pl2letCr1;
    while (true) {
        cout << player2 << ", введите первую букву координаты вашего двухпалубного Крейсера (убедитесь, что координаты попадают на доску): ";
        cin >> Pl2letCr1;
        Pl2letCr1 = toupper(Pl2letCr1);
        if (Pl2letCr1 >= 'A' && Pl2letCr1 <= 'J')
            break;
    }
    int Pl2numCr1 = 0;
    while (Pl2numCr1 <= 0 || Pl2numCr1 >= 11) {
        cout << player2 << ", введите первое число координаты вашего двухпалубного Крейсера (убедитесь, что кораблю хватает трех клеток по горизонтали / вертикали): ";
        cin >> Pl2numCr1;
    }
    
loop15:
    for (;;) {
        if (boardPl2[Pl2letCr1-'A'][Pl2numCr1-1] == 'O')
            break;
        for (;;) {
            cout << "Координата уже использована или находится вне игрового поля. Выберите другую: " << endl;
            cout << player2 << ", введите первую букву координаты вашего двухпалубного Крейсера (убедитесь, что координаты попадают на доску): ";
            cin >> Pl2letCr1;
            Pl2letCr1 = toupper(Pl2letCr1);
            if (Pl2letCr1 >= 'A' && Pl2letCr1 <= 'J')
                break;
        }
        for (;;) {
            cout << player2 << ", введите первое число координаты вашего двухпалубного Крейсера (убедитесь, что кораблю хватает трех клеток по горизонтали / вертикали): ";
            cin >> Pl2numCr1;
            if (Pl2numCr1 >= 1 && Pl2numCr1 <= 10)
                break;
        }
        if (boardPl2[Pl2letCr1-'A'][Pl2numCr1-1] == 'O')
            break;
        else
            goto loop15;
    }
    char Pl2letCr2;
    while (true) {
        cout << player2 << ", введите вторую букву координаты вашего двухпалубного Крейсера (убедитесь, что координаты попадают на доску): ";
        cin >> Pl2letCr2;
        Pl2letCr2 = toupper(Pl2letCr2);
        if (Pl2letCr2 >= 'A' && Pl2letCr2 <= 'J')
            break;
    }
    if (Pl2letCr1 != Pl2letCr2) {
        while (true) {
            if (Pl2letCr1 == Pl2letCr2)
                break;
            if (Pl2letCr2 == (Pl2letCr1+2))
                break;
            if (Pl2letCr2 == (Pl2letCr1-2))
                break;
            cout << player1 << ", введите вторую букву координаты вашего двухпалубного Крейсера (убедитесь, что координаты попадают на доску): ";
            cin >> Pl2letCr2;
            Pl2letCr2 = toupper(Pl2letCr2);
        }
    }
    int Pl2numCr2 = 0;
    while (Pl2numCr2 <= 0 || Pl2numCr2 >= 11) {
        cout << player2 << ", введите второе число координаты вашего двухпалубного Крейсера (убедитесь, что кораблю хватает трех клеток по горизонтали / вертикали): ";
        cin >> Pl2numCr2;
    }
    
loop16:
    for (;;) {
        if (boardPl2[Pl2letCr2-'A'][Pl2numCr2-1] == 'O')
            break;
        for (;;) {
            cout << "Координата уже использована или находится вне игрового поля. Выберите другую: " << endl;
            cout << player2 << ", введите вторую букву координаты вашего двухпалубного Крейсера (убедитесь, что координаты попадают на доску): ";
            cin >> Pl2letCr2;
            Pl2letCr2 = toupper(Pl2letCr2);
            if (Pl2letCr2 >= 'A' && Pl2letCr2 <= 'J')
                break;
        }
        for (;;) {
            cout << player2 << ", введите второе число координаты вашего двухпалубного Крейсера (убедитесь, что кораблю хватает трех клеток по горизонтали / вертикали): ";
            cin >> Pl2numCr2;
            if (Pl2numCr2 >= 1 && Pl2numCr2 <= 10)
                break;
        }
        if (boardPl2[Pl2letCr2-'A'][Pl2numCr2-1] == 'O')
            break;
        else
            goto loop16;
    }
    while (true) {
        if (Pl2letCr1 == Pl2letCr2) {
            if (Pl2numCr2 == (Pl2numCr1+2))
                break;
            if (Pl2numCr2 == (Pl2numCr1-2) && (Pl2numCr2>0 || Pl2numCr2<11))
                break;
        }
        if (Pl2letCr1 != Pl2letCr2) {
            if (Pl2numCr1 == Pl2numCr2)
                break;
        }
        cout << player2 << " Убедитесь, что кораблю хватает места (3) Введите второе число снова: ";
        cin >> Pl2numCr2;
    }
    char Pl2Pos1c= 'C';
    char Pl2Pos2c= 'C';
    int Pl2letCrPos;
    int Pl2letCrPos2;
    Pl2letCrPos = Pl2letCr1-'A';
    Pl2letCrPos2 = Pl2letCr2-'A';
    boardPl2[Pl2letCrPos][Pl2numCr1-1] = Pl2Pos1c;
    boardPl2[Pl2letCrPos2][Pl2numCr2-1] = Pl2Pos2c;
    if (Pl2letCr1 == Pl2letCr2) {
        if (Pl2numCr1<Pl2numCr2) {
            for (int Pl2x3= Pl2numCr1-1; Pl2x3 <= Pl2numCr2-1; Pl2x3++)
                boardPl2[Pl2letCrPos][Pl2x3] = 'C';
        }
        if (Pl2numCr2<Pl2numCr1) {
            for (int Pl2x3= Pl2numCr2-1; Pl2x3 <= Pl2numCr1-1; Pl2x3++)
                boardPl2[Pl2letCrPos][Pl2x3] = 'C';
        }
    }
    if (Pl2numCr1 == Pl2numCr2) {
        if (Pl2letCrPos<Pl2letCrPos2) {
            for (int Pl2y3= Pl2letCrPos; Pl2y3 <= Pl2letCrPos2; Pl2y3++) {
                boardPl2[Pl2y3][Pl2numCr1-1] = 'C';
            }
        }
        if (Pl2letCrPos2<Pl2letCrPos) {
            for (int Pl2y3= Pl2letCrPos2; Pl2y3 <= Pl2letCrPos; Pl2y3++) {
                board[Pl2y3][Pl2numCr1-1] = 'C';
            }
        }
    }
    displayBoardPl2(boardPl2);
    char Pl2letDs1;
    while (true) {
        cout << player2 << ", введите первую букву координаты вашего однопалубного Разрушителя (убедитесь, что координаты попадают на доску): ";
        cin >> Pl2letDs1;
        Pl2letDs1 = toupper(Pl2letDs1);
        if (Pl2letDs1 >= 'A' && Pl2letDs1 <= 'J')
            break;
    }
    int Pl2numDs1 = 0;
    while (Pl2numDs1 <= 0 || Pl2numDs1 >= 11) {
        cout << player2 << ", введите первое число координаты вашего однопалубного Разрушителя (убедитесь, что кораблю хватает двух клеток по горизонтали / вертикали): ";
        cin >> Pl2numDs1;
    }
    
loop17:
    for (;;) {
        if (boardPl2[Pl2letDs1-'A'][Pl2numDs1-1] == 'O')
            break;
        for (;;) {
            cout << "Координата уже использована или находится вне игрового поля. Выберите другую: " << endl;
            cout << player2 << ", введите первую букву координаты вашего однопалубного Разрушителя (убедитесь, что координаты попадают на доску): ";
            cin >> Pl2letDs1;
            Pl2letDs1 = toupper(Pl2letDs1);
            if (Pl2letDs1 >= 'A' && Pl2letDs1 <= 'J')
                break;
        }
        for (;;) {
            cout << player2 << ", введите первое число координаты вашего однопалубного Разрушителя (убедитесь, что кораблю хватает двух клеток по горизонтали / вертикали): ";
            cin >> Pl2numDs1;
            if (Pl2numDs1 >= 1 && Pl2numDs1 <= 10)
                break;
        }
        if (boardPl2[Pl2letDs1-'A'][Pl2numDs1-1] == 'O')
            break;
        else
            goto loop17;
    }
    char Pl2letDs2;
    while (true) {
        cout << player2 << ", введите вторую букву координаты вашего однопалубного Разрушителя (убедитесь, что координаты попадают на доску): ";
        cin >> Pl2letDs2;
        Pl2letDs2 = toupper(Pl2letDs2);
        if (Pl2letDs2 >= 'A' && Pl2letDs2 <= 'J')
            break;
    }
    if (Pl2letDs1 != Pl2letDs2) {
        while (true) {
            if (Pl2letDs1 == Pl2letDs2)
                break;
            if (Pl2letDs2 == (Pl2letDs1+1))
                break;
            if (Pl2letDs2 == (Pl2letDs1-1))
                break;
            cout << player2 << ", введите вторую букву координаты вашего однопалубного Разрушителя (убедитесь, что координаты попадают на доску): ";
            cin >> Pl2letDs2;
            Pl2letDs2 = toupper(Pl2letDs2);
        }
    }
    int Pl2numDs2 = 0;
    while (Pl2numDs2 <= 0 || Pl2numDs2 >= 11) {
        cout << player2 << ", введите второе число координаты вашего однопалубного Разрушителя (убедитесь, что кораблю хватает двух клеток по горизонтали / вертикали): ";
        cin >> Pl2numDs2;
    }
    
loop18:
    for (;;) {
        if (boardPl2[Pl2letDs2-'A'][Pl2numDs2-1] == 'O')
            break;
        for (;;) {
            cout << "Координата уже использована или находится вне игрового поля. Выберите другую: " << endl;
            cout << player2 << ", введите вторую букву координаты вашего однопалубного Разрушителя (убедитесь, что координаты попадают на доску): ";
            cin >> Pl2letDs2;
            Pl2letDs2 = toupper(Pl2letDs2);
            if (Pl2letDs2 >= 'A' && Pl2letDs2 <= 'J')
                break;
        }
        for (;;) {
            cout << player2 << ", введите второе число координаты вашего однопалубного Разрушителя (убедитесь, что кораблю хватает двух клеток по горизонтали / вертикали): ";
            cin >> Pl2numDs2;
            if (Pl2numDs2 >= 1 && Pl2numDs2 <= 10)
                break;
        }
        if (boardPl2[Pl2letDs2-'A'][Pl2numDs2-1] == 'O')
            break;
        else
            goto loop18;
    }
    while (true) {
        if (Pl2letDs1 == Pl2letDs2) {
            if (Pl2numDs2 == (Pl2numDs1+1))
                break;
            if (Pl2numDs2 == (Pl2numDs1-1) && (Pl2numDs2>0 || Pl2numDs2<11))
                break;
        }
        if (Pl2letDs1 != Pl2letDs2) {
            if (Pl2numDs1 == Pl2numDs2)
                break;
        }
        cout << player2 << " Убедитесь, что кораблю хватает места (2) Введите второе число снова: ";
        cin >> Pl2numDs2;
    }
    char Pl2Pos1d= 'D';
    char Pl2Pos2d= 'D';
    int Pl2letDsPos;
    int Pl2letDsPos2;
    Pl2letDsPos = Pl2letDs1-'A';
    Pl2letDsPos2 = Pl2letDs2-'A';
    boardPl2[Pl2letDsPos][Pl2numDs1-1] = Pl2Pos1d;
    boardPl2[Pl2letDsPos2][Pl2numDs2-1] = Pl2Pos2d;
    if (Pl2letDs1 == Pl2letDs2) {
        if (Pl2numDs1<Pl2numDs2) {
            for (int Pl2x4 = Pl2numDs1-1; Pl2x4 <= Pl2numDs2-1; Pl2x4++)
                boardPl2[Pl2letDsPos][Pl2x4] = 'D';
        }
        if (Pl2numDs2<Pl2numDs1) {
            for (int Pl2x4 = Pl2numDs2-1; Pl2x4 <= Pl2numDs1-1; Pl2x4++)
                boardPl2[Pl2letDsPos][Pl2x4] = 'D';
        }
    }
    if (Pl2numDs1 == Pl2numDs2) {
        if (Pl2letDsPos<Pl2letDsPos2) {
            for (int Pl2y4 = Pl2letDsPos; Pl2y4 <= Pl2letDsPos2; Pl2y4++) {
                boardPl2[Pl2y4][Pl2numDs1-1] = 'D';
            }
        }
        if (Pl2letDsPos2<Pl2letDsPos) {
            for (int Pl2y4 = Pl2letDsPos2; Pl2y4 <= Pl2letDsPos; Pl2y4++) {
                boardPl2[Pl2y4][Pl2numDs1-1] = 'D';
            }
        }
    }
    displayBoardPl2(boardPl2);
    initializeBoardAttack();
    initializeBoardPl2Attack();
    for(;;) {
        cout << player1 << " Сейчас Ваша очередь атаковать: " << endl;
        displayBoardAttack(boardAttack);
        displayBoard(board);
        char Pl1letAttack1;
        while (true) {
            cout << player1 << ", введите букву координаты Вашего атаки: ";
            cin >> Pl1letAttack1;
            Pl1letAttack1 = toupper(Pl1letAttack1);
            if (Pl1letAttack1 >= 'A' && Pl1letAttack1 <= 'J')
                break;
        }
        int Pl1numAttack1 = 0;
        while (Pl1numAttack1 <= 0 || Pl1numAttack1 >= 11) {
            cout << player1 << ", введите число координаты Вашего атаки: ";
            cin >> Pl1numAttack1;
        }
        char Pl1PosAttack1 = 'O';
        int Pl1letAttackPos;
        Pl1letAttackPos = Pl1letAttack1-'A';
        if (boardPl2[Pl1letAttackPos][Pl1numAttack1-1] != Pl1PosAttack1) {
            boardAttack[Pl1letAttackPos][Pl1numAttack1-1] = 'X';
            boardPl2[Pl1letAttackPos][Pl1numAttack1-1] = 'X';
            cout << "Попал(-а)!" << endl;
        }
        else {
            boardAttack[Pl1letAttackPos][Pl1numAttack1-1] = '!';
            boardPl2[Pl1letAttackPos][Pl1numAttack1-1] = '!';
            cout << "Не попал(-а)!" << endl;
        }
        displayBoardAttack(boardAttack);
        displayBoard(board);
        if (Pl1WinCheck() == true) {
            cout << player1 << ", Вы выиграли!" << endl;
            break;
        }
        cout << "Введите любой символ, чтобы продолжить: ";
        char c;
        cin >> c;
        cout << player1 << ": Сейчас Ваша очередь атаковать: " << endl;
        displayBoardPl2Attack(boardPl2Attack);
        displayBoardPl2(boardPl2);
        char Pl2letAttack2;
        while (true) {
            cout << player2 << ", введите букву координаты Вашего атаки: ";
            cin >> Pl2letAttack2;
            Pl2letAttack2 = toupper(Pl2letAttack2);
            if (Pl2letAttack2 >= 'A' && Pl2letAttack2 <= 'J')
                break;
        }
        int Pl2numAttack2 = 0;
        while (Pl2numAttack2 <= 0 || Pl2numAttack2 >= 11) {
            cout << player2 << ", введите число координаты Вашего атаки: ";
            cin >> Pl2numAttack2;
        }
        char Pl2PosAttack2 = 'O';
        int Pl2letAttackPos;
        Pl2letAttackPos = Pl2letAttack2-'A';
        if (board[Pl2letAttackPos][Pl2numAttack2-1] != Pl2PosAttack2) {
            boardPl2Attack[Pl2letAttackPos][Pl2numAttack2-1] = 'X';
            board[Pl2letAttackPos][Pl2numAttack2-1] = 'X';
            cout << "Попал(-а)!" << endl;
        }
        else {
            boardPl2Attack[Pl2letAttackPos][Pl2numAttack2-1] = '!';
            board[Pl2letAttackPos][Pl2numAttack2-1] = '!';
            cout << "Не попал(-а)!" << endl;
        }
        displayBoardPl2Attack(boardPl2Attack);
        displayBoardPl2(boardPl2);
        if (Pl2WinCheck() == true) {
            cout << player2 << ", Вы выиграли!" << endl;
            break;
        }
        cout << "Введите любой символ, чтобы продолжить: ";
        char d;
        cin >> d;
    }
    return 0;
}

void initializeBoard() {
    for(int x= 0; x<10; x++) {
        for (int y= 0; y<10; y++)
            board[x][y] = 'O';
    }
}

void displayBoard (char gameboard[10][10]) {
    cout << " " ;
    for (int col1=1 ; col1<=10; col1++)
        cout << setw(4) << col1;
    cout<<endl;
    for (int row =0 ; row<10; row++) {
        cout << (char) ('A'+row);
        for (int col=0; col<10; col++)
            cout << setw(4) << gameboard[row][col];
        cout << endl;
    }
}

void initializeBoardPl2() {
    for(int x= 0; x<10; x++) {
        for (int y= 0; y<10; y++)
            boardPl2[x][y] = 'O';
    }
}

void displayBoardPl2 (char gameboardPl2[10][10]) {
    cout << " ";
    for (int col1 = 1; col1 <= 10; col1++)
        cout << setw(4) << col1;
    for (int row = 0; row<10; row++) {
        cout << (char) ('A'+row);
        for (int col = 0; col<10; col++)
            cout << setw(4) << gameboardPl2[row][col];
    }
}

void initializeBoardAttack() {
    for(int x= 0; x<10; x++) {
        for (int y= 0; y<10; y++)
            boardAttack[x][y] = 'O';
    }
}

void displayBoardAttack(char gameboardAttack[10][10]) {
    cout << " ";
    for (int col1 = 1; col1 <= 10; col1++)
        cout << setw(4) << col1;
    for (int row = 0; row<10; row++) {
        cout << (char) ('A'+row);
        for (int col = 0; col<10; col++)
            cout << setw(4) << gameboardAttack[row][col];
    }
}

void initializeBoardPl2Attack() {
    for(int x= 0; x<10; x++) {
        for (int y= 0; y<10; y++)
            boardPl2Attack[x][y] = 'O';
    }
}

void displayBoardPl2Attack (char gameboardPl2Attack[10][10]) {
    cout << " ";
    for (int col1 = 1; col1 <= 10; col1++)
        cout << setw(4) << col1;
    for (int row = 0; row<10; row++) {
        cout << (char) ('A'+row);
        for (int col = 0; col<10; col++)
            cout << setw(4) << gameboardPl2Attack[row][col];
    }
}

bool Pl1WinCheck() {
    int counter= 0;
    for (int col = 0; col<10; col++) {
        for (int row= 0; row<10; row++) {
            if (boardPl2[col][row] == 'X') {
                counter++;
                if (counter ==  17)
                    return true;
            }
        }
    }
}

bool Pl2WinCheck() {
    int counter2 = 0;
    for (int col2 = 0; col2<10; col2++) {
        for (int row2 = 0; row2<10; row2++) {
            if (board[col2][row2] == 'X') {
                counter2++;
                if (counter2 == 17)
                    return true;
            }
        }
    }
}
