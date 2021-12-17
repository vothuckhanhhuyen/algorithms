#include <bits/stdc++.h>
using namespace std;

void bfs(queue<pair<int, int>> &q, vector<vector<int>> &mat, vector<vector<int>> &w, int x, int y, int u, int v) {
    
    if (w[u][v] == -1 && mat[u][v] == 0) {
        q.push({u, v});
        w[u][v] = w[x][y] + 1;
    }
}

int main() {

    int n, m, i0, j0;
    cin >> n >> m >> i0 >> j0;

    vector<vector<int>> mat;
    for (int i = 0; i < n; i++) {
        vector<int> tempV;
        int tempI;
        for (int j = 0; j < m; j++) {
            cin >> tempI;
            tempV.push_back(tempI);
        }
        mat.push_back(tempV);
    }

    vector<vector<int>> w;
    for (int i = 0; i < n; i++) {
        w.push_back(vector<int>(m, -1));
    }

    queue<pair<int, int>> q;
    q.push({i0 - 1, j0 - 1});
    w[i0 - 1][j0 - 1] = 1;

    int x, y;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            cout << w[x][y];
            return 0;
        }

        bfs(q, mat, w, x, y, x - 1, y);
        bfs(q, mat, w, x, y, x + 1, y);
        bfs(q, mat, w, x, y, x, y - 1);
        bfs(q, mat, w, x, y, x, y + 1);
    }

    cout << -1;

    return 0;
}