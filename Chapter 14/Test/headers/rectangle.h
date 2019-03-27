#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include <iostream>
using namespace std;

class rectangle : public shape {
public:
    rectangle();
    rectangle(double, double);
    ~rectangle();
    double perimeter();
    double area();
    bool operator==(rectangle&);
    rectangle operator+(rectangle&);
    rectangle operator-(rectangle&);
    friend ostream& operator<<(ostream&, rectangle);
    friend istream& operator>>(istream&, rectangle&);
private:
    int dim = 2;
};

#endif