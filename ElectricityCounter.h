#pragma once
#include "DigitalCounter.h"
class ElectricityCounter :
	public DigitalCounter {
    int bit_number;
    int precision;
    void value_check();
public:
    ElectricityCounter();
    ElectricityCounter(int, int, float, int, int);
    ElectricityCounter(ElectricityCounter&);

    friend istream &operator>>(istream &, ElectricityCounter &);
    friend ostream &operator<<(ostream &, ElectricityCounter &);
    ElectricityCounter &operator=(const ElectricityCounter&);
};
