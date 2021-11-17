#include <bits/stdc++.h>
using namespace std;

const int MAX = 5010;
int a[MAX];
int n, k;

int binary_search(int key, int left, int right) {

    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == key) {
            return 1 + binary_search(key, left, mid - 1) + binary_search(key, mid + 1, right);
        } else if (a[mid] < key) {
            return binary_search(key, mid + 1, right);
        } else {
            return binary_search(key, left, mid - 1);
        }
    }
    
    return 0;
}

int main() {

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (k - a[i] - a[j] > 0) {
                res += binary_search(k - a[i] - a[j], j + 1, n - 1);
            }
        }
    }

    cout << res; 

    return 0;
}