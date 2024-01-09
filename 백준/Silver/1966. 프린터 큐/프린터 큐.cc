#include <bits/stdc++.h>

using namespace std;



int solve() {
	int n, m;
	cin >> n >> m;
	int target = -1;
	queue<array<int, 2>> q;
	priority_queue<int> pq;
	for (int i = 0; i< n; i++) {
		int temp;
		cin>>temp;
		if (i == m) {
			target = i;
		}
		q.push({i, temp});
		pq.push(temp);
	}
//	cout << pq.size() << endl;
//	int k = pq.size();
	int i = 0;
	while(!q.empty()) {
		int t = q.front()[0];
		int p = q.front()[1];
		int tp = pq.top();
		if (tp != p) {
			q.pop();
			q.push({t, p});
			continue;
		}
		if (target == t) {
			return i + 1;
		}
		q.pop();
		pq.pop();
		i++;
	}
	return -1;
}
int main() {
	int t;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	
	while(t--) {
		cout << solve() << endl;
	}
}