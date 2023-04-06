#include <bits/stdc++.h>

using namespace std;

int dp[2][10001] = {};
int main() {
	int t, k;
	cin >> t >> k;
	int value[t], cnt[t];
	
	for (int i = 0; i < k; i++) {
		cin >> value[i] >> cnt[i];
	}
	dp[0][0] = 1;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j <= t; j++) {
			dp[(i + 1) % 2][j] = 0;
			for (int u = 0; u <= cnt[i]; u++) {
				if (j >= u * value[i]) {
					dp[(i + 1) % 2][j] += dp[i % 2][j - u * value[i]];
				}
			}
		}
	}
	cout << dp[k % 2][t];
}