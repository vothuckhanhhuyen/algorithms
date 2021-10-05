#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (leftSum == (sum - nums[i] - leftSum)) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};

int main() {

    Solution s;

    vector<int> nums = {1, 7, 3, 6, 5, 6};

    cout << s.pivotIndex(nums);

    return 0;
}
