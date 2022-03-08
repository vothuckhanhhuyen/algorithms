#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
ll n,k,ts=1,ms=1;
ll f(ll a, ll b){
    if (b==0) return 1;
    ll tmp = f(a,b/2);
    tmp = (tmp*tmp)%mod;
    if (b%2==1) tmp = (tmp*a)%mod;
    return tmp;
}
int main() {
    cin >> n >> k;
    for (int i=1;i<n+k;++i) ts = (ts*i)%mod;
    for (int i=1;i<k;++i) ms = (ms*i)%mod;
    for (int i=1;i<=n;++i) ms = (ms*i)%mod;
    ll ans = (ts*f(ms,mod-2))%mod;
    cout << ans;
}