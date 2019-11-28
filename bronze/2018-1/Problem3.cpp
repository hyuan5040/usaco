#include <iostream>
#include <algorithm>
using namespace std;
int ffind (int arr[], int n, int num) {
    for (int i = 0; i < n; i ++) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}
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
    while (arr != sarr) {
        for (int i = 0; i < n; i ++) {
            if (arr[i] != sarr[i]) {
                int thing = ffind(sarr, n, arr[i]);
                swap(arr[i], arr[thing]);
            }
        }
        counter ++;
    }
    cout << counter << endl;
    return 0;
}