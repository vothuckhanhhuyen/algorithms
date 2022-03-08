#include <bits/stdc++.h>
using namespace std;

int cnt;
int a[] = {0, 2, 3, 6, 7, 4, 5};

int P(int a[], int n, int W, int T, int k) {

    for (int v = 0; v <= 1; v++) {
        if (k == n) {
            if (T + v * a[k] == W) {
                cnt += 1;
            }
        } else {
            P(a, n, W, T + v * a[k], k + 1);
        }
    }
}

int main() {

    cnt  = 0;
    P(a, 6, 12, 0, 1);

    cout << cnt << endl;

    return 0;
}