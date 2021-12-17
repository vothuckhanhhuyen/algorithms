#include <bits/stdc++.h>
using namespace std;

long long calArea(int start, int end, long long hist[]) {

    if (start > end) {
        return 0;
    }

    int idx = start;
    for (int i = start + 1; i <= end; i++) {
        if (hist[i] < hist[idx]) {
            idx = i;
        }
    }

    return max({(end - start + 1) * hist[idx], calArea(start, idx - 1, hist), calArea(idx + 1, end, hist)});
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
        cout << calArea(0, n - 1, hist) << endl;
    }

    return 0;
}