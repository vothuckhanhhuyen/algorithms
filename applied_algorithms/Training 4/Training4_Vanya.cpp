#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, l;
    cin >> n >> l;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int dis = 0;
    for (int i = 1; i < n; i++) {
        dis = max(dis, arr[i] - arr[i - 1]);
    }

    float disf = dis;
    float res = max((float) arr[0], disf / 2);
    res = max(res, (float) l - arr[n - 1]);
    cout << fixed << setprecision(10) << res;  

    return 0;
}