#include <iostream>
#include <string>
#include "complexType.h"
using namespace std;

int main() {

   complexType c1(6, 3), c2(7, -5);

   cout << "c1: " << c1 << endl;
   cout << "c2: " << c2 << endl;

   cout << "c1 + c2: " << (c1 + c2) << endl;
   cout << "c1 - c2: " << (c1 - c2) << endl;
   cout << "c1 * c2: " << (c1 * c2) << endl;
   cout << "c1 / c2: " << (c1 / c2) << endl;

   cout << "c1 == c2: " << (c1 == c2) << endl;
   cout << "c1 > c2: " << (c1 == c2) << endl;
   cout << "c1 < c2: " << (c1 == c2) << endl;

   return 0;
}