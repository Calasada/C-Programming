#include "myString.h"
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;
// Constructor: conversion from the char string to newString
newString::newString(const char *str) {
  strLength = strlen(str);
  strPtr = new char[strLength + 1];  // allocate memory to
  // store the char string
  strcpy(strPtr, str);  // copy string into strPtr
}
// Default constructor to store the null string
newString::newString() {
  strLength = 0;
  strPtr = new char[1];
  strcpy(strPtr, "");
}
newString::newString(const newString &rightStr) {
  strLength = rightStr.strLength;
  strPtr = new char[strLength + 1];
  strcpy(strPtr, rightStr.strPtr);
}
newString::~newString() { }
// overload the assignment operator
const newString &newString::operator=(const newString &rightStr) {
  if (this != &rightStr)  // avoid self-copy
  {
    delete[] strPtr;
    strLength = rightStr.strLength;
    strPtr = new char[strLength + 1];
    strcpy(strPtr, rightStr.strPtr);
  }
  return *this;
}
char &newString::operator[](int index) {
  assert(0 <= index && index < strLength);
  return strPtr[index];
}
const char &newString::operator[](int index) const {
  assert(0 <= index && index < strLength);
  return strPtr[index];
}
// Overload the relational operators.
bool operator==(const newString &leftStr, const newString &rightStr) {
  return (strcmp(leftStr.strPtr, rightStr.strPtr) == 0);
}
bool operator<(const newString &leftStr, const newString &rightStr) {
  return (strcmp(leftStr.strPtr, rightStr.strPtr) < 0);
}
bool operator<=(const newString &leftStr, const newString &rightStr) {
  return (strcmp(leftStr.strPtr, rightStr.strPtr) <= 0);
}
bool operator>(const newString &leftStr, const newString &rightStr) {
  return (strcmp(leftStr.strPtr, rightStr.strPtr) > 0);
}
bool operator>=(const newString &leftStr, const newString &rightStr) {
  return (strcmp(leftStr.strPtr, rightStr.strPtr) >= 0);
}
bool operator!=(const newString &leftStr, const newString &rightStr) {
  return (strcmp(leftStr.strPtr, rightStr.strPtr) != 0);
}
newString newString::operator+(const newString& s) const {
  newString temp(*this);
  temp.strPtr = strcat(temp.strPtr, s.strPtr);
  temp.strLength += s.strLength;
  return temp;
}
void newString::operator+=(const newString& s) const {
    strcat(strPtr, s.strPtr);
}
int newString::length() {
  return strLength;
}
// Overload the stream insertion operator <<
ostream &operator<<(ostream &osObject, const newString &str) {
  osObject << str.strPtr;
  return osObject;
}
// Overload the stream extraction operator >>
istream &operator>>(istream &isObject, newString &str) {
  char temp[81];
  isObject >> setw(81) >> temp;
  str = temp;
  return isObject;
}
bool newString::output(int from, int to, ostream& out) {
  if(from > to) {
    out << "Index 1 > Index 2";
    return false;
  }
  if(from >= length() || to >= length() || from < 0 || to < 0) {
    out << "Index Out of Bounds";
    return false;
  }
  for(int i = from; i <= to; i++) {
    out << strPtr[i];
  }
  return true;
}
bool newString::search(int from, int to, char c, ostream& out) {
  if(from > to) {
    out << "Index 1 > Index 2";
    return false;
  }
  if(from >= length() || to >= length() || from < 0 || to < 0) {
    out << "Index Out of Bounds";
    return false;
  }
  for(int i = from; i <= to; i++) {
    if(c == strPtr[i]) {
      return true;
    };
  }
  return false;
}
bool newString::replace(int from, string s, ostream& out) {
  if(from >= length() || from < 0) {
    cout << "Index Out of Bounds";
    return false;
  }
  if(from + (s.size()) > length()) {
    out << "Replacing String too Large";
    return false;
  }
  for(int i = 0; i < s.size(); i++) {
    strPtr[i+from] = s[i];
  }
  return true;
}