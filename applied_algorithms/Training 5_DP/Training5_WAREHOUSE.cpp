#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, T, D;
    cin >> N >> T >> D;

    int a[N + 1], t[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> t[i];
    }

    int dp[N + 1][T + 1] = {0};
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= T; j++) {
            if (t[i] > j) {
                continue;
            }
            dp[i][j] = a[i];
            for (int k = 1; k <= D; k++) {
                if (i - k <= 0) {
                    continue;
                }
                dp[i][j] = max(dp[i][j], dp[i - k][j - t[i]] + a[i]);
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= T; j++) {
            res = max(res, dp[i][j]);
        }
    }

    cout << res;

    return 0;
}