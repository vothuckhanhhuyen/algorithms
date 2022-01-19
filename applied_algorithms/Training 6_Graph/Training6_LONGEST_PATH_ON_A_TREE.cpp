#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;

int n;
vector<vector<pair<int, int>>> adj(N);
vector<bool> visited(N, false);
int max_w = INT_MIN, res = INT_MIN, sum = 0, cnt = 0;
int vertex = 1;

void dfs(int u) {
    for (auto v : adj[u]) {
        if (!visited[v.first]) {
            cnt++;
            sum += v.second;
            visited[v.first] = true;

            if (sum > res) {
                res = sum;
                vertex = v.first;
            }

            if (sum + (N - cnt - 1) * max_w > res) {
                dfs(v.first);
            }

            cnt--;
            sum -= v.second;
            visited[v.first] = false;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int u, v, w;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        max_w = max(w, max_w);
    }

    dfs(1);

    visited.assign(visited.size(), false);
    res = INT_MIN;
    sum = 0;
    cnt = 0;
    dfs(vertex);

    cout << res;

    return 0;
}