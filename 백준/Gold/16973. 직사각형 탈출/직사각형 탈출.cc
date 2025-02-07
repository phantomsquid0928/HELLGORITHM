#include <bits/stdc++.h>

using namespace std;

int s[1001][1001] = {};
int visited[1001][1001];


priority_queue<array<int, 3>> pq;

int main(){
	int n, m;
	
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n >> m;
	
	
	
	for (int i=1 ;i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int in;
			cin >> in;
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + in;
			visited[i][j] = 0x3f3f3f3f;
		}
	}
//	cout << endl;
//	for (int i = 1; i <= n ;i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << s[i][j] << " ";
//		}
//		cout << endl;
//	}
	

	
	int h, w, sr, sc, fr, fc;
	
	cin >> h >> w >> sr >> sc >> fr >> fc;
	auto collides = [&](int x, int y) {
		if (x + h - 1 > n || y + w - 1> m) return 1;
		int res = s[x + h - 1][y + w - 1] - s[x + h - 1][y - 1] - s[x - 1][y + w - 1] + s[x - 1][y - 1];
		if (res == 0) return 0;
		return 1;
	};
	
//	for (int i= 1; i<= n ;i++) {
//		for (int j = 1; j<= m; j++) {
//			cout << collides(i, j) << " ";
//		}
//		cout << endl;
//	}
	
	int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

	pq.push({0, sr, sc}); 
	visited[sr][sc] = 0;
	
	while(!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		
		
		int cx = cur[1];
		int cy = cur[2];
		int cost = -cur[0];
//		cout << cx << " " << cy << endl;
		
		if (visited[cx][cy] < cost) continue;
	
		for (auto &d : dirs) {
			int nx = cx + d[0];
			int ny = cy + d[1];
			
			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
			if (collides(nx, ny)) continue;
//			if (collides(nx, ny)) continue;
			
			if (visited[nx][ny] > visited[cx][cy] + 1) {
				visited[nx][ny] = visited[cx][cy] + 1;
				pq.push({-cost - 1, nx, ny});
			}
		}
	}
	
	
	if (visited[fr][fc] == 0x3f3f3f3f) cout << -1 << endl;
	else cout << visited[fr][fc] << endl;
	
}