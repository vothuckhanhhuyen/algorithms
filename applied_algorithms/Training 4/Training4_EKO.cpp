#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
long long arr[1000010];

int choose(long long key) {

    long long height = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > key) {
            height += (arr[i] - key);
        }
        if (height >= m) {
            return 1;
        }
    }

    return 0;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    long long left = 0;
    long long right = arr[n - 1];
    long long mid;
    while (right > left + 1) {
        mid = (left + right) / 2;
        if (choose(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << left;

    return 0;
}