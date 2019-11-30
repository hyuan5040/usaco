#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <fstream>
using namespace std;

int calc_md(pair<int, int> one, pair<int, int> two) {
    return abs(one.first - two.first) + abs(one.second - two.second);
}
int total (vector<pair<int, int>> points, int n) {
    int total = 0;
    for (int i = 1; i < n; i ++) {
        total += calc_md(points[i], points[i - 1]);
    }
    return total;
}

int main (int argc, char *argv[]) {
    string inputFile = "marathon.in";
    string outputFile = "marathon.out";
    if (argc >2) {
        inputFile = argv[1];
        outputFile = argv[2];
    }
    ifstream fin (inputFile);
    ofstream fout (outputFile);

    int n;
    fin >> n;
    vector <pair<int, int>> points;
    for (int i = 0; i < n; i ++) {
        pair <int, int> temp;
        fin >> temp.first >> temp.second;
        points.push_back(temp);
    }
    int totall = total(points, n);
    //cout << "total1 is " << totall << endl;
    int least = 2147483647;
    for (int i = 1; i < n - 1; i ++) {
        //int temp = totall - ( calc_md(points[i - 1], points[i]) - calc_md(points[i + 1], points[i] -  calc_md(points[i - 1], points[i + 1]))
        int temp = totall + calc_md(points[i - 1], points[i + 1]) - calc_md(points[i - 1], points[i]) - calc_md(points[i + 1], points[i]);
        if (temp < least) {
            least = temp;
        }
    }
    fout << least;
}