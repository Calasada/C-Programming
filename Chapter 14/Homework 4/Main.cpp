#include <iostream>
#include <string>
using namespace std;

class clockType {
 public:
  void setTime(int, int, int);
  void getTime(int&, int&, int&) const;
  void getSeconds(int&) const;
  void printTime() const;
  void incrementSeconds();
  void incrementMinutes();
  void incrementHours();
  bool equalTime(const clockType&) const;

  friend clockType operator++(clockType& c);  //++a
  // friend clockType operator --(clockType c); //--a
  friend clockType operator++(clockType& c, int i);  // a++
  // friend clockType operator --(clockType c, int i); //a--

  friend bool operator<(clockType, clockType);
  friend bool operator>(clockType, clockType);
  friend bool operator==(clockType, clockType);

 private:
  int hr;
  int min;
  int sec;
};

void clockType::setTime(int hours, int minutes, int seconds) {
  if (0 <= hours && hours < 24)
    hr = hours;
  else
    hr = 0;
  if (0 <= minutes && minutes < 60)
    min = minutes;
  else
    min = 0;
  if (0 <= seconds && seconds < 60)
    sec = seconds;
  else
    sec = 0;
}
void clockType::getTime(int& hours, int& minutes, int& seconds) const {
  hours = hr;
  minutes = min;
  seconds = sec;
}
void clockType::getSeconds(int& seconds) const {
  seconds = hr * 3600 + min * 60 + sec;
}
void clockType::incrementHours() {
  hr++;
  if (hr > 23) hr = 0;
}
void clockType::incrementMinutes() {
  min++;
  if (min > 59) {
    min = 0;
    incrementHours();  // increment hours
  }
}
void clockType::incrementSeconds() {
  sec++;
  if (sec > 59) {
    sec = 0;
    incrementMinutes();  // increment minutes
  }
}
void clockType::printTime() const {
  if (hr < 10) cout << "0";
  cout << hr << ":";
  if (min < 10) cout << "0";
  cout << min << ":";
  if (sec < 10) cout << "0";
  cout << sec;
}
bool clockType::equalTime(const clockType& otherClock) const {
  return (hr == otherClock.hr && min == otherClock.min &&
          sec == otherClock.sec);
}

clockType operator++(clockType& c) {
  c.incrementSeconds();
  return c;
}

clockType operator++(clockType& c, int i) {
  clockType t = c;
  c.incrementSeconds();
  return t;
}

bool operator<(clockType c1, clockType c2) {
  int s1;
  int s2;
  c1.getSeconds(s1);
  c2.getSeconds(s2);
  return s1 < s2;
}
bool operator>(clockType c1, clockType c2) {
  int s1;
  int s2;
  c1.getSeconds(s1);
  c2.getSeconds(s2);
  return s1 > s2;
}
bool operator==(clockType c1, clockType c2) {
  int s1;
  int s2;
  c1.getSeconds(s1);
  c2.getSeconds(s2);
  return s1 == s2;
}

int main() {
  clockType clock1, clock2;
  clock1.setTime(0, 0, 15);
  clock2.setTime(0, 0, 30);

  clock1++.printTime();
  cout << endl;
  //clock1 is now 16 seconds, prints 15
  (++clock1).printTime();
  cout << endl;
  //clock1 is now 17 seconds, prints 17

  cout << ((clock1 < clock2) ? "true" : "false") << endl;
  cout << ((clock1 > clock2) ? "true" : "false") << endl;
  cout << ((clock1 == clock2) ? "true" : "false") << endl;

  return 0;
}