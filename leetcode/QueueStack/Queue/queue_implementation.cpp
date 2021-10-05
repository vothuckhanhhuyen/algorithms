#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    vector<int> data;
    int p_start;
public:
    MyQueue() {
        p_start = 0;
    }

    bool enQueue(int x) {
        data.push_back(x);
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        p_start++;
        return true;
    }

    int Front() {
        return data[p_start];
    }

    bool isEmpty() {
        return p_start >= data.size();
    }
};

int main() {
    MyQueue q;

    q.enQueue(5);
    q.enQueue(3);
    if (!q.isEmpty()) {
        cout << q.Front() << endl;
    }

    q.deQueue();
    if (!q.isEmpty()) {
        cout << q.Front() << endl;
    }

    q.deQueue();
    if (!q.isEmpty()) {
        cout << q.Front() << endl;
    }

    return 0;
}