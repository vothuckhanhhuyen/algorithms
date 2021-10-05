#include <bits/stdc++.h>
using namespace std;

const int P = 1000000000 + 7;

int main() {

    int n;
    cin >> n;

    int arr;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr;
        sum += arr;
        sum %= P;
    }

    cout << sum;

    return 0;
}