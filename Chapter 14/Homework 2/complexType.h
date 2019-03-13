#ifndef H_complexNumber
#define H_complexNumber
#include <iostream>
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
  complexType operator+(const complexType& otherComplex) const;
  // Overload the operator +
  complexType operator*(const complexType& otherComplex) const;
  // Overload the operator *
  bool operator==(const complexType& otherComplex) const;
  // Overload the operator ==
  complexType operator-(const complexType&) const;
  complexType operator/(const complexType&) const;
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
bool complexType::operator==(const complexType& otherComplex) const {
  return (realPart == otherComplex.realPart && imaginaryPart == otherComplex.imaginaryPart);
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
// overload the operator +
complexType complexType::operator+(const complexType& otherComplex) const {
  complexType temp;
  temp.realPart = realPart + otherComplex.realPart;
  temp.imaginaryPart = imaginaryPart + otherComplex.imaginaryPart;
  return temp;
}
complexType complexType::operator*(const complexType& otherComplex) const {
  complexType temp;
  temp.realPart = (realPart * otherComplex.realPart) - (imaginaryPart * otherComplex.imaginaryPart);
  temp.imaginaryPart =
      (realPart * otherComplex.imaginaryPart) + (imaginaryPart * otherComplex.realPart);
  return temp;
}

complexType complexType::operator-(const complexType& c) const {
    double r1, i1, r2, i2;
    this->getComplex(r1, i1);
    c.getComplex(r2, i2);
    complexType nc(r1-r2, i1-i2);
    return nc;
}
complexType complexType::operator/(const complexType& c) const {

}
#endif