#include <bits/stdc++.h>
using namespace std;

int n, c;
int arr[100010];

int choose(int mid) {

    int count = 1;
    int start = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[start] >= mid) {
            count++;
            start = i;
        }

        if (count >= c) {
            return 1;
        }
    }

    return 0;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> c;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);

        int left = 1;
        int right = arr[n - 1];
        int mid;
        while (right > left + 1) {
            mid = (left + right) / 2;
            if (choose(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        cout << left << endl;
    }

    return 0;
}

