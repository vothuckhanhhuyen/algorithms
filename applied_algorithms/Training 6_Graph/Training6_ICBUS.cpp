#include <bits/stdc++.h>
using namespace std;

struct town {
    int C;
    int D;
    void set_value(int _C, int _D) {
        C = _C;
        D = _D;
    }
};

const int N = 5002;

int n, k;
vector<town> t(N);
vector<vector<int>> adj(N), new_adj(N), dist(N, vector<int>(N, -1));
vector<int> cost(N, INT_MAX);

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    int c, d;
    for (int i = 1; i <= n; i++) {
        cin >> c >> d;
        t[i].set_value(c, d);
        dist[i][i] = 0;
    }

    int x, y;
    for (int i = 1; i <= k; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // bfs
    queue<int> Q;
    int u;
    for (int i = 1; i <= n; i++) {
        Q.push(i);
        while (!Q.empty()) {
            u = Q.front();
            Q.pop();
            for (auto v : adj[u]) {
                if (dist[i][v] < 0) {
                    if (dist[i][u] + 1 <= t[i].D) {
                        dist[i][v] = dist[i][u] + 1;
                        new_adj[i].push_back(v);
                        Q.push(v);
                    }
                }
            }
        }
    }

    // dijiktra
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    cost[1] = 0;
    PQ.push({cost[1], 1});
    while (!PQ.empty()) {
        c = PQ.top().first;
        d = PQ.top().second;
        PQ.pop();
        for (auto i : new_adj[d]) {
            if (cost[d] + t[d].C < cost[i]) {
                cost[i] = cost[d] + t[d].C;
                PQ.push({cost[i], i});
            }
        }
    }

    cout << cost[n];

    return 0;
}