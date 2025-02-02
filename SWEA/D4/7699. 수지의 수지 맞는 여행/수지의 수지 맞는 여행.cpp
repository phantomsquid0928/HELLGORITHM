#include <bits/stdc++.h>

using namespace std;


int arr[100][100];

int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int maxres = 0;
int r = 0, c = 0;

void solve(int x, int y, int val, int dist) {
	maxres = max(dist, maxres);
//	cout << x << y << endl;
	for (auto &d : dirs) {
		int nx = x + d[0];
		int ny = y + d[1];
		
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
		if ((val & (1 << arr[nx][ny])) != 0) continue;
		
		int temp = val | (1 << arr[nx][ny]);
		solve(nx, ny, temp, dist + 1);
	}
}
int main() {
	int t;
	cin >> t;
	
	
	for (int tt = 1; tt <= t; tt++) {
		cin >> r >> c;
		
		memset(arr, 0, sizeof(arr));
		for (int i= 0;i < r; i++) {
			string s;
			cin >> s;
			for (int j = 0;j < c; j++) {
				arr[i][j] = s[j] - 'A' + 1;
			}
		}
		
		maxres = 0;
		solve(0, 0, (1 << arr[0][0]), 1);
		
//		for (int i =0 ;i < r; i++) {
//			for (int j = 0; j < c; j++) {
//				cout << arr[i][j] << " ";
//			}
//			cout << endl;
//		}
//		
		
//		cout << (1 << arr[0][0]) << endl;
//		q.push({0, 0, (1 << arr[0][0]), 1});
//		
//		int maxval = 1;
//		while(!q.empty()){ 
//			auto cur = q.front(); q.pop();
//			int x = cur[0];
//			int y = cur[1];
//			int val = cur[2];
//			int dist = cur[3];
//			
//			
//			maxval = max(dist, maxval);
//			
//			for (auto &d :dirs ){
//				int nx = x + d[0];
//				int ny = y + d[1];
//				
//				if (nx <  0 || ny < 0 || nx >= r || ny >=c) continue;
//				if ((val & (1 << arr[nx][ny])) != 0) continue;
//
//				int temp = val | (1 << arr[nx][ny]);
//				q.push({nx, ny, temp, dist + 1 });
//			}
//			
//		}
//		
		cout << "#" << tt << " " << maxres << endl;
	}
}