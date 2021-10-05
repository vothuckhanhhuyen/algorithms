#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<pair<int, int> > checkpoints;
        vector<int> results;

        for (int i = temperatures.size() - 1; i >= 0 ; i--) {
            while (!checkpoints.empty() && temperatures[i] >= checkpoints.top().first) {
                checkpoints.pop();
            }
            if (checkpoints.empty()) {
                results.push_back(0);
            } else {
                results.push_back(checkpoints.top().second - i);
            }
            checkpoints.push(make_pair(temperatures[i], i));
        }

        reverse(results.begin(), results.end());
            
        return results;
    }
};

int main() {

    Solution s;

    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> dailyTemperatures = s.dailyTemperatures(temperatures);

    for (int i = 0; i < dailyTemperatures.size(); i++) {
        cout << dailyTemperatures[i] << endl;
    }

    return 0;
}