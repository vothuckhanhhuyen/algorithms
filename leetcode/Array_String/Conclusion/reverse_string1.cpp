#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> reverse;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            reverse.push_back(word);
        }

        string results = "";
        for (int i = reverse.size() - 1; i >= 0; i--) {
            results += reverse[i] + " ";
        }
        results.pop_back();
 
        return results;
    }
};

int main() {

    Solution s; 

    string str = "  Hello World  ";
    cout << s.reverseWords(str);

    return 0;
}