#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, b;
    cin >> n >> b;
    getchar();

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxLeft[n];
    int maxRight[n];
    maxLeft[0] = arr[0];
    maxRight[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++) {
        maxLeft[i] = max(maxLeft[i - 1], arr[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        maxRight[i] = max(maxRight[i + 1], arr[i]);
    }

    int res = INT_MIN;
    for (int i = 1; i < n - 1; i++) {
        if (maxLeft[i - 1] - arr[i] >= b && maxRight[i + 1] - arr[i] >= b) {
            res = max(res, maxLeft[i - 1] + maxRight[i + 1] - 2 * arr[i]);
        }
    }

    cout << (res == INT_MIN ? -1 : res); 

    return 0;
}



