#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    n = 1000 - n;

    int a[] = {1, 5, 10, 50, 100, 500};
    int m = 0;
    int i = 5;

    while (n > 0) {
        while (n < a[i]) {
            i--;
        }
        m += n / a[i];
        n = n % a[i];
    }

    cout << m;

    return 0;
}