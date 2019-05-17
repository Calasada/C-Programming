#include <iostream>
#include <string>
#include "linkedList.h"
using namespace std;

int main() {

    unorderedLinkedList<int> l;
    l.insertFirst(3);
    l.insertFirst(6);
    l.insertFirst(2);
    l.insertFirst(5);
    l.insertFirst(6);
    cout << l << endl;

    l.deleteLowest();
    cout << l << endl;

    l.deleteAll(6);
    cout << l << endl;

    l.get(2);
    cout << endl << l.get(1) << endl;

    l.deleteItem(0);
    cout << l;


   return 0;
}