#include <bits/stdc++.h>
using namespace std;

int main() {

    string str;
    getline(cin, str);

    int count[str.size()];
    count[0] = (str[0] == '[') ? 1 : 0;
    for (int i = 1; i < str.size(); i++) {
        count[i] = count[i - 1] + ((str[i] == '[') ? 1 : 0);
    }

    // for (int i = 1; i < str.size(); i++) {
    //     cout << count[i] << " ";
    // }
    // cout << endl;

    stack<int> index;
    int left = 0, right = 0, best = 0;
    for (int i = 0; i < str.size(); i++) {
        if (!index.empty() && ((str[i] == ']' && str[index.top()] == '[') || (str[i] == ')' && str[index.top()] == '('))) {
            index.pop();

            if (index.empty()) {
                if (count[i] >= best) {
                    best = count[i];
                    left = 0;
                    right = i;
                }
            } else {
                if (count[i] - count[index.top()] >= best) {
                    best = count[i] - count[index.top()];
                    left = index.top() + 1;
                    right = i;
                }
            }
        } else {
            index.push(i);
        }
    }

    cout << best << endl;
    if (left != right) {
        for (int i = left; i <= right; i++) {
            cout << str[i];
        }
    } else {
        cout << endl;
    }

    return 0;
}