#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pas;
        for (int i = 0; i <= rowIndex; i++) {
            vector<int> result(i + 1, 1);
            for (int j = 1; j < i; j++) {
                result[j] = pas[i - 1][j - 1] + pas[i - 1][j];
            }
            pas.push_back(result);
        }
        return pas[rowIndex];
    }
};

int main() {

    Solution s;

    vector<int> pas = s.getRow(3);
    for (int i = 0; i < pas.size(); i++) {
        cout << pas[i] << " ";
    }

    return 0;
}