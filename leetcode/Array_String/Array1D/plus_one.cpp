#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] == 9) { 
                digits[i] = 0;
                continue;
            } else {
                digits[i] += 1;
                return digits;
            }
        }
        vector<int> digitsTemp = vector<int>(digits.size() + 1, 0);
        digitsTemp[0] = 1;
        return digitsTemp;
    }
};

int main() {

    Solution s;

    // vector<int> digits = {9, 9, 9};
    vector<int> digits = {1, 9, 9, 8};
    vector<int> digitsTemp = s.plusOne(digits);

    for (int i = 0; i < digitsTemp.size(); i++) {
        cout << digitsTemp[i] << " ";
    }

    return 0;
}