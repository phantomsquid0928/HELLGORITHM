#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int arr[101];
	
	map<int, int> cnts;
	
	for (int tt = 1; tt <= 10; tt++) {
		int res = 0;
		int n;
		cin >> n;
		
		cnts.clear();
		
		for (int i = 0;i < 100;i ++) {
			int k;
			cin >> k;
			
			if (cnts.count(k)) {
				cnts[k]++;
			}else {
				cnts[k] = 1;
			}
		}
		
		for (int i = 0;i < n; i++) {
			auto small = *cnts.begin();
			auto end = *cnts.rbegin();
			
			if (small.first + 1 == end.first) break;
			
			cnts[small.first + 1]++;
			cnts[small.first]--;
			if (cnts[small.first] == 0) cnts.erase(small.first);
			cnts[end.first]--;
			cnts[end.first - 1]++;
			if (cnts[end.first] == 0) cnts.erase(end.first);
			
		
		}
	
		auto small = *cnts.begin();
		auto end = *cnts.rbegin();
		res = end.first - small.first;
		cout << "#" << tt << " " << res << endl;
	}
}