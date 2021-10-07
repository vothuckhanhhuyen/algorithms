#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int pivot = 0;
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            pivot = (left + right) / 2;
            if (nums[pivot] == target) {
                return pivot;
            } else if (nums[pivot] > target) {
                right = pivot - 1;
            } else {
                left = pivot + 1;
            }
        }

        return left;
    }
};

int main() {

    Solution s;

    vector<int> nums = {1, 2, 4, 5};

    cout << s.searchInsert(nums, 3);

    return 0;
}