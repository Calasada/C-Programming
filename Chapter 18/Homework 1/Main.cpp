#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

int main() {

    stack<int> s;
    stack<int> s2;
    s.push(1);
    s.push(2);
    s.push(3);
    s2.push(1);
    s2.push(2);
    s2.push(3);

    cout << s << endl << s2 << endl;
    cout << (s == s2);

   return 0;
}