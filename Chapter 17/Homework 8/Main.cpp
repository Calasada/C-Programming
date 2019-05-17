#include <iostream>
#include <string>
#include "linkedList.h"
using namespace std;

int main() {

    circularLinkedList<int> l;
    l.insertItem(5);
    l.insertItem(6);
    l.insertItem(2);

    cout << l << endl;
    cout << l.search(2) << endl;

    l.deleteItem(1);

    cout << l;

   return 0;
}