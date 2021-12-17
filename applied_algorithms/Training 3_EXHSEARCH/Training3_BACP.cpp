#include <bits/stdc++.h>
using namespace std;

const int N = 16;
const int M = 5;
int n, m;
int credit[N + 1];
int bound[N + 1][N + 1];
int assigned[N + 1];
int countA[M + 1];
int res_max = INT_MIN;
int res_min = INT_MAX;

void inputData() {

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> credit[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> bound[i][j];
        }
    }
}

bool checked(int a, int i) {

    for (int j = 1; j <= n; j++) {
        if (bound[a][j] == 1) {
            if (assigned[j] <= i && assigned[j] > 0) {
                return false;
            }
        }
        if (bound[j][a] == 1) {
            if (assigned[j] >= i) {
                return false;
            }
        }
    }

    return true;
}

void Try (int a) {

    for (int i = 1; i <= m; i++) {
        if (checked(a, i)) {
            int temp = res_max;
            assigned[a] = i;
            countA[i] += credit[a];
            res_max = max(res_max, countA[i]);

            if (a == n) {
                res_min = min(res_min, res_max);
            } else {
                if (res_max < res_min) {
                    Try(a + 1);
                }
            }

            assigned[a] = 0;
            countA[i] -= credit[a];
            res_max = temp;
        }
    }
}

int main() {

    inputData();

    Try(1);

    res_min = (res_min == INT_MAX ? -1 : res_min);

    cout << res_min;

    return 0;
}