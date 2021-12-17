#include <bits/stdc++.h>
using namespace std;

int n, i;
long long num[10001], k;

void precal_num() {

    num[0] = 1;
    long long sumi = 1;
    for (int j = 1; j <= i; j++) {
        if (num[j - 1] * 2 > long(1e9)) {
            num[j] = LONG_MAX;
            sumi = LONG_MAX;
        } else {
            num[j] = num[j - 1] * 2;
            sumi += num[j];
        }
    }

    for (int j = i + 1; j <= n; j++) {
        if (num[j - 1] == LONG_MAX)
            num[j] = LONG_MAX;
        else {
            num[j] = sumi;
            sumi = sumi - num[j - i - 1] + num[j];
            if (sumi > long(1e9))
                sumi = LONG_MAX;
        }
    }
}

void solve(int n, int k) {

    if (k > num[n]) {
        cout << -1;
        return;
    }

    if (n <= 0) {
        cout << endl;
        return;
    }

    if (n <= i) {
        for (int j = n - 1; j >= 0; j--) {
            if (j >= 32)
                cout << "0 ";
            else
                cout << (long(1) & ((k) >> (j))) << " ";
        }
        cout << endl;
    } else {
        long long sum = 0;
        for (int j = i; j >= 0; j--) {
            sum += num[n - j - 1];
            if (k < sum) {
                for (int t = 0; t < j; t++)
                    cout << "0 ";
                cout << "1 ";
                k = k - sum + num[n - j - 1];
                n = n - j - 1;
                solve(n, k);
                break;
            }
        }
    }
}

int main() {

    cin >> n >> k >> i;

    i--;
    k--;
    precal_num();
    solve(n, k);

    return 0;
}
