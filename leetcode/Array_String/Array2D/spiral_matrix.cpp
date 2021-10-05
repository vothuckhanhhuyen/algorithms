#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> results;

        int rows = matrix.size();
        int columns = matrix[0].size();
        int up = 0;
        int left = 0;
        int right = columns - 1;
        int down = rows - 1;

        while (results.size() < rows * columns) {

            for (int col = left; col <= right; col++) {
                results.push_back(matrix[up][col]);
            }

            for (int row = up + 1; row <= down; row++) {
                results.push_back(matrix[row][right]);
            }

            if (up != down) {
                for (int col = right - 1; col >= left; col--) {
                    results.push_back(matrix[down][col]);
                }
            }

            if (left != right) {
                for (int row = down - 1; row > up; row--) {
                    results.push_back(matrix[row][left]);
                }
            }

            left++;
            right--;
            up++;
            down--;
        }

        return results;
    }
};

int main() {

    Solution s;

    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> results = s.spiralOrder(matrix);

    for (auto r: results) {
        cout << r << " ";
    }

    return 0;
}