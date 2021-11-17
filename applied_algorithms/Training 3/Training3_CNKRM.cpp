#include <bits/stdc++.h>
using namespace std;

const int M = 1000000000 + 7;

int main() {

    int k, n;
    cin >> k >> n;

    int res[n + 1][n + 1];

    for (int i = 0; i <= n; i++) {
        res[0][i] = 1;
        res[i][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            res[j][i] = res[j][i - 1] % M + res[j - 1][i - 1] % M;
        }
    }

    cout << res[k][n] % M; 

    return 0;
}