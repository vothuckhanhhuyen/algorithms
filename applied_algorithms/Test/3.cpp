#include <bits/stdc++.h>
using namespace std;

int cmp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> pre(n + 1);
    vector<int> next(n + 1);
    vector<int> save(n + 2, 0);
    vector<pair<int, int>> vp(n + 1);

    for (int i = 1; i <= n; i++) {
        pre[i] = i - 1;
        next[i] = i + 1;
        cin >> save[i];
        vp[i] = {save[i], i};
    }
    sort(vp.begin() + 1, vp.end(), cmp);

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += vp[i].first + save[pre[vp[i].second]] + save[next[vp[i].second]];
        next[pre[vp[i].second]] = next[vp[i].second];
        pre[next[vp[i].second]]  = pre[vp[i].second];
    }

    cout << res << endl;

    return 0;
}