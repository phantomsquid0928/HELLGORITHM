#include<bits/stdc++.h>

using namespace std;

int n, m;
int arr[101][101];
int visited[101][101];

vector<pair<int, int>> airs[10001];
queue<pair<int, int>> q;
int outer = -1;

int dt[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int cnt = 0;
	int lastchez = 0;
	while(1) {
		int airscnt = 0;
		int endchk = 1;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && arr[i][j] == 0) {
					airscnt++;
					q.push({i, j});
					int chk = 0;
					while(!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						for (int k = 0; k < 4; k++) {
							int dx = x + dt[k][0];
							int dy = y + dt[k][1];
							if (dx < 0 || dx == n || dy < 0 || dy == m) {
								chk = 1;
								continue;
							}
							if (visited[dx][dy] != 0) continue;
							if (arr[dx][dy] == 1) {
								endchk = 0;
								continue;
							}
							visited[dx][dy] = airscnt;
							airs[airscnt].push_back({dx, dy});
							q.push({dx, dy});
						}
					}
					if (chk == 1) {
						outer = airscnt;
					}
				}
			}
		}
		if (endchk == 1) break;
		lastchez = 0;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				cout << visited[i][j] << " ";
//			}
//			cout << endl;
//		}
		for (auto t : airs[outer]) {
			int x = t.first;
			int y = t.second;
			for (int i =0; i < 4; i++) {
				int dx = x + dt[i][0];
				int dy = y + dt[i][1];
				if (dx < 0 || dx == n || dy < 0 || dy == m) continue;
				if (arr[dx][dy] == 1) {
					lastchez++;
					arr[dx][dy] = 0;
				}
			}
		}
		cnt++;
	}
	
	cout << cnt << "\n";
	cout << lastchez << "\n";
}