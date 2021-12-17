#include <bits/stdc++.h>
using namespace std;

int n, k;
int res = 0;
long long s, si = 0;
int mina = INT_MAX;
int arr[40];
int visited[40];

void Try(int a) {

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            si += arr[i];
            visited[i] = 1;

            if (a == k) {
                if (si == s) {
                    res++;
                }
            } else {
                if (si + (k - a) * mina <= s) {
                    Try(a + 1);
                }
            }

            si -= arr[i];
            visited[i] = 0;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k >> s;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        mina = min(mina, arr[i]);
    }
    sort(arr + 1, arr + n + 1);

    Try(1);

    long long mul = 1;
    for (int i = 1; i <= k; i++) {
        mul *= i;
    }

    cout << res / mul;

    return 0;
}