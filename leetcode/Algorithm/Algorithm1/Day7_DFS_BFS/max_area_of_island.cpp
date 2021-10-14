#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calArea(vector<vector<int>> &grid, vector<vector<int>> &seen, int r, int c) {

        if (r < 0 || r >= grid.size() ||
            c < 0 || c >= grid[0].size() ||
            seen[r][c] == 1 || grid[r][c] == 0) {
            return 0;
        }
        seen[r][c] = 1;
        return 1 + calArea(grid, seen, r + 1, c) +
               calArea(grid, seen, r, c + 1) +
               calArea(grid, seen, r - 1, c) +
               calArea(grid, seen, r, c - 1);
    }

    int maxAreaOfIsland(vector<vector<int>> &grid) {

        vector<vector<int>> seen(grid.size(), vector<int> (grid[0].size(), 0));

        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                ans = max(ans, calArea(grid, seen, i, j));
            }
        }

        return ans;
    }
};

int main() {
    
}