#ifndef STACK_H
#define STACK_H

#include <cassert>
#include "linkedList.h"

template<class type>
class stack {
public:
    stack();
    ~stack();
    void push(const type&);
    type pop();
    type top();
    int length() const;

    bool operator==(const stack<type>&);

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
type stack<type>::pop() {
    type temp = list->head->info;
    list->deleteItem(0);
    return temp;
}

template<class type>
type stack<type>::top() {
    return list->head->info;
}

template<class type>
bool stack<type>::operator==(const stack<type>& s) {
    assert(s.length() == length());
    for(int i = 0; i < length(); i++) {
        if(list->get(i) != s.list->get(i)) {
            return false;
        }
    }
    return true;
}

template<class type>
int stack<type>::length() const {
    return list->length();
}

template<class type>
ostream& operator<<(ostream& out, const stack<type>& s) {
    out << *s.list;
    return out;
}

#endif