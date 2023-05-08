#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[1005][1005];
int res[1005][1005];
int group[1005][1005];
int t[4][2] = {{1, 0},{-1, 0},{0, 1},{0, -1}};

int groupcnt[1000005];

int solve(int tx, int ty, int gnum) {
	queue<pair<int, int>> q;
	q.push({tx, ty});
	
	long long cnt = 0;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop(); 
		group[x][y] = gnum;
		
		cnt++;
		for (int k = 0; k < 4; k++) {
			int dx = x + t[k][0];
			int dy = y + t[k][1];
			
			if (dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
			if (group[dx][dy] != 0) continue;
			if (arr[dx][dy] != 0) continue;
			
			q.push({dx, dy});
			group[dx][dy] = gnum;
			//cout << dx << ":" << dy << endl;
			//visited[dx][dy] = 1;
		}
	}
	return cnt % 10;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i =0 ;i < n; i++) {
		for (int j = 0; j< m; j++) {
			char temp;
			cin >> temp;
			arr[i][j] = temp - 48;
		}
	}
//	for (int i =0 ;i < n; i++) {
//		for (int j =0 ;j < m; j++) {
//			cout << arr[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	cout << solve(0, 2, 1) << endl;
	int gnum = 1;
		
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = i;
			int y = j;
			if (arr[x][y] == 0&& group[x][y] == 0) {
				queue<pair<int, int>> q;
				q.push({x, y});
				
				//visited[x][y] = 1;
				long long cnt = 0;
				while(!q.empty()) {
					int tx = q.front().first;
					int ty = q.front().second;
					q.pop(); 
					group[tx][ty] = gnum;
					
					cnt++;
					for (int k = 0; k < 4; k++) {
						int dx = tx + t[k][0];
						int dy = ty + t[k][1];
						
						if (dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
						if (group[dx][dy] != 0) continue;
						if (arr[dx][dy] != 0) continue;
						
						q.push({dx, dy});
						group[dx][dy] = gnum;
//								visited[dx][dy] = 1;
						//cout << dx << ":" << dy << endl;
						//visited[dx][dy] = 1;
					}
				}
				groupcnt[gnum] = cnt % 10;
				gnum++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 0) {
				int sum = 0;
				set<int> samenode;
				int x = i;
				int y = j;
				for (int k = 0; k < 4; k++) {
					
					int dx = x + t[k][0];
					int dy = y + t[k][1];
					
					if (dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
		
					if (group[dx][dy] != 0 && samenode.find(group[dx][dy]) == samenode.end()) {
						sum += groupcnt[group[dx][dy]];
						samenode.insert(group[dx][dy]);
					}
				}
				res[i][j] = sum + 1;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << res[i][j] % 10;
		}
		cout << "\n";
	}
}