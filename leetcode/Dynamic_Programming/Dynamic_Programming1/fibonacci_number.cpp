#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        
        if (n == 0 || n == 1) {
            return n;
        }
        
        int res[n + 1];
        res[0] = 0;
        res[1] = 1;

        for(int i = 2; i <= n; i++) {
            res[i] = res[i - 1] + res[i - 2];
        }

        return res[n];
    }
};

int main() {

    Solution solution;

    cout << solution.fib(4);

    return 0;
}