#include <bits/stdc++.h>

using namespace std;

vector<array<int, 2>> targets;
vector<array<int, 2>> hist;

int main() {
	int n, m, d;
	cin >> n >> m >> d;
	
	for (int i = 0; i< n; i++) {
		for (int j = 0; j < m; j++) {
			int in;
			cin >> in;
			if (in == 0) continue;
			targets.push_back({i, j});
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
			
			vector<int> to_delete(targets.size(), 0);
			for (auto &a : archer) {
				int mindist = 1000000;
				int idx = -1;
				
				int x = a[0];
				int y = a[1];
				
				for (int i= 0 ;i < targets.size(); i++) {
					auto t = targets[i];
					int tx = t[0];
					int ty = t[1];
//					if (t[2]) continue;
					
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
				
				if (idx != -1) to_delete[idx] = 1;
			}
			
//			cout << "selected";
		
//			cout << "selected";
			int count = 0;
			int count2 = 0;
			targets.erase(remove_if(targets.begin(), targets.end(), [&](array<int, 2> & t) {
				if (to_delete[count]) {
					count2++;
//					cout << targets[count][0] << " " << targets[count][1] << "]";
				}
				return to_delete[count++];
			}
			), targets.end());
			res += count2;
//			cout << endl;
	
//			cout << endl;
			
//			for (auto &t : targets) {
////				if (t[2]) continue;
//				cout << t[0] << " " << t[1] << "]";
//			}
////			cout << endl;
			
//			for (auto &t : targets) {
//				
//				t[0]++;
//				if (t[0] == n) {
//					
//				}
//			}
			targets.erase(remove_if(targets.begin(), targets.end(), [&](array<int, 2> &t){ t[0]++; return t[0] == n;
			}), targets.end());
		}
		maxres = max(res, maxres);
	}
	cout << maxres << endl;
}