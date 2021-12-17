#include <bits/stdc++.h>
using namespace std;

int main() {

    // s[n - 1] = max(s[n - 2], e[n - 1])
    // e[n - 1] = max(e[n - 2] + a[n - 1], a[n - 1])
    // s[0] = a[0]
    // e[0] = a[0]

    int n;
    cin >> n;
    getchar();

    int a[n], s[n], e[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            e[i] = a[i];
            s[i] = a[i];
        } else {
            e[i] = max(e[i - 1] + a[i], a[i]);
            s[i] = max(s[i - 1], e[i]);
        }
    }

    cout << s[n - 1];

    return 0;
}