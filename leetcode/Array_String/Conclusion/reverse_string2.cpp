#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> rev;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            reverse(word.begin(), word.end());
            rev.push_back(word);
        }

        string results = "";
        for (int i = 0; i < rev.size(); i++) {
            results += rev[i] + " ";
        }
        results.pop_back();
 
        return results;
    }
};

int main() {

    Solution s; 

    string str = "Hello World";
    cout << s.reverseWords(str);

    return 0;
}