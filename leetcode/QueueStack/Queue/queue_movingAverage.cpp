#include <bits/stdc++.h>
using namespace std;

class MovingAverage {
private:
    queue<int> q;
    int size;
    int sum;
public:
    MovingAverage(int size) {
        this -> size = size;
        this -> sum = 0;
    }
    
    double next(int val) {
        sum += val;
        q.push(val);
        if (q.size() > size) {
            sum -= q.front();
            q.pop();
        }

        return 1.0 * sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
int main() {
    MovingAverage movingAverage(3);

    cout << movingAverage.next(1) << endl; // return 1.0 = 1 / 1
    cout << movingAverage.next(10) << endl; // return 5.5 = (1 + 10) / 2
    cout << movingAverage.next(3) << endl; // return 4.66667 = (1 + 10 + 3) / 3
    cout << movingAverage.next(5) << endl; // return 6.0 = (10 + 3 + 5) / 3

    return 0;
}