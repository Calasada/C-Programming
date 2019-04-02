#include<iostream>
#include<string>
#include<fstream>
using namespace std;

bool pallindrome(string);

int main() {

    ifstream file;
    file.open("words_alpha.txt");

    string largest = "";

    while(file) {
        string s;
        file >> s;
        cout << "Testing: \"" << s << "\"";
        cout << endl;
        if(pallindrome(s)) {
            if(s.length() > largest.length()) {
                largest = s;
            }
        }
    }

    cout << "Largest Pallindrome: " << largest;

    return 0;
}


bool pallindrome(string s) {
    if(s.length() == 0) {
        return true;
    }
    string l = s.substr(0, 1);
    string r = s.substr(s.length()-1, 1);
    if(s.length() == 2) {
        return (l == r);
    }
    string mid = s.substr(1, s.length()-2);

    if(s.length() <= 1) {
        return true;
    } else {
        return pallindrome(mid) && (l == r);
    }
}