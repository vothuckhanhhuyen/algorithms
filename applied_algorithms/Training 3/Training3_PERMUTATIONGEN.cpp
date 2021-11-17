#include <bits/stdc++.h>
using namespace std;

void permutation_gen(vector<int> arr, int n) {

    int j;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            j = i;
            break;
        }
    }

    int k = j + 1;
    for (int i = j + 2; i < n; i++) {
        if (arr[i] > arr[j] && arr[i] < arr[k]) {
            k = i;
        }
    }

    int temp;
    temp = arr[j];
    arr[j] = arr[k];
    arr[k] = temp;

    reverse(arr.begin() + j + 1, arr.end());

    for (int i = 0; i < n; i ++) {
        cout << arr[i] << " ";
    }
}

int main() {

    int n;
    cin >> n;

    vector<int> arr;
    int value;
    int check_last = 0;
    for (int i = 0; i < n; i++) {
        cin >> value;
        arr.push_back(value);
        if (arr[i] > n || arr[i] < 1) {
            cout << -1;
            return 0;
        }
        if (arr[i] == n - i) {
            check_last++;
        }
    }

    if (check_last == n) {
        cout << -1;
        return 0;
    }

    permutation_gen(arr, n);

    return 0;
}