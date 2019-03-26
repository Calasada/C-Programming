#include <iostream>
#include <cstring>
#include "myString.h"
using namespace std;

int main() {
    newString s1("Hello, "), s2("World!");
    cout << s1+s2 << endl;
    cout << (s1 == s2); 
    return 0;
}