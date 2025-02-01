#include <bits/stdc++.h>

using namespace std;


int visited[1001][1001];
int arr[1001][1001];

queue<array<int, 4>> q;

int main() {
	int n, m;
	
	cin >> n >> m;
	
	for (int i =0 ;i < n ;i++) {
		string s;
		cin >> s;
		
		for (int j = 0; j < m;j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	
	q.push({-1, 0, 0, 1});
	
	int res = 0x3f3f3f3f;
	int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
	
	while(!q.empty()) {
		auto cur = q.front(); q.pop();
		int x = cur[1];
		int y = cur[2];
		
//		cout << x << y << endl;
		int dist = -cur[0];
		int broke = cur[3];
//		cout << broke << endl;
		if ((visited[x][y] & broke) != 0) continue;
		visited[x][y] |= broke;

		if (x == n - 1 && y == m - 1) {
			res = min(res, dist);
			continue;
		}
		
		for (auto &d : dirs) {
			int nx = x + d[0];
			int ny=  y + d[1];
			
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (arr[nx][ny] == 1 && broke >= 2) continue;
			if (visited[nx][ny] & broke != 0) continue;
			if (arr[nx][ny] == 1) {
				q.push({-(dist + 1), nx, ny, broke + 1});
				continue;
			}
//			if (visited[nx][ny] > dist + 1) {
//			visited[nx][ny] =  + 1;
			q.push({-(dist + 1), nx, ny, broke});
//			}
		}
	}
	
	if (res != 0x3f3f3f3f) cout << res;
	else cout << -1;
}