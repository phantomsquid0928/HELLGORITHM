#include <bits/stdc++.h>

using namespace std;

int arr[20][20];

int dirs[4][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}};
int main() {
	for (int i=0 ;i < 19; i++) {
		for (int j = 0; j<19; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i=0 ;i < 19; i++) {
		for (int j = 0; j<19; j++) {
			if (arr[i][j] == 0) continue;
			int color = arr[i][j];
			
			for (auto &d : dirs) {
				int x = i;
				int y = j;
				int len = 1;
				while(1) {
					x += d[0];
					y += d[1];
					if (x < 0 || y < 0 || x >= 19 || y >= 19) break;
					if (arr[x][y] != color) break;
					len++;
				}
				if (len == 5) {
					int revx = i - d[0];
					int revy = j - d[1];
					bool valid = false;
					if (revx < 0 || revy < 0 || revx >= 19 || revy >= 19) {
						valid =true;
					}
					if (arr[revx][revy] != color) {
						valid = true;
					}
					if (valid) {
						cout << color << endl;
						cout << i + 1 << " " << j + 1 << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << 0 << endl;
}