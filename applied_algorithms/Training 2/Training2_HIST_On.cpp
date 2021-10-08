#include <bits/stdc++.h>
using namespace std;

// leetcode
long long calArea(int n, long long heights[]) {

    stack<int> stk;
    stk.push(-1);
    long long max_area = 0;

    for (size_t i = 0; i < n; i++) {
        while (stk.top() != -1 and heights[stk.top()] >= heights[i]) {
            long long current_height = heights[stk.top()];
            stk.pop();
            long long current_width = i - stk.top() - 1;
            max_area = max(max_area, current_height * current_width);
        }
        stk.push(i);
    }

    while (stk.top() != -1) {
        long long current_height = heights[stk.top()];
        stk.pop();
        long long current_width = n - stk.top() - 1;
        max_area = max(max_area, current_height * current_width);
    }

    return max_area;
}

int main() {

    int n;
    while (cin >> n) {
        if (n == 0) {
            return 0;
        }
        long long hist[n];
        for (int i = 0; i < n; i++) {
            cin >> hist[i];
        }
        cout << calArea(n, hist) << endl;
    }

    return 0;
}