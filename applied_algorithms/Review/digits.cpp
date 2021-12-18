#include <bits/stdc++.h>
using namespace std;

int N;
int Q = 0;
int characters[6];
bool values[9];

void inputData() {

    cin >> N;
}

bool checked(int i) {

    if (values[i] == 0) {
        return true;
    }

    return false;
}

int compute() {

    int result;

    result = (characters[0] * 1e4 + characters[1] * 1e3 + characters[2] * 1e2 + characters[2] * 1e1 + characters[3]) - (characters[2] * 1e4 + characters[4] * 1e3 + characters[0] * 1e2 + characters[3] * 1e1 + characters[5]);

    return result;
}

void solution() {

    if (compute() == N) {
        Q++;
    }
}

void Try(int a) {

    for (int i = 0; i < 9; i++) {
        if (i == 4) continue;
        if (checked(i)) {
            characters[a] = i + 1;
            values[i] = 1;

            if (a == 5) {
                solution();
            } else {
                Try(a + 1);
            }

            values[i] = 0;
        }
    }
}


int main() {

    inputData();

    Try(0);

    cout << Q;

    return 0;
}