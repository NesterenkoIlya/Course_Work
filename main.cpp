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
	cout << "Привет мир";
}

void Debug() {
	AccountBook test(1, 29, 2, 1600);
	cout << test;
}
