#include <iostream>
#include "queue.h"
using namespace std;

int main() {
 
    queue<int> q;

    q.push(4);
    q.push(3);
    cout << q.pop() << endl;
    cout << q.top();

    return 0;
}