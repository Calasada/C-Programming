#include <iostream>
#include <string>
#include "linkedList.h"
using namespace std;

int main() {
  orderedLinkedList<int>* l = new orderedLinkedList<int>;

  l->insert(5);
  l->insert(4);
  l->insert(3);

  cout << *l;

  return 0;
}