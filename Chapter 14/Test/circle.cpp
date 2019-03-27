#include "headers/circle.h"
#include <cmath>

# define M_PI 3.14159265358979323846

circle::circle() {
    dimension = new double[dim];
    for (int i = 0; i < dim; i++) dimension[i] = 0;
}

circle::circle(double r) {
    dimension = new double[dim];
    dimension[1] = r;
}

circle::~circle() {
    delete[] dimension;
}

double circle::perimeter() {
    return 2*M_PI*dimension[0];
}

double circle::area() {
    return M_PI*(pow(dimension[0], 2));
}

bool circle::operator==(circle& c) {
    return dimension[0] == c.dimension[0];
}

circle circle::operator+(circle& c) {
    double newRadius = 
}