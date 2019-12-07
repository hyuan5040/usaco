#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
int n, s[105], b[105], t[105];
int bk[1005];
int main () {
    ifstream fin;
    fin.open ("blist.in");
    ofstream fout;
    fout.open ("blist.out");
     memset(bk, 0, sizeof(bk));
     fin >> n;
     for(int i = 0; i < n; i++){
         fin >> s[i] >> t[i] >> b[i];
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
     fout << maxn << endl;
     return 0;
 }
