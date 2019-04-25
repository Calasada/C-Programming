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

    template<class type2>
    friend ostream& operator<<(ostream&, const stack<type2>&);

private:
    unorderedLinkedList<type>* list;
};

template<class type>
stack<type>::stack() {
    list = new unorderedLinkedList<type>;
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

template<class type>
ostream& operator<<(ostream& out, const stack<type>& s) {
    out << *s.list;
    return out;
}

#endif