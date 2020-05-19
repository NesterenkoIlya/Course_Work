#pragma once

#include "ElectricityCounter.h"

class Iter {
    ElectricityCounter* i;  //Поле данных
public:
    explicit Iter(ElectricityCounter*); //Конструктор иницииализации
    Iter(const Iter& x);    //Конструктор копирования
    Iter& operator=(const Iter& x); //Перегрузка оператора присваивания
    ElectricityCounter& operator*() const;  //Возвращает разименованое поле данных
    Iter& operator++();
    Iter& operator--();
    Iter& operator++(int);
    Iter& operator--(int);
    Iter operator+(int n);
    Iter operator-(int n);
    Iter& operator+=(int n);
    Iter& operator-=(int n);

    bool operator==(const Iter& x) const;
    bool operator!=(const Iter& x) const;
    bool operator<(const Iter& x) const;
    bool operator>(const Iter& x) const;
    bool operator<=(const Iter& x) const;
    bool operator>=(const Iter& x) const;

    friend int operator-(const Iter& x, const Iter& y);
};
