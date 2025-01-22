#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	for (int tt = 1; tt <= t; tt++) {
		int res = 0;
		int n, l;
		cin >> n >> l;
		
		vector<array<int, 2>> score;
		
		for (int i =0 ;i <n ; i++) {
			int cost, kal;
			cin >> cost >> kal;
			
			score.push_back({cost, kal});
		}
		
		int sel[21] = {};
		
		int maxsum = 0;
		
		for (int i = 1; i <= n; i++) {
			memset(sel, 0, sizeof(sel));
			for (int j = 0; j < i; j++) {
				sel[j] = i;
			}
			
			do {
				int sum = 0;
				int mincost = 0;
				int cost= 0;
				
				bool valid = true;
				
				
				for (int i = 0; i < n; i++) {
					if (sel[i]) {
						sum += score[i][0];
						cost += score[i][1];
						
						if (cost > l) {
							valid = false;
							break;
						}
						
					}
				}
				
				if (valid) maxsum = max(sum, maxsum);
				
			} while(prev_permutation(sel, sel + n));
		}
		
		cout << "#" << tt << " " << maxsum << endl;
	}
}