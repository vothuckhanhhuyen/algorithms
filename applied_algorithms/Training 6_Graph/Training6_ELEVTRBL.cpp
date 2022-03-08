#include <bits/stdc++.h>
using namespace std;

const int F = 1e6 + 2;

int f, s, g, u, d;
vector<bool> visited(F);
int cost = INT_MAX, cur_cost = 0;

void mytry(int s) {
    if (s == g) {
        cost = min(cost, cur_cost);
        return;
    }

    visited[s] = true;

    int up = s + u;
    int down = s - d;
    if (up <= f && !visited[up]) {
        cur_cost++;
        mytry(up);
        cur_cost--;
    }
    if (down >= 1 && !visited[down]) {
        cur_cost++;
        mytry(down);
        cur_cost--;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> f >> s >> g >> u >> d;

    mytry(s);

    if (cost == INT_MAX) {
        cout << "use the stairs";
    } else {
        cout << cost;
    }

    return 0;
}