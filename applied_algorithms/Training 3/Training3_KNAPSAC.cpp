#include <bits/stdc++.h>
using namespace std;

const int N = 30;

struct thing {
    int weight; 
    int value;
};

int n, b;
thing thing_list[N];
int total_weight = 0;
int total_value = 0;
int max_total_value = 0;

void inputData() {
    
    cin >> n >> b;

    for (int i = 0; i < n; i++) {
        cin >> thing_list[i].weight >> thing_list[i].value;
    }
}

void solution(int a) {

    if (total_weight > b) {
        total_value -= thing_list[a].value;
    } 

    max_total_value = max(max_total_value, total_value);

    if (total_weight > b) {
        total_value += thing_list[a].value;
    }
}

void Try(int a) {

    for (int i = 0; i <= 1; i++) {
        
        if (i == 1) {
            total_weight += thing_list[a].weight;
            total_value += thing_list[a].value;
        }

        if (total_weight > b || a == n - 1) {
            solution(a);
        } else {
            Try(a + 1);
        }

        if (i == 1) {
            total_weight -= thing_list[a].weight;
            total_value -= thing_list[a].value;
        }
    }
}


int main() {

    inputData();

    Try(0);

    cout << max_total_value;

    return 0;
}