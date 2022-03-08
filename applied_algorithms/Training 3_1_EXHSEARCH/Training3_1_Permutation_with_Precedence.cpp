#include<bits/stdc++.h>
using namespace std;
int n,k,dem=0;
bool d[16];
int a[16],l[16],r[16];

void xuat() {
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
}
bool kiemtra(){
    for (int i=1;i<n;++i){
        for (int j=i+1;j<=n;++j){
            for (int u=1;u<=k;++u){
                if (a[i]==r[u] && a[j]==l[u]) return false;
            }
        }
    }
    return true;
}
void Try(int k) {
    for (int i = 1; i <= n; i++) {
        if (!d[i]) {
            a[k] = i;
            d[i] = 1;
            if (k == n)
                {
                    if (kiemtra()==true) {
                        xuat();
                        dem++;
                    }

                }
            else
                Try(k + 1);
            d[i] = 0;
        }
    }
}

int main() {

    cin >> n >> k;
    for (int i=1;i<=k;++i) cin >> l[i] >> r[i];
    Try(1);
    cout << dem;
}
