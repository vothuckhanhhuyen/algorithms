#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    getchar();

    int arr[n];
    int res = 1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i > 0) {
            if (arr[i] != arr[i - 1]) {
                res++;
            }
        }
    }
    getchar();

    int q;
    cin >> q;
    getchar();

    int u, v;
    for (int i = 0; i < q; i++) {
        cin >> u >> v;
        getchar();

        if (u >= 2 && arr[u - 1] != arr[u - 2]) {
            res--;
        }
        
        if (u <= n - 1 && arr[u - 1] != arr[u]) {
            res--;
        }

        if (u >= 2 && v != arr[u - 2]) {
            res++;
        }

        if (u <= n - 1 && v != arr[u]) {
            res++;
        }

        arr[u - 1] = v;

        cout << res << endl;
    }

    return 0;
}