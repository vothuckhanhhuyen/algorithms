#include <bits/stdc++.h>
using namespace std;

int main() {

    unsigned long long num1, num2, div1, div2, mod1, mod2;

    cin >> num1 >> num2;
    
    div1 = num1 / 10; div2 = num2 / 10;
    mod1 = num1 % 10; mod2 = num2 % 10;

    if ((div1 + div2) == 0) {
        cout << (mod1 + mod2);
    } else {
        if ((mod1 + mod2) < 10) {
            cout << (div1 + div2) << (mod1 + mod2);
        } else {
            cout << (div1 + div2 + 1) << ((mod1 + mod2) % 10);
        }
    }

    return 0;
}