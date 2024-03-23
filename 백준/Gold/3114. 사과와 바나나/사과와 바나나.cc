#include <bits/stdc++.h>

using namespace std;
pair<int, int> arr[1503][1503];
int dp[1503][1503];
int r, c;

int main() {
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			string s;
			cin >> s;
			if (s[0] == 'A') {
				arr[i][j].first += arr[i - 1][j].first + stoi(s.substr(1, s.length()));
				arr[i][j].second += arr[i - 1][j].second;
			}
			else {
				arr[i][j].first += arr[i - 1][j].first;
				arr[i][j].second += arr[i - 1][j].second + stoi(s.substr(1, s.length()));
			}
		}
	}
	for (int i = 1; i <= c; i++) {
		for (int j = 1; j <= r; j++) {
			arr[j][i].first += arr[j][i - 1].first;
			arr[j][i].second += arr[j][i  - 1].second;
		}
	}
//	for (int i = 1; i <= r; i++) {
//		for (int j = 1; j <= c; j++) {
//			cout << arr[i][j].first << "," << arr[i][j].second << " ";
//		}
//		cout << endl;
//	}
//	cout << solve(r, c);
	for (int i = 1; i <= r; i++) {
		for (int j  = 1;j <= c; j++) {
			if (i > 1) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i][j - 1].first - arr[i - 1][j - 1].first);//down
			}
			if (j > 1) {
				dp[i][j] = max(dp[i][j], dp[i][j - 1] + arr[i - 1][j].second - arr[i - 1][j - 1].second); //r
			}
			if (i > 1 && j > 1) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + arr[i][j - 1].first + arr[i - 1][j].second - arr[i - 1][j - 1].first - arr[i - 1][j - 1].second); //diag
			}
			
		}
	}
	cout << dp[r][c];
}