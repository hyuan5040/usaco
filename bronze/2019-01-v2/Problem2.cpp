#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])   {
//sleepy
   string inputFile = "sleepy.in";
    string outputFile = "sleepy.out";
    if (argc >2) {
           inputFile = argv[1];
           outputFile = argv[2];
     }
     ifstream fin (inputFile);
     ofstream fout (outputFile);

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