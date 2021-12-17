#include <bits/stdc++.h>
using namespace std;

int m, k;
int arr[510];

int choose(long long mid) {

    long long s = 0;
    int count = 1;
    for (int i = m - 1; i >= 0; i--) {
        s += arr[i];
        if (s <= mid && i >= (k - count)) {
            continue;
        } else {
            count++;
            s = arr[i];
        }
    }

    if (count == k) {
        return 1;
    } else {
        return 0;
    }
}

void print_result(int threshold) {

    long long s = 0;
    int count = 1;
    int idx[k];
    idx[0] = m - 1;
    for (int i = m - 1; i >= 0; i--) {
        s += arr[i];
        if (s <= threshold && i >= (k - count)) {
            continue;
        } else {
            count++;
            idx[count - 1] = i;
            s = arr[i];
        }
    }

    int index = k - 1;
    for (int i = 0; i < m; i++) {
        cout << arr[i] << " ";
        if (i == idx[index] && index > 0) {
            cout << " / ";
            index--;
        }
    }
    
    cout << endl;
}

int main() {

    int n;
    cin >> n;
    while(n--) {
        cin >> m >> k;

        long long sum = 0;
        long long maxh = 0;
        for (int i = 0; i < m; i++) {
            cin >> arr[i];
            sum += arr[i];
            maxh = maxh > arr[i] ? maxh : arr[i];
        }

        long long left = maxh;
        long long right  = sum;
        long long mid;
        while(right > left + 1) {
            mid = (right + left) / 2;
            if (choose(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        print_result(right);
    }

    return 0;
}
