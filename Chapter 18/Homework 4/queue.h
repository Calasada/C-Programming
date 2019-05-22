#ifndef QUEUE_H
#define QUEUE_H

#include "linkedList.h"

template<class type>
class queue {
public:
    queue();
    ~queue();
    void push(const type&);
    type pop();
    type top();

    template<class type2>
    friend ostream& operator<<(ostream&, const queue<type2>&);

private:
    unorderedLinkedList<type>* list;
};

template<class type>
queue<type>::queue() {
    list = new unorderedLinkedList<type>;
}

template<class type>
queue<type>::~queue() {
    list->destroy();
}

template<class type>
void queue<type>::push(const type& newInfo) {
    list->insertFirst(newInfo);
}

template<class type>
type queue<type>::pop() {
    type temp = list->get(list->size - 1);
    list->deleteItem(list->size - 1);
    return temp;
}

template<class type>
type queue<type>::top() {
    return list->get(list->size - 1);
}

template<class type>
ostream& operator<<(ostream& out, const queue<type>& s) {
    out << *s.list;
    return out;
}

#endif