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
}