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

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    int xi, yi;
    for (int i = 1; i <= n; i++) {
        cin >> xi >> yi;
        point[i].first = xi;
        point[i].second = yi;
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

    vector<long long> res(n + 1, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> PQ;
    res[1] = 0;
    PQ.push({res[1], 1});
    int x;
    while (!PQ.empty()) {
        x = PQ.top().second;
        PQ.pop();
        for (auto y : adj[x]) {
            if (res[y] > res[x] + dist[x][y]) {
                res[y] = res[x] + dist[x][y];
                PQ.push({res[y], y});
            }
        } 
    }

    if (res[n] != LLONG_MAX) {
        cout << res[n];
    } else {
        cout << -1;
    }

    return 0;
}