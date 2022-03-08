#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int smax = a[0];
    int ei = a[0];
    for (int i = 1; i < n; i++) {
        ei = max(a[i], a[i] + ei);
        smax = max(smax, ei);
    }

    cout << smax;

    return 0;
}
