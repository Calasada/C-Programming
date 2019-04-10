#ifndef UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_H

#include "linkedList.h"

template <class type>
class unorderedLinkedList : public linkedList<type> {
public:
    bool search(const type& searchItem) const;
    void insertFirst(const type& newItem);
    void insertLast(const type& newItem);
    void delteNode(const type& deleteItem);
};

#endif