#include "AccountBook.h"

AccountBook::Date::Date() {
    day = 1;
    month = 1;
    year = 1970;
}

AccountBook::AccountBook() : m_lenght(0), m_accounts(nullptr), m_price(0) { }

AccountBook::AccountBook(int lenght, int m, int d, int y)
: m_lenght(lenght) {
    try {
        if (lenght < 0)
            throw "Lenght Error\n";
        else if (lenght == 0)
            m_accounts = nullptr;
        else {
            m_accounts = new ElectricityCounter[m_lenght];
            for (Iter i = begin(); i != end(); i++)
                *i = m_accounts[i - begin()];
        }
    } catch (string i) {
        cerr << i;
    }
}

AccountBook::AccountBook(const AccountBook& obj) {
    m_lenght = obj.m_lenght;
    m_accounts = new ElectricityCounter[m_lenght];
    for (Iter i(begin()); i != end(); ++i)
        *i = obj.m_accounts[i - begin()];
}

void AccountBook::erase() {
    delete[] m_accounts;
    m_accounts = nullptr; //Что б небыло висячего указателя
    m_lenght = 0;
}

void AccountBook::resize(int new_lenght) {
    if (new_lenght == m_lenght)
        return;
    else if (new_lenght <= 0) {
        erase();
        return;
    }
    ElectricityCounter *tmp = new ElectricityCounter[new_lenght];

    int copy = (m_lenght > new_lenght) ? new_lenght : m_lenght;
    for (Iter i(begin()); i != begin() + copy; ++i)
        tmp[i - begin()] = m_accounts[i-begin()];

    delete[] m_accounts;
    m_accounts = tmp;
    m_lenght = new_lenght;
}

void AccountBook::add_element(ElectricityCounter& elem, Iter index) {
    while (index < begin() || index > end()) {
        cout << "Вы ввели неправильный индекс\n"
            << "Повторите ввод индеска от 0 до " << m_lenght << ": ";
        int n;
        cin >> n;
        index = begin() + n;
    }

    ElectricityCounter *tmp = new ElectricityCounter[m_lenght + 1];

    for (Iter i(begin()); i != index; ++i)
        tmp[i - begin()] = m_accounts[i - begin()];
    tmp[index-begin()] = elem;
    for (Iter i(index); i < end(); ++i)
        tmp[i + 1 - begin()] = m_accounts[i-begin()];

    delete[] m_accounts;
    m_accounts = tmp;
    m_lenght++;
}

void AccountBook::remove_element(Iter index) {
    ElectricityCounter *tmp = new ElectricityCounter[m_lenght - 1];
    for (Iter i(begin()); i != index; ++i)
        tmp[i - begin()] = m_accounts[i - begin()];
    for (Iter i(index); i < end() - 1; i++)
        tmp[i - begin()] = m_accounts[i + 1 - begin()];

    delete[] m_accounts;
    m_accounts = tmp;
    m_lenght--;
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
        if ((m_date.day < 1 || m_date.day > 31) ||
            (m_date.day == 31 &&
             (m_date.month == 4 || m_date.month == 6 || m_date.month == 9 || m_date.month == 11))) {
            check = 0;
            cout << "Введите правильный день недели: ";
            cin >> m_date.day;
        } else if (m_date.month == 2 && m_date.day > 28) {
            if ((m_date.year % 400 == 0) ? true : (m_date.year % 4 == 0 && m_date.year % 100 != 0) && m_date.day > 29) {
                check = 0;
                cout << "Введите правильный день недели: ";
                cin >> m_date.day;
            } else if (m_date.day > 28) {
                check = 0;
                cout << "Введите правильный день недели: ";
                cin >> m_date.day;
            }
        }

        if (m_date.month < 1 || m_date.month > 12) {
            check = 0;
            cout << "Введите правильный месяц: "; cin >> m_date.month;
        }
        if (m_date.year < 0) {
            check = 0;
            cout << "Ввеите правильный год: "; cin >> m_date.year;
        }
    }
}   //Беды с датой

int AccountBook::get_lenght() {
     return m_lenght;
}

ElectricityCounter& AccountBook::operator[](Iter index) {
    int n;
    while (index < begin() || index >= end()) {
        cout << "Вы использовали неправильный индекс\n"
            << "Введите индекс от 0 до " << m_lenght - 1 << ": ";
        cin >> n;
        index = begin() + n;
    }
    return *index;
}

AccountBook::~AccountBook() {
    cout << "Destructor AccountBook\n";
    delete[] m_accounts;
}

istream &operator>>(istream &in, AccountBook &obj) {
    while (true) {
        cout << "Введите стоимость кВ/ч: "; in >> obj.m_price;
        if (obj.m_price < 0)
            cout << "Вы ввели не правильную стоимость. Повторите ввод";
        else
            break;
    }

    cout << "Введите день: "; in >> obj.m_date.day;
    cout << "Введите месяц: "; in >> obj.m_date.month;
    cout << "Введите год: "; in >> obj.m_date.year;
    obj.date_check();

    for (Iter i(obj.begin()); i != obj.end(); ++i) {
        cout << "Введите " << (i - obj.begin()) + 1 << " показание счетчика электричества\n";
        cin >> obj.m_accounts[i-obj.begin()];
    }

    return in;
}

ostream &operator<<(ostream &out, AccountBook &obj) {
    out << "Цена кВ/ч: " << obj.m_price
        << "\nДата\n"
        << "\n\tДень: " << obj.m_date.day
        << "\n\tМесяц: " << obj.m_date.month
        << "\n\tГод: " << obj.m_date.year << endl;

    return out;
}

Iter AccountBook::begin() {
    return Iter(m_accounts);
}

Iter AccountBook::end() {
    return Iter(m_accounts + m_lenght);
}

AccountBook &AccountBook::operator=(const AccountBook &obj) {
    m_lenght = obj.m_lenght;
    if (this != &obj) {
        delete[] m_accounts;
        m_accounts = new ElectricityCounter[m_lenght];
        for (Iter i(begin()); i != end(); ++i)
            *i = obj.m_accounts[i - begin()];
    }
    return *this;
}

float AccountBook::sum_all() {
    float sum = 0;
    for (Iter i(begin()); i != end(); ++i) {
        sum += m_accounts[i - begin()].m_counter;
    }

    return sum;
}

float AccountBook::price_all() {
    int sum = sum_all();
    int pr = sum * m_price;
    return pr;
}
