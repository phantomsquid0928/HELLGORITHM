#include <bits/stdc++.h>

using namespace std;

pair<int, int> lvarr[102][102];
pair<int, int> resarr[100000];
int cnt = 0;
void recur(int j, int k, int n) {
	if (lvarr[j][k].first == -10)  {
		resarr[cnt] = make_pair(j, k);
		cnt++;
		return;
	}
	if (lvarr[j][k].first != -100) {
		int t = lvarr[j][k].first;
		//cout << j << "-" << k << endl;
		recur(j, t, n);
		recur(t + 1, k, n);
	}
	else {
		
		resarr[cnt] = make_pair(j, k);
		cnt++;
		recur(j + 1, k - 1, n);
	}
}

int main() {
	int n;
	cin >> n;
	int arr[n + 1];
	int dp[n + 1][n + 1];
	getchar();
	for (int i = 1; i <= n; i++) {
		arr[i] = getchar() - 48;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = 10000;
		}
	}
	for (int i = 1; i <= n; i++) {
		dp[i][i] = 0;
	}
	int last;
	last = arr[1];
	for (int i = 1; i <= n - 1; i++) {
		if (i % 2 == 0) continue;
		for (int j = 1; j <= n - i; j++) {
			int k = j + i;
			int whowin = -1;
			int target = 0;
			if (i == 1) {
				if (last != arr[k]) {
					dp[j][k] = 3;
					lvarr[j][k].first = -10;
					lvarr[j][k].second = 1;
					last = arr[k];
				}
				continue;
			}
			for (int t = j; t <= k-1; t++) {
				//dp[j][k] = min(dp[j][t] + dp[t + 1][k], dp[j][k]);
				if (dp[j][t] + dp[t + 1][k] < dp[j][k]) {
					dp[j][k] = dp[j][t] + dp[t + 1][k];
					int lvt = lvarr[j][t].second;
					int lvt2 = lvarr[t + 1][k].second;
					target = t;
					whowin = max(lvt, lvt2);
				}
			}
			if (dp[j + 1][k - 1] != 10000 && arr[j] != arr[k]) {
				//cout << "Ff"; 
				int lv = lvarr[j + 1][k - 1].second + 1;
				//cout << dp[j + 1][k - 1] << ": " << 2 * lv << "-" << j - k << "   ";
				if (dp[j][k] > dp[j + 1][k - 1] + k - j + 2 * lv) {
					whowin = lvarr[j + 1][k - 1].second + 1;
					target = -100;
					dp[j][k] = dp[j + 1][k - 1] + k - j + 2 * lv;
				}
			}
			if (dp[j][k] != 10000){
				lvarr[j][k] = make_pair(target, whowin);
			}
		}
	}
	recur(1, n, n);
	cout << dp[1][n] << endl;
	sort(resarr, resarr + cnt);
	
	for (int i = 0; i < cnt; i++) {
		cout << resarr[i].first << " " << resarr[i].second << endl;
	}
	
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == 10000) {
				cout << setw(3) << "-";
				continue;
			}
			cout << setw(3) << dp[i][j];
		}
		cout << endl;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (lvarr[i][j].first == 0) {
				cout << setw(3)<<"- ";
				continue;
			}
			cout << setw(3)<<lvarr[i][j].first << ":" << lvarr[i][j].second;
		}
		cout << endl;
	}*/
	
}