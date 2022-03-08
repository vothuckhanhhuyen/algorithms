#include <bits/stdc++.h>
using namespace std;

struct job {
    int index;
    int d;
    int p;

    void set_value(int _index, int _d, int _p) {
        index = _index;
        d = _d;
        p = _p;
    }
};

int cmp(job const& a, job const& b) {
    return a.p > b.p;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<job> schedules(n + 1);
    int d, p;
    for (int i = 1; i <= n; i++) {
        cin >> d >> p;
        schedules[i].set_value(i, d, p);
    }
    sort(schedules.begin() + 1, schedules.end(), cmp);

    vector<bool> setup(n + 1);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = min(n, schedules[i].d); j >= 1; j--) {
            if (setup[j] == false) {
                setup[j] = true;
                res += schedules[i].p;
                break;
            }
        }
    }

    cout << res;

    return 0;
}