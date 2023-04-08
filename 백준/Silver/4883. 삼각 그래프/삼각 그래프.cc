#include <bits/stdc++.h>

using namespace std;

int arr[100003][4] = {};
long long dp[100003][4] = {};
int n;


long long solve(int i, int j) {
	if (i >= n || j <= 0 || j >= 4) return 100000000000L;
	if (i == n - 1 && j == 2) return arr[n - 1][2];
	if (dp[i][j] != -1) return dp[i][j];
	long long res = solve(i + 1, j - 1);
	res = min(res, solve(i + 1, j));
	res = min(res, solve(i + 1, j + 1));
	res = min(res, solve(i, j + 1));
	dp[i][j] = res + arr[i][j];
	return dp[i][j];
}
int main() {
	int cnt = 0;
	ios::sync_with_stdio(false);
    cin.tie(0);
	while (1) {
		cin >> n;
		if (n == 0) break;
		memset(dp, -1, sizeof(dp));
		for (int i= 0; i < n; i++) {
			cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
		}
		cout << cnt + 1 << ". " << solve(0, 2) << "\n";
		cnt++;
	}

}