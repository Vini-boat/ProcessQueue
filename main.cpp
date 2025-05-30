#include <iostream>
#include <string>
#include "queue.hpp"

using namespace std;
int main() {
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    while(!q.isEmpty())
    {
        cout << q.pop() << endl;
    }
    return 0;
}