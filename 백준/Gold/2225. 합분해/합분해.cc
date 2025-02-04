#include <bits/stdc++.h>

using namespace std;
	//i		j
int dp[201][201]; //j를 i개의 숫자로 만드는 경우의 수 

int main() {
	int n, k;
	
	cin >> n>> k;
	
	for (int i = 0; i <= n; i++) {
		dp[1][i] = 1;
	}
	
	for (int i = 2; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int t = 0; t <= j; t++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][t]) % 1000000000;
			}
		}
//		for (int j = 0; j <= n; j++) {
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
	}
	
	cout << dp[k][n] << endl;
	
}