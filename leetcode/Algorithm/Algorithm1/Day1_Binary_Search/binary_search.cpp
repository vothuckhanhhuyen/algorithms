#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
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

        return -1;
    }
};

int main() {

    Solution s;

    vector<int> nums = {1, 2, 3, 4, 5, 6};

    cout << s.search(nums, 4);

    return 0;
}