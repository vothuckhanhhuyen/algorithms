#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 +2;

int s, t;
int res = INT_MAX, sum = 0;
vector<vector<pair<int, int>>> adj(N);
vector<bool> visited(N);

void dfs(int u) {
    if (sum > res) {
        return;
    }
    for (auto v : adj[u]) {
        if (!visited[v.first]) {
            sum += v.second;
            visited[v.first] = true;

            if (v.first == t) {
                res = min(res, sum);
            } else {
                dfs(v.first);
            }

            sum -= v.second;
            visited[v.first] = false;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int u, v, w;
    for (int i = 1; i<= m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    cin >> s >> t;

    dfs(s);

    if (res == INT_MAX) {
        res = -1;
    }

    cout << res;

    return 0;
}