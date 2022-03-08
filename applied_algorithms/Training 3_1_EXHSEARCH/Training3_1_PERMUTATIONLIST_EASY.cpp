#include<bits/stdc++.h>
using namespace std;

int n;
bool d[16];
int a[16];

void xuat() {
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void Try(int k) {
    for (int i = 1; i <= n; i++) {
        if (!d[i]) {
            a[k] = i;
            d[i] = 1;
            if (k == n)
                xuat();
            else
                Try(k + 1);
            d[i] = 0;
        }
    }
}

int main() {

    cin >> n;
    Try(1);
}
