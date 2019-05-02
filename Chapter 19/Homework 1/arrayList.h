#ifndef ARRAYLIST_H
#define ARRAYLIST_H

template <class type>
class arrayList {
public:

    bool isEmpty() const;
    bool isFull() const;
    int getLength() const;
    int getMaxSize() const;

    void sort();
    void print() const;
    void insertAt(const type&, int);

    virtual void insert(const type&) = 0;

    arrayList(int size = 50);
    ~arrayList();

private:

    int maxSize;
    int length;

    type *list;
};

template <class type>
bool arrayList<type>::isEmpty() const {
    return length == 0;
}

template <class type>
bool arrayList<type>::isFull() const {
    return length == maxSize;
}

template <class type>
int arrayList<type>::getLength() const {
    return length;
}

template <class type>
int arrayList<type>::getMaxSize() const {
    return maxSize;
}

template <class type>
arrayList<type>::arrayList(int size) {
    maxSize = size;
    length = 0;
    list = new type[maxSize + 1];
}

template <class type>
arrayList<type>::~arrayList() {
    delete [] list;
}

template <class type>
void arrayList<type>::sort() {
    int i, j;
    int min;
    type temp;

    for(i = 0; i < length; i++) {
        min = i;
        for(j = i + 1; j < length; ++j) 
            if(list[j] < list[min])
                min = j;
        temp = list[i];
        list[i] = list[min];
        list[min] = temp;
    }
}

template <class type>
void arrayList<type>::print() const {
    int i;
    for(int i = 0; i < length; ++i)
        cout << list[i] << " ";
    cout << endl;
}

template <class type>
void arrayList<type>::insertAt(const type& item, int position) {
    assert(position >= 0 && position < maxSize);
    list[position] = item;
    length++;
}

template<class type>
class orderedArrayList : public arrayList<type> {
public:
    void insert(const type&);
};

template <class type>
void orderedArrayList<type>::insert(const type& item) {
    assert(!isFull());
    list[length] = item;
    sort();
    length++;
}

#endif