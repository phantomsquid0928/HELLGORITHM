#include <bits/stdc++.h>

using namespace std;


int arr[30][30];
int dirs[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
int main() {
	int t;
	cin >> t;
	
	for (int itt = 1; itt <= t; itt++) {
		int h, w;
		cin >> h >> w;
		
		int x, y;
		
		for (int i = 0 ;i < h; i++) {
			for (int j = 0; j < w; j++) {
				char c;
				cin >> c;
				
				if (c == '.') {
					arr[i][j] = 0;
				}
				if (c == '*') {
					arr[i][j] = 1;
				}
				if (c == '#') {
					arr[i][j] = 2;
					
				}if (c == '-') {
					arr[i][j] = 3;
				}if (c == '<') {
					arr[i][j] = 4;
					x = i;
					y = j;
				}
				if (c == '>') {
					arr[i][j] = 5;
					x = i;
					y = j;
				}if (c == 'v') {
					arr[i][j] = 6;
					x = i;
					y = j;
				}if (c == '^') {
					arr[i][j] = 7;
					x = i;
					y = j;
				}
			}
		}
		
		int n;
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			
			if (c == 'U') {
				arr[x][y] = 7;
				if (x - 1 >= 0 && arr[x - 1][y] == 0) {
					arr[x][y] = 0;
					x--;
					arr[x][y] = 7;
				}
			}
			if (c == 'D') {
				arr[x][y] = 6;
				if (x + 1 < h && arr[x + 1][y] == 0) {
					arr[x][y] = 0;
					x++;
					arr[x][y] = 6;
				}
			}
			if (c == 'L') {
				arr[x][y] = 4;
				if (y - 1 >= 0 && arr[x][y - 1] == 0) {
					arr[x][y] = 0;
					y--;
					arr[x][y] = 4;
				}	
			}
			if (c == 'R') {
				arr[x][y] = 5;
				if (y + 1 < w && arr[x][y + 1] == 0) {
					arr[x][y] = 0;
					y++;
					arr[x][y] = 5;
				}	
			}
			if (c == 'S') {
				int dir = arr[x][y] - 4;
				int nx = x;
				int ny = y;
				while(1) {
					nx += dirs[dir][0];
					ny += dirs[dir][1];
					
					if (nx < 0 || ny < 0 || nx >= h || ny >= w) break;
					if (arr[nx][ny] == 2) {
						break;
					}
					if (arr[nx][ny] == 1) {
						arr[nx][ny] = 0;
						break;
					}
				}
			}
		}
		
		cout << "#" << itt << " ";
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == 0) {
					cout << ".";
				}
				if (arr[i][j] == 1) {
					cout << "*";
				}
				if (arr[i][j] == 2) {
					cout << "#";
				}
				if (arr[i][j] == 3) {
					cout << "-";
				}
				if (arr[i][j] == 4) {
					cout << "<";
				}if (arr[i][j] == 5) {
					cout << ">";
				}
				if (arr[i][j] == 6) {
					cout << "v";
				}
				if (arr[i][j] == 7) {
					cout << "^";
				}
			}
			cout << endl;
		}
	}
}