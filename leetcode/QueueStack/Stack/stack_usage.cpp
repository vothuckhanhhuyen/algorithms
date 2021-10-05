#include <bits/stdc++.h>
using namespace std;

int main() {

    stack<int> s;

    s.push(5);
    s.push(13);
    s.push(8);
    s.push(6);

    if (s.empty()) {
        cout << "Stack is empty!" << endl;
        return 0;
    }

    s.pop();

    cout << "The top element is: " << s.top() << endl;
    cout << "The size is: " << s.size() << endl;

    return 0;
}