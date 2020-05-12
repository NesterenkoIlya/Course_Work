#include "ElectricityCounter.h"

ElectricityCounter::ElectricityCounter() {
    DigitalCounter(0, 0, 0);
    bit_number = 1;
    precision = 0;
}

ElectricityCounter::ElectricityCounter(int min, int max, float c, int bit, int p) :
DigitalCounter(min, max, c) {
    bit_number = bit;
    precision = p;
}

ElectricityCounter::ElectricityCounter(ElectricityCounter& obj) {
    min_value = obj.min_value;
    max_value = obj.max_value;
    bit_number = obj.bit_number;
    precision = obj.precision;
}

void ElectricityCounter::print_counter() {
    cout << setprecision(precision) << fixed
        << "Class ElectricityCounter\n"
        << "counter = " << counter
        << setprecision(6);
    cout.unsetf(ios::fixed);
}

ElectricityCounter &ElectricityCounter::operator=(const ElectricityCounter &obj) {
    if (counter < min_value || counter > max_value) {
        bool check = 0;
        do {
            cout << "You use incorrect counter\n"
                << "counter must be over " << min_value
                << " and under " << max_value << endl
                << "Repeat input\ncounter: ";
            cin >> counter;
            if (counter >= min_value || counter <= max_value)
                check = 1;
        } while(!check);
    }
    return *this;
}

// ElectricityCounter &ElectricityCounter::operator-(const ElectricityCounter&) {

//     return *this;
// }

ElectricityCounter::~ElectricityCounter() {
    cout << "Destructor ElectricityCounter\n";
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
    out << setprecision(6); //Стандартный setprecision
    out.unsetf(ios::fixed); //Убирает флаг fixed из потока
    return out;
}
