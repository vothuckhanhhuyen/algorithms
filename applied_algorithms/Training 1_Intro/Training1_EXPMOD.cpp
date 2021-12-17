#include <bits/stdc++.h>
using namespace std;

const unsigned long long P = 1000000000 + 7;

int main() {

    unsigned long long base, exp, result;

    cin >> base >> exp;

    base = base % P;
    exp = exp % (P - 1); // Fermat a^(p-1) = 1 (mod p) if p is a prime number
    result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
        result %= P;
    }

    cout << result;

    return 0;
}