#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
string s,t;
int ls,lt,ans=0;
ll tmp = 0,cur = 0;
ll f(ll a, ll b){
    if (b==0) return 1;
    ll tmp = f(a,b/2);
    tmp = (tmp*tmp)%mod;
    if (b%2==1) tmp = (tmp*a)%mod;
    return tmp;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    getline(cin,s);
    getline(cin,t);
    ls = s.size();
    lt = t.size();
    if (ls>lt){
        cout << 0;
        return 0;
    }
    for (int i=0;i<ls;++i){
        tmp = (tmp*503+s[i])%mod;
    }
    ll x = f(503,ls-1);
    for (int i=0;i<ls;++i){
        cur = (cur*503+t[i])%mod;
    }
    if (cur==tmp) ans++;
    for (int i=ls;i<lt;++i){
        cur = (cur-x*t[i-ls]+mod*mod)%mod;
        cur = (cur*503+t[i])%mod;
        if (cur==tmp) ans++;
    }
    cout << ans;
}