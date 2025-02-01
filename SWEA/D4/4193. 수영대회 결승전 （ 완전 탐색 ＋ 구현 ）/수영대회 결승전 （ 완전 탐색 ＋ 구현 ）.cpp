#include <bits/stdc++.h>

using namespace std;

int arr[100][100];
int visited[100][100];

int dirs[5][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {0, 0}};

int main() {
	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		
		int a, b;
		cin >> a >> b;
		int c, d;
		cin >> c >> d;
		
		
		memset(visited, 0, sizeof(visited));
		queue<array<int, 4>> q;
		
		q.push({a, b, 0, 0});
		
		bool found = false;
		
		while(!q.empty()) {
			auto t = q.front();
			q.pop();
			int tx = t[0];
			int ty = t[1];
			int time = t[2];
			int stayed = t[3];
			
			if (tx == c && ty == d) {
				cout << "#" << tt + 1 << " " << time << endl;
				found = true;
				break;
			}
			if (stayed > 4) {
				continue;
			}
			
			visited[tx][ty] = 1;
			
			for (int d = 0; d < 5; d++) {
				
				int dx = tx + dirs[d][0];
				int dy = ty + dirs[d][1];
				if (dx < 0 || dy < 0 || dx >= n || dy >= n) continue;
				if (visited[dx][dy] && d != 4) continue;
				if (arr[dx][dy] != 0) {
					if (arr[dx][dy] == 1) continue;
					if (time % 3 != 2) { //cannot pass
						if (arr[tx][ty] == 0) continue;
						if (d != 4) continue;
					}
				}
				if (d == 4) 
					q.push({dx, dy, time + 1, stayed + 1});
				else q.push({dx, dy, time + 1, 0});
			}
		}
		if (!found) {
			cout << "#" << tt + 1 << " " << -1 << endl;
		}
	}
	
	
}