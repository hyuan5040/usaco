#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    int n;
    cin >> n;
    int arr[n];
    int sarr[n];
    for (int i = 0; i < n; i ++) {
        cin >> arr[i];
        sarr[i] = arr[i];
    }
    int counter = 0;
    while (arr[i] != sarr) {
        for (int i = 0; i < n; i ++) {
            if (arr[i] != sarr[i]) {
                swap(arr[i], arr[find(sarr, sarr + n, arr[i])]);
            }
        }
        counter ++;
    }
    cout << counter << endl;
    return 0;
}