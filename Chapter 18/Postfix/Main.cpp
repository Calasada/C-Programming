#include <iostream>
#include <string>
#include "linkedList.h"
#include "stack.h"
using namespace std;

void operate(char, stack<int>*);
int char_to_int(char);

int main() {

  string exp;
  cin >> exp;

  stack<int> *s = new stack<int>;

  for(int i = 0; i < exp.size(); i++) {
    int num = char_to_int(exp[i]);
    if((num >= 0) && (num) < 10) {
      s->push(num);
    } else {
      operate(exp[i], s);
    }
  }

  cout << s->top();

  return 0;
}

void operate(char oper, stack<int>* s) {
  int num_1 = s->pop();
  int num_2 = s->pop();
  switch (oper) {
    case '+':
      s->push(num_1 + num_2);
      break;
    case '-':
      s->push(num_1 - num_2);
      break;
    case '*':
      s->push(num_1 * num_2);
      break;
    case '/':
      s->push(num_1 / num_2);
      break;
  }
}

int char_to_int(char c) {
  return ((int) c) - 48;
}