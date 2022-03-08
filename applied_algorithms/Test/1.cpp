#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int x;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x;
            if (i != j && x == 0) {
                cout << 0;
                return 0;
            }
        }
    }

    cout << 1;

    return 0;
}