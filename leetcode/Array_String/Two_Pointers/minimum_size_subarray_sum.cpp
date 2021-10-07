#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int left = 0;
        int sum = 0;
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= target) {
                ans = min(ans, i  + 1 - left);
                sum -= nums[left];
                left++;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

int main() {

    Solution s;

    vector<int> nums = {1, 4, 4};

    cout << s.minSubArrayLen(15, nums); 

    return 0;
}