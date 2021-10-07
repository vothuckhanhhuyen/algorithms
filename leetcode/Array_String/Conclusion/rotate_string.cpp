#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        k %= length; // *
        reverse(nums, 0, length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, length - 1);
    }
};

int main() {

    Solution s;

    int k = 3;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

    s.rotate(nums, k);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}