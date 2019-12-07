#include <iostream>
#include <string>

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

  string inputFile = "billboard.in";
  string outputFile = "billboard.out";
  if (argc >2) {
         inputFile = argv[1];
         outputFile = argv[2];
   }
   ifstream fin (inputFile);
   ofstream fout (outputFile);

  int solve, xright, xleft, ydown, yup;
  int x1, y1, x2, y2, xx1, yy1, xx2, yy2;


  fin >> x1 >> y1 >> x2 >> y2 >> xx1 >> yy1 >> xx2 >> yy2;
  if (xx1 > x1) {
    xleft = 0;
  }
  else {
    xleft = 1;
  }
  if (xx2 < x2) {
    xright = 0;
  }
  else {
    xright = 1;
  }
  if (yy1 > y1) {
    ydown = 0;
  }
  else {
    ydown = 1;
  }
  if (yy2 < y2) {
    yup = 0;
  }
  else {
    yup = 1;
  }
  solve = (x2 - x1) * (y2 - y1);
  if ((xleft == 1) && (xright == 1)) {
    if ((ydown == 1) && (yup == 1)) {
      solve = 0;
    }
    else if ((ydown == 1) && (yup == 0)) {
      solve = (x2-x1)*(y2-yy2);
    }
    else if ((ydown == 0)&&(yup == 1)) {
      solve = (x2-x1)*(yy1-y1);
    }
  }
  else if ((ydown == 1) && (yup == 1)) {
    if ((xleft == 1) && (xright == 0)) {
      solve = (y2-y1)*(x2-xx2);
    }
    if ((xright == 1) && (xleft == 0)) {
      solve = (y2-y1)*(xx1-x1);
    }
  }
  fout << solve;
  return 0;
}