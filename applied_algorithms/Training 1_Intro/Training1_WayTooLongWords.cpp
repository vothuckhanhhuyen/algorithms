#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    string str;
    int len;
    for (int i = 0; i < n; i++) {
        cin >> str;

        len = str.length();
        if (len > 10) {
            cout << str[0] << len - 2 << str[len - 1];
        } else {
            cout << str;
        }

        if (i < n - 1) {
            cout << endl;
        }
    }

    return 0;
}