#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int size = nums.size();
        vector<int> dp(size);
        vector<int> e(size);

        dp[0] = nums[0];
        e[0] = nums[0];
        for (int i = 1; i < size; i++) {
            e[i] = max(nums[i], nums[i] + e[i - 1]);
            dp[i] = max(dp[i - 1], e[i]);
        }

        return dp[size - 1];
    }
};

int main() {

    Solution s; 

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << s.maxSubArray(nums);   

    return 0;
}