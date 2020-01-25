#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

#define MAXSIZE 5 

struct stack {
    int stk[MAXSIZE];
    int top; 
    int time[MAXSIZE];
};

typedef struct stack STACK;
STACK s;

void push(void);
int pop_stack(void);
int pop_queue(void);
bool is_auto ();
void display(void);

int main() {
    int choice;
    s.top = 0;
    printf("Добро пожаловать в менеджер задач! Выберите пункт меню: \n");
    while (choice != 5) {
        printf("1: Добавить задачу \n");
        printf("2: Выполнить задачи в режиме стека \n");
        printf("3: Выполнить задачи в режиме очереди \n");
        printf("4: Показать список задач \n");
        printf("5: Выход \n");
        printf("\n");
        printf("Введите вариант: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop_stack();
                break;
            case 3:
                pop_queue();
                break;
            case 4:
                display();
                break;
        }
    }
}

void push() {
    int cnt = 0;
    srand((unsigned int) time(NULL));
    if (is_auto()) {
        printf("Сколько задач вы хотите добавить?(от 1 до %d задач)\n",MAXSIZE);
        scanf("%d", &cnt);
        if ((cnt > MAXSIZE) || (cnt <= 0)) {
            printf("Ошибка ввода количества задач.\n");
            return;
        }
        for (int i = 1; i <= cnt; i++) {
            s.top = s.top + 1;
            s.time[s.top] = 0 + rand()%4;
            s.stk[s.top] = i;
        }
    }
    else {
        int num;
        if (s.top == (MAXSIZE)) {
            printf("Список задач переполнен!\n");
            return;
        } else {
            printf("Введите имя задачи (Только числа!)\n");
            scanf("%d", &num);
            s.top = s.top + 1;
            int tmp;
            printf("Введите время её выполнения:\n");
            scanf("%d", &tmp);
            s.time[s.top] = tmp;
            s.stk[s.top] = num;
        }
        return;
    }
}

int pop_queue() {
    if (s.top == 0) {
        printf("Список задач пуст!\n");
        return (s.top);
    } else {
        printf("Выбран алгоритм очереди\n");
        for (int i = 1; i <= s.top; i++) {
            printf("Выбрана задача № %d\n", s.stk[i]);
            printf("Задача будет длится %d секунд. Подождите...\n", s.time[i]);
            sleep(s.time[i]);
        }
        s.top = 0;
    }
    return 0;
}

int pop_stack() {
    if (s.top == 0) {
        printf("Список задач пуст!\n");
        return (s.top);
    } else {
        printf("Выбран алгоритм cтека\n");
        for (int i = s.top; i > 0; i--) {
            printf("Выбрана задача № %d\n", s.stk[i]);
            printf("Задача будет длится %d секунд. Подождите...\n", s.time[i]);
            sleep(s.time[i]);
        }
        s.top = 0;
    }
    return 0;
}

void display() {
    if (s.top == 0) {
        printf("Список задач пуст!\n");
        return;
    } else {
        printf("\n Перечень задач: \n");
        for (int i = 1; i <= s.top; i++) {
            printf("Задача %d, время выполнения - %d\n", s.stk[i], s.time[i]);
        }
    }
    printf("\n");
}

bool is_auto() {
    int ch=0;
    printf("0 - ввести данные самостоятельно\n");
    printf("1 - сгенерировать задачи автоматически\n");
    scanf("%d", &ch);
    return ch;
}
