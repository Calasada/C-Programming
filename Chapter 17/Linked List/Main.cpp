#include <iostream>
#include <string>
#include "linkedList.h"
using namespace std;

int main() {
  unorderedLinkedList<int>* l = new unorderedLinkedList<int>;

  l->build(5);
  cout << *l << endl;
  l->insertFirst(3);
  cout << *l << endl;
  l->insertFirst(2);
  cout << *l << endl;
  l->insertLast(5);
  cout << *l << endl;
  l->deleteNode(3);
  cout << *l << endl;
  l->insertItem(1, 5);
  cout << *l << endl;
  l->deleteItem(0);
  cout << *l;

  return 0;
}