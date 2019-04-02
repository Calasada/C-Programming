#include<iostream>
using namespace std;

void decToBase(int, int);

int main() {

    int num, base;
    cout << "Decimal Number: ";
    cin >> num;
    cout << "Base: ";
    cin >> base;

    decToBase(num, base);

    return 0;
}

void decToBase(int dec, int base) {
    if(dec > 0) {
        decToBase(dec/base, base);
        int digit = dec % base;
        if(digit > 9) {
            char charDigit = (char) (64 + (digit - 9));
            cout << charDigit;
        } else {
            cout << digit;
        }
    }
}
