#include <bits/stdc++.h>
using namespace std;

void calculate(queue<pair<int, int>> &q, vector<vector<int>> &w, int x, int y, int u, int v) {

    if (w[u][v] == -1) {
        w[u][v] = w[x][y]+ 1;
        q.push({u, v});
    }
}

int main() {

    int a, b, c;
    cin >> a >> b >> c;

    vector<vector<int>> w;
    for (int i = 0; i < a + 1; i++) {
        w.push_back(vector<int>(b + 1, -1));
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    w[0][0] = 0; 

    int x, y, temp;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if (x == c || y == c) {
            cout << w[x][y];
            return 0;
        }

        calculate(q, w, x, y, x, 0);
        calculate(q, w, x, y, x, b);
        calculate(q, w, x, y, 0, y);
        calculate(q, w, x, y, a, y);
        temp = min(a - x, y);
        calculate(q, w, x, y, x + temp, y - temp);
        temp = min(x, b - y);
        calculate(q, w, x, y, x - temp, y + temp);
    }

    cout << -1;
    
    return 0;
}