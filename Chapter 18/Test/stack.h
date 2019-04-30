#ifndef STACK_H
#define STACK_H

#include "linkedList.h"

template<class type>
class stack {
public:
    stack();
    ~stack();
    void push(const type&);
    type pop();
    type top();

    template<class type2>
    friend ostream& operator<<(ostream&, const stack<type2>&);

private:
    unorderedLinkedList<type>* list = new unorderedLinkedList<type>;
};

template<class type>
stack<type>::stack() {
}

template<class type>
stack<type>::~stack() {
    list->destroy();
}

template<class type>
void stack<type>::push(const type& newInfo) {
    list->insertFirst(newInfo);
}

template<class type>
type stack<type>::pop() {
    type temp = list->getHead();
    list->deleteItem(0);
    return temp;
}

template<class type>
type stack<type>::top() {
    return list->getHead();
}

template<class type>
ostream& operator<<(ostream& out, const stack<type>& s) {
    out << *s.list;
    return out;
}

#endif