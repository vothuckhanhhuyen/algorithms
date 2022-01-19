#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;

vector<int> color(N, 0);
vector<vector<int>> adj(N);

bool res = false;

void dfs(int u) {
    if (res) {
        return;
    }
    for (auto v : adj[u]) {
        if (color[v] > 0) {
            if (color[v] != 5 - color[u]) {
                res = true;
            }
        } else {
            color[v] = 5 - color[u];
            dfs(v);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (!res && (color[i] == 0)) {
            color[i] = 1;
            dfs(i);
        }
    }

    cout << !res;

    return 0;
}