#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second > b.second) return true;
    if (a.second == b.second) 
        if (a.first >= b.first) return true;
    return false;
}

int main() {
    vector<pair<int, int>> dict;
    int key, value;
    while (cin >> key && cin >> value) {
        dict.push_back({key, value});
    }
    
    sort(dict.begin(), dict.end(), cmp);

    for (int i = 0; i < dict.size(); i++) {
        cout << dict[i].first << " " << dict[i].second << endl;
    }
    
    return 0;
}