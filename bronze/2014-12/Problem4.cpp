#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <fstream>
#include <climits>
using namespace std;
int main() {
    string fin ("learning.in");
    string fout ("learning.out");
    if (argc >2) {
            inputFile = argv[1];
            outputFile = argv[2];
    }
    ifstream fin (inputFile);
    ofstream fout (outputFile);
    int n, A, B;
    fin >> n >> A >> B;
    vector<pair<int, int> > V;
    for(int i=0; i<n; i++) {
        char buf[100];
        int w;
        fin >> buf >> w;
        V.push_back(make_pair(w, buf[0] == 'S' ? 1 : 0));
    }
    long long INF = LLONG_MAX;
    V.push_back(make_pair(-INF, 0));
    V.push_back(make_pair(INF, 0));
    sort(V.begin(), V.end());
    int ans = 0;
    for(int i = 0; i + 1 < V.size(); i ++) {
        int S = V[i].first;
        int E = V[i + 1].first;
        int M = (S + E) / 2;
        if(V[i].second == 1) {
            int s = max(A, S + 1);
            int e = min(B, M);
        if(e >= s) {
            ans += e - s + 1;
        }
    }
    if(V[i+1].second == 1) {
        int s = max(A, M + 1);
        int e = min(B, E);
        if(e >= s) {
            ans += e - s + 1;
        }
    }
    if(V[i+1].second == 1 && V[i].second == 0 && (S % 2) == (E % 2) && A <= M && M <= B) {
        ans ++;
    }
  }
  fout << ans;
}