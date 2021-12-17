#include <bits/stdc++.h>
using namespace std;

const int mx = 1e4 + 10;
int n, m;
int x[mx], y[mx];
int res[mx][mx];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> y[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (x[i] == y[j]) {
                res[i][j] = res[i - 1][j - 1] + 1;
            } else {
                res[i][j] = max(res[i - 1][j], res[i][j - 1]);
            }
        }
    }

    cout << res[n][m];

    return 0;
}
