#include <bits/stdc++.h>

using namespace std;

int arr[101][101];
int visited[101][101];

int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

queue<array<int, 2>> q;

int main() {
	int t;
	cin >> t;
	
	for (int itt=  1; itt<= t; itt++) {
		int n;
		cin >> n;
		
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));
		
		for (int i  =0;i <n; i++) {
			for (int j = 0;j < n;j ++) {
				cin >> arr[i][j];
			}
		}
		
		int maxcnt = 0;
		
		for (int i = 1; i <= 100; i++) {
			bool busted = true;
			for (int j = 0; j < n; j++){ 
				for (int k = 0; k < n; k++) {
					if (arr[j][k] >= 1) busted = false; 
					arr[j][k]--;
				}
			}
			
			if (busted) break;
			memset(visited, 0, sizeof(visited));
			
			int groupcnt = 0;
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (visited[j][k]) continue;
					if (arr[j][k] < 0) continue;
					
					groupcnt++;
					
					q.push({j, k});
					
					while(!q.empty()) {
						auto cur = q.front(); q.pop();
						
						int x = cur[0];
						int y = cur[1];
						if (visited[x][y]) continue;
						visited[x][y] = groupcnt;
						
						for (auto &d : dirs) {
							int nx = x + d[0];
							int ny = y + d[1];
							
							if (nx < 0 || ny < 0 || nx >= n||ny >= n) continue;
							if (visited[nx][ny]) continue;
							if (arr[nx][ny] < 0) continue;
							
							q.push({nx, ny});
						}
					}
				}
			}
			
			maxcnt = max(maxcnt, groupcnt);
		}
		
		cout << "#" << itt << " " << maxcnt << endl;
	}
}