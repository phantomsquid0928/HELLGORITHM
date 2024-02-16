#include <bits/stdc++.h>

using namespace std;

int arr[101][101][101];
int visited[101][101][101];

int dt[6][3] = {{1, 0, 0}, {0, 1, 0}, {-1, 0, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
queue<array<int, 4>> q;
set<array<int, 3>> to;

int main() {
	int m, n, h;
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n >> h;

	for (int k = 0; k< h; k++) {
		for(int i = 0; i < n; i++) {
			for (int j = 0; j< m; j++) {
				cin >> arr[k][i][j];
				if (arr[k][i][j] == 1) {
					q.push({k, i, j, 0});
					visited[k][i][j] = 1;
				}
				if (arr[k][i][j] == 0) {
					to.insert({k, i, j});
				}
			}
		}
	}
	
	int reslv = -1;
	while(!q.empty()) {
		
		int k = q.front()[0];
		int i = q.front()[1];
		int j = q.front()[2];
		int lv = q.front()[3];
		q.pop();
//		if (visited[k][i][j] == 1) continue;
//		visited[k][i][j] = 1;
		reslv = max(lv, reslv);
//		cout << k << i << j << endl;
		
		for (int x = 0; x< 6; x++) {
			int dx = i + dt[x][0];
			int dy = j + dt[x][1];
			int dz = k + dt[x][2];
			if (dx < 0 || dx >= n || dy < 0 || dy >= m || dz < 0 || dz >= h) continue;
			if (visited[dz][dx][dy] == 1) continue;
			if (arr[dz][dx][dy] == -1 || arr[dz][dx][dy] == 1) continue;
			q.push({dz, dx, dy, lv + 1});
//			cout << dz << dx << dy << endl;
			to.erase({dz, dx, dy});
			visited[dz][dx][dy] = 1;
		}
		
	}
	if (to.empty()) {
		cout << reslv << endl;
	}
	else {
		cout << -1 << endl;
	}

}