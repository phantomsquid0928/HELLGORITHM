#include <bits/stdc++.h>

using namespace std;

int arr[100000];
int dp[2][100000];
int n;

int main() {
	cin >> n;
	for (int i = 0; i< n;i ++) {
		cin >> arr[i];
	}
	dp[0][0] = arr[0];
	dp[0][1] = arr[1];
	dp[1][1] = arr[0] + arr[1];
	for (int i = 2; i < n; i++) {
		int maxv = 0;
		int maxidx = 0;
		dp[1][i] = dp[0][i - 1] + arr[i];
		dp[0][i] = max(dp[0][i - 2] + arr[i], dp[1][i - 2] + arr[i]);
	}
	int res = 0;
	for (int k = 0; k < 3; k++) {
		res = max(res, dp[k][n - 1]);
	}
	cout << res << endl;
}