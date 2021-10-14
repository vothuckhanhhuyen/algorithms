#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<pair<int, int>> edges;
    vector<int> vec1;
    vector<int> vec2;
    int x, y;

    edges.push_back({0, 0});
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        edges.push_back({x, y});

        if (x == 0) {
            vec1.push_back({i});
        }
    }

    int k, e;
    for (int i = 0; i < vec1.size(); i++) {
        e = vec1[i];
        while (e) {
            k = e;
            e = edges[k].second;
        }
        vec2.push_back(k);
    }

    for (int i = 0; i < vec1.size() - 1; i++) {
        edges[vec2[i]].second = vec1[i + 1];
        edges[vec1[i + 1]].first = vec2[i];
    }

    for (int i = 1; i <= n; i++) {
        cout << edges[i].first << " " << edges[i].second << endl;
    }

    return 0;
}