#include <bits/stdc++.h>
using namespace std;

const int M = 1000000000 + 7;
const int N = 1000;
int n, k1, k2;
int result = 0;
int count_ones = 0;
int arr[N + 1];

bool checked(int a, int i) {

    if (arr[a - 1] == 0) {
        if (i == 0) {
            return false;
        } else {
            if (n - a + 1 < k1) {
                return false;
            }
            return true;
        }
    } else {
        if (count_ones < k1) {
            if (i == 0) {
                return false;
            }
            return true;
        }
        if (count_ones >= k2) {
            if (i == 1) {
                return false;
            }
            return true;
        }
        return true;
    }
}

void Try(int a) {

    for (int i = 0; i < 2; i++) {
        if (a == 1 || checked(a, i)) {
            arr[a] = i;
            int temp = count_ones;
            if (i == 1) {
                if (arr[a - 1] == 1) {
                    count_ones++;
                } else {
                    count_ones = 1;
                }
            } else {
                count_ones = 0; 
            }

            if (a == n) {
                result++;
            } else {
                Try(a + 1);
            }

            count_ones = temp;
        }
    }
}

int main() {

    cin >> n >> k1 >> k2;

    Try(1);

    cout << result % M;

    return 0;
}