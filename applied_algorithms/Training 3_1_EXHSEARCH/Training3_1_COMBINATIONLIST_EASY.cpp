#include<bits/stdc++.h>
using namespace std;

#define max 20
int x[max];
int n, k;
void Xuatnghiem()  {
    for (int i = 1; i <= k; i++) cout << x[i] << ' ';
    cout << '\n';
}
void ToHop (int i)  {
    for (int j = x[i-1] + 1; j <= n-k+i; j++)  {
        x[i] = j;
        if (i == k)
            Xuatnghiem();
        else
            ToHop(i+1);
    }
}
int main()  {
    cin >> n >> k;
    x[0] = 0;  ToHop(1);
    return 0;
}