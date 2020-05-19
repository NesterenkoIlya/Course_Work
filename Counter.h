#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <time.h>
using namespace std;

class Counter {
public:
	float m_counter;
	
	virtual void print_counter() = 0;

	template <typename T> static void input_check(T& num, istream& in = cin) {
		while (!(in >> num)) {
			in.clear();
			in.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Ошибка типа данных\nЗначение должно быть типа "
				 << "\nПовторите ввод: ";
		}
	}

	virtual ~Counter();
};
