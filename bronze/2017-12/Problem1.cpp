#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <fstream>
using namespace std;
struct corners {
    int x1;
    int x2;
    int y1;
    int y2;
};
bool whole[2000][2000];
int main (int argc, char *argv[]) {

    string inputFile = "billboard.in";
    string outputFile = "billboard.out";
    if (argc > 2) {
        inputFile = argv[1];
        outputFile = argv[2];
    }
    for(int i=0;i<2000;i++)
      for(int j=0;j<2000;j++)
        whole[i][j] = false;

    ifstream fin (inputFile.c_str());
    ofstream fout (outputFile.c_str());

    //fout << "hi , 112"  << endl;

    corners bb1;
    corners bb2;
    corners truck;
    fin >> bb1.x1 >> bb1.y1 >> bb1.x2 >> bb1.y2;
    fin >> bb2.x1 >> bb2.y1>> bb2.x2 >> bb2.y2;
    fin >> truck.x1 >> truck.y1 >> truck.x2 >> truck.y2;


    int total = 0;
    for (int i = bb1.x1 + 1000; i < bb1.x2 + 1000; i ++) {
        for (int j = bb1.y1 + 1000; j < bb1.y2 + 1000; j ++) {
            whole[i][j] = true;
            total ++;
            //fout << i << ", " << j << " , " << endl;
        }
    }
    //fout << total << endl;
    for (int i = bb2.x1 + 1000; i < bb2.x2 + 1000; i ++) {
        for (int j = bb2.y1 + 1000; j < bb2.y2 + 1000; j ++) {
            whole[i][j] = true;
            total ++;
            //fout << i << ", " << j << " , " << endl;
        }
    }
    //fout << total << endl;
    for (int i = truck.x1 + 1000; i < truck.x2 + 1000; i ++) {
        for (int j = truck.y1 + 1000; j < truck.y2 + 1000; j ++) {
            if (whole[i][j] == true) {
                total --;
                //fout << i << ", " << j << " , " << endl;
            }
        }
    }
    fout << total;
}