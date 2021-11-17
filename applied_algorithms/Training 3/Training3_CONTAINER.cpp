#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;
int h, w, n, hi, wi;
int freetime[MAX + 1][MAX + 1];
int result = 0;
vector<pair<int, int>> rec;

bool cmp(pair<int, int> a, pair<int, int> b) {

    if (a.first > b.first) {
        return true;
    } else if (a.first == b.first) {
        if (a.second > b.second) {
            return true;
        }
        return false;
    } else {
        return false;
    }
}

bool checked(int u, int v, int a) {

    if (rec[a].first + u - 1 <= h && rec[a].second + v - 1 <= w) {
        for (int i = u; i < rec[a].first + u; ++i) {
            for (int j = v; j < rec[a].second + v; ++j) {
                if (freetime[i][j] == 0) {
                    return false;
                }
            }
        }

        return true;
    }

    return false;
}

void Try(int a) {

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (freetime[i][j] == 0) {
                break;
            }
            if (checked(i, j, a)) {
                for (int u = i; u < rec[a].first + i; ++u) {
                    for (int v = j; v < rec[a].second + j; ++v) {
                        freetime[i][j] = 0;
                    }
                }

                if (a == n - 1) {
                    result = 1;
                } else {
                    if (result == 1) {
                        return;
                    }
                    Try(a + 1);
                }

                for (int u = i; u < rec[a].first + i; ++u) {
                    for (int v = j; v < rec[a].second + j; ++v) {
                        freetime[i][j] = 1;
                    }
                }
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> h >> w;

    cin >> n;
    int area = 0;
    for(int i = 1; i <= n; i++) {
        cin >> hi >> wi; 
        rec.push_back({hi, wi});
        area += hi * wi;
    }

    if (area > h * w) {
        cout << 0;
        
        return 0;
    }

    memset(freetime, 1, sizeof(freetime));

    sort(rec.begin(), rec.end(), cmp);

    Try(0);

    cout << result;

    return 0;
}