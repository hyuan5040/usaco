#include <iostream>
using namespace std;
int main() {
    int n;
	cin >> n;
	int cows[n];
    int res = n - 1;
	for(int i = 0; i < n; i ++) {
		cin >> cows[i];
	}
	for(int i = n - 2; i >= 0; i --) {
		if(cows[i] < cows[i + 1]) res = i;
		else break;
	}
	cout << res << endl;
	return 0;
}