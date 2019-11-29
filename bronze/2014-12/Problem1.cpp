#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int calc_md(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
struct checkpoint {
    int x;
    int y;
};
int main () {
    int n;
    cin >> n;
    checkpoint checkpoints[n];
    int time_saved[n] = {};
    for (int i = 0; i < n; i ++) {
        cin >> checkpoints[i].x >> checkpoints[i].y;
    }
    for (int i = 1; i < n - 1; i ++) {
        int x1 = checkpoints[i - 1].x;
        int x2 = checkpoints[i].x;
        int x3 = checkpoints[i + 1].x;
        int y1 = checkpoints[i - 1].y;
        int y2 = checkpoints[i].y;
        int y3 = checkpoints[i + 1].y;
        for (int j = 1; j < n - 1; j ++) {
            time_saved[i] += calc_md(checkpoints[j].x, checkpoints[j].y, checkpoints[j + 1].x, checkpoints[j + 1].y);
        }
        time_saved[i] += calc_md(x1, y1, x3, y3);
        time_saved[i] -= calc_md(x1, y1, x2, y2);
        time_saved[i] -= calc_md(x2, y2, x3, y3);
    }
    int max = 0;
    int position;
    for (int i = 1; i < n - 1; i ++) {
        if (time_saved[i] > max) {
            max = time_saved[i];
            position = i;
        }
    }
    cout << time_saved[position];
}