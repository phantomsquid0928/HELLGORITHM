#include <bits/stdc++.h>

using namespace std;

vector<array<int, 3>> targets;
vector<array<int, 3>> hist;

int main() {
	int n, m, d;
	cin >> n >> m >> d;
	
	for (int i = 0; i< n; i++) {
		for (int j = 0; j < m; j++) {
			int in;
			cin >> in;
			if (in == 0) continue;
			targets.push_back({i, j, 0});
		}
	}
	
	hist = targets;
	
	int maxres = 0;
	
	for (int i = 1; i < pow(2, m); i++) {
		int temp = i;
		int cnt = 0;
		
		vector<array<int, 2>> archer;
		targets = hist;
		
		for (int k = 0; k < m; k++) {
			if (temp & 1 == 1) {
				archer.push_back({n, k});
				cnt++;
			}
			temp = temp >> 1;
		}
		if (cnt != 3) continue;
		
		int res = 0;
		
		for (int tt = 0; tt < n; tt++) {
			set<int> s;
			for (auto &a : archer) {
				int mindist = 1000000;
				int idx = -1;
				
				int x = a[0];
				int y = a[1];
				
				for (int i= 0 ;i < targets.size(); i++) {
					auto t = targets[i];
					int tx = t[0];
					int ty = t[1];
					if (t[2]) continue;
					
					int dist = abs(x - tx) + abs(y - ty);
					
					if (dist > d) continue;
					if (mindist >= dist) {
						if (idx == -1) {
							idx = i;
							mindist = dist;
							continue;
						}
						if (mindist == dist && targets[idx][1] <= ty) continue;
						idx = i;
						mindist = dist;
					}
				}
				
				if (idx != -1) s.insert(idx);
			}
			
//			cout << "selected";
			for (auto &r : s) {
//				cout << targets[r][0] << " " << targets[r][1] << ",";
				targets[r][2] = 1;
				res++;
			}
//			cout << endl;
			
//			for (auto &t : targets) {
//				if (t[2]) continue;
//				cout << t[0] << " " << t[1] << "]";
//			}
//			cout << endl;
			
			int ss = 0;
			for (auto &t : targets) {
				if (t[2]) {
					ss++;
					continue;
				}
				
				t = {t[0] + 1, t[1], t[2]};
				if (t[0] == n) {
					t[2] = 1;
				}
			}
			if (ss == targets.size()) break;
		}
		maxres = max(res, maxres);
	}
	cout << maxres << endl;
}