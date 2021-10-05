#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> results;

        for (int i = 0; i < numRows; i++) {
            vector<int> result(i + 1, 1);
            for (int j = 1; j < i; j++) {
                result[j] = results[i - 1][j - 1] + results[i - 1][j];
            }
            results.push_back(result);
        }
        
        return results;
    }
};

int main() {

    Solution s;

    vector<vector<int>> results = s.generate(5);

    for (int i = 0; i < results.size(); i++) {
        for (int j = 0; j < results[i].size(); j++) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}