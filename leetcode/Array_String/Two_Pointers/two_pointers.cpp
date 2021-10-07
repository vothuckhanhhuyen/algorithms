#include <bits/stdc++.h>
using namespace std;

void reverse(int *v, int N) {

    int i = 0;
    int j = N - 1;
    while (i < j) {
        swap(v[i], v[j]);
        i++;
        j--;
    }
}

int removeElement(vector<int>& nums, int val) {

    int k = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            ++k;
        }
    }
    
    return k;
}

int main() {

    
}