#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> nums3(m);
        for (int i = 0; i < nums3.size(); i++) {
            nums3[i] = nums1[i];
        }

        int i = 0;
        int j = 0;
        int k = 0;
        while(i < m && j < n) {
            if (nums3[i] <= nums2[j]) {
                nums1[k] = nums3[i];
                i++;
            } else {
                nums1[k] = nums2[j];
                j++;
            }
            k++;
        }

        if (i < m) {
            for (int u = i; u < m; u++) {
                nums1[k] = nums3[u];
                k++;
            }
        }

        if (j < n) {
            for (int v = j; v < n; v++) {
                nums1[k] = nums2[v];
                k++;
            }
        }
    }
};

int main() {

    Solution s;

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

    s.merge(nums1, 3, nums2, 3);

    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }

    return 0;
}