#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <fstream>
using namespace std;

int main (int argc, char *argv[]) {
    string inputFile = "billboard.in";
    string outputFile = "billboard.out";
    if (argc >2) {
        inputFile = argv[1];
        outputFile = argv[2];
    }
    ifstream fin (inputFile);



    ofstream fout (outputFile);
    fout << "42";
    // hi, this is the end
}
