#pragma once
#include "DigitalCounter.h"
class ElectricityCounter :
	public DigitalCounter {
    int bit_number;
    int precision;
public:
    ElectricityCounter();
    ElectricityCounter(int, int, float, int, int);
    ElectricityCounter(ElectricityCounter&);

    void print_counter() override;

    friend istream &operator>>(istream &, ElectricityCounter &);
    friend ostream &operator<<(ostream &, ElectricityCounter &);
    ElectricityCounter &operator=(const ElectricityCounter&);
    //ElectricityCounter &operator-(const ElectricityCounter&);

    virtual ~ElectricityCounter() {
        cout << "Destructor ElectricityCounter\n";
    }
};
