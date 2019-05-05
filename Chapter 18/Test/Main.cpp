#include <iostream>
#include "linkedList.h"
#include "stack.h"
using namespace std;

int main() {

    unorderedLinkedList<int> *l = new unorderedLinkedList<int>;

    l->insertFirst(7);
    l->insertFirst(2);
    l->insertFirst(4);
    l->insertFirst(2);
    l->insertFirst(9);

    cout << "List L: " << *l << endl;

    stack<node<int>*> *s = new stack<node<int>*>;

    node<int> *current = l->head;
    for(int i = 0; i < l->length(); i++) {
        s->push(current);
        current = current->link;
    }

    cout << "Stack: " << *s << endl;

    cout << "L Backwards: ";
    for(int i = 0; i < l->length(); i++) {
        cout << s->pop()->info << ", ";
    }

    return 0;
}