#include <bits/stdc++.h>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        unsigned long long pivot;
        unsigned long long first = 1;
        unsigned long long last = n;
        while (first < last) {
            pivot = (first + last) / 2;
            if (isBadVersion(pivot)) {
                last = pivot;
            } else {
                first = pivot + 1;
            }
        }
        
        return first;
    }
};