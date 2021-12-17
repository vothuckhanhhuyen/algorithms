#include <bits/stdc++.h>
using namespace std;

int res[2000][2000];
vector<pair<int, int> > arr1, arr2;
int l, c, p;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {

        memset(res, 0, sizeof(res));

        arr1.clear();
        arr2.clear();

        cin >> l >> c;

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
                cin >> p;
                if (p) {
                    arr1.push_back({i, j});
                }
            }
        }

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
                cin >> p;
                if (p) {
                    arr2.push_back({i, j});
                }
            }
        }

        for (int i = 0; i < arr1.size(); i++) {
            for (int j = 0; j < arr2.size(); j++) {
                res[arr1[i].first - arr2[j].first + 1000][arr1[i].second - arr2[j].second + 1000]++;
            }
        }

        int count = INT_MIN;
        for (int i = 0; i < 2000; i++) {
            for (int j = 0; j < 2000; j++) {
                count = max(count, res[i][j]);
            }
        }

        cout << count << endl;
    }
}