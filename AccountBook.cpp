#include "AccountBook.h"

AccountBook::Date::Date() {
    day = 1;
    month = 1;
    year = 1970;
}

AccountBook::Date::Date(int d, int m, int y) {
    // bool check = 0;
    // if (m <= 0 || m > 12) {
    //     cout << "Month must be over 0 and under 12\n";
    //     check = 1;
    // }


    // while (check) {
    //     cout << "Repeat input\n";
    //     cout << "day: "; cin >> day;
    //     cout << "\nmonth: "; cin >> month;
    //     cout << "\nyear: "; cin >> year;
    // }
    day = d;
    month = m;
    year = y;
}

AccountBook::AccountBook():
lenght(0), accounts(nullptr) {}

AccountBook::AccountBook(int l, int d, int m, int y):
lenght(l), date(d, m, y) {
    try {
        if (l < 0)
            throw "Lenght Error\n";
        else if (l == 0) 
            accounts = nullptr;
        else
            accounts = new ElectricityCounter[l];
    } catch (string i) {
        cerr << i;
    }
}

void AccountBook::erase() {
    delete[] accounts;
    accounts = nullptr; //Что б не было висячего указателя
    lenght = 0;
}

void AccountBook::resize(int new_lenght) {
    if (new_lenght == lenght)
        return;
    if (new_lenght <= 0) {
        erase();
        return;
    }

    ElectricityCounter *tmp = new ElectricityCounter[new_lenght];

    int copy = (lenght > new_lenght) ? new_lenght : lenght;
    for (int i(0); i < copy; i++)
        tmp[i] = accounts[i];

    delete[] accounts;

    accounts = tmp;
    lenght = new_lenght;

    delete[] tmp;
    tmp = nullptr;
}

void AccountBook::add_element(ElectricityCounter& elem, int index) {
    ElectricityCounter *tmp = new ElectricityCounter[lenght+1];

    for (int i(0); i < index; i++)
        tmp[i] = accounts[i];

    tmp[index] = elem;

    for (int i(index); i < lenght; i++)
        tmp[i+1] = accounts[i];

    delete[] accounts;

    accounts = tmp;

    delete[] tmp;
    lenght++;
}

void AccountBook::remove_element(int index) {
    ElectricityCounter *tmp = new ElectricityCounter[lenght-1];
    for (int i(0); i < index; i++) 
        tmp[i] = accounts[i];
    for (int i(index); i < lenght-1; i++)
        tmp[i] = accounts[i+1];

    delete[] accounts;
    accounts = tmp;
    delete[] tmp;
    lenght--;
}

void AccountBook::add_elem_begin(ElectricityCounter& elem) {
    add_element(elem, 0);
}

void AccountBook::add_elem_end(ElectricityCounter& elem) {
    add_element(elem, lenght);
}

void AccountBook::data_input() {
    bool check = 0;
    string day_diapasone;
    // while(!check) {
    //     cout << "Enter date:\n";
    //     cout << "\tyear from 1: "; cin >> date.year;
    //     cout << "\tmonth from 1 to 12: "; cin >> date.month;
    //     if (date.year % 4 == 0 && date.month == 2)
    //         day_diapasone = "from 1 to 29: ";
    //     if (date.month == 2)
    //         day_diapasone = "from 1 to 28: ";
    //     else if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12)
    //         day_diapasone = "from 1 to 30: ";
    // }
    //Беды с датой
}

int AccountBook::get_lenght() {
     return lenght;
}

ElectricityCounter& AccountBook::operator[](int index) {
    try {
        if (index < 0 || index > lenght)
            throw "Index Error\n";
        return accounts[index];
    } catch (string i) {
        cerr << i;
    }
}

AccountBook::~AccountBook() {
    cout << "Destructor AccountBook\n";
    delete[] accounts;
}