#include <iostream>
#include <string>
#include "linkedList.h"
using namespace std;

int main() {

    unorderedLinkedList<int> list_1;
    unorderedLinkedList<int> list_2;
    list_1.insertFirst(5);
    list_1.insertFirst(4);
    list_1.insertFirst(0);
    list_2.insertFirst(8);
    list_2.insertFirst(2);
    list_2.insertFirst(1);
    cout << list_1 << endl << list_2 << endl;

    list_1.merge(list_2);
    cout << list_1 << endl;


   return 0;
}