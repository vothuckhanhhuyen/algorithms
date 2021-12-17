#include <bits/stdc++.h>
using namespace std;

// n là số món hàng
// K là số xe
// Q là dung tích mỗi xe
int n, K, Q;

// d[] là mảng dung tích món hàng
// t[] là mảng số xe đã có hàng
// load[] là mảng dung tích đã mất của xe
// bi_val[] là giá trị thập phân tương ứng với biểu diễn tập các hàng xe mang
// pow2[] là lũy thừa của 2
// u[] là lưu kết quả
int d[13], t[13], load[6], bi_val[6], pow2[13], u[10000];

// mảng khoảng cách
int dis[15][15];

int sumdis, ans, mindis = 1e9, ANS = 1e9;

void input() {

    cin >> n >> K >> Q;
    pow2[1] = 1;
    t[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        pow2[i + 1] = pow2[i] * 2;
    }

    for (int i = 1; i <= K; i++) {
        load[i] = 0;
        bi_val[i] = 0;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> dis[i][j];

            if (i != j) {
                mindis = min(mindis, dis[i][j]);
            }
        }
    }

    for (int i = 0; i < 2 * pow2[n]; i++) {
        u[i] = 0;
    }
}

vector<pair<int, bool>> trans_to_list(int x) {

    vector<pair<int, bool>> list;

    for (int i = 1; i <= n; i++) {
        if (x == 0) {
            break;
        }

        if (x % 2 == 1) {
            list.push_back(make_pair(i, false));
        }

        x = x / 2;
    }

    return list;
}

void try_dis(vector<pair<int, bool>> list, int k, int p) {

    if ((sumdis + mindis * (int(list.size()) - k + 2)) >= ans) {
        return;
    }

    if (k == int(list.size() + 1)) {
        ans = min(ans, sumdis + dis[p][0]);
        return;
    }

    for (int i = 0; i < int(list.size()); i++) {
        if (list[i].second) {
            continue;
        }

        int q = p;
        p = list[i].first;
        list[i].second = true;
        sumdis += dis[q][p];
        try_dis(list, k + 1, p);
        list[i].second = false;
        sumdis -= dis[q][p];
        p = q;
    }
}

int cal_dis(int x) {

    if (u[x] > 0) {
        return u[x];
    }

    sumdis = 0;
    ans = 1e9;
    vector<pair<int, bool>> list = trans_to_list(x);
    try_dis(list, 1, 0);
    u[x] = ans;

    return u[x];
}

void main_try(int k) {

    if ((K - t[k - 1]) > (n - k + 1)) {
        return;
    }

    if (k == (n + 1)) {
        int R = 0;
        for (int i = 1; i <= K; i++) {
            R += cal_dis(bi_val[i]);
        }
        ANS = min(ANS, R);
        return;
    }

    int s = min(t[k - 1] + 1, K);

    for (int i = 1; i <= s; i++) {
        if (i == (t[k - 1] + 1)) {
            t[k] = t[k - 1] + 1;
            load[i] += d[k];
            bi_val[i] += pow2[k];
            main_try(k + 1);
            load[i] -= d[k];
            bi_val[i] -= pow2[k];
        } else {
            if ((load[i] + d[k]) > Q) {
                continue;
            }
            t[k] = t[k - 1];
            load[i] += d[k];
            bi_val[i] += pow2[k];
            main_try(k + 1);
            load[i] -= d[k];
            bi_val[i] -= pow2[k];
        }
    }
}

int main() {

    input();

    main_try(1);
    cout << ANS;

    return 0;
}