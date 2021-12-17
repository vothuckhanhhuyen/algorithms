#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, l1, l2;
    cin >> n >> l1 >> l2;

    int arr[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int m[n + 1]; // tong vang lon nhat, i la cuoi cung
    int s[n + 1]; // tong vang lon nhat, tu 1 den i
    m[0] = s[0] = 0;
    for (int i = 1; i <= n; i++) {
        m[i] = arr[i];
        for (int j = l1; j <= l2; j++) {
            if (i - j < 0) {
                break;
            }
            m[i] = max(m[i], m[i - j] + arr[i]);
        }
        s[i] = max(s[i - 1], m[i]);
    }

    cout << s[n];

    return 0;
}