#include <bits/stdc++.h>
using namespace std;

int main() {

    string str;
    cin >> str;

    int countA = 0, countB = 0;
    for (int i = 0; i < str.size(); i++) {
        if (i % 2 == 0) {
            if (str.at(i) == '-') {
                countA++;
            } else {
                countB++;
            }
        } else {
            if (str.at(i) == '-') {
                countB++;
            } else {
                countA++;
            }
        }
    }

    if (countA == countB) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}