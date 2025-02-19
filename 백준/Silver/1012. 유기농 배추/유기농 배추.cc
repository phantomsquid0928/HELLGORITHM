#include <bits/stdc++.h>

using namespace std;

int arr[51][51];
int visited[51][51];
queue<array<int, 2>> q;

int dirs[4][2] = {{-1, 0} , {1, 0}, {0, 1}, {0, -1}};
int main() {
	int t;
	cin >> t;
	
	while(t--){
		int m, n, k;
		cin >> m >> n >> k;
		
		memset(arr, 0, sizeof arr);
		memset(visited, 0, sizeof visited);
		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			
			arr[b][a] = 1;
		}
		
		
		int groupcnt = 0;
		for (int i =0 ;i < n; i++) {
			for (int j = 0; j<m; j++) {
				if (!arr[i][j]) continue;
				if (visited[i][j]) continue;
				
				q.push({i, j});
				groupcnt++;
				visited[i][j] = groupcnt;
				
				while(!q.empty()) {
					auto cur = q.front(); q.pop();
					
					int x = cur[0];
					int y = cur[1];
					
					for (auto &d : dirs) {
						int nx = x + d[0];
						int ny = y + d[1];
						
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (visited[nx][ny]) continue;
						if (arr[nx][ny] == 0) continue;
						
						visited[nx][ny] = groupcnt;
						
						
						q.push({nx, ny});
					}
				}
			}

		}
//		
//		for (int i =0 ; i< n; i++) {
//			for (int j =0; j < m; j++) {
//				cout << arr[i][j] <<  " ";
//			}
//			cout << endl;
//		}
		
		cout << groupcnt << endl;
	}
}