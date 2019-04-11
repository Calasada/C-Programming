#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <class type>
class node {
public:
    type info;
    node<type> *link;
};

template <class type>
class linkedList {
public:

    linkedList();
    ~linkedList();
    node<type>* build(int);
    int length() const;
    void destroy();
    type getHead();
    type getLast();
    
    const linkedList<type>& operator=(const linkedList<type>&);
    
    template <class type2>
    friend ostream& operator<<(ostream&, const linkedList<type2>&);

    // virtual bool search(const type& searchItem) const = 0;
    // virtual bool insertFirst(const type& newItem) const = 0;
    // virtual bool insertLast(const type& newItem) const = 0;
    // virtual bool deleteNode(const type& deleteItem) const = 0;

    node<type> *head;
    node<type> *last;

    int size;
};



template <class type>
linkedList<type>::linkedList() {
    head = NULL;
    last = NULL;
    size = 0;
}

template <class type>
linkedList<type>::~linkedList() {}

template <class type>
node<type>* linkedList<type>::build(int l) {
    node<type>* newNode;
    head = NULL;
    for(int i = 0; i < l; i++) {
        newNode = new node<type>;
        newNode->info = 0;
        newNode->link = head;
        head = newNode;
        if(i == 0) {
            last = newNode;
        }
    }
    size = l;
    return head;
}

template <class type>
ostream& operator<<(ostream& out, const linkedList<type>& l) {
    out << "head -> ";
    node<type> *next = l.head;
    for(int i = 0; i < l.size; i++) {
        out << "[" << next->info << "]";
        if(i != l.size-1) {
            out << " -> ";
        }
        next = next->link;
    }
    return out;
}

#endif