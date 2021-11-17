#include <bits/stdc++.h>
using namespace std;

int main() {
 
    int arr[4];
    for(int i = 0; i < 4; i++) {
        cout << "? " << i + 1 << " " << i + 2 << endl;
        cout.flush();
        cin >> arr[i];
    }

    vector<int> vc = {4, 8, 15, 16, 23, 42};
    do {
        bool check = true;

        for(int i = 0; i < 4; i++){
            check &= (vc[i] * vc[i + 1] == arr[i]);
        }

        if (check) {
            break;
        }
    } while (next_permutation(vc.begin(), vc.end()));

    cout << "!";
    for(int i = 0; i < 6; i++) {
        cout << " " << vc[i];
    }
    cout << endl;

    return 0;
}