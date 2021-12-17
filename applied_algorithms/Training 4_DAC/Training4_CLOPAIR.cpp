#include <bits/stdc++.h>
using namespace std;

typedef struct pair<double, double> dd;
typedef struct pair<dd, int> ddi;

#define x first.first
#define y first.second
#define id second
#define MAXN 100001

const double oo = 1e12;

int n;
int p1, p2;
ddi p[MAXN];

double global_res = oo;

double dis(ddi i, ddi j) {
    return sqrt((i.x - j.x) * (i.x - j.x) + (i.y - j.y) * (i.y - j.y));
}

bool cprY(ddi a, ddi b) {
    if (a.y < b.y)
        return true;
    if (a.y == b.y)
        return a.x <= b.x;
    return false;
}

double find_min_dis(int l, int r) {

    if (l == r) {
        return oo;
    }

    int mid = (l + r) >> 1;
    double D1 = find_min_dis(l, mid);
    double D2 = find_min_dis(mid + 1, r);

    double D = min(D1, D2);

    vector<ddi> X;
    for (int i = l; i <= r; i++) {
        X.push_back(p[i]);
    }
    sort(X.begin(), X.end(), cprY);

    for (int i = 0; i < X.size(); i++) {
        for (int j = i + 1; j < X.size(); j++) {
            if (X[i].y + D < X[j].y)
                break;
            if (dis(X[i], X[j]) < global_res) {
                global_res = dis(X[i], X[j]);
                p1 = min(X[i].id, X[j].id);
                p2 = max(X[i].id, X[j].id);
            }
        }
    }

    return global_res;
}

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].id = i;
    }
    sort(p + 1, p + n + 1);

    global_res = find_min_dis(1, n);

    printf("%d %d %0.6lf", p1 - 1, p2 - 1, global_res);
    
    return 0;
}