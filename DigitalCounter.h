#pragma once

#include <iostream>
#include "Counter.h"
using namespace std;

class DigitalCounter : public Counter {
	int min_value;
	int max_value;

	void value_check();
public:
	DigitalCounter();
	DigitalCounter(int, int, float);
	DigitalCounter(DigitalCounter&);

	void counter_increment();
	void input();
	void output();

	void print_counter() override;
	
	void set_min_value(int);
	void set_max_value(int);
	float get_counter();

	void operator()(int, int, float);
	void operator++(int);
	void operator--(int);
	friend DigitalCounter& operator+=(DigitalCounter&, float);
	friend DigitalCounter& operator-=(DigitalCounter&, float);
	DigitalCounter& operator=(const DigitalCounter&);
	friend istream& operator>>(istream&, DigitalCounter&);
	friend ostream& operator<<(ostream&, DigitalCounter&);

	~DigitalCounter();
};
