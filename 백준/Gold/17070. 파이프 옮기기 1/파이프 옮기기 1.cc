#include <bits/stdc++.h>

using namespace std;

int arr[17][17];
array<int, 4> dp[17][17]; // dir 1, 2, 4 / 3 ints indictes where from?

//dp n, m definition : from 0, 0 to n, m : num of ways of going n, m.?
//dp n, m def : from i, j to n, n : from starting i, j : num of ways of going n,m ? i have no idea
int main() {
	int n;
	cin >> n;
	memset(dp, 0, sizeof(dp));
	
	for (int i =0 ;i < n; i++ ){
		for (int j = 0;j < n;j ++) {
			cin >> arr[i][j];
		}
	}
	
	dp[0][1][0] = 1;
	dp[0][1][1] = 1;
	
	for (int i=0; i <n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) continue;
			int dirs = dp[i][j][0];
			
			if ((dirs & 1) != 0) {
				if (j + 1 < n && arr[i][j + 1] == 0 && dp[i][j][1] != 0) { /// ga-> ga
					dp[i][j + 1][0] |= 1;
					dp[i][j + 1][1] += dp[i][j][1];
				}
				if (i + 1 < n && j + 1 < n && arr[i + 1][j + 1] == 0 && arr[i][j + 1] == 0 && arr[i + 1][j] == 0 && dp[i][j][1] != 0) { // ga to slash
					dp[i + 1][j + 1][0] |= 2;
					dp[i + 1][j + 1][2] += dp[i][j][1];
				}
			}
			if ((dirs & 2) != 0) {
				if (j + 1 < n && arr[i][j + 1] == 0 && dp[i][j][2] != 0) { //slash to ga
					dp[i][j + 1][0] |= 1;
					dp[i][j + 1][1] += dp[i][j][2];
				}
				if (i + 1 < n && j + 1 < n && arr[i + 1][j + 1] == 0 && arr[i][j + 1] == 0 && arr[i + 1][j] == 0 && dp[i][j][2] != 0) { //slash to slash
					dp[i + 1][j + 1][0] |= 2;
					dp[i + 1][j + 1][2] += dp[i][j][2];
				}
				if (i + 1 < n && arr[i + 1][j] == 0 && dp[i][j][2] != 0) { //slash to vert
					dp[i + 1][j][0] |= 4;
					dp[i + 1][j][3] += dp[i][j][2];
				}
			}
			if ((dirs & 4) != 0) {
				if (i + 1 < n && arr[i + 1][j] == 0 && dp[i][j][3] != 0) { //vert to vert
					dp[i + 1][j][0] |= 4;
					dp[i + 1][j][3] += dp[i][j][3];
				}
				if (i + 1 >= n || j + 1 >= n) continue;
				if (arr[i + 1][j + 1] == 0 && arr[i][j + 1] == 0 && arr[i + 1][j] == 0 && dp[i][j][3] != 0) { //vert to diag
					dp[i + 1][j + 1][0] |= 2;
					dp[i + 1][j + 1][2] += dp[i][j][3];
				}
			}
		}
	}
	
//	for (int i = 0; i < n; i++) {
//		for (int j = 0;j < n; j++) {
//			cout << dp[i][j][0] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0;j < n; j++) {
//			cout << dp[i][j][1] << " ";
//		}
//		cout << endl;
//	}cout << endl;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0;j < n; j++) {
//			cout << dp[i][j][2] << " ";
//		}
//		cout << endl;
//	}cout << endl;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0;j < n; j++) {
//			cout << dp[i][j][3] << " ";
//		}
//		cout << endl;
//	}cout << endl;
	
	cout << dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2] + dp[n - 1][n - 1][3] << endl;
}