#include <bits/stdc++.h>
using namespace std;

// leetcode
long long calArea(int n, long long heights[]) {

    // stack<int> stk;
    // stk.push(-1);
    // long long max_area = 0;

    // for (size_t i = 0; i < n; i++) {
    //     while (stk.top() != -1 and heights[stk.top()] >= heights[i]) {
    //         long long current_height = heights[stk.top()];
    //         stk.pop();
    //         long long current_width = i - stk.top() - 1;
    //         max_area = max(max_area, current_height * current_width);
    //     }
    //     stk.push(i);
    // }

    // while (stk.top() != -1) {
    //     long long current_height = heights[stk.top()];
    //     stk.pop();
    //     long long current_width = n - stk.top() - 1;
    //     max_area = max(max_area, current_height * current_width);
    // }

    // return max_area;

    vector<int> left(n, 0);
    for (int i = 1; i < n; i++) {
        left[i] = i;
        while (left[i] > 0 && heights[left[i] - 1] >= heights[i]) {
            left[i] = left[left[i] - 1];
        }
    }

    vector<int> right(n, n - 1);
    for (int i = n - 2; i >= 0; i--) {
        right[i] = i;
        while (right[i] < n - 1 && heights[right[i] + 1] >= heights[i]) {
            right[i] = right[right[i] + 1];
        }
    }

    long long maxArea = 0;
    for (int i = 0; i < n; i++) {
        maxArea = max(maxArea, heights[i] * (right[i] - left[i] + 1));
    }

    return maxArea;
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