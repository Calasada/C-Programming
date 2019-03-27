#include "headers/rectangle.h"
#include <iostream>
using namespace std;

rectangle::rectangle() {
    dimension = new double[dim];
    for (int i = 0; i < dim; i++) dimension[i] = 0;
}

rectangle::rectangle(double w, double h) {
    dimension = new double[dim];
    dimension[0] = w;
    dimension[1] = h;
}

rectangle::~rectangle() {
    delete[] dimension;
}

double rectangle::area() {
    return dimension[0] * dimension[1];
} 

double rectangle::perimeter() {
    return 2 * (dimension[0] + dimension[1]);
}

bool rectangle::operator==(rectangle& r) {
    return area() == r.area();
}
rectangle rectangle::operator+(rectangle& r) {
    double newWidth, newHeight;
    newWidth = dimension[0] + r.dimension[0];
    newHeight = dimension[1] + r.dimension[1];
    rectangle newR(newWidth, newHeight);
    return newR;
}
rectangle rectangle::operator-(rectangle& r) {
    double newWidth, newHeight;
    newWidth = dimension[0] - r.dimension[0];
    newHeight = dimension[1] - r.dimension[1];
    rectangle newR(newWidth, newHeight);
    return newR;
}

ostream& operator<<(ostream& out, rectangle r) {
    out << "Width: " << r.dimension[0] << ", Height: " << r.dimension[1];
    return out;
}
istream& operator>>(istream& in, rectangle& r) {
    cout << "New Width: ";
    in >> r.dimension[0];
    cout << "New Height: ";
    in >> r.dimension[1];
    return in;
}
