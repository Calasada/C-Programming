#include<iostream>
using namespace std;

void stars(int, int, bool);

int main() {

    int i;
    cout << "Nonnegative Integer: ";
    cin >> i;

    stars(i, i, false);

    return 0;
}

void stars(int num, int top, bool up) {
    for(int j = 0; j < num; j++) {
        cout << "*";
    }
    if(num != 0) {
        cout << endl;
    }

    if(up) {
        if(num == top) {
            return;
        }
        stars(num+1, top, up);
    } else {
        if(num == 0) {
            stars(num+1, top, true);
        } else {
            stars(num-1, top, up);
        }
    }
}