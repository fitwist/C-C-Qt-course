#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const char* phonebook_filename = "/Users/helenkapatsa/Репозитории/cpp-itmo/Xcode/07/phonebook/phonebook/phone_book.txt"; // Телефонная книга – отдельный файл
enum groups {Family, Friends, Colleagues, VIP, Others}; // Перечисление групп

struct contact_info { // Структура контакта (имя, телефон, группа)
    string phone_number;
    string contact_name;
    groups contact_group; // Каждый контакт книги снабжен указателем с адресом следующего элемента в перечне. Последний контакт книги хранит значение NULL в данном указателе.
    contact_info* next_element=NULL;
};

contact_info* phonebook=NULL; // Телефонная книга хранится как связанный список.
unsigned int N_entries = 0; // Переменная, хранящая количество контактов телефонной книги

contact_info* look_up[26] = {NULL}; // Пустой массив для хранения контактов, где элементы являются указателями на определенный объект структуры contact_info. В i-м элементе массива look_up указатели на первый номер телефона – объект, хранимый под нулевым пунктом A, последний объект хранится по индексом Z.

contact_info* create_entry();        // Принятие пользовательского ввода при создании карточки
void contact_insert(contact_info*);  // Создание нового контакта
contact_info* contact_find(string);  // Поиск данных контакта
void contact_show(contact_info);     // Отображение данных контакта
void contact_show_all();     // Поиск и удаление контакта
void contact_find_show();            // Поиск и отображение контакта
void phonebook_save();               // Вставка контакта в телефонную книгу в алфавитном порядке с помощью указателя
void phonebook_load();               // Загрузка внешней телефонной книги

int main() {
    phonebook_load(); // Чтение телефонной книги из внешнего файла
    char userchoice; // Меню пользовательских действий
    do {
        cout << endl;
        cout << "1. Создать новый контакт" << endl;
        cout << "2. Показать все контакты" << endl;
        cout << "3. Найти контакт " << endl;
        cout << "4. Сохранить книгу " << endl;
        cout << "5. Выйти из программы " << endl;
        cout << endl << "Ваш выбор: ";
        cin >> userchoice;
        
        switch (userchoice) {
        case '1': // Создание нового контакта
            contact_insert(create_entry());
            break;
        case '2': // Отображений книги контактов
            contact_show_all();
            break;
        case '3': // Поиск контакта
            contact_find_show();
            break;
        case '4': // Сохранение телефонной книги
            phonebook_save();
            break;
        default: // Обработка ошибочного ввода
            cout << endl << "Пожалуйста, введите цифру от 1 до 5, чтобы выбрать действие: " << endl;
        }
    } while (userchoice != '5');
    cout << "Выход из программы..." << endl;
    return 0;
}

// Создать прототип функции, добавляющей новый контакт в телефонную книгу
contact_info* create_entry() {
    contact_info* new_entry = new contact_info;
    cout << "Введите имя: ";
    cin.ignore(); // Очистка буфера обмена для последующего использования getline()
    getline (cin,new_entry->contact_name);
    cout << "Введите номер телефона: ";
    getline (cin,new_entry->phone_number);
    cout << "Введите номер группы: " << endl;
    cout << "1 – Семья" << endl;
    cout << "2 – Друзья" << endl;
    cout << "3 – Коллеги" << endl;
    cout << "4 – VIP" << endl;
    cout << "или любая другая цифра для группы \'Прочее\'" << endl;
    cout << "Выш выбор: ";
    char groupchoice;
    cin >> groupchoice;

    switch (groupchoice) {
    case '1':
        new_entry->contact_group=Family;
        break;
    case '2':
        new_entry->contact_group=Friends;
        break;
    case '3':
        new_entry->contact_group=Colleagues;
        break;
    case '4':
        new_entry->contact_group=VIP;
        break;
    default:
        new_entry->contact_group=Others;
    }
    new_entry->next_element=NULL;
    cout << "Контакт успешно создан" << endl;
    return new_entry;
}

void contact_insert(contact_info* newcontact) { // Сохранение данных в файл в алфавитном порядке
    if (N_entries==0 || phonebook->contact_name.compare(newcontact->contact_name)>0) { // Обработка особого случая – контакт попадает на первое место в телефонной книге
        newcontact->next_element=phonebook;
        phonebook=newcontact;
    }
    else {
        contact_info* previous=phonebook;
        contact_info* next=phonebook->next_element;
        while(next!=NULL) {
            if (newcontact->contact_name.compare(next->contact_name)<0) break;
            previous=next;
            next=next->next_element;
        }
        previous->next_element=newcontact;
        newcontact->next_element=next;
    }
    N_entries++;
}

contact_info* contact_find(string Name) { // Поиск контакта и его отображение
    contact_info* contact = phonebook;
    while (contact != NULL) {
        if (Name.compare(contact->contact_name)==0)
            return contact;
        else
            contact=contact->next_element;
    }
    return NULL;
}

void contact_show(contact_info* contact) { // Отображение данных контакта
    cout << "Имя: " << contact->contact_name << endl;
    cout << "Телефон: " << contact->phone_number << endl;
    cout << "Группа: ";
    switch (contact->contact_group) {
        case Family: cout << "СЕМЬЯ" << endl; break;
        case Friends: cout << "ДРУЗЬЯ" << endl; break;
        case Colleagues: cout << "КОЛЛЕГИ" << endl; break;
        case VIP: cout << "VIP" << endl; break;
        default: cout << "ДРУГОЕ" << endl;
    }
}

void contact_show_all() { // Отображение всех контактов
    contact_info* contact = phonebook;
    
    while (contact != NULL) {
        cout << "Имя: " << contact->contact_name << endl;
        cout << "Телефон: " << contact->phone_number << endl;
        cout << "Группа: " << contact->contact_group << endl;
        cout << "–––––––––––––––" << endl;
        contact=contact->next_element;
    }
}

void contact_find_show() { // Ппоиск контакта по имени
    cout << "Введите имя, чтобы найти карточку: ";
    string Name;
    cin.ignore();
    getline (cin,Name);
    cout << endl;
    contact_info* contact = contact_find(Name);
    if(contact != NULL)
        contact_show(contact);
    else
        cout << "Контакт " << Name << " не найден" << endl;
}

void phonebook_save() { // Сохранение телефонной книги в отдельный файл
    ofstream phonebook_file;
    phonebook_file.open(phonebook_filename); // "phone_book.txt".
    cout << "Записано " << N_entries << " карточек " << phonebook_filename << " ..." << endl;
    phonebook_file << N_entries << endl; // На первой строке хранится количество контактов
    contact_info* current_item=phonebook;
    while (current_item != NULL) {
        phonebook_file << "–––––––––––––––" << endl; // Разделитель контактов внутри файла
        phonebook_file << current_item->contact_name << endl; // В первой строке контакта находится имя
        phonebook_file << current_item->phone_number << endl; // В первой строке контакта находится телефон
        switch (current_item->contact_group) {
            case Family: phonebook_file << "СЕМЬЯ" << endl; break;
            case Friends: phonebook_file << "ДРУЗЬЯ" << endl; break;
            case Colleagues: phonebook_file << "КОЛЛЕГИ" << endl; break;
            case VIP: phonebook_file << "VIP" << endl; break;
            default: phonebook_file << "ДРУГОЕ" << endl;
        }
        current_item = current_item->next_element;
    }
    phonebook_file.close();
}

void phonebook_load() { // Чтение файла телефонной книги
    ifstream phonebook_file;
    phonebook_file.open(phonebook_filename);
    if(!phonebook_file.is_open()) {
        cout << "Не удается открыть телефонную книгу. Проверьте наличие файла в папке с программой" << endl;
    } else {
        phonebook_file >> N_entries;
        contact_info** previous=&phonebook;
        string text;
        getline (phonebook_file,text); // Символ возврата каретки не считывается из-за чтения числа
        cout << "Считываю " << N_entries << " карточек(-ки)..." << endl;
        for (int i=0;i<N_entries;i++) {
            contact_info* new_entry = new contact_info;
            getline (phonebook_file,text); // Пропуск разделителя
            getline (phonebook_file,new_entry->contact_name);
            getline (phonebook_file,new_entry->phone_number);
            getline (phonebook_file,text);
            if      (text.compare("СЕМЬЯ") == 0)  new_entry->contact_group=Family;
            else if (text.compare("ДРУЗЬЯ") == 0) new_entry->contact_group=Friends;
            else if (text.compare("КОЛЛЕГИ")==0)  new_entry->contact_group=Colleagues;
            else if (text.compare("VIP") == 0)    new_entry->contact_group=VIP;
            else    new_entry->contact_group=Others;
            new_entry->next_element=NULL;
            *previous=new_entry;
            previous=&new_entry->next_element;
        }
        phonebook_file.close();
    }
}
