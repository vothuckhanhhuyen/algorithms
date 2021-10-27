#include <bits/stdc++.h>
using namespace std;

const int N = 11;
const int K = 10;

int n, k = 1;
int distanceMin = INT_MAX;
int distanceCur = 0;
int k_count = 0;
int dist[2*N + 1][2*N + 1];
bool visited[2*N + 1];
int path[2*N + 1];
int pathMin = INT_MAX;

void inputData() {

    cin >> n;
    for (int i = 0; i <= 2*n; i++) {
        for (int j = 0; j <= 2*n; j++) {
            cin >> dist[i][j];
        }
    }
}

void findMinPath() {

    for (int i = 0; i <= 2*n; i++) {
        for (int j = 0; j <= 2*n; j++) {
            if (i != j) {
                pathMin = min(pathMin, dist[i][j]);
            }
        }
    }
}

bool checked(int i) {

    if (i <= n && k_count >= k) {
        return false;
    } else {
        if (!visited[i]) {
            if (i > n) {
                if (!visited[i - n]) {
                    return false;
                }
            }
            return true;
        }
    }
    
    return false;
}

void solution() {

    distanceMin = min(distanceMin, distanceCur + dist[path[2*n]][0]);
}

void Try(int a) {

    for (int i = 1; i <= 2*n; i++) {
        if (checked(i)) {
            path[a] = i;

            visited[i] = true;
            distanceCur += dist[path[a - 1]][i];

            if (i <= n) {
                k_count++;
            } else {
                k_count--;
            }

            if (a == 2*n) {
                solution();
            } else {
                if (distanceCur + (2*n - a)*pathMin < distanceMin) {
                    Try(a + 1);
                }
            }

            if (i <= n) {
                k_count--;
            } else {
                k_count++;
            }

            visited[i] = false;
            distanceCur -= dist[path[a - 1]][i];
        }
    }
}

int main() {

    inputData();

    findMinPath();

    path[0] = 0;
    visited[0] = true;

    Try(1);

    cout << distanceMin; 

    return 0;
}

