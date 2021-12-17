#include <bits/stdc++.h>
using namespace std;

const int M = 10000;
int n, m, k;
int arr[M + 1];
int idx = 0;

void solution() {

    idx++;

    if (idx == k) {
        for (int i = 1; i <= m; i++) {
            cout << arr[i] << " ";
        }
    }
}

void Try(int a) {

    for (int i = arr[a - 1] + 1; i <= n - m + a; i++) {
        arr[a] = i;

        if (a == m) {
            solution();
        } else {
            if (idx < k) {
                Try(a + 1);
            }
        }
    }
}

int main() {

    cin >> n >> m >> k;

    arr[0] = 0;

    Try(1);

    if (idx < k) {
        cout << -1;
    }

    return 0;
}