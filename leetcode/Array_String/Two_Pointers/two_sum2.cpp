#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        int sum;
        while (i < j) {
            sum = numbers[i] + numbers[j];
            if (sum == target) {
                return {i + 1, j + 1};
            } else if (sum > target) {
                j--;
            } else {
                i++;
            }
        }
        return {-1, -1};
    }
};

int main() {

    Solution s;

    int target = 22;
    vector<int> numbers = {2, 7, 11, 15};

    vector<int> results = s.twoSum(numbers, target);
    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << " ";
    }

    return 0;
}