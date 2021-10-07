#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};

int main() {

    Solution s;

    vector<int> nums = {1, 2, 3, 4};

    cout << s.arrayPairSum(nums);

    return 0;
}