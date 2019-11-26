#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, s[105], b[105], t[105];
int bk[1005];
int main () {
     memset(bk, 0, sizeof(bk));
     cin >> n;
     for(int i = 0; i < n; i++){
         cin >> s[i] >> t[i] >> b[i];
     }
     for(int i = 0; i < n; i++){
         for(int k = s[i]; k <= t[i]; k++){
             bk[k] += b[i];
         }
     }
     int maxn = 0;
     for(int i = 0; i <= 1000; i++){
         if(bk[i] > maxn){
             maxn = bk[i];
         }
     }
     cout << maxn << endl;
     return 0;
 }
