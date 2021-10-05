#include <bits/stdc++.h>
using namespace std;

int main() {

    string str[9] = {" ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    int n;
    cin >> n;
    getchar();

    string message;
    int sum;
    for (int i = 0; i < n; i++) {
        getline(cin, message);
        sum = 0;
        for (int j = 0; j < message.length(); j++) {
            for (int u = 0; u < 9; u++) {
                for (int v = 0; v < str[u].length(); v++) {
                    if (message[j] == str[u][v]) {
                        sum += v + 1;
                    }
                }
            }
        }
        cout << "Case #" << i + 1 << ": " << sum << endl;
    }

    return 0;
}