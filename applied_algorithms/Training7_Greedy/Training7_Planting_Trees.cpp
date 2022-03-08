#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> days(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> days[i];
    }
    sort(days.begin() + 1, days.end(), [](const int &x, const int &y) {
        return x > y;
    });

    int res = INT_MIN;
    for (int i = 1; i <= n; i++) {
        res = max(res, days[i] + i);
    }

    cout << res + 1;

    return 0;
}