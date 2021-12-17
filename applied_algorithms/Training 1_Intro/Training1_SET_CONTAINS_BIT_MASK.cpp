#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m, i, j;

    cin >> n;
    getchar();
    int arr1[n];
    for (i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    sort(arr1, arr1 + n);

    cin >> m;
    getchar();
    int arr2[m];
    for (j = 0; j < m; j++) {
        cin >> arr2[j];
    }
    sort(arr2, arr2 + m);

    j = 0;
    for (i = 0; i < n; i++) {
        if (j < m) {
            if (arr1[i] < arr2[j]) {
                continue;
            } else if (arr1[i] == arr2[j]) {
                j++;
                continue;
            } else {
                cout << 0;
                return 0;
            }
        }
    }

    if (j == m) {
        cout << 1;
    } else {
        cout << 0;
    }
    
    return 0;
}