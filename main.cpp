#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>

#include "DigitalCounter.h"
#include "ElectricityCounter.h"
#include "AccountBook.h"

using namespace std;

void Debug();

int main() {
	system("chcp 1251");
	Debug();
}

void Debug() {
	AccountBook test(1, 5, 5, 5);
	ElectricityCounter ttt(0, 999, 9, 4, 2);
	test.add_elem_end(ttt);
}
