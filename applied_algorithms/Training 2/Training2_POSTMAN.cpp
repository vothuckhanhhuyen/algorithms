#include <bits/stdc++.h>
using namespace std;

long long distance(vector<pair<long long, long long>> v, int k) {

    sort(v.rbegin(), v.rend());

    long long x, m;
    long long used, times, remain = 0, result = 0;
    for (int i = 0; i < v.size(); i++) {
        x = v[i].first;
        m = v[i].second;
        used = min(m, remain);
        m -= used;
        remain -= used;

        times = (m + k - 1) / k;
        result += x * times * 2;
        remain += k * times - m;
    }

    return result;
}

int main() {

    int n, k;
    cin >> n >> k;

    vector<pair<long long, long long>> neg, pos;

    long long x, m;
    for (int i = 0; i < n; i++) {
        cin >> x >> m;
        if (x < 0) {
            neg.push_back({-1 * x, m});
        } else {
            pos.push_back({x, m});
        }
    }

    cout << distance(neg, k)  + distance(pos, k) << endl;

    return 0;
}