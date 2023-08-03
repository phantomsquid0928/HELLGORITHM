#include <bits/stdc++.h>

using namespace std;

int n, k;
int weight[1000];
int value[1000];
int dp[100001];
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> weight[i] >> value[i];
	}
	
	for (int i = 0; i< n; i++) {
		for (int t = k; t >= weight[i]; t--) {
			if (dp[t] < dp[t - weight[i]] + value[i]) {
				dp[t] = dp[t - weight[i]] + value[i];
			}
		}
	}
	cout << dp[k];
}