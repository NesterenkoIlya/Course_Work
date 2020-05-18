#pragma once
#include "DigitalCounter.h"
class ElectricityCounter :
	public DigitalCounter {
    int *m_bit_number;  //Разрядность
    int m_precision;    //Точность
public:
    ElectricityCounter();   //Конструктор по умолчанию
    ElectricityCounter(int, int, float, int, int);  //Конструктор с параметрами
    ElectricityCounter(ElectricityCounter&);    //Конструктор глубокого копирования

    //Переопределенный метод для вывода текущего значения счетчика
    void print_counter() override final;

    //Вод текущего значения счетчика
    friend istream &operator>>(istream &, ElectricityCounter &);
    //Вывод текущего значения счетчика
    friend ostream &operator<<(ostream &, ElectricityCounter &);
    //Установка текущего значения счетчика
    void operator=(float);
    //Получение текущего значения счетчика
    float operator*();
    ElectricityCounter &operator=(const ElectricityCounter&);

    //Сеттеры и геттеры полей класса
    void set_bit_number(int*);
    int get_bit_number();
    void set_precision(int);
    int get_precision();

    virtual ~ElectricityCounter();
};
