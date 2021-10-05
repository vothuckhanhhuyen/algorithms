#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<pair<int, int> > st;
public:
    void push (int x) { 
        if (st.empty()) {
            st.push({x, x});
        } else {
            st.push({x, min(st.top().second, x)});
        }
    }

    void pop () {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

int main() {

    MinStack obj;
 
    obj.push(3);
    obj.push(4);
    obj.pop();
    
    int param_3 = obj.top();
    int param_4 = obj.getMin();

    cout << param_3 << " " << param_4 << endl;

    return 0;
}