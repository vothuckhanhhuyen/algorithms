#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;

vector<int> component(N, -1);
vector<vector<int>> adj(N);

void dfs(int u) {
    for (auto v : adj[u]) {
        if (component[v] < 0) {
            component[v] = component[u];
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

    int comp = 0;
    for (int i = 1; i <= n; i++) {
        if (component[i] < 0) {
            comp += 1;
            component[i] = comp;
            dfs(i);
        }
    }

    cout << comp;

    return 0;
}