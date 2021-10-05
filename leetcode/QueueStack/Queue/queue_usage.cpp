#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;

    q.push(5);
    q.push(13);
    q.push(8);
    q.push(6);

    if (q.empty()) {
        cout << "Queue is empty!" << endl;
        return 0;
    }

    q.pop();

    cout << "The first element is: " << q.front() << endl;
    cout << "The last element is: " << q.back() << endl;
    cout << "The size is: " << q.size() << endl;

    return 0;
}