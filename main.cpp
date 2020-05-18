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
    ElectricityCounter test;
    cin >> test;
    cout << test;
}
