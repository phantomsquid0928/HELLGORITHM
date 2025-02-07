#include <bits/stdc++.h>

using namespace std;

int ts[16];
int ps[16];
int dp[111];

int main() {
	int n;
	cin >> n;
	
	for (int i= 0 ;i < n; i++) {
		cin >> ts[i] >> ps[i];
	}
	
	for (int i = n - 1; i >= 0; i--) {
		if (i + ts[i] > n) {
			dp[i] = dp[i + 1];
			continue;
		}
		dp[i] = max(dp[i + ts[i]] + ps[i], dp[i + 1]);
	}
	
//	for (int i = 0;i < n; i++) {
//		cout << dp[i] << " ";
//	}
//	cout << endl;
	cout << dp[0] << endl;
}