#include "ElectricityCounter.h"
#include <cmath>
#include <iomanip>

void ElectricityCounter::value_check() {

}

ElectricityCounter::ElectricityCounter() {
    bit_number = 1;
    precision = 0;
}

ElectricityCounter::ElectricityCounter(int min, int max, float c, int bit, int precis) :
DigitalCounter(min, max, c) {
    bit_number = bit;
    precision = precis;
    value_check();
}

ElectricityCounter::ElectricityCounter(ElectricityCounter& obj) {
    min_value = obj.min_value;
    max_value = obj.max_value;
    bit_number = obj.bit_number;
    precision = obj.precision;
}

ElectricityCounter &ElectricityCounter::operator=(const ElectricityCounter &) {

    return *this;
}

istream &operator>>(istream &in, ElectricityCounter &obj) {
    bool check = 1;
    while (true) {
        cout << "bit_number: "; in >> obj.bit_number;
        cout << "precision: "; in >> obj.precision;
        cout << "min_value: "; in >> obj.min_value;
        cout << "max_value: "; in >> obj.max_value;
        cout << "counter: "; in >> obj.counter;

        if (obj.bit_number < 1) {
            check = 0;
            cout << "You input incorrect bit_number\n"
                 << "bit_number must be over 1\n";
        }

        if (obj.precision < 0) {
            check = 0;
            cout << "You input incorrect precision\n"
                 << "precision must be over 0\n";
        }

        int power = pow(10,obj.bit_number);
        if (obj.max_value > power || obj.max_value < obj.min_value)
            cout << "You input incorrect max_value\n"
                << "max_value must be over " << obj.min_value
                << "and under " << power;

        if (obj.counter > obj.max_value || obj.counter < obj.min_value) {
            check = 0;
            cout << "You input incorrect counter\n"
                 << "counter must be in diapasone from"
                 << obj.min_value << " to " << obj.max_value;
        }

        if (check == 1) {
            cout << "Input is correct\n";
            break;
        } else {
            cout << "Input is uncorrect\n"
                << "Try again\n";
        }
    }
    return in;
}

ostream &operator<<(ostream &out, ElectricityCounter &obj) {
    out << setprecision(obj.precision) << fixed;
    out << "Counter = " << obj.counter;
    out << setprecision(6);

    return out;
}
