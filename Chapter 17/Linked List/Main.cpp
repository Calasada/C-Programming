#include <iostream>
#include <string>
#include "linkedList.h"
using namespace std;

int main() {
  unorderedLinkedList<int>* l = new unorderedLinkedList<int>;

  l->build(5);
  l->insertFirst(3);
  l->insertFirst(2);
  l->insertLast(5);
  l->deleteNode(3);
  l->insertItem(1, 5);
  l->deleteItem(0);
  cout << *l;

  return 0;
}