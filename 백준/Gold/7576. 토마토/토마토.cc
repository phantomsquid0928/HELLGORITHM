#include <bits/stdc++.h>

using namespace std;

int arr[1001][1001];
int visited[1001][1001];

int dt[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<array<int, 3>> q;

int n, m;
int main() {
	cin >>m>>n;
	for (int i = 0; i < n; i++) {
		for (int j = 0;j <m; j++) {
			cin >> arr[i][j];
			visited[i][j] = arr[i][j];
			if (arr[i][j] == 1) {
				q.push({i, j, 0});
                visited[i][j] = 1;
			}
		}
	}
	int reslv = 0;
	while(!q.empty()) {
		int x = q.front()[0];
		int y = q.front()[1];
		int lv = q.front()[2];
		reslv = max(lv, reslv);
		q.pop();
//		cout << x << ":" << y << endl;
		visited[x][y] = 1;
	
		for (int i = 0; i < 4; i++) {
			int dx = x + dt[i][0];
			int dy = y + dt[i][1];
			if (dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
			if (visited[dx][dy] != 0) continue;
			q.push({dx, dy, lv+1});
            visited[dx][dy] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 0) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << reslv << endl;
	
	
	
}