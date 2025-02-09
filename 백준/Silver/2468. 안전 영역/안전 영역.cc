#include <bits/stdc++.h>

using namespace std;

int visited[101][101];
int arr[101][101];

int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
	int n;
	cin >> n;
	
	int minval = 10000;
	int maxval = 0;
	
	for (int i = 0 ;i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			minval = min(arr[i][j], minval);
			maxval = max(arr[i][j], maxval);
		}
	}
	
	queue<pair<int, int>> q;
	
	int maxres = 0;
	for (int h = minval - 1; h <= maxval; h++) {
		int groupcnt = 0;
		for (int i= 0 ;i < n; i++) {
			for (int j =0; j < n; j++) {
				if (visited[i][j]) continue;
				if (arr[i][j] <= h) continue;
				
				q.emplace(i, j);
				
				groupcnt++;
				
				while(!q.empty()) {
					auto cur = q.front(); q.pop();
					
					int x = cur.first;
					int y = cur.second;
					if (visited[x][y]) continue;
					visited[x][y] = groupcnt;
					
					for (auto &d : dirs) {
						int nx = x + d[0];
						int ny = y + d[1];
						
						if (nx < 0 || ny < 0 || nx >=n||ny>=n)continue;
						if (visited[nx][ny]) continue;
						if (arr[nx][ny] <= h) continue;
						
						q.emplace(nx, ny);
					}
				}
			}
		}
		
//		cout << groupcnt << endl;
		maxres = max(groupcnt, maxres);
		memset(visited, 0, sizeof(visited));
	}
	
	cout << maxres << endl;
}