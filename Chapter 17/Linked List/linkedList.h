#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <class type>
class node {
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
    type head();
    type last();
    
    const linkedList<type>& operator=(const linkedList<type>&);
    friend ostream& operator<<(ostream&, const linkedList<type>&);

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
    cout << "head -> ";
    node<type> *next = head;
    for(int i = 0; i < l; i++) {
        cout << "[" << next->info << "] -> ";
        next = next->link;
    }
    return 0;
}

#endif