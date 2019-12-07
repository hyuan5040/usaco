#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin ("sleepy.in");
    ofstream fout ("sleepy.out");
    int n;
	fin >> n;
	int cows[n];
    int res = n - 1;
	for(int i = 0; i < n; i ++) {
		fin >> cows[i];
	}
	for(int i = n - 2; i >= 0; i --) {
		if(cows[i] < cows[i + 1]) res = i;
		else break;
	}
	fout << res << endl;
	return 0;
}