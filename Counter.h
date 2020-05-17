#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Counter {
public:
	float m_counter;
	
	virtual void print_counter() = 0;

	// template <typename T> void input_check(T num) {
	// 	while (!(cin >> num)) {
	// 		cin.clear();
	// 		cin.ignore(cin.rdbuf()->in_avail());
	// 		cout << "Вы используете неправильный тип данных\n"
	// 			 << "Переменная должна быть " << typeid(num).name() << endl
	// 			 << "Повторите ввод: ";
	// 	}
	// }

	virtual ~Counter();
};
