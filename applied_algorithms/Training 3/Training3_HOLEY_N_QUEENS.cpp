#include <bits/stdc++.h>
using namespace std;

const int N = 12;
int n, m;
int row, col;
int result;
int check_col[N + 1];
int check_sub[2*N - 1];
int check_add[2*N - 1];
int holey[N + 1][N + 1];

void n_queens(int a) {

    for (int j = 1; j <= n; j++) {
        if (!check_col[j] == 1 && !check_sub[a - j + n - 1] == 1 && !check_add[a + j - 2] == 1 && !holey[a][j] == 1) {
            check_col[j] = check_sub[a - j + n - 1] = check_add[a + j - 2] = 1;

            if (a == n) {
                result++;
            } else {
                n_queens(a + 1);
            }

            check_col[j] = check_sub[a - j + n - 1] = check_add[a + j - 2] = 0;
        }
    }
}

int main() {


    while(true) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        } else {
            memset(check_col, 0, sizeof(check_col));
            memset(check_sub, 0, sizeof(check_sub));
            memset(check_add, 0, sizeof(check_add));
            memset(holey, 0, sizeof(holey));
            result = 0;

            for (int i = 0; i < m; i++) {
                cin >> row >> col;
                holey[row][col] = 1;
            }

            n_queens(1);

            cout << result << endl;
        }
    }
}