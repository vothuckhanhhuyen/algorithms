#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    int u, v, w;
    for (int i = 1; i<= m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int s, t;
    cin >> s >> t;

    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    dist[s] = 0;
    PQ.push({0, s});
    int x, y;
    while (!PQ.empty()) {
        x = PQ.top().second;
        PQ.pop();
        for (auto z : adj[x]) {
            y = z.first;
            if (dist[y] > dist[x] + z.second) {
                dist[y] = dist[x] + z.second;
                PQ.push({dist[y], y});
            }
        } 
    }

    int res = dist[t];
    if (res == INT_MAX) {
        res = -1;
    }

    cout << res;

    return 0;
}