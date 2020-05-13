#pragma once

#include "ElectricityCounter.h"

class AccountBook {
    int lenght;
    ElectricityCounter *accounts;
    float price;
    struct Date {
        int day;
        int month;
        int year;
        Date();
        Date(int, int, int);
    } date;
public:
    AccountBook();
    AccountBook(int, int, int, int);

    void erase();
    void resize(int);
    void add_element(ElectricityCounter&, int);
    void remove_element(int);
    void add_elem_begin(ElectricityCounter&);
    void add_elem_end(ElectricityCounter&);

    //bool data_check();
    void date_check(); //беды с датой

    int get_lenght();

    ElectricityCounter& operator[](int);

    ~AccountBook();
};