#include <iostream>
#include "linkedList.h"
#include "stack.h"
using namespace std;

int main() {

  stack<int> s;

  s.push(5);
  cout << s.pop() << endl;

  s.push(4);
  cout << s.top() << endl;

  cout << s;

  return 0;
}