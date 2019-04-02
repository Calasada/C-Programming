#include<iostream>
using namespace std;

int gcd(int, int);

int main() {

    int x, y;
    cout << "Two Integers: " << endl;
    cin >> x;
    cin >> y;

    cout << gcd(x, y);

    return 0;
}

int gcd(int x, int y) {
    if(y == 0) {
        return x;
    } else {
        return gcd(y, x%y);
    }
}