#include <bits/stdc++.h>

using namespace std;


int visited[1001][1001][2];
int arr[1001][1001];

priority_queue<array<int, 4>> pq;

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
	
	memset(visited, 0x3f, sizeof visited);
	
	visited[0][0][0] = 1;
	
	pq.push({-1, 0, 0, 0});
	
	int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
	while(!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		int x = cur[1];
		int y = cur[2];
		int dist = -cur[0];
		int broke = cur[3];
		
		for (auto &d : dirs) {
			int nx = x + d[0];
			int ny=  y + d[1];
			
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (arr[nx][ny] == 1 && broke == 1) continue;
			if (arr[nx][ny] == 1) {
				visited[nx][ny][1] = dist + 1;
				pq.push({-(dist + 1), nx, ny, broke + 1});
				continue;
			}
			if (visited[nx][ny][broke] > dist + 1) {
				visited[nx][ny][broke] = dist + 1;
				pq.push({-(dist + 1), nx, ny, broke});
			}
		}
	}
	int res = min(visited[n - 1][m - 1][0], visited[n - 1][m - 1][1]);
	if (res != 0x3f3f3f3f) cout << res;
	else cout << -1;
}