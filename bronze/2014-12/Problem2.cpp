#include <vector>
#include <fstream>
#include <iostream>
#define MP make_pair
#define PB push_back
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main() {
  string fin("crosswords.in");
  string fout("crosswords.out");

  string inputFile = "marathon.in";
  string outputFile = "marathon.out";
  if (argc >2) {
          inputFile = argv[1];
          outputFile = argv[2];
  }
  ifstream fin (inputFile);
  ofstream fout (outputFile);

  long long R, C;
  fin >> R >> C;
  vector<vector<char> > G(R, vector<char>(C, ' '));
  for(long long r = 0; r < R; r ++) {
    char buf[100];
    fin >> buf;
    for(ll c = 0; c < C; c ++) {
      G[r][c] = buf[c];
    }
  }
  vector<pair<long long, long long>> A;
  for(long long r = 0; r < R; r ++) {
    for(ll c = 0; c < C; c ++) {
      bool horizontal = (c + 2 < C && G[r][c ] == '.' && G[r][c + 1] == '.' && G[r][c + 2] == '.' && (c == 0 || G[r][c - 1] == '#'));
      bool vertical = (r + 2 < R && G[r][c] == '.' && G[r + 1][c]== '.' && G[r + 2][c] == '.' && (r == 0 || G[r - 1][c] == '#'));
      if(horizontal || vertical) {
        A.PB(MP(r + 1, c + 1));
      }
    }
  }
  fout << A.size() << endl;
  for(pll clue : A) {
    fout << clue.first << " " << clue.second << endl;
  }
}