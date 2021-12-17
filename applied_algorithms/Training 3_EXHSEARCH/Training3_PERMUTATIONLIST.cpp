#include<bits/stdc++.h>
using namespace std;

long long fac[10001];
int n, k;
vector<int> num;

void precal_fac() {

    fac[0] = 1;
    for(int i = 1; i <= n; i++) {
        if (fac[i - 1]  * i < long(1e9)) fac[i] = fac[i - 1] * i;
        else fac[i] = LONG_MAX;
    }
}

int main() {

    cin >> n >> k;

    precal_fac();
    if (k > fac[n]) {
        cout << -1;
        return 0;
    }

    k--;
    for (int i = 0; i <= n; i++) num.push_back(i);
    for (int i = n; i >= 2; i--) {
        int index = k / fac[i - 1];
        k = k % fac[i - 1];
        cout << num[index + 1] << " ";
        num.erase(num.begin() + index + 1);
    }
    
    cout << num[1];

    return 0;
}