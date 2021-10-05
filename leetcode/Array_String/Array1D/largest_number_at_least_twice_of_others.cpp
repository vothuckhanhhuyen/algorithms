#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max1 = *max_element(nums.begin(), nums.end());
        int idx1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == max1) { idx1 = i; continue; }
            if (2 * nums[i] > max1) { return -1; }
        }
        return idx1;
    }
};

int main() {

    Solution s;

    vector<int> nums = {3, 6, 1, 0};

    cout << s.dominantIndex(nums);

    return 0;
}