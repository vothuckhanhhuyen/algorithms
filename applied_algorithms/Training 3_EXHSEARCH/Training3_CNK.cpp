#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll mulmod(ll a, ll b, ll n) {

    ll r = 0;
    while (b > 0) {
        if (b % 2 == 1) {
            r = (r + a) % n;
        }
        a = a * 2 % n;
        b = b / 2;
    }
    return r % n;
}

ll powmod(ll a, ll b, ll n) {

    a %= n;
    if (a == 0) {
        return 0;
    }
    ll product = 1;
    while(b > 0) {
        if (b % 2 == 1) {   
            product = mulmod(product, a, n);
            --b;
        }
        a = mulmod(a, a, n);
        b /= 2;  
    }

    return product;
}

ll inv(ll a, ll p) {

    return powmod(a, p - 2, p);
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    
    ll n, m;
    int k;
    for (int i = 0; i < T; i++) {
        cin >> n >> k >> m;

        ll factk, factnk;
        factk = factnk = 1;
        for (int j = 1; j <= k; j++) {
            factk = mulmod(factk, j, m);
            factnk = mulmod(factnk, n - k + j, m);
        }

        cout << mulmod(factnk, inv(factk, m), m) << endl;
    }

    return 0;
}