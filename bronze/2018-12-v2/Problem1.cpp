#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])  {
//mixmilk
 string inputFile = "mixmilk.in";
  string outputFile = "mixmilk.out";
  if (argc >2) {
         inputFile = argv[1];
         outputFile = argv[2];
   }
   ifstream fin (inputFile);
   ofstream fout (outputFile);

    int c1, c2, c3, m1, m2, m3;
    fin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;
    for (int i = 0; i < 100; i ++) {
        if (i % 3 == 0) {
            while (m1 > 0 && m2 < c2) {
                m1 --;
                m2 ++;
            }
        }
        else if (i % 3 == 1) {
            while (m2 > 0 && m3 < c3) {
                m2 --;
                m3 ++;
            }
        }
        else {
            while (m3 > 0 && m1 < c1) {
                m3 --;
                m1 ++;
            }
        }
    }
    fout << m1 << endl;
    fout << m2 << endl;
    fout << m3;
}
