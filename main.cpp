#include <iostream>
#include "DigitalCounter.h"
#include "ElectricityCounter.h"
#include <cmath>
#include <iomanip>

using namespace std;

void Debug();

int main() {
	system("chcp 1251");
	Debug();
}

void Debug() {
	cout << "ElectricityCounter Debug\n";
	ElectricityCounter test;
	cout << test;
	cin >> test;
	cout << test;
}
