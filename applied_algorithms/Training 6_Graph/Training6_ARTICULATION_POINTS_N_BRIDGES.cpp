#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;

int timeDfs = 0, bridge = 0, cntJoint = 0;
vector<vector<int>> adj(N);
vector<int> low(N);
vector<int> num(N);
vector<bool> joint(N);

void dfs(int u, int pre) {
    int child = 0; // Số lượng con trực tiếp của đỉnh u trong cây DFS
    num[u] = low[u] = ++timeDfs;
    for (auto v : adj[u]) {
        if (v == pre) continue;
        if (!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v]) bridge++;
            child++;
            if (u == pre) { // Nếu u là đỉnh gốc của cây DFS
                if (child > 1) joint[u] = true;
            } else {
                if (low[v] >= num[u]) joint[u] = true;
            }
        } else {
            low[u] = min(low[u], num[v]);
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
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (!num[i]) {
            dfs(i, i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cntJoint += joint[i];
    }

    cout << cntJoint << " " << bridge;

    return 0;
}