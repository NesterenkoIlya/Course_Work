#include "DigitalCounter.h"

//Сбрасывает счетчик в начальное положение при достижении максиммального значения
void DigitalCounter::value_check() {
	if (m_counter == m_max_value)
        m_counter = m_min_value;
    else if (m_counter > m_max_value){
        while (m_counter > (m_max_value - m_min_value)){
            m_counter -= m_max_value - m_min_value + 1;
        }
        m_counter += m_min_value;
    }
}

//Конструктор по умолчанию
DigitalCounter::DigitalCounter() {
    m_min_value = 0;
    m_counter = m_min_value;
    m_max_value = 1;
}

DigitalCounter::DigitalCounter(int min_value, int max_value, float counter) {
    bool check = 0;
    while (true) {
        if (check == 0)
            check = 1;
        else
            break;
        if (min_value > max_value) {
            check = 0;
            cout << "Вы используете неправильное минимальное значение\n"
                 << "минимальное значение должно быть меньше" << max_value
                 << "\nПовторите ввод\n"
                 << "\nmin_value: "; input_check(min_value);
        }
        if (counter < min_value || counter > max_value) {
            check = 0;
            cout << "Вы используете неправильное значение счетчика\n"
                 << "Счетчик должен быть в диапазоне [" << min_value << "; "
                 << max_value << "]\n"
                 << "Повторите ввод\n"
                 << "counter: "; input_check(counter);
        }
    }
    m_min_value = min_value;
    m_max_value = max_value;
    m_counter = counter;
	value_check();
}

DigitalCounter::DigitalCounter(DigitalCounter &obj) {
    m_counter = obj.m_counter;
    m_min_value = obj.m_min_value;
}

void DigitalCounter::counter_increment() {
	m_counter++;
	value_check();
}

void DigitalCounter::input() {
	cout << "Class Digital counter\n";
	cout << "min_value: "; input_check(m_min_value);
	cout << "max_value: "; input_check(m_max_value);
	cout << "counter: "; input_check(m_counter);
	bool check = 0;
	while(true) {
	    if (check == 0)
	        check = 1;
	    else
	        break;
        if (m_min_value > m_max_value) {
            check = 0;
            cout << "Вы используете неправильное минимальное значение\n"
                 << "минимальное значение должно быть меньше" << m_max_value
                 << "\nПовторите ввод\n"
                 << "\nmin_value: "; input_check(m_min_value);
        }
        if (m_counter < m_min_value || m_counter > m_max_value) {
            check = 0;
            cout << "Вы используете неправильное значение счетчика\n"
                 << "Счетчик должен быть в диапазоне [" << m_min_value << "; "
                 << m_max_value << "]\n"
                 << "Повторите ввод\n"
                 << "counter: "; input_check(m_counter);
        }
	}
	value_check();
}

void DigitalCounter::output() {
	cout << "Class DigitalCounter\n"
         << "min_vlaue = " << m_min_value
         << "\nmax_value = " << m_max_value
         << "\ncounter = " << m_counter
		 << endl;
}

void DigitalCounter::print_counter() {
	cout << "Class DigitalCounter\n"
         << "counter = " << m_counter
		<< endl;
}

void DigitalCounter::set_min_value(int min_value) {
    m_min_value = min_value;
}

void DigitalCounter::set_max_value(int max_value) {
    m_max_value = max_value;
}

float DigitalCounter::get_counter() {
	return m_counter;
}

void DigitalCounter::operator()(int min_value, int max_value, float counter) {
    m_min_value = min_value;
    m_max_value = max_value;
    m_counter = counter;
	value_check();
}

void DigitalCounter::operator++(int) {
	m_counter++;
	value_check();
}

void DigitalCounter::operator--(int) {     //Проверочка
	m_counter--;
	value_check();
}

DigitalCounter& DigitalCounter::operator=(const DigitalCounter& obj) {
    m_min_value = obj.m_min_value;
    m_max_value = obj.m_max_value;
    m_counter = obj.m_counter;
	return *this;
}

DigitalCounter::~DigitalCounter() {
	cout << "Destructor DigitalCounter\n";
}

DigitalCounter& DigitalCounter::operator+=(float right) {
    m_counter += right;
	value_check();
	return *this;
}

DigitalCounter& DigitalCounter::operator-=(float right) {
    m_counter -= right;
	value_check();
	return *this;
}

istream& operator>>(istream &in, DigitalCounter &obj) {
    cout << "Class Digital counter\n";
    cout << "min_value: "; obj.input_check(obj.m_min_value, in);
    cout << "max_value: "; obj.input_check(obj.m_max_value, in);
    cout << "counter: "; obj.input_check(obj.m_counter, in);
    bool check = 0;
    while (true) {
        if (check == 0)
            check = 1;
        else
            break;
        if (obj.m_min_value > obj.m_max_value) {
            check = 0;
            cout << "Вы используете неправильное минимальное значение\n"
                 << "минимальное значение должно быть меньше" << obj.m_max_value
                 << "\nПовторите ввод\n"
                 << "\nmin_value: "; obj.input_check(obj.m_min_value, in);
        }
        if (obj.m_counter < obj.m_min_value || obj.m_counter > obj.m_max_value) {
            check = 0;
            cout << "Вы используете неправильное значение счетчика\n"
                 << "Счетчик должен быть в диапазоне [" << obj.m_min_value << "; "
                 << obj.m_max_value << "]\n"
                 << "Повторите ввод\n"
                 << "counter: "; obj.input_check(obj.m_counter, in);
        }
    }
	return in;
}

ostream& operator<<(ostream& out, DigitalCounter& obj) {
	out << "Class DigitalCounter\n"
		<< "min_vlaue = " << obj.m_min_value
		<< "\nmax_value = " << obj.m_max_value
		<< "\ncounter = " << obj.m_counter
		<< endl;
	return out;
}

int DigitalCounter::get_min_value() {
    return m_min_value;
}

int DigitalCounter::get_max_value() {
    return m_max_value;
}
