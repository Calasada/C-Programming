#include <iostream>
#include <string>
#include "linkedList.h"
using namespace std;

int main() {

    unorderedLinkedList<int> l;

    l.build(3);
    l.insertFirst(15);

    cout << l;

   return 0;
}
