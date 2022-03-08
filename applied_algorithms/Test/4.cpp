#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int n, maxpos;
ll ans(0);
set<pll> sm, stt;
ll tmp;
set<pll>::iterator p;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &tmp);
        sm.insert({tmp, -i});
        stt.insert({i, tmp});
    }
    sm.insert({0, 0});
    sm.insert({0, n + 1});
    stt.insert({0, 0});
    stt.insert({n + 1, 0});

    while (sm.size() > 2) {
        p = prev(sm.end());
        maxpos = -p->second;
        sm.erase(p);
        p = stt.lower_bound({maxpos, LONG_MIN});
        ans += p->second;
        ans += prev(p)->second;
        ans += next(p)->second;
        stt.erase(p);
    }

    printf("%lld", ans);

    return 0;
}