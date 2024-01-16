#include <bits/stdc++.h>

using namespace std;

int val[100001];
int dp[10001];
int main() {
	int n, k;
	cin >> n >> k;
	
	for (int i= 0;i < n; i++) {
		int temp;
		cin >> temp;
		val[i] = temp;
	}
	
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - val[i] < 0) continue;
			dp[j] += dp[j - val[i]];
		}
	}
//	for (int i = 1; i <= k; i++) {
//		cout << dp[i] << " ";
//	}
	cout << dp[k] << endl;
}