#include <iostream>
#include "DigitalCounter.h"

using std::cin;
using std::cout;
using std::endl;

void Debug();

int main() {
	Debug();
}

void Debug() {
	DigitalCounter obj(10, 20, 10);
	obj.output();
	obj++;
	obj.output();
}