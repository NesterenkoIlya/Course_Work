#include "DigitalCounter.h"

void DigitalCounter::value_check() {
	if (counter > max_value || counter < min_value)
		counter = min_value;
}

DigitalCounter::DigitalCounter() {
	min_value = 0;
	counter = min_value;
	max_value = 0;
	value_check();
}

DigitalCounter::DigitalCounter(int min, int max, float c) {
	min_value = min;
	max_value = max;
	counter = c;
	value_check();
}

DigitalCounter::DigitalCounter(DigitalCounter& obj) {
	counter = obj.counter;
	min_value = obj.min_value;
	max_value = obj.max_value;
	value_check();
}

void DigitalCounter::counter_increment() {
	counter++;
	value_check();
}

void DigitalCounter::input() {
	cout << "Class Digital counter\n";
	cout << "min_value: "; cin >> min_value;
	cout << "max_value: "; cin >> max_value;
	cout << "counter: "; cin >> counter;
	value_check();
}

void DigitalCounter::output() {
	cout << "Class DigitalCounter\n"
		<< "min_vlaue = " << min_value
		<< "\nmax_value = " << max_value
		<< "\ncounter = " << counter
		<< endl;
}

void DigitalCounter::print_counter() {
	cout << "Class DigitalCounter\n";
	cout << "counter = " << counter;
}

void DigitalCounter::set_min_value(int min) {
	min_value = min;
}

void DigitalCounter::set_max_value(int max) {
	max_value = max;
}

float DigitalCounter::get_counter() {
	return counter;
}

void DigitalCounter::operator()(int min, int max, float c) {
	min_value = min;
	max_value = max;
	counter = c;
	value_check();
}

void DigitalCounter::operator++(int) {
	counter++;
	value_check();
}

void DigitalCounter::operator--(int) {
	counter--;
	value_check();
}

DigitalCounter& DigitalCounter::operator=(const DigitalCounter& obj) {
	min_value = obj.min_value;
	max_value = obj.max_value;
	counter = obj.counter;
	return *this;
}

DigitalCounter::~DigitalCounter() {
	cout << "Destructor DigitalCounter\n";
}

DigitalCounter& operator+=(DigitalCounter& left, float right) {
	left.counter += right;
	left.value_check();
	return left;
}

DigitalCounter& operator-=(DigitalCounter& left, float right) {
	left.counter -= right;
	left.value_check();
	return left;
}

istream& operator>>(istream& in, DigitalCounter& obj) {
    bool check = 1;
    while (true) {
        cout << "min_value: "; in >> obj.min_value;
        cout << "max_value: "; in >> obj.max_value;
        cout << "counter: "; in >> obj.counter;

        if (obj.max_value < obj.min_value)
            cout << "You input incorrect max_value\n"
                 << "max_value must be over " << obj.min_value;

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

ostream& operator<<(ostream& out, DigitalCounter& obj) {
	out << "Class DigitalCounter\n"
		<< "min_vlaue = " << obj.min_value
		<< "\nmax_value = " << obj.max_value
		<< "\ncounter = " << obj.counter
		<< endl;
	return out;
}
