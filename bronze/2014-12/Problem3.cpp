#include <vector>
#include <fstream>
using namespace std;
int main() {
    string fin ("cowjog.in");
    string fout ("cowjog.out");
    if (argc >2) {
            inputFile = argv[1];
            outputFile = argv[2];
    }
    ifstream fin (inputFile);
    ofstream fout (outputFile);

    int n;
    fin >> n;
    vector<int> cows;
    for(int i = 0; i < n; i ++) {
        int x, s;
        fin >> x >> s;
        cows.push_back(s);
    }
    int ans = 1;
    int slow = cows[n-1];
    for(int i=n-2; i>=0; i--) {
        if(cows[i] > slow) {}
        else
            ans++;
        slow = min(slow, cows[i]);
    }
    fout << ans;
}