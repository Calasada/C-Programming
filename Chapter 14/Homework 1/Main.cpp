#include <iostream>
#include <string>
using namespace std;

class rectangleType {
   public:
    void setDimension(double l, double w);
    //Function to set the length and width of the rectangle.
    //Postcondition: length = l; width = w;
    double getLength() const;
    //Function to return the length of the rectangle.
    //Postcondition: The value of length is returned.
    double getWidth() const;
    //Function to return the width of the rectangle.
    //Postcondition: The value of width is returned.
    double area() const;
    //Function to return the area of the rectangle.
    //Postcondition: The area of the rectangle is
    // calculated and returned.
    double perimeter() const;
    //Function to return the perimeter of the rectangle.
    //Postcondition: The perimeter of the rectangle is
    // calculated and returned.
    void print() const;
    //Function to output the length and width of
    //the rectangle.
    rectangleType();
    //Default constructor
    //Postcondition: length = 0; width = 0;
    rectangleType(double l, double w);
    //Constructor with parameters
    //Postcondition: length = l; width = w;
    // rectangleType operator ++(int); // a++
    // rectangleType operator ++(); // ++a
    // rectangleType operator +(rectangleType);
    // rectangleType operator -(rectangleType);
    // bool operator <(rectangleType);
    // bool operator >(rectangleType);
    // bool operator ==(rectangleType);
    friend rectangleType operator ++(rectangleType&, int);
    friend rectangleType operator ++(rectangleType&);
    friend rectangleType operator +(rectangleType, rectangleType);
    friend rectangleType operator -(rectangleType, rectangleType);
    friend bool operator <(rectangleType, rectangleType);
    friend bool operator >(rectangleType, rectangleType);
    friend bool operator ==(rectangleType, rectangleType);
   private:
    double length;
    double width;
};

void rectangleType::setDimension(double l, double w) {
    if (l >= 0)
        length = l;
    else
        length = 0;
    if (w >= 0)
        width = w;
    else
        width = 0;
}
double rectangleType::getLength() const {
    return length;
}
double rectangleType::getWidth() const {
    return width;
}
double rectangleType::area() const {
    return length * width;
}
double rectangleType::perimeter() const {
    return 2 * (length + width);
}
void rectangleType::print() const {
    cout << "Length = " << length
         << "; Width = " << width;
}
rectangleType::rectangleType(double l, double w) {
    setDimension(l, w);
}
rectangleType::rectangleType() {
    length = 0;
    width = 0;
}

//Members
// // a++
// rectangleType rectangleType::operator ++(int i) {
//     rectangleType temp = *this;
//     this->length++;
//     this->width++;
//     return temp;
// }

// // ++a
// rectangleType rectangleType::operator ++() {
//     this->length++;
//     this->width++;
//     return *this;
// }

// rectangleType rectangleType::operator +(rectangleType r) {
//     double nl = this->getLength() + r.getLength();
//     double nw = this->getWidth() + r.getWidth();
//     rectangleType nr(nl, nw);
//     return nr;
// }

// rectangleType rectangleType::operator -(rectangleType r) {
//     double nl = this->getLength() - r.getLength();
//     double nw = this->getWidth() - r.getWidth();
//     rectangleType nr(nl, nw);
//     return nr;
// }

// bool rectangleType::operator >(rectangleType r) {
//     return this->area() > r.area();
// }

// bool rectangleType::operator <(rectangleType r) {
//     return this->area() < r.area();
// }

// bool rectangleType::operator ==(rectangleType r) {
//     return (this->getLength() == r.getLength()) && (this->getWidth() == r.getWidth());
// }

//Non-Members
// a++
rectangleType operator ++(rectangleType& r, int i) {
    rectangleType temp = r;
    r.length++;
    r.width++;
    return temp;
}

// ++a
rectangleType operator ++(rectangleType& r) {
    r.length++;
    r.width++;
    return r;
}

rectangleType operator +(rectangleType r1, rectangleType r2) {
    double nl = r1.getLength() + r2.getLength();
    double nw = r1.getWidth() + r2.getWidth();
    rectangleType nr(nl, nw);
    return nr;
}

rectangleType operator -(rectangleType r1, rectangleType r2) {
    double nl = r1.getLength() - r2.getLength();
    double nw = r1.getWidth() - r2.getWidth();
    rectangleType nr(nl, nw);
    return nr;
}

bool operator >(rectangleType r1, rectangleType r2) {
    return r1.area() > r2.area();
}

bool operator <(rectangleType r1, rectangleType r2) {
    return r1.area() < r2.area();
}

bool operator ==(rectangleType r1, rectangleType r2) {
    return (r1.getLength() == r2.getLength()) && (r1.getWidth() == r2.getWidth());
}

int main() {
    
    rectangleType r1(3, 4), r2(6, 2);

    cout << "r1: ";
    r1.print();
    cout << endl;
    cout << "r2: ";
    r2.print();
    cout << endl;

    cout << "r1++: ";
    r1++.print();
    //print r1, then increment
    cout << endl;
    cout << "++r1: ";
    (++r1).print();
    //increment r1, then print
    cout << endl;

    rectangleType r3 = r1 + r2;
    cout << "r3 (r1 + r2): ";
    r3.print();
    cout << endl;

    cout << "r2 < r3: " << (r2 < r3) << endl;
    cout << "r2 > r1: " << (r2 > r1) << endl;
    cout << "r1 == r3: " << (r1 == r3) << endl;

    return 0;
}