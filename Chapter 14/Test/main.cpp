#include <iostream>
#include <string>
#include "headers/shape.h"
#include "headers/rectangle.h"
using namespace std;

int main() {

   rectangle r1, r2;
   cout << "Rectangle 1: " << endl;
   cin >> r1;

   cout << endl << "Rectangle 2: " << endl;
   cin >> r2;

   cout << endl << "R2 Perimeter: " << r1.perimeter() << endl;
   cout << "R1 Area: " << r1.area() << endl;
   cout << endl << "R2 Perimeter: " << r2.perimeter() << endl;
   cout << "R2 Area: " << r2.area() << endl;

   cout << endl << "R1 == R2: " << (r1 == r2) << endl;
   cout << "R1 + R2: " << (r1+r2) << endl;
   cout << "R1 - R2: " << (r1-r2) << endl;
   cout << "R2 - R1 : " << (r2-r1) << endl;

   return 0;
}