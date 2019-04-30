#include <iostream>
#include <cstring>
#include "myString.h"
using namespace std;

int main() {
    newString s1("Hello, "), s2("World!");
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    int output_from, output_to;

    cout << "Outputting from s1 ... " << endl;
    cout << "From: "; 
    cin >> output_from;
    cout << "To: ";
    cin >> output_to;
    s1.output(output_from, output_to, cout);
    cout << endl;


    int search_from, search_to;
    char search_for;

    cout << "Searching in s1 ... " << endl;
    cout << "From: "; 
    cin >> search_from;
    cout << "To: ";
    cin >> search_to;
    cout << "For: ";
    cin >> search_for;
    cout << s1.search(search_from, search_to, search_for, cout) << endl;


    int replace_from;
    string replace_for;

    cout << "Replacing in s1 ... " << endl;
    cout << "From: "; 
    cin >> replace_from;
    cout << "For: ";
    cin >> replace_for;
    s1.replace(replace_from, replace_for, cout);
    cout << endl;

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    cout << "s1+s2: " << s1+s2 << endl;
    cout << "s1==s2: " << (s1==s2) << endl;
    cout << "s1>s2: " << (s1>s2) << endl;
    cout << "s1<s2: " << (s1<s2) << endl;


    return 0;
}