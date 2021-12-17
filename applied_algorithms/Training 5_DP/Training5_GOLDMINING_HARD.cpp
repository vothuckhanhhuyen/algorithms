#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, l1, l2;
    cin >> n >> l1 >> l2;

    int arr[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int dp[n + 1];
    for (int i = 1; i <= l1; i++) {
        dp[i] = arr[i];
    }

    priority_queue<pair<long long, int>> PQ;
    for (int i = l1 + 1; i <= n; i++) {
        while (!PQ.empty() && PQ.top().second < i - l2) {
            PQ.pop();
        }
        PQ.push({dp[i - l1], i - l1});
        dp[i] = PQ.top().first + arr[i];
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dp[i]);
    }

    cout << res;

    return 0;
}