#include <bits/stdc++.h>

using namespace std;

int a[503][503] = {};
int dp[504][504];
int m, n;

long long solve(int i, int j) {
	if (i == m && j == n) return 1;
	if (i > m || j > n || i == 0 || j == 0) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = 0;
	if (a[i + 1][j] < a[i][j]) dp[i][j] += solve(i + 1, j);
	if (a[i - 1][j] < a[i][j]) dp[i][j] += solve(i - 1, j);
	if (a[i][j + 1] < a[i][j]) dp[i][j] += solve(i, j + 1);
	if (a[i][j - 1] < a[i][j]) dp[i][j] += solve(i, j - 1);
	return dp[i][j];
}
int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++){ 
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(1, 1);
}