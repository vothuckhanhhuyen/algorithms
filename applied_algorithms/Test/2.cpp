#include <bits/stdc++.h>
using namespace std;

struct DisjoinSet {

    vector<int> par;

    void init(int n) {
        par = vector<int>(n + 1, -1);
    }

    int root(int u) {
        return (par[u] < 0 ? u : root(par[u]));
    }

    void join(int u, int v) {
        int ru = root(u);
        int rv = root(v);
        if (ru == rv)
            return;
        if (par[ru] < par[rv]) {
            swap(ru, rv);
        }
        par[ru] += par[rv];
        par[rv] = ru;
    }
} dsu;

const int maxN = 1e5 + 10;
pair<int, int> e[maxN];
int q[maxN];
long long res[maxN];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    dsu.init(n + 1);
    bool mark[n + 1] = {0};
    for (int i = 1; i <= n - 1; i++) {
        cin >> e[i].first >> e[i].second;
    }

    int Q;
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> q[i];
        mark[q[i]] = true;
    }

    for (int i = 1; i <= n - 1; i++) {
        if (mark[i]) {
            continue;
        }
        dsu.join(e[i].first, e[i].second);
    }

    for (int i = Q; i >= 1; i--) {
        int tmp = q[i];
        int x = e[tmp].first;
        int y = e[tmp].second;
        int m1 = dsu.root(x);
        int m2 = dsu.root(y);
        res[i] = 1LL * dsu.par[m1] * dsu.par[m2];
        dsu.join(x, y);
    }

    for (int i = 1; i <= Q; i++) {
        cout << res[i] << '\n';
    } 
        
    return 0;
}