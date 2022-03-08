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

    if (values[i] == 0 && i != 0 && i != 5) {
        return true;
    }

    return false;
}

int compute() {

    int result;

    result = (characters[0] * 10000 + characters[1] * 1000 + characters[2] * 110 + characters[3]) - (characters[2] * 10000 + characters[4] * 1000 + characters[0] * 100 + characters[3] * 10 + characters[5]);

    return result;
}

void solution() {

    if (compute() == N) {
        Q++;
    }
}

void Try(int a) {

    for (int i = 0; i <= 9; i++) {
        if (checked(i)) {
            characters[a] = i;
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