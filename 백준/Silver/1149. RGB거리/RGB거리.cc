#include <bits/stdc++.h>

using namespace std;

vector<array<int, 3>> infos;
int dp[3][1001];
int main() {
	int n;
	cin >> n;
	
	for (int i= 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >>c ;
		infos.push_back({a, b, c});
	}
	dp[0][0] = infos[0][0];
	dp[1][0] = infos[0][1];
	dp[2][0] = infos[0][2];
	for (int i = 1; i < n; i++) {
		dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + infos[i][0];
		dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + infos[i][1];
		dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + infos[i][2];
	}
	
	int res = min({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]});
	cout<<res<<endl;
}