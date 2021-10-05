#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> digits;
        int digit1;
        int digit2;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i].size() > 1 || isdigit(tokens[i][0])) {
                digits.push(stoi(tokens[i]));
            } else {
                digit2 = digits.top(); digits.pop();
                digit1 = digits.top(); digits.pop();
                switch (tokens[i][0]) {
                    case '+': digits.push(digit1 + digit2); break;
                    case '-': digits.push(digit1 - digit2); break;
                    case '*': digits.push(digit1 * digit2); break;
                    case '/': digits.push(digit1 / digit2); break;
                }
            }
        }

        return digits.top();
    }
};

int main() {

    Solution s;

    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

    cout << s.evalRPN(tokens);

    return 0;
}