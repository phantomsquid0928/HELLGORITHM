#include <bits/stdc++.h>

using namespace std;

int map2[53][53] = {};
int dp[53][53][53][53]; // n, m, c, last
int dp2[53] = {}; // c
int n, m, c;
int mod = 1000007;

int solve(int i, int j, int c, int last) {
	if (i > n || j > m) return 0;
	if (i == n && j == m) {
		if (c == 0 && map2[i][j] == 0) {
			return 1;
		}
		if (c == 1 && map2[i][j] > last) {
			return 1;
		}
		return 0;
	}
	if (dp[i][j][c][last] != -1) return dp[i][j][c][last];
	dp[i][j][c][last] = 0;
	if (map2[i][j] == 0) {
		dp[i][j][c][last] = (solve(i + 1, j, c, last) + solve(i, j + 1, c, last)) % mod;
	}
	if (map2[i][j] > last) {
		dp[i][j][c][last] = (solve(i + 1, j, c - 1, map2[i][j]) + solve(i, j + 1, c - 1, map2[i][j]))%mod;
	}
	return dp[i][j][c][last];
}
int main() {
	cin >> n >> m >> c;
	for (int i = 0; i < c; i++) {
		int a, b;
		cin >> a >> b;
		map2[a][b] = i + 1;
	}
	memset(dp, -1, sizeof(dp));
		 
	for (int k = 0; k <= c; k++) {
		cout << solve(1, 1, k, 0) << " ";
	}
//	for (int i = 0; i <= c; i++) {
//		for (int j = 0; j <= n; j++) {
//			for (int k = 0; k <= m; k++) {
//				cout << dp[j][k][i] << " ";
//			}
//			cout << endl;
//		}
//		cout << endl << endl;
//	}
}