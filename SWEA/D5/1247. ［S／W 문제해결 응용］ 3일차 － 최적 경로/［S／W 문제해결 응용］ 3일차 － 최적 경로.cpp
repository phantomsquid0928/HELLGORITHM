#include <bits/stdc++.h>

using namespace std;

vector<array<int, 2>> dots;

queue<array<int, 4>> q; // 4 for hist


int main() {
	
	int t;
	cin >> t;
	
	for (int tt = 1; tt <= t; tt++) {
		int n;
		cin >> n;
		
		dots.clear();
		for (int i =0 ;i <n + 2 ; i++) {
			int a,b ;
			cin >> a >> b;
			dots.push_back({a, b});
		}
		
//		q.clear();
		
		q.push({0, 0, 0, 0}); //start always 0
		
		int mincost = 0x3f3f3f3f;
		
		
		while(!q.empty()) {
			auto temp = q.front(); q.pop();
			
			int cur = temp[0];
			int cost = temp[1];
			int level = temp[2];
			int hist = temp[3];
			
//			cout << cur << " " <<  cost << " " <<level << " " << hist << endl;
			
			if (cost > mincost) continue;
			if (level == n) { //visited all
				int finalcost = abs(dots[cur][0] - dots[1][0]) + abs(dots[cur][1] - dots[1][1]);
				mincost = min(mincost, cost + finalcost);
				continue;
			}
			
			for (int i = 2; i < n + 2; i++) {
				if ((hist & (1 << (i - 2))) != 0) continue;
				
				int temp = hist;
				temp |= (1 << (i - 2));
				
				int ncost = abs(dots[i][0] - dots[cur][0]) + abs(dots[i][1] - dots[cur][1]);
				q.push({i, cost + ncost, level + 1, temp});
			}
		}
		
		cout << "#" << tt << " " << mincost << endl;
	}
}