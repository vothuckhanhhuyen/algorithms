#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;

int timeDfs = 0, scc = 0;
vector<vector<int>> adj(N);
vector<int> low(N);
vector<int> num(N);
vector<bool> deleted(N);
stack<int> st;

void dfs(int u) {
    num[u] = low[u] = ++timeDfs;
    st.push(u);
    for (auto v : adj[u]) {
        if (deleted[v]) continue;
        if (!num[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], num[v]);
        }
    }
    if (low[u] == num[u]) {
        scc++;
        int v;
        do {
            v = st.top();
            st.pop();
            deleted[v] = true;
        } while (v != u);
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
    }

    for (int i = 1; i <= n; i++) {
        if (!num[i]) {
            dfs(i);
        }
    }

    cout << scc;

    return 0;
}