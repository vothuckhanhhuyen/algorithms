#include <bits/stdc++.h>
using namespace std;

const int MAX = 10010;
const double PI = atan(1) * 4;

int n, f;
double a[MAX], maxsize;

int judge(double size) {	

    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += floor(a[i] / size);
    }

    return sum >= f;
}

double binary_search(double low, double high) {

    double size = (high + low) / 2;

    if (high - low < 1e-6) { // keep note
        return size;
    } else {
        if (judge(size)) {
            return binary_search(size, high);
        } else {
            return binary_search(low, size);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        maxsize = 0; 

        cin >> n >> f;
        f++;
        int temp;
        for(int i = 0; i < n; i++) {
            cin >> temp;
            a[i] = temp * temp * PI;
            maxsize = max(maxsize, a[i]);
        }

        printf("%.6f\n", binary_search(0, maxsize));
    }

    return 0;
}