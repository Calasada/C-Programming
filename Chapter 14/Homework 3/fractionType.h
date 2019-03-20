#ifndef FRACTIONTYPE_H
#define FRACTIONTYPE_H

#include <iostream>
using namespace std;

class fractionType {
public: 
    fractionType();
    fractionType(int, int);

    fractionType operator+(const fractionType&) const;
    fractionType operator-(const fractionType&) const;
    fractionType operator*(const fractionType&) const;
    fractionType operator/(const fractionType&) const;

    bool operator==(const fractionType&) const;
    bool operator<(const fractionType&) const;
    bool operator>(const fractionType&) const;

    friend ostream& operator<<(ostream& os, const fractionType&);
    friend istream& operator>>(istream& os, fractionType&);
private:
    int n;
    int d;
};

fractionType::fractionType() {
    
}

fractionType::fractionType(int numerator, int denominator) {
    n = numerator;
    d = denominator;
}

fractionType fractionType::operator+(const fractionType& f) const {
    fractionType temp((n*f.d + d*f.n), d*f.d);
    return temp;
}
fractionType fractionType::operator-(const fractionType& f) const {
    fractionType temp((n*f.d - d*f.n), d*f.d);
    return temp;
}
fractionType fractionType::operator*(const fractionType& f) const {
    fractionType temp(n*f.n, d*f.d);
    return temp;
}
fractionType fractionType::operator/(const fractionType& f) const {
    fractionType temp(n*f.d, d*f.n);
    return temp;
}

bool fractionType::operator==(const fractionType& f) const {
    return n*f.d == d*f.n;
}
bool fractionType::operator<(const fractionType& f) const {
    return n*f.d < d*f.n;
}
bool fractionType::operator>(const fractionType& f) const {
    return n*f.d > d*f.n;
}

ostream& operator<<(ostream& os, const fractionType& f) {
    os << f.n << "/" << f.d;
    return os;
}
istream& operator>>(istream& is, fractionType& f) {
    cout << "Numerator: ";
    is >> f.n;
    cout << "Denominator: ";
    is >> f.d;
    return is;
}

#endif