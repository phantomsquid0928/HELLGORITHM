#include <bits/stdc++.h>

using namespace std;

int arr[301][301];
int res[301][301];

int dirs[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
void rotate(int n, int m, int rr) {
	int midx = ceil(n / 2); //3
	int midy = ceil(m / 2); //2
	
	int stage = min(midx, midy); // 2
	
//	cout << stage << endl;

	
	for (int i= 0 ; i<n ;i++) {
		for (int j =0 ; j< m; j++) {
		
			int curdir = 0;
			
			int r = -1;
			for (int t = 0; t < stage; t++) {
				if (i == t || i == n - t - 1 || j == t || j == m - t - 1) {
					if (i == t) {
						curdir = 0;
					}
					if (j == t) {
						curdir = 1;
					}
					if (i == n - t - 1) {
						curdir = 2;
					}
					if (j == m - t - 1) {
						curdir = 3;
					}
					r = t;
					break;
				}
			}
			
			int xx = n - 2 * r;
			int yy = m - 2 * r;
			
			int modd = 2 * xx + 2 * yy - 4;
			
//			cout << modd << endl;
			
			int sx = i;
			int sy = j;
			
//			cout << sx << " " << sy << " " << " dir : " << curdir << endl;
			
			for (int t = 0; t < rr % modd; t++) {
				int nx = sx + dirs[curdir][0];
				int ny = sy + dirs[curdir][1];
				if (nx < r || nx >= n - r || ny < r || ny >= m - r) {
					t--;
					curdir = (curdir + 1) % 4;
					continue;
				}
				sx = nx;
				sy = ny;
			}
			
//			cout << i << " " << j << "c to : " << sx << " " << sy << endl;
			res[sx][sy] = arr[i][j];
			
		}
	}
}
int main() {
	int n, m, r;
	
	
	cin >> n >> m >> r;
	
	for (int i =0;i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	
	rotate(n, m, r);
	
	for (int i =0 ; i< n; i++) {
		for (int j= 0 ;j < m; j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}