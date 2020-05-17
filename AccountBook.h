#pragma once

#include "Iter.h"

class AccountBook {
    int m_lenght;
    ElectricityCounter *m_accounts;
    float m_price;
    struct Date {
        int day;
        int month;
        int year;
        Date();
    } m_date;
public:
    AccountBook();
    AccountBook(int, int, int, int);
    AccountBook(const AccountBook&);

    void erase();
    void resize(int);
    void add_element(ElectricityCounter&, Iter);
    void remove_element(Iter);
    void add_elem_begin(ElectricityCounter&);
    void add_elem_end(ElectricityCounter&);

    float sum_all();
    float price_all();

    Iter begin();
    Iter end();

    void date_check(); //беды с датой

    int get_lenght();

    ElectricityCounter& operator[](Iter);
    friend istream& operator>>(istream&, AccountBook&);
    friend ostream& operator<<(ostream&, AccountBook&);
    AccountBook& operator=(const AccountBook&);

    ~AccountBook();
};