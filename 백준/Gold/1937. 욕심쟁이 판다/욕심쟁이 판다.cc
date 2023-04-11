#include<bits/stdc++.h>

using namespace std;

int a[501][501];
int dp[501][501];
int n;
int solve(int x, int y){
	if(x == 0 || y == 0 || x > n || y > n) return 0;
	int &ret = dp[x][y];
	if(ret != -1) return ret;
	ret = 1;
	if(a[x][y] < a[x+1][y]) {
		int temp = solve(x + 1, y) + 1;
		ret = max(temp, ret);
	}
	if(a[x][y] < a[x-1][y]) {
		int temp = solve(x -1, y) + 1;
		ret = max(temp, ret);
	}
	if(a[x][y] < a[x][y+1]) {
		int temp = solve(x, y + 1) + 1;
		ret = max(temp, ret);
	}
	if(a[x][y] < a[x][y-1]) {
		int temp = solve(x, y - 1) + 1;
		ret = max(temp, ret);
	}
	return ret;
}
int main(){
	cin >> n;
	for(int i = 1; i<= n; i++){
		for(int j=  1; j<= n; j++){
			cin >> a[i][j];
		}
	}
	int res = 0;
	memset(dp, -1, sizeof(dp));
	for(int i =1; i <= n;i++) {
		for(int j = 1; j<=n; j++){
			dp[i][j] = max(dp[i][j], solve(i, j));
			res = max(res, dp[i][j]);
		}
	}
//	for(int i =1; i <= n;i++) {
//		for(int j = 1; j<=n; j++){
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
	cout << res;
}