// #include <bits/stdc++.h>
// using namespace std;

// bool cmp(pair<int, int> p1, pair<int, int> p2) {
//     return p1.first < p2.first;
// }

// int main() {

//     int n;
//     cin >> n;

//     int arr[n];
//     int res[n];
//     vector<pair<int, int>> coup;

//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//         coup.push_back({arr[i], i});
//     }

//     sort(coup.begin(), coup.end(), cmp);

//     int distance;
//     int maxIndex = coup[0].second;
//     for (int i = 0; i < n; i++) {
//         distance = maxIndex - coup[i].second - 1;
//         res[coup[i].second] = (distance < 0) ? -1 : distance;
//         maxIndex = max(maxIndex, coup[i].second);
//     }

//     for (int i = 0; i < n; i++) {
//         cout << res[i] << " ";
//     }
    
//     return 0;
// }
