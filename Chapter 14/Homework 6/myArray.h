#ifndef H_MYARRAY
#define H_MYARRAY

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cassert>
using namespace std;

template <class type>
class newArray {

    template<class type2>
    friend ostream& operator<<(ostream&, const newArray<type2>&);

public:
    newArray& operator=(const newArray<type>&) const;
    newArray(const type*, int len);
    newArray(const newArray<type>&);
    ~newArray();

    type &operator[](int);
    const type &operator[](int) const;
    template<class type2>
    friend bool operator==(const newArray<type2>&, const newArray<type2>&);
    template<class type2>
    friend bool operator!=(const newArray<type2>&, const newArray<type2>&);

    bool output(int, int, ostream&);
    bool search(int, int, type, ostream&);
    bool replace(int, const newArray<type>&, ostream&);

    newArray<type> operator+(const newArray<type>&) const;
    void operator+=(const newArray<type>&);

    int length() const;

private:
    type* arrPtr;
    int arrLength;

};

template<class type>
newArray<type>& newArray<type>::operator=(const newArray<type>& rightArr) const {
  if (this != &rightArr)  // avoid self-copy
  {
    delete[] arrPtr;
    arrLength = rightArr.length();
    arrPtr = new type[arrLength];
    for(int i = 0; i < rightArr.length(); i++) {
        arrPtr[i] = rightArr.arrPtr[i];
    }
  }
  return *this;
}
template<class type>
newArray<type>::newArray(const type* arr, int len) {
    arrLength = len;
    arrPtr = new type[arrLength];
    for(int i = 0; i < len; i++) {
        arrPtr[i] = arr[i];
    }
}

template<class type>
newArray<type>::newArray(const newArray<type>& arr) {
    arrLength = arr.length();
    arrPtr = new type[arrLength];
    for(int i = 0; i < arr.length(); i++) {
        arrPtr[i] = arr.arrPtr[i];
    }
}

template<class type>
newArray<type>::~newArray() {
    delete[] arrPtr;
}

template<class type>
type &newArray<type>::operator[](int index) {
  assert(0 <= index && index < arrLength);
  return arrPtr[index];
}

template<class type>
const type &newArray<type>::operator[](int index) const {
  assert(0 <= index && index < arrLength);
  return arrPtr[index];
}

template<class type>
bool operator==(const newArray<type>& leftArr, const newArray<type>& rightArr) {
    assert(leftArr.length() == rightArr.length());
    for(int i = 0; i < leftArr.length(); i++) {
        if(leftArr.arrPtr[i] != rightArr.arrPtr[i]) return false;
    }
    return true;
}

template<class type>
bool operator!=(const newArray<type>& leftArr, const newArray<type>& rightArr) {
    assert(leftArr.length() == rightArr.length());
    for(int i = 0; i < leftArr.length(); i++) {
        if(leftArr.arrPtr[i] == rightArr.arrPtr[i]) return false;
    }
    return true;
}

template<class type>
bool newArray<type>::output(int from, int to, ostream& out) {
  if(from > to) {
    out << "Index 1 > Index 2";
    return false;
  }
  if(from >= length() || to >= length() || from < 0 || to < 0) {
    out << "Index Out of Bounds";
    return false;
  }
  for(int i = from; i <= to; i++) {
    out << arrPtr[i];
  }
  return true;
}

template<class type>
bool newArray<type>::search(int from, int to, type t, ostream& out) {
  if(from > to) {
    out << "Index 1 > Index 2";
    return false;
  }
  if(from >= length() || to >= length() || from < 0 || to < 0) {
    out << "Index Out of Bounds";
    return false;
  }
  for(int i = from; i <= to; i++) {
    if(t == arrPtr[i]) {
      return true;
    };
  }
  return false;
}

template<class type>
bool newArray<type>::replace(int from, const newArray<type>& a, ostream& out) {
  if(from >= length() || from < 0) {
    cout << "Index Out of Bounds";
    return false;
  }
  if(from + (a.length()) > length()) {
    out << "Replacing String too Large";
    return false;
  }
  for(int i = 0; i < a.length(); i++) {
    arrPtr[i+from] = a.arrPtr[i];
  }
  return true;
}

template<class type>
newArray<type> newArray<type>::operator+(const newArray<type>& a) const {
    newArray<type> temp(*this);
    temp.arrPtr = new type[length() + a.length()];
    for(int i = 0; i < length(); i++)
        temp.arrPtr[i] = arrPtr[i];
    for(int i = 0; i < a.length(); i++)
        temp.arrPtr[i+length()] = a.arrPtr[i];
    temp.arrLength += a.length();
    return temp;
}

template<class type>
void newArray<type>::operator+=(const newArray<type>& a) {
    newArray<type> temp(*this);
    arrPtr = new type[length() + a.length()];
    for(int i = 0; i < length(); i++)
        arrPtr[i] = temp.arrPtr[i];
    for(int i = 0; i < a.length(); i++)
        arrPtr[i+length()] = a.arrPtr[i];
    arrLength += a.length();
}

template<class type>
int newArray<type>::length() const {
    return arrLength;
}

template<class type>
ostream& operator<<(ostream& osObject, const newArray<type>& arr) {
    for(int i = 0; i < arr.length(); i++) {
        osObject << arr.arrPtr[i];
    }
    return osObject;
}



#endif