#include <bits/stdc++.h>

using namespace std;

int a[305], s[305] = {};
int dp[305][305];

void reverse(int j, int i) { // 8 3
	if (j == 0 && i == 0) {
		return;
	}
	for (int k = j; k >= 1; k--) {
		if (max(dp[j - k][i - 1], s[j] - s[j - k]) == dp[j][i]) {
			reverse(j - k, i - 1);
			cout << k << " ";
			return;
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] += s[i - 1] + a[i];
		dp[i][1] = s[i];
	}
	dp[0][0] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= j; k++) {
				dp[j][i] = min(dp[j][i], max(dp[j - k][i - 1], s[j] - s[j - k]));
				//  4rofmf 2ro     4 2       31   11  , 21 21,  11 13 
			}
		}
	}
//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j <= m; j++) {
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
	cout << dp[n][m] << endl;
	reverse(n, m); // 8 3
	
}
