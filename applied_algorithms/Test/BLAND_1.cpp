#include <bits/stdc++.h>
using namespace std;

const int N = 502;

vector<pair<int, int>> point(N);
vector<vector<int>> adj(N);
vector<vector<int>> dist(N, vector<int>(N, 0));
vector<bool> visited(N, false);
int n, k;

int distance(pair<int, int> a, pair<int, int> b) {
    return (int) sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

bool found = false;

void dfs(int u) {
    if (found) {
        return;
    }
    if (u == n) {
        found = true;
        return;
    }
    visited[u] = true;
    for (auto v : adj[u]) {
        if (!visited[v]) {     
            dfs(v);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    int x, y;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        point[i].first = x;
        point[i].second = y;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = distance(point[i], point[j]);
            if (dist[i][j] <= k && i != j) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    dfs(1);

    if (found) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}