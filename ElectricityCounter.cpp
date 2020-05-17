#include "ElectricityCounter.h"

ElectricityCounter::ElectricityCounter() {
    DigitalCounter(0, 0, 0);
    m_bit_number = 1;
    m_precision = 0;
}

ElectricityCounter::ElectricityCounter(int min, int max, float c, int bit, int p) :
DigitalCounter(min, max, c) {
    m_bit_number = bit;
    m_precision = p;
}

ElectricityCounter::ElectricityCounter(ElectricityCounter& obj) {
    m_min_value = obj.m_min_value;
    m_max_value = obj.m_max_value;
    m_bit_number = obj.m_bit_number;
    m_precision = obj.m_precision;
}

void ElectricityCounter::print_counter() {
    cout << setprecision(m_precision) << fixed
         << "Class ElectricityCounter\n"
         << "counter = " << m_counter
        << setprecision(6);
    cout.unsetf(ios::fixed);
}

void ElectricityCounter::operator=(float c) {
    while(true) {
        if (c >= m_min_value && c <= m_max_value) {
            m_counter = c;
            break;
        }
        cout << "Вы используете неправильное значение счетчика\n"
             << "счетчик должен быть больше " << m_min_value << " и меньше " << m_max_value << endl
            << "Повторите ввод\n"
            << "counter: ";
        cin >> c;
    }
}

ElectricityCounter &ElectricityCounter::operator=(const ElectricityCounter &obj) {
    m_counter = obj.m_counter;
    m_min_value = obj.m_min_value;
    m_max_value = obj.m_max_value;
    m_bit_number = obj.m_bit_number;
    m_precision = obj.m_precision;
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
        cout << "bit_number: "; in >> obj.m_bit_number;
        cout << "precision: "; in >> obj.m_precision;
        cout << "min_value: "; in >> obj.m_min_value;
        cout << "max_value: "; in >> obj.m_max_value;
        cout << "counter: "; in >> obj.m_counter;

        if (obj.m_bit_number < 1) {
            check = 0;
            cout << "You input incorrect bit_number\n"
                 << "bit_number must be over 1\n";
        }

        if (obj.m_precision < 0) {
            check = 0;
            cout << "You input incorrect precision\n"
                 << "precision must be over 0\n";
        }

        int power = pow(10,obj.m_bit_number);
        if (obj.m_max_value > power || obj.m_max_value < obj.m_min_value)
            cout << "You input incorrect max_value\n"
                << "max_value must be over " << obj.m_min_value
                << "and under " << power;

        if (obj.m_counter > obj.m_max_value || obj.m_counter < obj.m_min_value) {
            check = 0;
            cout << "You input incorrect counter\n"
                 << "counter must be in diapasone from"
                 << obj.m_min_value << " to " << obj.m_max_value;
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
    out << setprecision(obj.m_precision) << fixed;
    out << "Counter = " << obj.m_counter << endl;
    out << obj.m_max_value << endl;
    out << setprecision(6); //Стандартный setprecision
    out.unsetf(ios::fixed); //Убирает флаг fixed из потока
    return out;
}
