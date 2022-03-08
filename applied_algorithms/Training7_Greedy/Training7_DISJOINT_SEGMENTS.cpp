#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int N = 1e5+5;
int n,dem=0;
vector < pair<int,int> > a;
int l,r;
int t[N];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    a.pb(mp(-1,-1));
    for (int i=1;i<=n;++i){
        cin >> l >> r;
        a.pb(mp(r,l));
    }
    sort(a.begin(),a.end());
    while(dem<n){
        for (int i=a[dem].first+1;i<a[dem+1].first;++i) t[i]=t[i-1];
        t[a[dem+1].first] = max(t[a[dem+1].second-1] + 1,t[a[dem+1].first]);
        t[a[dem+1].first] = max(t[a[dem+1].first],t[a[dem+1].first-1]);
        dem++;
    }
    cout << t[a[n].first] ;
}
