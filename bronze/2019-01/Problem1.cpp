#include <iostream>
#include <algorithm>
using namespace std;
struct Swap{
    int a, b, guess;
};
int main () {
    int swaps;
    cin >> swaps;
    int location[3];
    Swap logg[swaps];
    for (int i = 0; i < swaps; i ++) {
        cin >> logg[i].a >> logg[i].b >> logg[i].guess;
    }
    int max = 0;
    for (int i = 0; i < 3; i ++) {
        location[i] = 1;
        int tempCount = 0;
        for (int j = 0; j < swaps; j ++) {
            swap(location[logg[j].a], location[logg[j].b]);
            if (location[logg[j].guess] == 1) {
                tempCount ++;
            }
        }
        if(tempCount > max) {
            max = tempCount;
        }
    }
    cout << max;
}
