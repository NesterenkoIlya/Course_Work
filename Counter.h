#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Counter {
public:
	float counter;
	
	virtual void print_counter() = 0;

	virtual ~Counter();
};

