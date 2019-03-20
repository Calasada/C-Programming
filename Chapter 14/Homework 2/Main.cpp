#include <iostream>
#include <string>
#include "complexType.h"
using namespace std;

int main() {

   complexType c1(6, 3), c2(7, -5);

   complexType c3 = c1/c2;
   c3.print();
   cout << endl;

   return 0;
}