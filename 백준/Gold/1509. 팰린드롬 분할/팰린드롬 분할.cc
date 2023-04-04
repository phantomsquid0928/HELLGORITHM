#include <bits/stdc++.h>

using namespace std;
int dp2[5000][5000] = {};
//map<pair<int, int>, int> dp2;
//int ispalin(string s, int start, int end) {
//	if (end - start <= 0) return 1;
//	if (dp2[start][end] != -1) return dp2[start][end];
//	if (s[start] == s[end]) {
//		dp2[start][end] = ispalin(s, start + 1, end - 1);
//		return dp2[start][end];
//	}
//	else {
//		return 0;
//	}
//}
//int ispalin(string s, int start, int end) {
//	if (end - start <= 0) return 1;
//	if (dp2.find(make_pair(start, end)) != dp2.end()) return dp2[make_pair(start, end)];
//	if (s[start] == s[end]) {
//		int res = ispalin(s, start + 1, end - 1);
//		dp2.insert(make_pair(make_pair(start, end), res));
//		return res;
//	}
//	else {
//		return 0;
//	}
//}
int ispalin(string s, int start, int end) {
	if (end - start <= 0) return 1;
	if (dp2[start][end] != -1) return dp2[start][end];
	if (s[start] == s[end]) {
		dp2[start][end] = ispalin(s, start + 1, end - 1);
		return dp2[start][end];
	}
	else {
		return 0;
	}
}
//int check(string s, int * dp, int t) {
//	if (t == s.length()) return 0;
//	if (dp[t] != 1000000) return dp[t];
//	for (int i = t; i < s.length(); i++) {
//		if (ispalin(s, t, i)) {
//			dp[t] = min(dp[t], 1 + check(s, dp, i + 1));
//		}
//	}
//	return dp[t];
//}
int check(string s, int * dp) {
	for (int i=1; i<=s.length(); i++) {
		dp[i] = -1;
		for (int j = 1; j <= i; j++) {
			if (ispalin(s, j - 1, i - 1) == 1) {
				if (dp[i] == -1 || dp[i] > dp[j - 1] + 1) {
					dp[i] = dp[j - 1] + 1;
				}
			}
		}
	}
	return dp[s.length()];
}
int main() {
	string s;
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> s;
	//cout << ispal(s, 0, s.length() - 1) << endl;
	int dp[s.length() + 1] = {};
//	for (int i =0 ; i < s.length(); i++) {
//		dp[i] = 1000000;
//	}
	memset(dp2, -1, sizeof(dp2));
	cout << check(s, dp);
}