#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double tol = 0.01;
double newtons(double, double);

int main() {

   int num;
   cout << "Number: ";
   cin >> num;

   cout << newtons(num, num);

   return 0;
}

double newtons(double x, double a) {
   if(abs(pow(a, 2) - x) <= tol) {
      return a;
   } else {
      return newtons(x, (pow(a, 2) + x) / (2 * a));
   }
}