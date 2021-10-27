// #include <bits/stdc++.h>
// using namespace std;

// const int M = 11;
// const int N = 31;

// int m, n, k, course, conflict_count, course_temp1, course_temp2;
// int course_list[M][N];
// int conflict[N][N];
// int assigned[M][N];
// int countCourse[M];
// int res = 0;

// void inputData() {

//     cin >> m >> n;

//     for (int i = 1; i <= m; i++) {
//         cin >> k;
//         for (int j = 1; j <= k; j++) {
//             cin >> course;
//             course_list[i][course] = 1;
//         }
//     }

//     cin >> conflict_count;

//     for (int i = 1; i <= conflict_count; i++) {
//         cin >> course_temp1 >> course_temp2;
//         conflict[course_temp1][course_temp2] = 1;
//         conflict[course_temp2][course_temp1] = 1;
//     }
// }

// bool checked(int m, int a) {

//     if (course_list[m][a] == 1) {
//         for (int i = 1; i <= n; i++) {
//             if (assigned[m][i] == 1 && conflict[a][i] == 1) {
//                 return false;
//             }
//         }
//         return true;
//     }

//     return false;
// }

// void solution() {

//     for (int i = 1; i <= m; i++) {
//         if (countCourse[i] > res) {
//             res = countCourse[i];
//         }
//     }
// }

// void Try(int a) {

//     for (int i = 1; i <= m; i++) {
//         if (checked(i, a)) {
//             assigned[i][a] = 1;
//             countCourse[i]++;

//             if (a == n) {
//                 solution();
//             } else {
//                 Try(a + 1);
//             }

//             assigned[i][a] = 0;
//             countCourse[i]--;
//         }
//     }
// }

// int main() {

//     inputData();

//     Try(1);

//     res = (res == 0 ? -1 : res);

//     cout << res;

//     return 0;
// }