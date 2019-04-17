#ifndef STACK_H
#define STACK_H

#include "linkedList.h"

template<class type>
class stack {
public:
    stack();
    ~stack();
    void push(const type&);
    void pop();
private:
    unorderedLinkedList<type>* list = new unorderedLinkedList<type>;
};

template<class type>
stack<type>::stack() {
    list->list();
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
void stack<type>::pop() {
    list->deleteItem(0);
}

#endif