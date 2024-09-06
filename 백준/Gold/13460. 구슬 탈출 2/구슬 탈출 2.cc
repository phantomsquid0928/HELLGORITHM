#include <bits/stdc++.h>

using namespace std;

int arr[11][11] = {};
struct status {
	pair<int, int> rpos;
	pair<int, int> bpos;
	int lv;
};
int main() {
	int n, m;
	cin >> n >> m;
	
	pair<int, int> startr;
	pair<int, int> startb;
	pair<int, int> end;
	
	for (int i =0 ;i < n; i++) {
		for (int j =0; j< m; j++) {
			char c;
			cin >> c;
			if (c == '#') arr[i][j] = 1;
			if (c == 'B') {
				arr[i][j] = 2;
				startb = {i, j};
			}
			if (c == 'R') {
				startr = {i, j};
				arr[i][j] = 3;
			}
			if (c == 'O') {
				end = {i, j};
				arr[i][j] = 4;
			}
		
		}
	
	}
	
	status s;
	s.bpos = startb;
	s.rpos = startr;
	s.lv = 0;
	
	queue<status> q;
	
	q.push(s);
	
	int maxres = 11;
	auto getnext = [&](status &cur, pair<int, int> dir) {
		pair<int, int> lastr = cur.rpos;
		pair<int, int> lastb = cur.bpos;
		bool found = false;
		while(true) {
			int nextrx = lastr.first + dir.first;
			int nextry = lastr.second + dir.second;
			int nextbx = lastb.first + dir.first;
			int nextby = lastb.second + dir.second;
			
			int check = 0;
			
			if (lastr == end) {
				found = true;
				nextrx = lastr.first;
				nextry = lastr.second;
				
				if (arr[nextbx][nextby] == 1 || lastb == end) {
					nextbx = lastb.first;
					nextby = lastb.second;
					break;
				}
				lastb.first = nextbx;
				lastb.second = nextby;
				continue;
			}
			if (nextrx == lastb.first && nextry == lastb.second && arr[nextbx][nextby] == 1) {
				nextrx = lastr.first;
				nextry = lastr.second;
				nextbx = lastb.first;
				nextby = lastb.second;
				check += 2;
			}
			if (nextbx == lastr.first && nextby == lastr.second && arr[nextrx][nextry] == 1) {
				nextbx = lastb.first;
				nextby = lastb.second;
				nextrx = lastr.first;
				nextry = lastr.second;
				check += 2;
			}
			
			if (arr[nextrx][nextry] == 1) {
				nextrx = lastr.first;
				nextry = lastr.second;
				check++;
			}
			if (arr[nextbx][nextby] == 1) {
				nextbx = lastb.first;
				nextby = lastb.second;
				check++;
			}
			
			lastr.first = nextrx;
			lastr.second = nextry;
			lastb.first = nextbx;
			lastb.second = nextby;
			
			if (check >= 2) break;
			if (lastb == end) break;
			//if (lastr == end || lastb == end) break;
			//if (lastr == end.first && nextby == end.second) break;
		}
		status ret;
		
		ret.rpos = lastr;
		ret.bpos = lastb;
		ret.lv = cur.lv + 1;
		return ret;
	};
	
	pair<int, int> dirs[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
	
	while(!q.empty()) {
		auto cur = q.front(); q.pop();
		
		arr[cur.rpos.first][cur.rpos.second] = 3;
		arr[cur.bpos.first][cur.bpos.second] = 2;
		
//		for (int i = 0; i< n; i++) {
//			for (int j = 0; j< m; j++) {
//				cout << arr[i][j] << " ";
////					if (arr[i][j] == 1) cout << '#';
////					if (arr[i][j] == 0) cout << '.';
////					if (arr[i][j] == 2) cout << 'B';
////					if (arr[i][j] == 3) cout << 'R';
//			}
//			cout << endl;
//		}
			
		for (auto d : dirs) {
			status next = getnext(cur, d);
			if (next.rpos == cur.rpos && next.bpos == cur.bpos) continue;
			if (next.lv > 10) continue;
			if (next.bpos == end) continue;
			if (next.rpos == end && next.bpos != end) {
				maxres = min(maxres, next.lv);
				continue;
			}
//			cout << "rpos : " << cur.rpos.first << cur.rpos.second << endl;
//			cout << "bpos : " << cur.bpos.first << cur.bpos.second<< endl;

			arr[cur.rpos.first][cur.rpos.second] = 0;
			arr[cur.bpos.first][cur.bpos.second] = 0;
			q.push(next);
		}
	} 
	
	if (maxres == 11) cout << -1 << endl;
	else cout << maxres << endl;
	
}