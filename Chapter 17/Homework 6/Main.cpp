#include <iostream>
#include <string>
#include "linkedList.h"
using namespace std;

int main() {

    unorderedLinkedList<int> l;
    linkedList<int>* list_1 = new unorderedLinkedList<int>;
    linkedList<int>* list_2 = new unorderedLinkedList<int>;
    l.insertFirst(6);
    l.insertLast(1);
    l.insertLast(4);
    l.insertLast(4);
    l.insertLast(9);
    cout << l << endl;

    l.subLists(3, list_1, list_2);

    cout << *list_1 << endl;
    cout << *list_2 << endl;

   return 0;
}