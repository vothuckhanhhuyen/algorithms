#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkMatches(vector<int> v1, vector<int> v2) {
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        vector<int> str1(26, 0);
        vector<int> str2(26, 0);

        for (int i = 0; i < s1.length(); i++) {
            str1[s1[i] - 'a']++;
            str2[s2[i] - 'a']++;
        }

        for (int j = 0; j < s2.length() - s1.length(); j++) {
            if (checkMatches(str1, str2)) {
                return true;
            }

            str2[s2[s1.length() + j] - 'a']++;
            str2[s2[j] - 'a']--;
        }

        return checkMatches(str1, str2);
    }
};

int main() {

    Solution s; 

    string s1 = "ab";
    string s2 = "agjjdkbad";

    cout << s.checkInclusion(s1, s2);

    return 0;
}