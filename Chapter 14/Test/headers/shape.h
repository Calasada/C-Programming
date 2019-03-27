#ifndef SHAPE_H
#define SHAPE_H

class shape { 
public:
    virtual double perimeter() = 0;
    virtual double area() = 0;
    
    double* dimension;
    int dim;
};

#endif