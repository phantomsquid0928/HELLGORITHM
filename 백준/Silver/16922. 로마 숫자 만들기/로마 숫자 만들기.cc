#include <bits/stdc++.h>

using namespace std;

int nums[] = {1, 5, 10, 50};

int n = 0;
int dp2[10001];

set<array<int, 4>> uses;
void solve(int t, int cur, array<int, 4> used) {
	if (t == n) {
		dp2[cur]++;
		return;
	}
	uses.insert(used);
	for (int i = 0; i < 4; i++) {
		used[i]++;
		if (uses.count(used)) {
			used[i]--;
			continue;
		}
		solve(t + 1, cur + nums[i], used);
		used[i]--;
	}
}
int main () {
	cin >> n;
	
	solve(0, 0, {0, 0, 0, 0});
	
	int cnt = 0;
	for (int i= 1; i <= 50 * n; i++) {
		if (dp2[i] != 0) {
//			cout << i << endl;
			cnt++;
		}
		
	}
	cout << cnt << endl;
}