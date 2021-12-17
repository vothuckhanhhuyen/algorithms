#include <bits/stdc++.h>
using namespace std;

const int M = 2e6 + 10;
int max_l[M] = {0}; // M[i]: khoang thoi gian lon nhat cho den thoi diem i

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int s[n], t[n] = {0};
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
        max_l[t[i]] = max(max_l[t[i]], t[i] - s[i]);
    }

    int m = *max_element(s, s + n);
    for (int i = 1 ; i <= m; i++) {
        max_l[i] = max(max_l[i - 1], max_l[i]);
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, max_l[s[i] - 1] + t[i] - s[i]);
    }

    cout << res;

    return 0;
}