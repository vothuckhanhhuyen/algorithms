#include <bits/stdc++.h>
using namespace std;

int N;
int Q = 0;
int characters[7];
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

    result = (characters[0] * 100 + characters[1] * 10 + characters[2]) - (characters[6] * 100 + 62) +  (characters[3] * 1000 + characters[4] * 100 + characters[5] * 10 + characters[2]);

    return result;
}

void solution() {

    if (compute() == N) {
        Q++;
    }
}

void Try(int a) {

    for (int i = 0; i < 9; i++) {
        if (checked(i)) {
            characters[a] = i + 1;
            values[i] = 1;

            if (a == 6) {
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