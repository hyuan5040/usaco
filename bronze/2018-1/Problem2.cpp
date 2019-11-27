#include <bits/stdc++.h>
using namespace std;
struct lifeguard {
    int start, end;
} lifeguard;
int main() {
    int n;
    cin >> n;
    lifeguard lifeguards[n];
    int max_time = 0;
    for (int i = 0; i < n; i ++) {
        cin >> lifeguards.start >> lifeguards.end;
    }
    for (int i = 0; i < n; i ++) {
        int time[1000] = {};
        for (int j = 0; j < n; j ++) {
            int temp = 0;
            if (j == i) {
                break;
            }
            else {
                for (int k = lifeguards.start; k < lifeguards.end; k ++) {
                    if (time[k] == 0) {
                        temp ++;
                        time[k] == 1;`
                    }
                }
            }
        }
        if (temp >= max_time) {
            max_time = temp;
        }
    }
    cout << max_time << endl;
    return 0;
}
