#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int dp[10001]; //dp n = i원을 쓸때 n원을  만드는데 드는 동전의 최소. 


int main() {
	int n, k;
	cin >> n >> k;
	
	for (int i = 0;i <n ;i++ ) {
		int in;
		cin >> in;
		
		arr.push_back(in);
	}
	
	memset(dp, 0x3f, sizeof dp);
	
	dp[0] = 0;
	
	for (int i = 0;i < n; i++ ) {
		for (int j = arr[i]; j <= k; j++) {
			
			dp[j] = min(dp[j], dp[j - arr[i]] + 1);
			
		} 
	}
	
	if (dp[k] == 0x3f3f3f3f) cout << -1 << endl;
	
	else cout << dp[k] << endl;
}