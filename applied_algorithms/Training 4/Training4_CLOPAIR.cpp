// #include <bits/stdc++.h>
// using namespace std;

// const double oo = DBL_MAX;

// struct point {
//     int x;
//     int y;
//     int id;
// };

// int n, id1, id2;
// double global_res = oo;
// point arr[50010];

// bool cmpx(point a, point b) {
    
//     if (a.x < b.x) {
//         return true;
//     } else if (a.x == b.x) {
//         return a.y <= b.y;
//     } else {
//         return false;
//     }
// }

// bool cmpy(point a, point b) {
    
//     if (a.y < b.y) {
//         return true;
//     } else if (a.y == b.y) {
//         return a.x <= b.x;
//     } else {
//         return false;
//     }
// }

// double dis(point a, point b) {

//     return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
// }

// double clopair(int left, int right) {

//     if (left == right) {
//         return oo;
//     }

//     if (left + 1 == right) {
//         if (dis(arr[left], arr[right]) < global_res) {
//             id1 = arr[left].id;
//             id2 = arr[right].id;
//             global_res = dis(arr[left], arr[right]);
//         }
//         return global_res;
//     }

//     int mid = (left + right) / 2;

//     double d1 = clopair(left, mid);
//     double d2 = clopair(mid, right);
//     double d = min(d1, d2);

//     vector<point> mid_points;
//     for (int i = left; i <= right; i++) {
//         mid_points.push_back(arr[i]);
//     }
//     sort(mid_points.begin(), mid_points.end(), cmpy);

//     for (int i = 0; i < mid_points.size(); i++) {
//         for (int j = i + 1; j < mid_points.size(); j++) {
//             if (mid_points[i].y + d < mid_points[j].y) {
//                 break;
//             }
//             if (dis(mid_points[i], mid_points[j]) < global_res) {
//                 id1 = min(mid_points[i].id, mid_points[j].id);
//                 id2 = max(mid_points[i].id, mid_points[j].id);
//                 global_res = dis(mid_points[i], mid_points[j]);
//             }
//         }
//     }

//     return global_res;
// }

// int main() {

//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i].x >> arr[i].y;
//         arr[i].id = i;
//     }
//     sort(arr, arr + n, cmpx);

//     double res = clopair(0, n - 1);

//     cout << id1 << " " << id2 << " ";
//     cout << fixed << setprecision(6) << res;

//     return 0;
// }
