#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,u=1;
    cin >> n;
    for (int i=1;i<=n;++i) u = u*2;
    for (int i=0;i<u;++i){
        int x = i;
        v.clear();
        for (int i=0;i<n;++i){
            v.push_back(x%2);
            x = x/2;
        }
        for (int i=0;i<n;++i) cout << v[n-1-i] ;
        cout << '\n';
    }
}