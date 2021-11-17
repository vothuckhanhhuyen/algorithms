#include <bits/stdc++.h>
using namespace std;

void combination_gen(vector<int> arr, int n, int m) {

    int j;
    for (int i = m - 1; i >= 0; i--) {
        if (arr[i] != n - m + 1 + i) {
            j = i;
            break;
        }
    }

    arr[j] += 1;

    for (int i = j + 1; i < m; i++) {
        arr[i] = arr[j] + i - j;
    }

    for (int i = 0; i < m; i ++) {
        cout << arr[i] << " ";
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> arr;
    int value;
    int check_last = 0;
    for (int i = 0; i < m; i++) {
        cin >> value;
        arr.push_back(value);
        if (arr[i] > n || arr[i] < 1) {
            cout << -1;
            return 0;
        }
        if (arr[i] == n - m + 1 + i) {
            check_last++;
        }
    }

    if (check_last == m) {
        cout << -1;
        return 0;
    }

    combination_gen(arr, n, m);

    return 0;
}