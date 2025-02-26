#include <bits/stdc++.h>

using namespace std;

vector<array<int, 2>> info;
int dp[100001];

int main() {
	int t = 3;
	while(t--) {
		int n;
		cin >> n;
		
		int sum = 0;
		memset(dp, 0, sizeof dp);
		info.clear();
		
		for (int i= 0 ;i < n; i++) {
			int a, b;
			cin >> a >> b;
			info.push_back({a, b});
			sum += a * b;
		}
		
		int mid= sum / 2;
		if (sum % 2 == 1) {
			cout << 0 << endl;
			continue;
		}
		
		dp[0] = 1;
		
		for (auto &i : info) {
			for (int j = mid; j >= i[0]; j--) {
//				if (dp[j - i[0]] == 0) continue;
				for (int k = 1; k <= i[1]; k++){ 
					if (j - k * i[0] < 0) break;
					if (dp[j - k * i[0]] == 0) continue;
					dp[j] = 1;
				}
			}
		}
		
//		for (int i = 1; i<= sum; i++) {
//			cout << dp[i] << " ";
//		}
//		cout << endl;
//		cout << dp[mid] << endl;
		
		if (dp[mid] != 0) cout << 1 << endl;
		else cout << 0 << endl;
	}
}