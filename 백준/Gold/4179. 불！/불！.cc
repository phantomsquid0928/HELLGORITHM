#include <bits/stdc++.h>

using namespace std;

int a[1001][1001];
int visited[1001][1001];
pair<int, int> start;
vector<pair<int, int>> fstart;
int dt[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int main() {
	int n, m;
	cin >> n >> m; // 4,4  -> 0, 3 equals exxit. 
	for (int i = 0 ; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == '#') {
				a[i][j] = -1;
			}
			if (c == 'J') {
				a[i][j] = 1;
				start.first = i;
				start.second = j;
			}
			if (c == '.') {
				a[i][j] = 0;
			}
			if (c == 'F') {
				a[i][j] = 2;
				fstart.push_back({i, j});
			}
		}
	}
	
//	for (int i = 0; i< n; i++) {
//		for (int j = 0;j < m; j++ ){
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	queue<array<int, 3>> q;
	queue<array<int, 3>> fq;
	q.push({start.first, start.second, 0});
	visited[start.first][start.second] = 1;
	for (auto t : fstart) {
		fq.push({t.first, t.second, 0});
		visited[t.first][t.second] = 2;
	}
	int stage = 0;
	while(1) {
		while(!q.empty()) {
			int x = q.front()[0];
			int y = q.front()[1];
			int dist = q.front()[2];
			if (dist != stage) break;
			if (visited[x][y] == 2) {
				q.pop();
				continue;
			}
//			cout << "1pop: " << x << ", " << y << ", " << dist << endl;
			q.pop();
			for (int k = 0; k < 4; k++){ 
				int dx = x + dt[k][0];
				int dy = y + dt[k][1];
				if (dx < 0 || dx >= n || dy < 0 || dy >= m) {
//					if (a[x][y] == 1) {
//						cout << dist + 1 << endl;
//						return 0;
//					}
					cout << dist + 1<< endl;
					return 0;
				}
				if (a[dx][dy] == -1) continue;
				if (a[dx][dy] == 2) continue;
				if (visited[dx][dy] > 0) continue;
				
//				cout << dx << "," << dy << dist << endl;
	//			if (a[dx][dy] == 0 && (dx == 0 || dx == n - 1 || dy == 0 || dy == n - 1)) {
	//				cout << dist + 1 << endl;
	//				return 0;
	//			}
//				if (visited[dx][dy] > 0) continue;
				visited[dx][dy] = 1;
				q.push({dx, dy, dist + 1});
			}
		}
		if (q.empty()) break;
		while(!fq.empty()) {
			int fx = fq.front()[0];
			int fy = fq.front()[1];
			int fst = fq.front()[2];
			if (fst != stage) break;
			fq.pop();
			
			for (int k = 0; k < 4; k++){ 
				int fdx = fx + dt[k][0];
				int fdy = fy + dt[k][1];
				if (fdx < 0 || fdx >= n || fdy < 0 || fdy >= m) continue;
				if (a[fdx][fdy] == -1) continue;
				if (visited[fdx][fdy] == 2) continue;
				visited[fdx][fdy] = 2;
				fq.push({fdx, fdy, fst + 1});
			}
		}
//		cout << q.size() << " : " << fq.size() << endl;
//		for (int i = 0; i< n; i++){ 
//			for (int j = 0;j < m; j++) {
//				cout << a[i][j] << " ";
//			}
//			cout << endl;
//		}
		stage++;
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}