#include "AccountBook.h"

AccountBook::Date::Date() {
    day = 1;
    month = 1;
    year = 1970;
}

AccountBook::Date::Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

AccountBook::AccountBook() : m_length(0), m_accounts(nullptr), m_price(0), m_date(new Date()) { }

AccountBook::AccountBook(int lenght) {
    bool check = 0;
    while (true) {
        if (check == 0)
            check = 1;
        else
            break;
        if (lenght < 0) {
            cout << "Вы ввели неправильный размер\n"
                << "Размер должен быть больше 0\n"
                << "Повторите ввод: "; Counter::input_check(lenght);
        }
    }
    m_price = 0;
    m_date = new Date();
    m_accounts = new ElectricityCounter[lenght];
    m_length = lenght;
}

AccountBook::AccountBook(int length, float price, int d, int m, int y) {
    try {
        if (length < 0)
            throw "Lenght Error\n";
        else if (length == 0) {
            m_accounts = nullptr;
            m_length = 0;
        } else {
            m_length = length;
            m_accounts = new ElectricityCounter[m_length];
            for (Iter i = begin(); i != end(); i++)
                *i = m_accounts[i - begin()];
        }
    } catch (string i) {
        cerr << i;
    }
    bool check = 0;
    while (true) {
        if (check == 0)
            check = 1;
        else
            break;
        if (price < 0) {
            cout << "Вы ввели неправильную стоимость кВ/ч\n"
                 << "Стоимость должна быть больше 0\nПовторите ввод\n"
                 << "price: "; Counter::input_check(price);
        }
    }
    m_price = price;
    m_date = new Date(d, m ,y);
    date_check();
}

AccountBook::AccountBook(const AccountBook& obj) {
    m_price = obj.m_price;
    m_length = obj.m_length;
    m_date = new Date(obj.m_date->day, obj.m_date->month, obj.m_date->year);
    m_length = obj.m_length;
    if (obj.m_accounts) {
        m_accounts = new ElectricityCounter[m_length];
        for (Iter i(begin()); i != end(); ++i)
            *i = obj.m_accounts[i - begin()];
    } else
        m_accounts = nullptr;
}

void AccountBook::erase() {
    delete[] m_accounts;
    m_accounts = nullptr; //Что б небыло висячего указателя
    m_length = 0;
}

void AccountBook::resize(int new_length) {
    if (new_length == m_length)
        return;
    else if (new_length <= 0) {
        erase();
        return;
    }
    ElectricityCounter *tmp = new ElectricityCounter[new_length];

    int copy = (m_length > new_length) ? new_length : m_length;
    for (Iter i(begin()); i != begin() + copy; ++i)
        tmp[i - begin()] = m_accounts[i-begin()];

    delete[] m_accounts;
    m_accounts = tmp;
    m_length = new_length;
}

void AccountBook::add_element(ElectricityCounter& elem, Iter index) {
    while (index < begin() || index > end()) {
        cout << "Вы ввели неправильный индекс\n"
             << "Повторите ввод индеска от 0 до " << m_length << ": ";
        int n;
        Counter::input_check(n);
        index = begin() + n;
    }

    ElectricityCounter *tmp = new ElectricityCounter[m_length + 1];

    for (Iter i(begin()); i != index; ++i)
        tmp[i - begin()] = m_accounts[i - begin()];
    tmp[index-begin()] = elem;
    for (Iter i(index); i < end(); ++i)
        tmp[i + 1 - begin()] = m_accounts[i-begin()];

    delete[] m_accounts;
    m_accounts = tmp;
    m_length++;
}

void AccountBook::remove_element(Iter index) {
    while (index < begin() || index >= end()) {
        cout << "Вы ввели неправильный индекс\n"
            << "Повторите ввод индеска от 0 до " << m_length << ": ";
        int n;
        Counter::input_check(n);
        index = begin() + n;
    }
    ElectricityCounter *tmp = new ElectricityCounter[m_length - 1];
    for (Iter i(begin()); i != index; ++i)
        tmp[i - begin()] = m_accounts[i - begin()];
    for (Iter i(index); i < end() - 1; i++)
        tmp[i - begin()] = m_accounts[i + 1 - begin()];

    delete[] m_accounts;
    m_accounts = tmp;
    m_length--;
}

void AccountBook::add_elem_begin(ElectricityCounter& elem) {
    add_element(elem, begin());
}

void AccountBook::add_elem_end(ElectricityCounter& elem) {
    add_element(elem, end());
}

void AccountBook::date_check() {
    bool check = 0;
    while(true) {
        if (check == 0)
            check = 1;
        else
            break;
        if ((m_date->day < 1 || m_date->day > 31) ||
            (m_date->day == 31 &&
             (m_date->month == 4 || m_date->month == 6 || m_date->month == 9 || m_date->month == 11))) {
            check = 0;
            cout << "Введите правильный день недели: ";
            Counter::input_check(m_date->day);
        } else if (m_date->month == 2 && m_date->day > 28) {
            if ((m_date->year % 400 == 0) ? true : (m_date->year % 4 == 0 && m_date->year % 100 != 0) && m_date->day == 29) {
                check = 1;
            } else if (m_date->day > 28) {
                check = 0;
                cout << "Введите правильный день недели: ";
                Counter::input_check(m_date->day);
            }
        }
        if (m_date->month < 1 || m_date->month > 12) {
            check = 0;
            cout << "Введите правильный месяц: "; Counter::input_check(m_date->month);
        }
        if (m_date->year < 0) {
            check = 0;
            cout << "Ввеите правильный год: "; Counter::input_check(m_date->year);
        }
    }
}

int AccountBook::get_lenght() {
     return m_length;
}

void AccountBook::set_date(int d, int m, int y) {
    delete m_date;
    m_date = new Date(d, m, y);
    date_check();
}

ElectricityCounter& AccountBook::operator[](Iter index) {
    int n;
    while (index < begin() || index >= end()) {
        cout << "Вы использовали неправильный индекс\n"
             << "Введите индекс от 0 до " << m_length - 1 << ": ";
        Counter::input_check(n);
        index = begin() + n;
    }
    return *index;
}

AccountBook::~AccountBook() {
    delete[] m_accounts;
    delete m_date;
    cout << "Destructor AccountBook\n";
}

istream &operator>>(istream &in, AccountBook &obj) {
    while (true) {
        cout << "Введите стоимость кВ/ч: "; Counter::input_check(obj.m_price, in);
        if (obj.m_price < 0)
            cout << "Вы ввели не правильную стоимость. Повторите ввод";
        else
            break;
    }
    int d, m, y;
    cout << "Введите день: "; Counter::input_check(d);
    cout << "Введите месяц: ";Counter::input_check(m);
    cout << "Введите год: ";  Counter::input_check(y);
    obj.set_date(d, m, y);
    for (Iter i(obj.begin()); i != obj.end(); ++i) {
        cout << "Введите " << (i - obj.begin()) + 1 << " показание счетчика электричества\n";
        in >> obj.m_accounts[i-obj.begin()];
    }
    return in;
}

ostream &operator<<(ostream &out, AccountBook &obj) {
    out << "Цена кВ/ч: " << obj.m_price
        << "\nДата"
        << "\n\tДень: " << obj.m_date->day
        << "\n\tМесяц: " << obj.m_date->month
        << "\n\tГод: " << obj.m_date->year << endl;
    for (Iter i(obj.begin()); i != obj.end(); ++i) {
        out << (i - obj.begin()) + 1 << " показание счетчика электричества\n";
        out << obj.m_accounts[i-obj.begin()];
    }
    return out;
}

Iter AccountBook::begin() {
    return Iter(m_accounts);
}

Iter AccountBook::end() {
    return Iter(m_accounts + m_length);
}

AccountBook &AccountBook::operator=(const AccountBook &obj) {
    m_length = obj.m_length;
    if (this != &obj) {
        delete[] m_accounts;
        m_accounts = new ElectricityCounter[m_length];
        for (Iter i(begin()); i != end(); ++i)
            *i = obj.m_accounts[i - begin()];
    }
    return *this;
}

float AccountBook::sum_accounts() {
    float sum = 0;
    for (Iter i(begin()); i != end(); ++i) {
        sum += m_accounts[i - begin()].m_counter;
    }
    return sum;
}

float AccountBook::price_accounts() {
    float sum = sum_accounts();
    float price = sum * m_price;
    return price;
}

void AccountBook::set_price(float price) {
    while (price < 0) {
        cout << "Вы используете неправильную стоимость кВ/ч\n"
             << "Повторите ввод\n"
             << "price: "; Counter::input_check(price);
    }
    m_price = price;
}

float AccountBook::get_price() {
    return m_price;
}

void AccountBook::set_lenght(int length) {
    bool check = 0;
    while (true) {
        if (check == 0)
            check = 1;
        else
            break;
        if (length < 0) {
            cout << "Вы ввели неправильный размер\n"
                << "Размер должен быть больше 0\n"
                << "Повторите ввод: "; Counter::input_check(length);
        }
    }
    m_length = length;
}

ifstream &operator>>(ifstream &fin, AccountBook &obj) {
    obj.m_accounts = new ElectricityCounter[0];
    int i = 1;
    while (!fin.eof()) {
        obj.resize(i);
        fin >> obj.m_accounts[i-1];
        i++;
    }
    return fin;
}

ofstream &operator<<(ofstream &fout, AccountBook &obj) {
    fout << "Расчетная книга\n"
         << "Cтоимость кВ/ч = " << obj.m_price
         << "\nДата:\n"
         << "\tдень: " << obj.m_date->day
         << "\n\tмесяц: " << obj.m_date->month
         << "\n\tгод: " << obj.m_date->year << endl;

    fout << "\nПоказания счетчика\n";

    for (Iter i(obj.begin()); i != obj.end(); ++i) {
        fout << (i - obj.begin()) + 1 << " показание счетчика электричества\n";
        fout << obj.m_accounts[i-obj.begin()] << endl;
    }

    fout << endl << "Общее колличество киловат: " << obj.sum_accounts() << endl;
    fout << "Общая стоимость: " << obj.price_accounts() << endl;

    return fout;
}
