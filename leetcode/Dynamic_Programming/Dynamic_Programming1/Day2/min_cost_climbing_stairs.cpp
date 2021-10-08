#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        int minCost[n + 1];
        
        minCost[0] = minCost[1] = 0;
        for (int i = 2; i <= n; i++) {
            minCost[i] = min(minCost[i - 2] + cost[i - 2], minCost[i - 1] + cost[i - 1]);
        }
        
        return minCost[n];
    }
};

int main() {

    Solution s;

    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    cout << s.minCostClimbingStairs(cost);

    return 0;
}