// #include <bits/stdc++.h>
// using namespace std;

// const int N = 10000;
// const int U = 13;
// int n, k;
// int arr[N];
// bool visited[N];
// int idx = 0;

// void Try(int a) {

//     for (int i = 0; i < n; i++) {
//         if (!visited[i]) {
//             arr[a - 1] = i + 1;
//             visited[i] = true;

//             if (a == n) {
//                 idx++;

//                 if (idx == k) {
//                     for (int i = 0; i < n; i++) {
//                         cout << arr[i] << " ";
//                     }
//                 }
//             } else {
//                 if (idx < k) {
//                     Try(a + 1);
//                 }
//             }

//             visited[i] = false;
//         }
//     }
// }

// int main() {

//     ios_base::sync_with_stdio(false);   cin.tie(0);

//     cin >> n >> k;

//     Try(1);

//     Try(1);

//     if (idx < k) {
//         cout << -1;
//     }

//     return 0;
// }