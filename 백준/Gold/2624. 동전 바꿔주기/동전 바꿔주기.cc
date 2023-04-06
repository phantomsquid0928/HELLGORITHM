#include <bits/stdc++.h>

using namespace std;

int dp[10001] = {};
int main() {
	int t, k;
	cin >> t >> k;
	int value[t], cnt[t];
	
	for (int i = 0; i < k; i++) {
		cin >> value[i] >> cnt[i];
	}
	dp[0] = 1;
	for (int i = 0; i < k; i++) {
		for (int j = t; j >= 0; j--) {
			//dp[j] = 0;
			for (int u = 1; u <= cnt[i]; u++) {
				if (j >= u * value[i]) {
					dp[j] += dp[j - u * value[i]];
				}
			}
		}
	}
	cout << dp[t];
}