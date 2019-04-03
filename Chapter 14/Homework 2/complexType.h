#ifndef H_complexNumber
#define H_complexNumber
#include <iostream>
#include <cmath>
using namespace std;
class complexType {
  // Overload the stream insertion and extraction operators
  friend ostream& operator<<(ostream&, const complexType&);
  friend istream& operator>>(istream&, complexType&);

 public:
  void setComplex(const double& real, const double& imag);
  // Function to set the complex numbers according to
  // the parameters.
  // Postcondition: realPart = real; imaginaryPart = imag;
  void getComplex(double& real, double& imag) const;
  // Function to retrieve the complex number.
  // Postcondition: real = realPart; imag = imaginaryPart;
  complexType(double real = 0, double imag = 0);
  // Constructor
  // Initializes the complex number according to
  // the parameters.
  // Postcondition: realPart = real; imaginaryPart = imag;
  void print();
  // complexType operator+(const complexType& otherComplex) const;
  // // Overload the operator +
  // complexType operator*(const complexType& otherComplex) const;
  // // Overload the operator *
  // bool operator==(const complexType& otherComplex) const;
  // // Overload the operator ==
  // complexType operator-(const complexType&) const;
  // complexType operator/(const complexType&) const;

  friend complexType operator+(complexType&, complexType&);
  friend complexType operator-(complexType&, complexType&);
  friend complexType operator*(complexType&, complexType&);
  friend complexType operator/(complexType&, complexType&);
  friend bool operator==(complexType&, complexType&);
  friend bool operator<(complexType&, complexType&);
  friend bool operator>(complexType&, complexType&);
 private:
  double realPart;       // variable to store the real part
  double imaginaryPart;  // variable to store the
  // imaginary part
};

istream& operator>>(istream& isObject, complexType& complex) {
  char ch;
  isObject >> ch;                     // Step a
  isObject >> complex.realPart;       // Step b
  isObject >> ch;                     // Step c
  isObject >> complex.imaginaryPart;  // Step d
  isObject >> ch;                     // Step e
  return isObject;                    // return the istream object
}
ostream& operator<<(ostream& isObject, const complexType& complex) {
  isObject << complex.realPart;       // Step b
  isObject << "+";                     // Step c
  isObject << complex.imaginaryPart;  // Step d
  isObject << "i";                     // Step e
  return isObject;                    // return the istream object
}

// Constructor
complexType::complexType(double real, double imag) {
  realPart = real;
  imaginaryPart = imag;
}
// Function to set the complex number after the object
// has been declared.
void complexType::setComplex(const double& real, const double& imag) {
  realPart = real;
  imaginaryPart = imag;
}
void complexType::getComplex(double& real, double& imag) const {
  real = realPart;
  imag = imaginaryPart;
}
// bool complexType::operator==(const complexType& otherComplex) const {
//   return (realPart == otherComplex.realPart && imaginaryPart == otherComplex.imaginaryPart);
// }
// // overload the operator +
// complexType complexType::operator+(const complexType& otherComplex) const {
//   complexType temp;
//   temp.realPart = realPart + otherComplex.realPart;
//   temp.imaginaryPart = imaginaryPart + otherComplex.imaginaryPart;
//   return temp;
// }
// complexType complexType::operator*(const complexType& otherComplex) const {
//   complexType temp;
//   temp.realPart = (realPart * otherComplex.realPart) - (imaginaryPart * otherComplex.imaginaryPart);
//   temp.imaginaryPart =
//       (realPart * otherComplex.imaginaryPart) + (imaginaryPart * otherComplex.realPart);
//   return temp;
// }

// complexType complexType::operator-(const complexType& c) const {
//     double r1, i1, r2, i2;
//     this->getComplex(r1, i1);
//     c.getComplex(r2, i2);
//     complexType nc(r1-r2, i1-i2);
//     return nc;
// }
// complexType complexType::operator/(const complexType& c) const {
//   double denom = pow(c.realPart, 2) + pow(c.imaginaryPart, 2);
//   complexType temp1 = c;
//   temp1.imaginaryPart *= -1;
//   complexType temp2 = *this*temp1;
//   temp2.realPart /= denom;
//   temp2.imaginaryPart /= denom; 
//   return temp2;
// }

complexType operator+(complexType& c1, complexType& c2) {
  double r1, i1, r2, i2;
  c1.getComplex(r1, i1);
  c2.getComplex(r2, i2);
  complexType nc(r1+r2, i1+i2);
  return nc;
}
complexType operator-(complexType& c1, complexType& c2) {
  double r1, i1, r2, i2;
  c1.getComplex(r1, i1);
  c2.getComplex(r2, i2);
  complexType nc(r1-r2, i1-i2);
  return nc;
}
complexType operator*(complexType& c1, complexType& c2) {
  complexType temp;
  temp.realPart = (c1.realPart * c2.realPart) - (c1.imaginaryPart * c2.imaginaryPart);
  temp.imaginaryPart = (c1.realPart * c2.imaginaryPart) + (c1.imaginaryPart * c2.realPart);
  return temp;
}
complexType operator/(complexType& c1, complexType& c2) {
  double denom = pow(c2.realPart, 2) + pow(c2.imaginaryPart, 2);
  complexType temp1 = c2;
  temp1.imaginaryPart *= -1;
  complexType temp2 = c1*temp1;
  temp2.realPart /= denom;
  temp2.imaginaryPart /= denom; 
  return temp2;
}
bool operator==(complexType& c1, complexType& c2) {
  return (c1.realPart == c2.realPart && c1.imaginaryPart == c2.imaginaryPart);
}
bool operator<(complexType& c1, complexType& c2) {
  return (c1.realPart < c2.realPart && c1.imaginaryPart < c2.imaginaryPart);
}
bool operator>(complexType& c1, complexType& c2) {
 return (c1.realPart > c2.realPart && c1.imaginaryPart > c2.imaginaryPart);
}
void complexType::print() {
  cout << realPart << " + " << imaginaryPart << "i";
}
#endif