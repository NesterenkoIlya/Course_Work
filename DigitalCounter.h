#pragma once
#include "Counter.h"

class DigitalCounter :
	public Counter {
    void value_check();
protected:
	int m_min_value;
	int m_max_value;
public:
	DigitalCounter();
	DigitalCounter(int, int, float);
	DigitalCounter(DigitalCounter &);

	void counter_increment();
    void input();
	void output();

	void print_counter() override;

	void set_min_value(int);
	int get_min_value();
	void set_max_value(int);
	int get_max_value();
	float get_counter();

	void operator()(int, int, float);
	void operator++(int);
	void operator--(int);
	DigitalCounter& operator+=(float);
	DigitalCounter& operator-=(float);
	DigitalCounter& operator=(const DigitalCounter &);
	friend istream &operator>>(istream &, DigitalCounter &);
	friend ostream &operator<<(ostream &, DigitalCounter &);

	virtual ~DigitalCounter();
};
