#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int newColor) {

        if (image[sr][sc] == color) {
            image[sr][sc] = newColor;
            if (sr - 1 >= 0) {dfs(image, sr - 1, sc, color, newColor);}
            if (sc - 1 >= 0) {dfs(image, sr, sc - 1, color, newColor);}
            if (sr + 1 < image.size()) {dfs(image, sr + 1, sc, color, newColor);}
            if (sc + 1 < image[0].size()) {dfs(image, sr, sc + 1, color, newColor);}
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        int color = image[sr][sc];
        if (color != newColor) {
            dfs(image, sr, sc, color, newColor);
        }
        
        return image;
    }
};

int main() {

}