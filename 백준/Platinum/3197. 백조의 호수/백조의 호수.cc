#include <bits/stdc++.h>

using namespace std;

int arr[1501][1501];
int visited[1501][1501] = {};
int visited2[1501][1501] = {};

int unionfind[3000000];

inline int find(int a) {
	if (a == unionfind[a]) {
		return a;
	}
	return unionfind[a] = find(unionfind[a]);
}
inline void _union(int a, int b) {
	a = find(a);
	b = find(b);
	
	unionfind[a] = b;
}


queue<array<int,2>> targets;
queue<array<int, 3>> ntargets;

vector<pair<int, int>> grounds;

vector<array<int, 2>> starts;

queue<pair<int, int>> q;

int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int main() {
	int n, m;
	
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	
	
	
	for (int i = 0;i < n; i++) {
		string s;
		cin >> s;
		for (int j =0 ; j < m; j++) {
			if (s[j] == '.') {
				grounds.push_back({i, j});
				arr[i][j] = 0;
			}
			if (s[j] == 'X') {
				arr[i][j] = 1;
			}
			if (s[j] == 'L') {
				grounds.push_back({i, j});
				starts.push_back({i, j});
				arr[i][j] = 0;
			}
		}
	}
	
	int groupcnt = 0;
	for (auto &g : grounds) {
		int x = g.first;
		int y = g.second;
		
		if (visited[x][y]) continue;
		groupcnt++;
		unionfind[groupcnt] = groupcnt;
		
		q.push({x, y});
		
		
		while(!q.empty()) {
			auto cur = q.front(); q.pop();
			
			int cx = cur.first;
			int cy = cur.second;
			
			if (visited[cx][cy]) continue;
			
			visited[cx][cy] = groupcnt;
			
			bool edge = false;
			
			for (auto &d : dirs) {
				int nx=  cx + d[0];
				int ny = cy + d[1];
				
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (visited[nx][ny]) continue;
				if (arr[nx][ny]) {
					edge = true;
					continue;
				}
				
				q.emplace(nx, ny);
			}
			
			if (edge) {
				targets.push({cx, cy});
			}
		}
	}
	
	int stage = 0;
	//visited = non ices with group
	
	int groupa = visited[starts[0][0]][starts[0][1]];
	int groupb = visited[starts[1][0]][starts[1][1]];
	
//	cout << groupa << groupb << endl;
//	
//	for (int i = 0;i < n; i++) {
//		for (int j = 0;j < m; j++){
//			cout << visited[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	int cnt = 0;
	
	while(1) {
		if (find(groupa) == find(groupb)) break;
		
		memset(visited2, 0, sizeof(visited2));
		
//		cout << endl;
		while(!targets.empty()) {
			auto t = targets.front(); targets.pop();
			int x = t[0];
			int y = t[1];
			int color = visited[x][y];
			if (visited2[x][y]) continue;
			
			for (auto &d : dirs) {
				int nx = x + d[0];
				int ny = y + d[1];
				
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (visited[nx][ny] != 0) continue;
				if (visited2[nx][ny]) continue;
				visited2[nx][ny] = 1;
				
				ntargets.push({nx, ny, color});
			}
		}
		
		while(!ntargets.empty()) { //ice neighbor of water
			auto t = ntargets.front(); ntargets.pop();
			int x = t[0];
			int y = t[1];
			int color = t[2];
//			cout << "ice : " << x << " " << y << " fate : " << color << endl;
			
			
			if (visited[x][y] != 0 && visited[x][y] != color) {
				_union(visited[x][y], color);
				continue;
			}
			
			visited[x][y] = color;
			for (auto &d : dirs) {
				int nx = x + d[0];
				int ny = y + d[1];
				
				if (nx < 0 || ny < 0 || nx >= n || ny >= m ) continue;
				if (visited[nx][ny] == 0) continue;
				if (visited[nx][ny] == color) continue;
				
				_union(visited[nx][ny], color);
			}
			targets.push({x, y}); //becomes water neighbors ice.
		}
		
		stage++;
	}
//	while(ices.size() > 0) {
//		if (find(groupa) == find(groupb)) break;
////		cout << endl;
//		
//		
//		while(!ices.empty()) {
//			auto i = ices.front(); ices.pop();
//			int cx = i.first;
//			int cy = i.second;
////			if (dead) {
////				cout << "dead" << endl;
////				continue;
////			}
//
//			int groupnum = 0;
//			for (auto &d : dirs) {
//				int nx = cx + d[0];
//				int ny = cy + d[1];
//				
//				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
//				if (visited[nx][ny] == 0) continue;
////				if (groupnum != 0 && groupnum != visited[nx][ny]) {
////					_union(groupnum, visited[nx][ny]);
////				}
//				groupnum = visited[nx][ny];
//				
//			}
//			if (groupnum != 0) {
//				melt.push({cx, cy, groupnum});
//				
//			}
//			else {
//				ices2.emplace(cx, cy);
//			}
//		}
//		
//		ices.swap(ices2);
//		
////		cout << "melt target" << melt.size() << endl;
//		
//		while(!melt.empty()) {
//			auto cur = melt.front(); melt.pop();
//			int cx = cur[0];
//			int cy = cur[1];
//			int affector = cur[2];
//			
////			assert(affector != 0);
////			cout << "melting: " << cx << cy << affector << endl;
////			
//			
////			cout << "cur color " << visited[cx][cy] << " " << affector << endl;
//			if (visited[cx][cy] && affector != visited[cx][cy]) {
////				cout << "melting target : " << cx << cy << affector << endl;
//				_union(visited[cx][cy], affector);
////				cout << "unioning" << visited[cx][cy] << " " << affector << endl;
//				continue;
//			}
//			
//			visited[cx][cy] = affector;
//			
//			for (auto &d : dirs) {
//				int nx = cx + d[0];
//				int ny = cy + d[1];
//				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
////				cout << "	4 dir color of " << cx << " " <<  cy << " : "  << visited[nx][ny] << endl; 
//				if (visited[nx][ny] == affector) continue;
//				if (visited[nx][ny] == 0) continue;
//				if (visited[nx][ny] && visited[nx][ny] != affector) {
//					_union(visited[nx][ny], affector);
////					cout << "unioning" << visited[nx][ny] << " " << affector << endl;
//				}
//			}
//		}
//		
////		cout << endl;
////		for (int i= 0; i < n; i++) {
////			for (int j = 0; j < m; j++) {
////				cout << visited[i][j] << " ";
////			}
////			cout << endl;
////		}
////		cout << "visited 2" << endl;
////		cout << endl;
////		for (int i = 0; i< n; i++) {
////			for (int j = 0;j < m; j++) {
////				cout << visited2[i][j] << " ";
////			}
////			cout << endl;
////		}
//		stage++;
//	}
	
	cout << stage << endl;
}