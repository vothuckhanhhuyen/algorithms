#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> pos;
    vector<int> neg;
    vector<int> zeros;
    
    int temp;
    for (int i = 0; i < n; i++) {
        cin>> temp;
        if (temp == 0) {zeros.push_back(temp);}
        if (temp < 0) {neg.push_back(temp);}
        if (temp > 0) {pos.push_back(temp);}
    }

    if (pos.size() == 0) {
        temp = neg.back();
        neg.pop_back();
        pos.push_back(temp);

        temp = neg.back();
        neg.pop_back();
        pos.push_back(temp);
    }

    if (neg.size() % 2 == 0) {
        temp = neg.back();
        neg.pop_back();
        zeros.push_back(temp);
    }

    cout << neg.size() << " ";
    for (int i = 0; i < neg.size(); i++) {
        cout << neg[i] << " ";
    }
    cout << endl;

    cout << pos.size() << " ";
    for (int i = 0; i < pos.size(); i++) {
        cout << pos[i] << " ";
    }
    cout << endl;

    cout << zeros.size() << " ";
    for (int i = 0; i < zeros.size(); i++) {
        cout << zeros[i] << " ";
    }
    cout << endl;

    return 0;
}