#include <iostream>
#include "myArray.h"
using namespace std;

int main() {

    const int length = 5;
    int arr[length] = { 1, 2, 3, 4, 5 };
    int arr_2[length] = { 1, 2, 3, 4, 5 };

    int* arr_ptr;
    arr_ptr = arr;
    int* arr_ptr_2;
    arr_ptr_2 = arr_2;

    newArray<int> a1(arr_ptr, length);
    newArray<int> a2(arr_ptr_2, length);

    cout << "a1: " << a1 << endl;
    cout << "a2: " << a2 << endl;

    cout << "a1 == a2: " << (a1 == a2) << endl;

    newArray<int> a3(a1 + a2);
    cout << "a3 = a1 + a2: " << (a1 + a2) << endl;


    int output_from, output_to;

    cout << "Outputting from a3 ... " << endl;
    cout << "From: "; 
    cin >> output_from;
    cout << "To: ";
    cin >> output_to;
    a3.output(output_from, output_to, cout);
    cout << endl;


    int search_from, search_to;
    char search_for;

    cout << "Searching in a3 ... " << endl;
    cout << "From: "; 
    cin >> search_from;
    cout << "To: ";
    cin >> search_to;
    cout << "For: ";
    cin >> search_for;
    cout << a3.search(search_from, search_to, search_for, cout) << endl;

    return 0;
}