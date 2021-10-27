#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> res(n + 1, 0);
        res[1] = nums[0];
        
        for (int i = 2; i <= n; i++) {
            res[i] = max(res[i - 1], nums[i - 1] + res[i - 2]);
        }
        
        return res[n];
    }
};

int main() {

    
}