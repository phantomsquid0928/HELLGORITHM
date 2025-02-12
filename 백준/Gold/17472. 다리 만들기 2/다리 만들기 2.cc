#include <bits/stdc++.h>

using namespace std;

int arr[11][11];
int visited[11][11];
int visited2[11][11];
int unionfind[100];

int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int find(int a) {
	if (a == unionfind[a]) return a;
	return unionfind[a] = find(unionfind[a]);
}
void _union(int a, int b) {
	a = find(a);
	b = find(b);
	
	unionfind[b] = a;
}



vector<array<int, 2>> edges;

queue<array<int, 2>> q;


int main() {
	int n, m;
	
	cin >> n >> m;
	
	for (int i= 0; i< n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	
	int groupcnt = 0;
	for (int i = 0; i < n; i++){ 
		for (int j = 0;j < m; j++) {
			if (arr[i][j] == 0) continue;
			if (visited[i][j]) continue;
			
			groupcnt++;
			q.push({i, j});
			
			while(!q.empty()) {
				auto cur = q.front(); q.pop();
				int x = cur[0];
				int y = cur[1];
				
				if (visited[x][y]) continue;
				visited[x][y] = groupcnt;
				
				for (auto &d : dirs) {
					int nx = x + d[0];
					int ny = y + d[1];
					
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (visited[nx][ny]) continue;
					
					if (arr[nx][ny] == 0) {
						
						if (visited2[x][y] == 0) edges.push_back({x, y});
						visited2[x][y] = 1;
						continue;
					}
					
					q.push({nx, ny});
				}
			}
		}
	}
//	
//	for (int i=0 ;i < n; i++) {
//		for (int j = 0;j < m; j++) {
//			cout << visited[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	vector<array<int, 3>> bridges;
	for (auto &e : edges) {
//		cout <<e[0] <<e[1] << endl;
		
		for (auto &d : dirs) {
			int x = e[0];
			int y = e[1];
			int len = 0;
			int color = visited[x][y];
			while(1) {
				x += d[0];
				y += d[1];
				
				if (x < 0 || y < 0 || x >= n || y >= m) break;
				if (visited[x][y] == color) break;
				if (visited[x][y] != 0 && visited[x][y] != color && len == 1) break;
				if (visited[x][y] != 0 && visited[x][y] != color && len != 1) {
					bridges.push_back({len, visited[x][y], color});
					break;
				}
				len++;
			}
		}
	}
	
	for (int i = 1; i<= groupcnt; i++) {
		unionfind[i] = i;
	}
	
	sort(bridges.begin(), bridges.end());
	int res = 0;
	for (auto &b : bridges) {
//		cout << b[0] << endl;
		if (find(b[1]) == find(b[2])) continue;
		_union(b[1], b[2]);
		res += b[0];
	}
	
//	bool valid = true;
	for (int i = 1; i < groupcnt; i++) {
		if (find(i) != find(i + 1)) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << res << endl;
}