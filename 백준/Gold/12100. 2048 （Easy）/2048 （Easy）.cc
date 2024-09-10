#include <bits/stdc++.h>

using namespace std;


struct status {
	int arr[21][21];
	int max = 0;
	int lv;
};
int main() {
	int n;
	cin >> n;
	
	status start;
	for (int i = 0; i< n; i++) {
		for (int j = 0; j< n; j++) {
			cin >> start.arr[i][j];
		}
	}
	start.lv = 0;
	queue<status> q;
	pair<int, int> dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	pair<int, int> startpos[4] = {{0, 0}, {n - 1, 0}, {0, 0}, {0, n - 1}};
	pair<int, int> checkdir[4] = {{0, 1}, {0, 1}, {1, 0}, {1, 0}};
	
	auto getnext = [&](status cur, int d) {
		status next = cur;
		int dx = dir[d].first;
		int dy = dir[d].second;
		
		int resmax = 0;
	
		for (int k = 0; k < n; k++) {
			int curx = startpos[d].first + k * checkdir[d].first; 
			int cury = startpos[d].second + k * checkdir[d].second;
			int curv = cur.arr[curx][cury];
			vector<int> resvec;
			//resvec.push_back(curv);
			for (int i= 0; i < n; i++){ 
				
				if (curx + dx > n - 1 || cury + dy> n - 1 || curx + dx < 0 || cury + dy < 0) break;
				int nextv = next.arr[curx + dx][cury + dy];
				
				if (curv == 0) {
					curv = nextv;
					curx += dx;
					cury += dy;
					continue;
				}
				if (nextv == 0) {
					curx += dx;
					cury += dy;
					continue;
				}
				
				if (nextv == curv && nextv != 0){
					resvec.push_back(curv + nextv);
					curv = 0;
					curx += dx;
					cury += dy;
					continue;
				}
				resvec.push_back(curv);
				curv = nextv;
				curx += dx;
				cury += dy;
			}
			resvec.push_back(curv);
			//resmax = max(resmax, curv);
//			
//			if (cur.lv == 0) {
//				cout << "res: ";
//				for (auto i : resvec) {
//					cout << i << " ";
//				}
//				cout << endl;
//			}
			if (resvec.size() < n) {
				while(resvec.size() != n) resvec.push_back(0);
			}
//			if (d % 2 == 1) {
//				reverse(resvec.begin(), resvec.end());
//			}
			int x = startpos[d].first + k * checkdir[d].first; 
			int y = startpos[d].second + k * checkdir[d].second;
			for (int i =0 ; i< n; i++) {
				next.arr[x][y] = resvec[i];
				resmax = max(resmax, resvec[i]);
				x += dx;
				y += dy;
			}
		}
		next.lv++;
		next.max = resmax;
		return next;
	};
	int maxres = 0;
	q.push(start);
	while(!q.empty()) {
		status cur = q.front(); q.pop();
		if (cur.lv == 5) continue;
		for (int d= 0; d< 4; d++) {
			status next = getnext(cur, d);
			//if (next.lv == 1) {
//			for (int i=0 ;i < n; i++){ 
//					for (int j = 0; j< n; j++) {
//						cout << next.arr[i][j] << " ";
//					}
//					cout << endl;
//				}
//				cout << endl;
			//}
			
			maxres = max(maxres, next.max);
			
			q.push(next);
		}
	}
	
	cout << maxres << endl;
	
}