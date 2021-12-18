#include <bits/stdc++.h>
using namespace std;

int countSol(int coeff[], int start, int end, int rhs) {

    if (rhs == 0) return 1;

    int result = 0;
    for (int i = start; i <= end; i++)
        if (coeff[i] <= rhs) result += countSol(coeff, i, end, rhs - coeff[i]);

    return result;
}

int main() {

    int coeff[] = {5, 7, 8, 2};
    int rhs = 38;

    int n = sizeof(coeff) / sizeof(coeff[0]);
    cout << countSol(coeff, 0, n - 1, rhs);

    return 0;
}
