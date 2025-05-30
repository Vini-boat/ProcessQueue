#include <iostream>
#include <string>
#include "datastructures/queue.hpp"

using namespace std;
int main() {
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.exists(5) << endl;
    while(!q.isEmpty())
    {
        cout << q.pop() << endl;
    }
    return 0;
}