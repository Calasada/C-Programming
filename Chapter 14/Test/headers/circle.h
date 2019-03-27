#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <iostream>
using namespace std;

class circle : public shape {
public: 
    circle();
    circle(double);
    ~circle();
    double perimeter();
    double area();
    bool operator==(circle&);
    circle operator+(circle&);
    circle operator-(circle&);
    friend ostream& operator<<(ostream&, circle);
    friend istream& operator>>(istream&, circle&);
private:
    int dim = 1;
};


#endif