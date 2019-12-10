#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <fstream>

using namespace std;
struct lifeguard {
    int start;
    int end;
};
int main(int argc, char *argv[]) {
  string inputFile = "lifeguards.in";
  string outputFile = "lifeguards.out";
  if (argc >2) {
         inputFile = argv[1];
         outputFile = argv[2];
   }
   ifstream fin (inputFile);
   ofstream fout (outputFile);

    int n;
    fin >> n;
    lifeguard lifeguards[n];
    int max_time = 0;
    for (int i = 0; i < n; i ++) {
        fin >> lifeguards[i].start >> lifeguards[i].end;
    }
    for (int i = 0; i < n; i ++) {
        int time[1000] = {};
        int temp = 0;
        for (int j = 0; j < n; j ++) {
            if (j == i) {
                break;
            }
            else {
                for (int k = lifeguards[j].start; k < lifeguards[j].end; k ++) {
                    if (time[k] == 0) {
                        temp ++;
                        time[k] == 1;
                    }
                }
            }
        }
        if (temp >= max_time) {
            max_time = temp;
        }
    }
    fout << max_time << endl;
    return 0;
}
