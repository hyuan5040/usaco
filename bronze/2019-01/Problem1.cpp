#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
struct Swap{
    int a, b, guess;
};
int main () {
    ifstream fin ("shell.in");
    ofstream fout ("shell.out");
    int swaps;
    fin >> swaps;
    int location[3];
    Swap logg[swaps];
    for (int i = 0; i < swaps; i ++) {
        fin >> logg[i].a >> logg[i].b >> logg[i].guess;
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
    fout << max;
}
