#include <bits/stdc++.h>
using namespace std;

const unsigned long long P = 1000000000 + 7;

int main() {
    
    unsigned long long num1, num2, mod1, mod2, modSum;

    cin >> num1 >> num2;

    mod1 = num1 % P;
    mod2 = num2 % P;
    modSum = (mod1 + mod2) % P;

    cout << modSum;

    return 0;
}