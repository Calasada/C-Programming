#include <iostream>
#include <string>
#include "fractionType.h"
using namespace std;

int main() {

    //Uses cin operator
    fractionType f1, f2;
    cout << "f1: " << endl;
    cin >> f1;

    cout << "f2: " << endl;
    cin >> f2;

    cout << "f1 + f2: " << (f1 + f2) << endl;
    cout << "f1 - f2: " << (f1 - f2) << endl;
    cout << "f1 * f2: " << (f1 * f2) << endl;
    cout << "f1 / f2: " << (f1 / f2) << endl;

    return 0;
}