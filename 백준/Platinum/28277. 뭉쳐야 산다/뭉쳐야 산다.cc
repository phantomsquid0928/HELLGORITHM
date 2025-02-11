#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<set<int>> sets;
int main() {
	int n, q;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> q;
	
	for (int i =1 ;i  <= n; i++) {
		set<int> temp;
		int nn;
		cin >> nn;
		
		for (int j = 0; j < nn; j++) {
			int in;
			cin >> in;
			temp.insert(in);
		}
		sets.push_back(temp);
	}
	
	while(q--) {
		int a;
		cin >> a;
		
		if (a == 2) {
			int b;
			cin >> b;
			cout << sets[b - 1].size() << endl;
		}
		if (a == 1) {
			int b, c;
			cin >> b >> c;
			if (sets[b -1].size() > sets[c - 1].size()) {
				sets[b - 1].insert(sets[c - 1].begin(), sets[c - 1].end());
				sets[c - 1].clear();
			}
			else {
				sets[c - 1].insert(sets[b - 1].begin(), sets[b - 1].end());
				sets[b - 1].clear();
				sets[b - 1].swap(sets[c - 1]);
			}
		}
	}
}