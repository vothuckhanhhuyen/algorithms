#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int a[n], even[n], odd[n];;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        even[i] = odd[i] = -1e9;
    }
    
    if (a[0] % 2 == 0) even[0] = a[0];
    else odd[0] = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] % 2 == 0) {
            even[i] = max(a[i], even[i - 1] + a[i]);
            odd[i] = odd[i - 1] + a[i];
        } else {
            even[i] = odd[i - 1] + a[i];
            odd[i] = max(a[i], even[i - 1] + a[i]);
        }
    }

    int res = -1e9;
    for (int i = 0; i < n; i++) res = max(res, even[i]);
    cout << res;
    
    return 0;
}