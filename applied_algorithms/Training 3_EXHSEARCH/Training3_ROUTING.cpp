#include <bits/stdc++.h>
using namespace std;

int n, r;
int spot[101][101];
bool visited[101];
vector<int> route;
int result = -1;
int mine = 1e9;

void btrack(int root, int cost, int len) {

    visited[root] = true;
    if (len == route.size()) {
        if (result == -1) result = cost;
        else result = min(result, cost);
    } else {
        for (int i = 1; i <= n; i++) {
            if (len + 1 != route.size() && i == route[route.size() - 1]) continue;
            if (visited[i] == true) continue;
            if (spot[root][i] == 0) continue;
            if (result != - 1 && cost + spot[root][i] + (route.size() - len - 1) * mine >= result) continue;
            btrack(i, cost + spot[root][i], len + 1);
        }
    }
    visited[root] = false;
}

void solve() {

    mine = 1e9;
    for (int i = 0; i < route.size(); i++) {
        for (int j = 0; j < route.size(); j++) {
            if (spot[route[i]][route[j]] == 0) continue;
            mine = min(mine, spot[route[i]][route[j]]);
        }
    }

    btrack(route[0], 0, 1);
}

int main() {

    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> spot[i][j];
        }
    }

    string qq[r + 1];
    string s;
    getline(cin, s);
    for (int i = 1; i <= r; i++) {
        getline(cin, s);
        qq[i] = s;
    }

    for (int i = 1; i <= r; i++) {
        result = -1;
        route.clear();
        for (int i = 1; i <= n; i++) visited[i] = true;

        stringstream temp;
        temp << qq[i];
        while (!temp.eof()) {
            int q;
            temp >> q;
            visited[q] = false;
            route.push_back(q);
        }

        solve();
        if (result == -1) cout << 0 << endl;
        else cout << result << endl;
    }

    return 0;
}

