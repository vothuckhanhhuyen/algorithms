#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> results;
        map<int, vector<int>> mp;
        
        for(int i = 0 ; i < mat.size() ; i++)  {
            for(int j = 0 ; j < mat[i].size() ; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }
        
        for(auto i : mp) {
            if((i.first) % 2 == 0)  {
                reverse(i.second.begin(), i.second.end()); 
            }
            for(auto k : i.second) {
                results.push_back(k);
            }
        }
        return results;
    }
};

int main() {

    Solution s;

    vector<vector<int> > mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> results = s.findDiagonalOrder(mat);

    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << " ";
    }

    return 0;
}