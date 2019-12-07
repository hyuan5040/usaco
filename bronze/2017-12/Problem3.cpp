#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <fstream>
using namespace std;

int main (int argc, char *argv[]) {
    string inputFile = "measurement.in";
    string outputFile = "measurement.out";
    if (argc >2) {
        inputFile = argv[1];
        outputFile = argv[2];
    }
    ifstream fin (inputFile.c_str());
    ofstream fout (outputFile.c_str());
    fout << "42";
}