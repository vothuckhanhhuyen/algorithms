#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int cmp(vector<int> v1, vector<int> v2) {
    int sum1 = 0;
    int sum2 = 0;
    for (int i : v1) {
        sum1 += i;
    }
    for (int i : v2) {
        sum2 += i;
    }
    
    return sum1 > sum2;
}

int main() {
    int val1, val2;
    cin >> val1 >> val2;
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };

    //# sắp xếp các vector trong a theo tổng các phần tử giảm dần
    /*****************
    # YOUR CODE HERE #
    *****************/
    sort(a.begin(), a.end(), cmp);

    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}