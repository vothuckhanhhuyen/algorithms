#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main() {

    Solution s;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 1, 1};

    cout << s.removeElement(nums, 1);

    return 0;
}