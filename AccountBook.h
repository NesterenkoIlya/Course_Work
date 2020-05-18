#pragma once

#include "Iter.h"
#include "Counter.h"

class AccountBook {
    int m_length;
    ElectricityCounter *m_accounts;
    float m_price;
    struct Date {
        int day;
        int month;
        int year;
        Date();
        Date(int, int, int);
    } *m_date;
public:
    AccountBook();
    AccountBook(int);
    AccountBook(int, float, int, int, int);
    AccountBook(const AccountBook&);

    void erase();
    void resize(int);
    void add_element(ElectricityCounter&, Iter);
    void remove_element(Iter);
    void add_elem_begin(ElectricityCounter&);
    void add_elem_end(ElectricityCounter&);

    float sum_accounts();
    float price_accounts();

    void set_price(float);
    float get_price();
    void set_lenght(int);
    int get_lenght();

    Iter begin();
    Iter end();

    void date_check();

    ElectricityCounter& operator[](Iter);
    AccountBook& operator=(const AccountBook&);
    friend istream& operator>>(istream&, AccountBook&);
    friend ostream& operator<<(ostream&, AccountBook&);
    friend ifstream& operator>>(ifstream&, AccountBook&);
    friend ofstream& operator<<(ofstream&, AccountBook&);

    ~AccountBook();
};