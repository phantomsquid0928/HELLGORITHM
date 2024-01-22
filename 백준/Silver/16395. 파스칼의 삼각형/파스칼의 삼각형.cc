#include <bits/stdc++.h>

using namespace std;

int dp[2000];
int main() {
	int n, k;
	cin >> n >> k;
	dp[0] = 1;
	dp[1] = 1;
	
	for (int j = 0; j < n - 2; j++) {
		for (int i = n; i >= 1; i--){ 
			dp[i] = dp[i] + dp[i - 1];
		}
	}
	
//	for (int i =0 ; i< n; i++) {
//		cout << dp[i] << " ";
//	}
//	cout << endl;

	cout << dp[k - 1] << endl;
}