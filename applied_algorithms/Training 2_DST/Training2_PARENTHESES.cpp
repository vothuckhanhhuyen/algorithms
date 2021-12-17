#include <bits/stdc++.h>
using namespace std;

int correct(string str) {

    stack<char> res;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {res.push(str[i]);}
        else {
            if (res.empty()) {return 0;}
            if (str[i] == ')' && res.top() != '(') {return 0;}
            if (str[i] == ']' && res.top() != '[') {return 0;}
            if (str[i] == '}' && res.top() != '{') {return 0;}
            res.pop();
        }
    }

    return res.empty() ? 1 : 0;
}

int main() {

    int n;
    cin >> n;
    getchar();

    string str;
    for (int i = 0; i < n; i++) {
        getline(cin, str);  
        cout << correct(str) << endl;
    }
}