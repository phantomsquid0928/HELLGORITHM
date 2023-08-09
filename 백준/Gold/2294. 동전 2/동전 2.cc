#include <bits/stdc++.h>

using namespace std;

int n, k;
int v[101];
int coin[10001];
int dp[10001];
int main() {
	cin >> n >> k;
	int dup = 0;
	for (int i = 0;i < n; i++) {
		int t;
		cin >> t;
		v[i] = t;
	}
	
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 1;i <= k;i++) {
		for (int j = 0; j < n; j++) {
			int value = v[j];
			if (i >= value) {
				dp[i] = min(dp[i], dp[i - value] + 1);
			}
		}
	}
    if (dp[k] == 0x3f3f3f3f) {
        cout << "-1\n";
        return 0;
    }

	cout << dp[k] << endl;
}