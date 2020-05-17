#include "Iter.h"

Iter::Iter(ElectricityCounter *accounts) : i(accounts) { }

Iter::Iter(const Iter &x) : i(x.i) { }

Iter &Iter::operator=(const Iter &x) {
    i = x.i;
    return *this;
}

ElectricityCounter &Iter::operator*() const {
    return *i;
}

Iter &Iter::operator++() {
    ++i;
    return *this;
}

Iter &Iter::operator--() {
    --i;
    return *this;
}

Iter &Iter::operator++(int) {
    i++;
    return *this;
}

Iter &Iter::operator--(int) {
    i--;
    return *this;
}

Iter Iter::operator+(int n) {
    return Iter(i + n);
}

Iter Iter::operator-(int n) {
    return Iter(i - n);
}

Iter &Iter::operator+=(int n) {
    i += n;
    return *this;
}

Iter &Iter::operator-=(int n) {
    i -= n;
    return *this;
}

bool Iter::operator==(const Iter &x) const {
    return i == x.i;
}

bool Iter::operator!=(const Iter &x) const {
    return i != x.i;
}

bool Iter::operator<(const Iter &x) const {
    return i < x.i;
}

bool Iter::operator>(const Iter &x) const {
    return i > x.i;
}

bool Iter::operator<=(const Iter &x) const {
    return i <= x.i;
}

bool Iter::operator>=(const Iter &x) const {
    return i >= x.i;
}

int operator-(const Iter &x, const Iter &y) {
    return x.i - y.i;
}
