#include <iostream>
#include <string.h>
#include <unistd.h>
#define MAX 100

using namespace std;

int top;
struct stack_s{
    public:
    string name;
    int time;
    int priority;
};
stack_s stack[MAX];

void initstack() { // Инициализация стека
    top=-1;
}

// Набор символов для автогенерации 
static const char alphanum[] = 
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";

// Случайная длина
int stringLength = sizeof(alphanum); 

// Генерация случайной части имени
char genRandom() { 
    return alphanum[rand() % stringLength];
}

// Проверка опустошенности стека
int isEmpty() { 
    if(top==-1)
        return 1;
    else
        return 0;
}

// Проверка наполненности стека
int isFull() { 
    if(top==MAX-1)
        return 1;
    else
        return 0;
}

void autoPush(
    string name, 
    int time, 
    int priority) {
        if(isFull()) {
            cout << "Стек полон" << endl;
            return;
        }
    ++top;
    
    stack[top].name = name;
    stack[top].time = time;
    stack[top].priority = priority;
    cout << "Задача \"" << name << 
    "\" добавлена.\n" << endl;
}

// Отображение текущего состояния стека
void peek() { 
    int i;
    if(isEmpty()) {
        cout << "Стек пуст" << endl;
        return;
    }
    
    for(i = top; i>=0; i--) {
        cout << 
        stack[i].name<< ", " << 
        stack[i].time << ", " << 
        stack[i].priority << endl;
    }
}

void push(
    string name, 
    int time, 
    int priority) {
        if(isFull()) {
            cout << "Стек полон" << endl;
            return;
        }
    ++top;
    stack[top].name = name;
    stack[top].time = time;
    stack[top].priority = priority;
    cout << "Задача \"" << name << 
    "\" добавлена.\n" << endl;
}

void pop() { // Удаление задачи
    string temp;
    if(isEmpty()) {
        cout << "Стек пуст" << endl;
        return;
    }
    
    temp = stack[top].name;
    cout << "Ожидание удаления задачи..." 
    << endl;
    sleep(stack[top].time);
    top--;
    cout << "Задача \"" << temp << 
    "\" удалена.\n" << endl;
}

int main() {
    string name;
    int time;
    int priority;
    
    initstack();
    int a;
    
    do {
        cout << "1. Добавить\n" << 
        "2. Удалить\n" << 
        "3. Отобразить\n" << 
        "4. Сгенерировать задачу\n" << 
        "5. Выйти из программы.\n" << 
        "Выберите действие: ";
        cin >> a;
        cout << endl;
        switch(a) {
            case 1:
                cout << "\nВведите имя: ";
                cin >> name;
                cout << 
                "Введите " << 
                " время: ";  
                cin >> time;
                cout << 
                "приоритет от 1 до 3: ";
                cin >> priority;
                push(
                    name, 
                    time, 
                    priority);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                cout << "Текущих задач: " 
                << top+1 << endl;
                break;
            case 4:
                // Генерация имени
                for(
                    unsigned int i = 0; 
                    i < 12; 
                    ++i) { 
                    name += genRandom();
                }
                time = rand() % 10;
                priority = rand() % 9;
                autoPush(
                    name, 
                    time, 
                    priority);
                break;
            default:
                cout << "Ваш выбор:\n";
        }
    } while (a != '5');
    cout << "Выход из программы..." << 
    endl;
    return 0;
}
