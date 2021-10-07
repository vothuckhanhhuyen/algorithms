#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() == 0) {
            return 0;
        }
        
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return (i + 1);
    }
};

int main() {

    Solution solution;

    vector<int> nums = {1, 1, 3, 4, 4, 5, 6, 7};

    cout << solution.removeDuplicates(nums);

    return 0;
}