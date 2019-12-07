#include <iostream>
 #include <algorithm>
 #include <fstream>
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
     ifstream fin ("backforth.in");
     ofstream fout ("backforth.out");
     int n;
     fin >> n;
     int arr[n];
     int sarr[n];
     for (int i = 0; i < n; i ++) {
         fin >> arr[i];
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
     fout << counter << endl;
     return 0;
 }