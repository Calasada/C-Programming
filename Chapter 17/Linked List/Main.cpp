#include <iostream>
#include <string>
#include "linkedList.h"
using namespace std;

int main() {

    linkedList<int> l;

    l.build(3);

    cout << l;


   return 0;
}