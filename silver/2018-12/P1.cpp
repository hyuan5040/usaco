#include <bits/stdc++.h>
using namespace std;
multiset<int> S[2]; 
int pos[2001];
int numOutcomes;
void dfs(int day, int amount) {
	if(day == 6) {
		numOutcomes += 1 - pos[amount];
		pos[amount] = 1;
		return;
	}
	vector<int> vals;
	int p = (day % 2);
	multiset<int>::iterator it = S[p].begin();
	while(it != S[p].end()) {
		vals.push_back(*it);
		it ++;
	}
	for(int i = 0;i < vals.size(); i++) {
		S[p].erase(S[p].find(vals[i]));
		S[1 - p].insert(vals[i]);
                if (p == 0) {
			dfs(day + 1, amount - vals[i]);
                } else {
			dfs(day + 1, amount + vals[i]);
                }
		S[1 - p].erase(S[1 - p].find(vals[i]));
		S[p].insert(vals[i]); 
	}
}
int main() {
	int val;
	for(int p = 0; p < 2;p ++)
		for(int i = 0;i < 10;i ++) {
			cin >> val;
			S[p].insert(val);
		}
	dfs(2, 1000);
	cout << numOutcomes << '\n';
}
