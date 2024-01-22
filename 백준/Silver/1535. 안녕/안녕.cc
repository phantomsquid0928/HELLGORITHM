#include <bits/stdc++.h>

using namespace std;

int cost[1000];
int value[1000];
int dp[101];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	for (int i = 0;i < n; i++){
		cin >> value[i];
	}
	
	for (int i = 0; i< n; i++) {
		for (int k = 99; k >= 0; k--){
			if(k - cost[i] >= 0)
				dp[k] = max(dp[k], dp[k - cost[i]] + value[i]);
		} 
	}
//	
//	for (int i =0 ; i< n; i++){
//		cout << dp[i] << endl;
//	}
	cout << dp[99] << endl;
}