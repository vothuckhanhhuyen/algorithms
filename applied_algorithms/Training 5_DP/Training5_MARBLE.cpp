#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int w, h;
    cin >> w >> h;

    int waste[w + 1][h + 1];
    for (int i = 0; i <= w; i++) {
        for(int j = 0; j <= h; j++) {
            waste[i][j] = i * j;
        }
    }

    int n, wi, hi;
    cin >> n;

    while (n--) {
        cin >> wi >> hi;
        waste[wi][hi] = 0;
    }

    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++) {
            for (int k = 1; k <= i; k++) {
                waste[i][j] = min(waste[i][j], waste[k][j] + waste[i - k][j]);
            }
            for (int k = 1; k <= j; k++) {
                waste[i][j] = min(waste[i][j], waste[i][k] + waste[i][j - k]);
            }
        }
    }

    cout << waste[w][h];

    return 0;
}