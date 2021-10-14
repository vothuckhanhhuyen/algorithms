#include <bits/stdc++.h>
using namespace std;

// bool cmp(pair<int, int> p1, pair<int, int> p2) {
//     return p1.first < p2.first;
// }

int main() {

    int n;
    cin >> n;

    int arr[n];
    int res[n];
    vector<pair<int, int>> coup;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        coup.push_back({arr[i], i});
    }

    // sort(coup.begin(), coup.end(), cmp);
    sort(coup.begin(), coup.end());

    int maxIndex = -1;
    for (int i = 0; i < n; i++) {
        res[coup[i].second] = max(0, maxIndex - coup[i].second);
        maxIndex = max(maxIndex, coup[i].second);
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] - 1 << " ";
    }
    
    return 0;
}
