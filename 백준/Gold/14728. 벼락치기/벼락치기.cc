#include <bits/stdc++.h>

using namespace std;


int dp[10004];
int main() {
	int n, t;
	cin >> n >> t;
	int value[n];
	int cost[n];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++){
		cin >> cost[i] >>value[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = t; j >= 1; j--) {
			if (cost[i] > j) continue;
			dp[j] = max(dp[j], dp[j - cost[i]] + value[i]);
		}
	}
	cout << dp[t] << endl;
}