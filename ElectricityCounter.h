#pragma once
#include "DigitalCounter.h"
class ElectricityCounter :
	public DigitalCounter {
    int *m_bit_number;
    int m_precision;
public:
    ElectricityCounter();
    ElectricityCounter(int, int, float, int, int);
    ElectricityCounter(ElectricityCounter&);

    void print_counter() override;

    friend istream &operator>>(istream &, ElectricityCounter &);
    friend ostream &operator<<(ostream &, ElectricityCounter &);
    void operator=(float);
    ElectricityCounter &operator=(const ElectricityCounter&);
    float operator*();

    void set_bit_number(int*);
    int get_bit_number();
    void set_precision(int);
    int get_precision();

    virtual ~ElectricityCounter();
};
