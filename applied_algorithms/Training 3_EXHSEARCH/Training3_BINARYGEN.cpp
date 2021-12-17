#include <bits/stdc++.h>
using namespace std;

void binary_gen(vector<int> arr, int n) {

    int j;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 0) {
            j = i;
            break;
        }
    }

    arr[j] = 1;

    for (int i = j + 1; i < n; i++) {
        arr[i] = 0;
    }

    for (int i = 0; i < n; i ++) {
        cout << arr[i];
    }
}

int main() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> arr;
    int value;
    int check_last = 0;
    for (int i = 0; i < n; i++) {
        value = (int) s.at(i) - '0';
        arr.push_back(value);
        if (arr[i] < 0 || arr[i] > 1) {
            cout << -1;
            return 0;
        }
        if (arr[i] == 1) {
            check_last++;
        }
    }

    if (check_last == n) {
        cout << -1;
        return 0;
    }

    binary_gen(arr, n);

    return 0;
}