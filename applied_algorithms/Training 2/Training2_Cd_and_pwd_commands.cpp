#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    getchar();

    string s;
    vector<string> q;
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        
        stringstream ss(s);
        string word;
        while (getline(ss, word, ' ')) {
            if (word == "pwd") {
                cout << "/";
                for (int  i = 0; i < q.size(); i++) {
                    cout << q[i] << "/"; 
                }
                cout << endl;
            } else if (word == "cd") {
                continue;
            } else {
                stringstream ww(word);
                string wi;
                while(getline(ww, wi, '/')) {
                    if (wi == "..") {
                        if (!q.empty()) {
                            q.pop_back();
                        }
                    } else if (wi == "") {
                        q.clear();
                    } else {
                        q.push_back(wi);
                    }
                }
            }
        }
    }

    return 0;
}