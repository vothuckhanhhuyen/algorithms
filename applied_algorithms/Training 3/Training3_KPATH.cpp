#include <bits/stdc++.h>
using namespace std;

const int N = 30;
const int K = 10;
int n, k;
int m, u, v;
int edges[N + 1][N + 1];
int path[K];
bool visited[N + 1];
int result = 0;

bool checked(int a, int i) {

    if (edges[path[a - 2]][i] == 1) {
        if (!visited[i]) {
            return true;
        }
    }

    return false;
}

void k_path(int a) {

    for (int i = 1; i <= n; i++) {
        if (a == 1 || checked(a, i)) {
            path[a - 1] = i;
            visited[i] = true;

            if (a == k + 1) {
                result++;
            } else {
                k_path(a + 1);
            }

            visited[i] = false;
        }
    }
}

int main() {

    cin >> n >> k;

    cin >> m;
    for (int i = 0; i < m ; i++) {
        cin >> u >> v;

        edges[u][v] = 1;
        edges[v][u] = 1;
    }

    k_path(1);

    cout << result / 2;

    return 0;
}
