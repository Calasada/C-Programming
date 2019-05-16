#include <iostream>
#include <string>
#include "linkedList.h"
using namespace std;

int main() {

    unorderedLinkedList<int> l;
    l.insertFirst(9);
    l.insertFirst(5);
    l.insertFirst(8);
    l.insertFirst(3);
    l.insertFirst(2);
    cout << l << endl;

    l.printBackward();

   return 0;
}