#include <bits/stdc++.h>

using namespace std;

int main() {
	int arr[102][102] = {};
	int visited[102][102] = {};
	
	int n;
	cin >> n;
	
	for (int t = 0;t < n; t++) {
		int a, b;
		cin >> a >> b;
		
		for (int i = a; i < a + 10; i++) {
			for (int j = b; j < b + 10; j++) {
				arr[i + 1][j + 1] = 1;
			}
		}
	}
	
	queue<array<int,2>> q;
	int cnt = 0;
	
	int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
	for (int i = 1; i <= 100;i++){ 
		for (int j = 1; j <= 100; j++) {
			if (arr[i][j] != 1) continue;
			if (visited[i][j]) continue;
		
			
			q.push({i, j});
			
			while(!q.empty()) {
				auto cur= q.front(); q.pop();
				int x = cur[0];
				int y = cur[1];
			
				if (visited[x][y] && arr[x][y]) continue;
				visited[x][y] = 1;
				if (arr[x][y] == 0) {
					cnt++;
					continue;
				}
				for (auto &d : dirs) {
					int nx = x + d[0];
					int ny = y + d[1];
					
					if (nx < 0 || ny < 0 || nx > 101 || ny > 101) continue;
					if (visited[nx][ny] && arr[nx][ny]) continue;
					
					q.push({nx, ny});
				}
			}
		}
	}
	cout <<  cnt << endl;
}