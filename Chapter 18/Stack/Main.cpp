#include <iostream>
#include "linkedList.h"
#include "stack.h"
using namespace std;

int main() {

  stack<int> *s = new stack<int>;

  s->push(5);
  s->pop();

  cout << *s;

  return 0;
}