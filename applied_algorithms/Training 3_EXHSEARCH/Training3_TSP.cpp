#include <bits/stdc++.h>
using namespace std;

const int N = 21;

int n, m;
int cost[N][N];
bool visited[N];
int path[N];
int path_cost[N];
int costMin = INT_MAX;

bool checked(int a, int i) {

    // no path
    if (cost[path[a - 1]][i] == 0) {
        return false;
    }

    // have visited
    if (visited[i]) {
        return false;
    }

    return true;
}

void solution() {

    if (cost[path[n]][1] == 0) {
        return;
    }

    costMin = min(path_cost[n] + cost[path[n]][1], costMin);
}

void Try(int a) {

    for (int i = 2; i <= n; i++) {
        if (checked(a, i)) {
            path[a] = i;
            path_cost[a] = path_cost[a - 1] + cost[path[a - 1]][i];
            visited[i] = true;

            if (a == n) {
                solution();
            } else {
                if (path_cost[a] < costMin) {
                    Try(a + 1);
                }
            }

            visited[i] = false;
        }
    }
}

int main() {

    cin >> n >> m;

    int temp1, temp2, temp3;
    for (int i = 0; i < m; i++) {
        cin >> temp1 >> temp2 >> temp3;
        cost[temp1][temp2] = temp3;
    }

    visited[1] = true;
    path[1] = 1;
    path_cost[1] = 0;

    Try(2);

    cout << costMin; 

    return 0;
}