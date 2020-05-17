#include "ElectricityCounter.h"

ElectricityCounter::ElectricityCounter() {
    DigitalCounter(0, 0, 0);
    m_bit_number = new int(1);
    m_precision = 0;
}

ElectricityCounter::ElectricityCounter(int min_value, int max_value, float counter, int bit_number, int precision) :
DigitalCounter(min_value, max_value, counter) {
    m_bit_number = new int(bit_number);
    m_precision = precision;
}

ElectricityCounter::ElectricityCounter(ElectricityCounter& obj) {
    m_min_value = obj.m_min_value;
    m_max_value = obj.m_max_value;
    m_bit_number = new int(*obj.m_bit_number);  //Глубинное копирование, так как мы не присваиваем адресс, а само значение
    m_precision = obj.m_precision;
}

void ElectricityCounter::print_counter() {
    cout << setprecision(m_precision) << fixed
         << "Class ElectricityCounter\n"
         << "counter = " << m_counter
         << setprecision(6);
    cout.unsetf(ios::fixed);
}

void ElectricityCounter::operator=(float counter) {
    while(true) {
        if (counter >= m_min_value && counter <= m_max_value) {
            m_counter = counter;
            break;
        }
        cout << "Вы используете неправильное значение счетчика\nПовторите ввод\n"
             << "счетчик должен быть в диапазоне [" << m_min_value << "; " << m_max_value << "]\n"
             << "counter: "; cin >> counter;
    }
}

ElectricityCounter &ElectricityCounter::operator=(const ElectricityCounter &obj) {
    m_counter = obj.m_counter;
    m_min_value = obj.m_min_value;
    m_max_value = obj.m_max_value;
    m_bit_number = new int(*obj.m_bit_number);
    m_precision = obj.m_precision;
    return *this;
}

float ElectricityCounter::operator*() { //Определение текущего значения счетчика
    return m_counter;
}

ElectricityCounter::~ElectricityCounter() {
    delete m_bit_number;
    cout << "Destructor ElectricityCounter\n";
}

istream &operator>>(istream &in, ElectricityCounter &obj) {
    cout << "bit_number: "; in >> *obj.m_bit_number;
    cout << "precision: "; in >> obj.m_precision;
    cout << "min_value: "; in >> obj.m_min_value;
    cout << "max_value: "; in >> obj.m_max_value;
    cout << "counter: "; in >> obj.m_counter;
    bool check = 0;
    while (true) {
        if (check == 0) {
            check = 1;
        } else
            break;

        if (*obj.m_bit_number < 1) {
            check = 0;
            cout << "Вы ввели неправильную разрядность\n"
                 << "Разрядность должна быть больше 1\n"
                 << "bit_number: "; in >> *obj.m_bit_number;
        }
        if (obj.m_precision < 0) {
            check = 0;
            cout << "Вы ввели неправильную точность\n"
                 << "Точность должна быть больше 0\n"
                 << "precision: "; in >> obj.m_precision;
        }

        if (obj.m_min_value > obj.m_max_value) {
            check = 0;
            cout << "Вы ввели неправильное минимальное значение\n"
                 << "Минимальное значение должно быть меньше " << obj.m_max_value
                 << "\nmin_value: "; in >> obj.m_min_value;
        }

        int power = pow(10, *obj.m_bit_number);
        if (obj.m_max_value > power || obj.m_max_value < obj.m_min_value) {
            check = 0;
            cout << "Вы ввели неправильное максимальное значение\n"
                 << "максимальное значение должно быть в диапазоне [" << obj.m_min_value
                 << "; " << power << "]\n"
                 << "\nmax_value: "; in >> obj.m_max_value;
        }

        if (obj.m_counter > obj.m_max_value || obj.m_counter < obj.m_min_value) {
            check = 0;
            cout << "Вы ввели неправильное значение счетчика\n"
                 << "счетчик должен быть в диапазоне [" << obj.m_min_value
                 << "; " << obj.m_max_value << "]"
                 << "\ncounter: "; in >> obj.m_counter;
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

void ElectricityCounter::set_bit_number(int *bit_number) {
    while (*bit_number < 1) {
        cout << "Вы используете неправильную разрядность\nПовторите ввод: ";
        cin >> *bit_number;
    }
    m_bit_number = bit_number;
}

int ElectricityCounter::get_bit_number() {
    return *m_bit_number;
}

void ElectricityCounter::set_precision(int precision) {
    while (precision < 0) {
        cout << "Вы используете неправильную разрядность\nПовторите ввод: ";
        cin >> precision;
    }
    m_precision = precision;
}

int ElectricityCounter::get_precision() {
    return m_precision;
}
